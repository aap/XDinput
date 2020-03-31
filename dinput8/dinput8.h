#pragma once

#define INITGUID
#define _CRT_SECURE_NO_WARNINGS

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

class m_IDirectInput8A;
class m_IDirectInput8W;
class m_IDirectInputDevice8A;
class m_IDirectInputDevice8W;
class m_IDirectInputEffect;

#include "AddressLookupTable.h"
#include "..\Common\Logging.h"

typedef HRESULT(WINAPI *DirectInput8CreateProc)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)();
typedef	HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID, REFIID, LPVOID *);
typedef HRESULT(WINAPI *DllRegisterServerProc)();
typedef HRESULT(WINAPI *DllUnregisterServerProc)();
typedef	LPCDIDATAFORMAT(WINAPI *GetdfDIJoystickProc)();

void genericQueryInterface(REFIID CalledID, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

#include "IDirectInput8A.h"
#include "IDirectInput8W.h"
#include "IDirectInputDevice8A.h"
#include "IDirectInputDevice8W.h"
#include "IDirectInputEffect.h"
#include "IDirectInputEnumDevice.h"
#include "IDirectInputEnumEffect.h"
#include "IClassFactory.h"

#include <Xinput.h>

#define VERBOSE

struct HookedPad
{
	GUID guid;
	m_IDirectInputDevice8A *pad;
	DIDATAFORMAT format;
	int buttonIds[20];
	int axisIds[20];
	int povId;
	void *OldState, *NewState;
	int xpadId;
	DIDEVICEOBJECTDATA queueData[32];
	int numQueue;

	void Init(m_IDirectInputDevice8A *p);
	void X2D(void *ds, XINPUT_STATE *xs);
	void ClearState(void *state);
	void QueueData(void);
	int ReadData(DIDEVICEOBJECTDATA *data, bool peek);

	HRESULT EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT SetDataFormat(LPCDIDATAFORMAT lpdf);
	HRESULT GetDeviceState(DWORD cbData, LPVOID lpvData);
	HRESULT GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
};
extern HookedPad hookedPad;
