/**
* Copyright (C) 2019 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "dinput8.h"

HRESULT m_IDirectInput8A::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	if ((riid == IID_IDirectInput8A || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectInput8A::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInput8A::Release()
{
	ULONG ref = ProxyInterface->Release();

	if (ref == 0)
	{
		delete this;
	}

	return ref;
}

HRESULT m_IDirectInput8A::CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8A *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	HRESULT hr = ProxyInterface->CreateDevice(rguid, lplpDirectInputDevice, pUnkOuter);

	if (SUCCEEDED(hr) && lplpDirectInputDevice)
	{
		*lplpDirectInputDevice = ProxyAddressLookupTable.FindAddress<m_IDirectInputDevice8A>(*lplpDirectInputDevice);
		m_IDirectInputDevice8A *dev = *(m_IDirectInputDevice8A**)lplpDirectInputDevice;
		if(rguid == hookedPad.guid)
			hookedPad.Init(dev);
	}

	return hr;
}

static LPDIENUMDEVICESCALLBACKA origCB;
BOOL PASCAL MyEnumDevices(LPCDIDEVICEINSTANCEA inst, LPVOID arg)
{
	if((inst->dwDevType&0xFF) == DI8DEVTYPE_GAMEPAD){
#ifdef VERBOSE
		printf("seeing gamepad <%s>\n", inst->tszInstanceName);
#endif
		if(strcmp(inst->tszInstanceName, "Controller (XBOX 360 For Windows)") == 0 ||
		   strcmp(inst->tszInstanceName, "Controller (Xbox One For Windows)") == 0){
			strncpy(((DIDEVICEINSTANCEA*)inst)->tszInstanceName, "Hackpad", MAX_PATH);
			strncpy(((DIDEVICEINSTANCEA*)inst)->tszProductName, "Hackpad", MAX_PATH);
			hookedPad.guid = inst->guidInstance;
		}
		return origCB(inst, arg);
	}
	return origCB(inst, arg);
}

HRESULT m_IDirectInput8A::EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	origCB = lpCallback;
	return ProxyInterface->EnumDevices(dwDevType, MyEnumDevices, pvRef, dwFlags);
//	return ProxyInterface->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInput8A::GetDeviceStatus(REFGUID rguidInstance)
{
	return ProxyInterface->GetDeviceStatus(rguidInstance);
}

HRESULT m_IDirectInput8A::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return ProxyInterface->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT m_IDirectInput8A::Initialize(HINSTANCE hinst, DWORD dwVersion)
{
	return ProxyInterface->Initialize(hinst, dwVersion);
}

HRESULT m_IDirectInput8A::FindDevice(REFGUID rguidClass, LPCSTR ptszName, LPGUID pguidInstance)
{
	return ProxyInterface->FindDevice(rguidClass, ptszName, pguidInstance);
}

HRESULT m_IDirectInput8A::EnumDevicesBySemantics(LPCSTR ptszUserName, LPDIACTIONFORMATA lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCBA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	if (!lpCallback)
	{
		return E_INVALIDARG;
	}

	ENUMDEVICEA CallbackContext;
	CallbackContext.pvRef = pvRef;
	CallbackContext.lpCallback = lpCallback;

	return ProxyInterface->EnumDevicesBySemantics(ptszUserName, lpdiActionFormat, m_IDirectInputEnumDevice::EnumDeviceCallbackA, &CallbackContext, dwFlags);
}

HRESULT m_IDirectInput8A::ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMSA lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
	return ProxyInterface->ConfigureDevices(lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
