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
#include <assert.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput9_1_0.lib")

HookedPad hookedPad;


/*
DIDEVICEOBJECTINSTANCEA xinputObjectsDefault[20] = {
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_YAxis, 0,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(1) | DIDFT_FFACTUATOR,
		DIDOI_POLLED | DIDOI_ASPECTPOSITION | DIDOI_FFACTUATOR,
		"Y", 10, 256, 1, 0, 1, 0x31, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_XAxis, 4,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(0) | DIDFT_FFACTUATOR,
		DIDOI_POLLED | DIDOI_ASPECTPOSITION | DIDOI_FFACTUATOR,
		"X", 10, 256, 1, 0, 1, 0x30, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_RyAxis, 8,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(4),
		DIDOI_ASPECTPOSITION,
		"Y Rotation", 0, 0, 2, 0, 1, 0x34, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_RxAxis, 0xC,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(3),
		DIDOI_ASPECTPOSITION,
		"X Rotation", 0, 0, 2, 0, 1, 0x33, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_ZAxis, 0x10,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(2),
		DIDOI_ASPECTPOSITION,
		"Z Axis", 0, 0, 3, 0, 1, 0x32, 0, 0, 0 },

	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x18,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(0) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"1", 0, 0, 0, 0, 9, 0x1, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x19,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(1) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"2", 0, 0, 0, 0, 9, 0x2, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1A,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(2) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"3", 0, 0, 0, 0, 9, 0x3, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1B,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(3) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"4", 0, 0, 0, 0, 9, 0x4, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1C,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(4) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"5", 0, 0, 0, 0, 9, 0x5, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1D,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(5) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"6", 0, 0, 0, 0, 9, 0x6, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1E,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(6) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"7", 0, 0, 0, 0, 9, 0x7, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1F,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(7) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"8", 0, 0, 0, 0, 9, 0x8, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x20,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(8) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"9", 0, 0, 0, 0, 9, 0x9, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x21,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(9) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"10", 0, 0, 0, 0, 9, 0x10, 0, 0, 0 },

	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_POV, 0x14,
		DIDFT_POV,
		0,
		"Hat Switch", 0, 0, 0, 0, 1, 0x39, 14, 0, 0 },

	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(0),
		0,
		"Collection 0 - Game Pad", 0, 0, 0, 0, 1, 0x5, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(1),
		0,
		"Collection 1", 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(2),
		0,
		"Collection 2", 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(3),
		0,
		"Collection 3", 0, 0, 0, 0, 1, 0, 0, 0, 0 },

};
*/

DIDEVICEOBJECTINSTANCEA xinputObjects[] = {
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_XAxis, 0,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(0) | DIDFT_FFACTUATOR,
		DIDOI_POLLED | DIDOI_ASPECTPOSITION | DIDOI_FFACTUATOR,
		"X", 10, 256, 1, 0, 1, 0x30, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_YAxis, 4,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(1) | DIDFT_FFACTUATOR,
		DIDOI_POLLED | DIDOI_ASPECTPOSITION | DIDOI_FFACTUATOR,
		"Y", 10, 256, 1, 0, 1, 0x31, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_RxAxis, 8,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(2),
		DIDOI_ASPECTPOSITION,
		"X Rotation", 0, 0, 2, 0, 1, 0x33, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_RyAxis, 0xC,
		DIDFT_ABSAXIS | DIDFT_MAKEINSTANCE(3),
		DIDOI_ASPECTPOSITION,
		"Y Rotation", 0, 0, 2, 0, 1, 0x34, 0, 0, 0 },

	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x18,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(0) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"1", 0, 0, 0, 0, 9, 0x1, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x19,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(1) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"2", 0, 0, 0, 0, 9, 0x2, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1A,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(2) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"3", 0, 0, 0, 0, 9, 0x3, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1B,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(3) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"4", 0, 0, 0, 0, 9, 0x4, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1C,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(4) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"5", 0, 0, 0, 0, 9, 0x5, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1D,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(5) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"6", 0, 0, 0, 0, 9, 0x6, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1E,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(6) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"7", 0, 0, 0, 0, 9, 0x7, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x1F,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(7) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"8", 0, 0, 0, 0, 9, 0x8, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x20,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(8) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"9", 0, 0, 0, 0, 9, 0x9, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x21,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(9) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"10", 0, 0, 0, 0, 9, 0xA, 0, 0, 0 },

#if 1
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x16,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(10) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"11", 0, 0, 0, 0, 9, 0xB, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Button, 0x17,
		DIDFT_PSHBUTTON | DIDFT_MAKEINSTANCE(11) | DIDFT_FFEFFECTTRIGGER,
		DIDOI_POLLED | DIDOI_FFEFFECTTRIGGER,
		"12", 0, 0, 0, 0, 9, 0xC, 0, 0, 0 },
#endif


	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_POV, 0x10,
		DIDFT_POV,
		0,
		"Hat Switch", 0, 0, 0, 0, 1, 0x39, 14, 0, 0 },

	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(0),
		0,
		"Collection 0 - Game Pad", 0, 0, 0, 0, 1, 0x5, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(1),
		0,
		"Collection 1", 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(2),
		0,
		"Collection 2", 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ sizeof(DIDEVICEOBJECTINSTANCEA), GUID_Unknown, 0,
		DIDFT_COLLECTION | DIDFT_NODATA | DIDFT_MAKEINSTANCE(3),
		0,
		"Collection 3", 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0 }
};

#define DBTN(data, i) (*(BYTE*)((char*)(data) + format.rgodf[i].dwOfs))
#define DAXIS(data, i) (*(LONG*)((char*)(data) + format.rgodf[i].dwOfs))
#define DPOV(data, i) (*(LONG*)((char*)(data) + format.rgodf[i].dwOfs))	// actually same as axis

void
HookedPad::Init(m_IDirectInputDevice8A *p)
{
	int i;
	XINPUT_STATE state;

	for(i = 0; i < 20; i++)
		buttonIds[i] = -1;
	for(i = 0; i < 20; i++)
		axisIds[i] = -1;
	povId = -1;

	pad = p;
	for(i = 0; i < 4; i++)
		if(XInputGetState(i, &state) == ERROR_SUCCESS){
#ifdef VERBOSE
			printf("using xinput pad %d\n", i);
#endif
			xpadId = i;
			return;
		}
	// fail
	pad = NULL;
}

void HookedPad::X2D(void *ds, XINPUT_STATE *xs)
{
	DBTN(ds, buttonIds[0]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_A) ? 0x80 : 0;
	DBTN(ds, buttonIds[1]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_B) ? 0x80 : 0;
	DBTN(ds, buttonIds[2]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_Y) ? 0x80 : 0;
	DBTN(ds, buttonIds[3]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_X) ? 0x80 : 0;

	DBTN(ds, buttonIds[4]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) ? 0x80 : 0;
	DBTN(ds, buttonIds[5]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) ? 0x80 : 0;
	DBTN(ds, buttonIds[6]) = (xs->Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) ? 0x80 : 0;
	DBTN(ds, buttonIds[7]) = (xs->Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) ? 0x80 : 0;
	DBTN(ds, buttonIds[8]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_START) ? 0x80 : 0;
	DBTN(ds, buttonIds[9]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_BACK) ? 0x80 : 0;
	DBTN(ds, buttonIds[10]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) ? 0x80 : 0;
	DBTN(ds, buttonIds[11]) = (xs->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) ? 0x80 : 0;

	if(xs->Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || xs->Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		DAXIS(ds, axisIds[0]) = xs->Gamepad.sThumbLX + 32768;
	else
		DAXIS(ds, axisIds[0]) = 32768;
	if(xs->Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || xs->Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		DAXIS(ds, axisIds[1]) = 32768 - xs->Gamepad.sThumbLY;
	else
		DAXIS(ds, axisIds[1]) = 32768;
	if(xs->Gamepad.sThumbRX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || xs->Gamepad.sThumbRX < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		DAXIS(ds, axisIds[2]) = xs->Gamepad.sThumbRX + 32768;
	else
		DAXIS(ds, axisIds[2]) = 32768;
	if(xs->Gamepad.sThumbRY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || xs->Gamepad.sThumbRY < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		DAXIS(ds, axisIds[3]) = 32768 - xs->Gamepad.sThumbRY;
	else
		DAXIS(ds, axisIds[3]) = 32768;

#define XINPUT_GAMEPAD_DPAD (XINPUT_GAMEPAD_DPAD_UP|XINPUT_GAMEPAD_DPAD_RIGHT|XINPUT_GAMEPAD_DPAD_DOWN|XINPUT_GAMEPAD_DPAD_LEFT)
	int pov = -1;
	if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == XINPUT_GAMEPAD_DPAD_UP)
		pov = 0;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == (XINPUT_GAMEPAD_DPAD_UP|XINPUT_GAMEPAD_DPAD_RIGHT))
		pov = (1*45)*100;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == XINPUT_GAMEPAD_DPAD_RIGHT)
		pov = (2*45)*100;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == (XINPUT_GAMEPAD_DPAD_RIGHT|XINPUT_GAMEPAD_DPAD_DOWN))
		pov = (3*45)*100;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == XINPUT_GAMEPAD_DPAD_DOWN)
		pov = (4*45)*100;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == (XINPUT_GAMEPAD_DPAD_DOWN|XINPUT_GAMEPAD_DPAD_LEFT))
		pov = (5*45)*100;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == XINPUT_GAMEPAD_DPAD_LEFT)
		pov = (6*45)*100;
	else if((xs->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD) == (XINPUT_GAMEPAD_DPAD_LEFT|XINPUT_GAMEPAD_DPAD_UP))
		pov = (7*45)*100;
	else
		pov = -1;
	DPOV(ds, povId) = pov;
}

void HookedPad::ClearState(void *state)
{
	int i;
	for(i = 0; i < (int)format.dwNumObjs; i++){
		if(format.rgodf[i].dwType & DIDFT_BUTTON)
			DBTN(state, i) = 0;
		else if(format.rgodf[i].dwType & DIDFT_AXIS)
			DAXIS(state, i) = 32768;
		else if(format.rgodf[i].dwType & DIDFT_POV)
			DPOV(state, i) = -1;
	}
}

void
HookedPad::QueueData(void)
{
	int i;
	for(i = 0; i < (int)format.dwNumObjs; i++){
		if(numQueue >= 32)
			return;
		if(format.rgodf[i].dwType & DIDFT_BUTTON){
			if(DBTN(OldState, i) != DBTN(NewState, i)){
				queueData[numQueue].dwData = DBTN(NewState, i);
				queueData[numQueue].dwOfs = format.rgodf[i].dwOfs;
				// TODO
				queueData[numQueue].dwSequence = 0;
				queueData[numQueue].dwTimeStamp = 0;
				queueData[numQueue].uAppData = 0;
				DBTN(OldState, i) = DBTN(NewState, i);
				numQueue++;
			}
		}else if(format.rgodf[i].dwType & DIDFT_AXIS){
			if(DAXIS(OldState, i) != DAXIS(NewState, i)){
				queueData[numQueue].dwData = DAXIS(NewState, i);
				queueData[numQueue].dwOfs = format.rgodf[i].dwOfs;
				// TODO
				queueData[numQueue].dwSequence = 0;
				queueData[numQueue].dwTimeStamp = 0;
				queueData[numQueue].uAppData = 0;
				DAXIS(OldState, i) = DAXIS(NewState, i);
				numQueue++;
			}
		}else if(format.rgodf[i].dwType & DIDFT_POV){
			if(DPOV(OldState, i) != DPOV(NewState, i)){
				queueData[numQueue].dwData = DPOV(NewState, i);
				queueData[numQueue].dwOfs = format.rgodf[i].dwOfs;
				// TODO
				queueData[numQueue].dwSequence = 0;
				queueData[numQueue].dwTimeStamp = 0;
				queueData[numQueue].uAppData = 0;
				DPOV(OldState, i) = DPOV(NewState, i);
				numQueue++;
			}
		}
	}
}

int
HookedPad::ReadData(DIDEVICEOBJECTDATA *data, bool peek)
{
	if(numQueue == 0)
		return 0;

	memcpy(data, queueData, sizeof(DIDEVICEOBJECTDATA));
	if(!peek){
		numQueue--;
		memmove(queueData, &queueData[1], numQueue*sizeof(DIDEVICEOBJECTDATA));
	}
	return 1;
}

HRESULT HookedPad::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	DIDEVICEOBJECTINSTANCEA *inst;
	for(inst = xinputObjects; inst->dwSize != 0; inst++){
		if(dwFlags == DIDFT_ALL ||
		   (inst->dwFlags & dwFlags) != 0)
			lpCallback(inst, pvRef);
	}
	return DI_OK;
}


char *gettypestr(DWORD type)
{
	static char buf[1000];
	char *p = buf;

	p[0] = '\0';
	if(type & DIDFT_RELAXIS) p += sprintf(p, " DIDFT_RELAXIS");
	if(type & DIDFT_ABSAXIS) p += sprintf(p, " DIDFT_ABSAXIS");
	if(type & DIDFT_PSHBUTTON) p += sprintf(p, " DIDFT_PSHBUTTON");
	if(type & DIDFT_TGLBUTTON) p += sprintf(p, " DIDFT_TGLBUTTON");
	if(type & DIDFT_POV) p += sprintf(p, " DIDFT_POV");
	if(type & DIDFT_COLLECTION) p += sprintf(p, " DIDFT_COLLECTION");
	if(type & DIDFT_NODATA) p += sprintf(p, " DIDFT_NODATA");
	if(type & DIDFT_FFACTUATOR) p += sprintf(p, " DIDFT_FFACTUATOR");
	if(type & DIDFT_FFEFFECTTRIGGER) p += sprintf(p, " DIDFT_FFEFFECTTRIGGER");
	if(type & DIDFT_VENDORDEFINED) p += sprintf(p, " DIDFT_VENDORDEFINED");
	if(type & DIDFT_ALIAS) p += sprintf(p, " DIDFT_ALIAS");
	if(type & DIDFT_OUTPUT) p += sprintf(p, " DIDFT_OUTPUT");
	p += sprintf(p, " %d", DIDFT_GETINSTANCE(type));
	return buf;
}

HRESULT HookedPad::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	int i;

	format = *lpdf;
	format.rgodf = (DIOBJECTDATAFORMAT*)malloc(sizeof(DIOBJECTDATAFORMAT)*lpdf->dwNumObjs);
	memcpy(format.rgodf, lpdf->rgodf, sizeof(DIOBJECTDATAFORMAT)*lpdf->dwNumObjs);
	for(i = 0; i < (int)lpdf->dwNumObjs; i++){
		if(lpdf->rgodf[i].dwType & DIDFT_BUTTON)
			buttonIds[DIDFT_GETINSTANCE(lpdf->rgodf[i].dwType)] = i;
		else if(lpdf->rgodf[i].dwType & DIDFT_AXIS)
			axisIds[DIDFT_GETINSTANCE(lpdf->rgodf[i].dwType)] = i;
		else if(lpdf->rgodf[i].dwType & DIDFT_POV)
			povId = i;
	}

	for(i = 0; i < 12; i++)
		assert(buttonIds[i] != -1);
	for(i = 0; i < 4; i++)
		assert(axisIds[i] != -1);
	assert(povId != -1);

	OldState = malloc(lpdf->dwDataSize);
	NewState = malloc(lpdf->dwDataSize);
	memset(OldState, 0, lpdf->dwDataSize);
	memset(NewState, 0, lpdf->dwDataSize);

#ifdef VERBOSE
	printf("SetDataFormat %p\n", this);
//	printf("%x %X %d %d %d\n", caps.dwFlags, caps.dwDevType, caps.dwAxes, caps.dwButtons, caps.dwPOVs);
	printf("%u %u %u %u %u\n", lpdf->dwSize, lpdf->dwObjSize, lpdf->dwFlags, lpdf->dwDataSize, lpdf->dwNumObjs);
	for(i = 0; i < (int)lpdf->dwNumObjs; i++){
		printf("  %p %d %X(%s) %d\n",
			lpdf->rgodf[i].pguid,
			lpdf->rgodf[i].dwOfs,
			lpdf->rgodf[i].dwType, gettypestr(lpdf->rgodf[i].dwType),
			lpdf->rgodf[i].dwFlags);
	}
#endif


	return pad->ProxyInterface->SetDataFormat(&c_dfDIJoystick);
}

HRESULT HookedPad::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	XINPUT_STATE xstate;
//	printf("Get State\n");
	memset(lpvData, 0, cbData);
	ClearState(lpvData);
	if(NewState){
		XInputGetState(xpadId, &xstate);
		hookedPad.X2D(NewState, &xstate);
		memcpy(OldState, NewState, format.dwDataSize);
	}
	return DI_OK;
}

HRESULT HookedPad::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	XINPUT_STATE xstate;
	int n, i;

	// get more data
	if(memcmp(OldState, NewState, format.dwDataSize) == 0){
	//	printf("getting data\n");
		XInputGetState(xpadId, &xstate);
		X2D(NewState, &xstate);
	}
	QueueData();

	n = *pdwInOut;
	*pdwInOut = 0;
	for(i = 0; i < n; i++)
		if(ReadData(&rgdod[i], dwFlags == DIGDD_PEEK))
			(*pdwInOut)++;
		else
			break;
//	n = *pdwInOut;
//	for(i = 0; i < n; i++){
//		printf("getting data %d %X: %X %X\n", n, dwFlags, rgdod[i].dwOfs, rgdod[i].dwData);
//	}
	return DI_OK;
}









HRESULT m_IDirectInputDevice8A::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	if ((riid == IID_IDirectInputDevice8A || riid == IID_IUnknown) && ppvObj)
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

ULONG m_IDirectInputDevice8A::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInputDevice8A::Release()
{
	ULONG ref = ProxyInterface->Release();

	if (ref == 0)
	{
		if(hookedPad.pad == this)
			hookedPad.pad = NULL;
		delete this;
	}

	return ref;
}

HRESULT m_IDirectInputDevice8A::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	HRESULT res;
	res = ProxyInterface->GetCapabilities(lpDIDevCaps);
	if(hookedPad.pad && hookedPad.pad == this){
//		printf("geting caps: %x %X %d %d %d\n",
//			lpDIDevCaps->dwFlags, lpDIDevCaps->dwDevType,
//			lpDIDevCaps->dwAxes, lpDIDevCaps->dwButtons, lpDIDevCaps->dwPOVs);
		lpDIDevCaps->dwAxes = 4;
		lpDIDevCaps->dwButtons = 12;
		lpDIDevCaps->dwPOVs = 1;
	}
	return res;
}

HRESULT m_IDirectInputDevice8A::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	if(this == hookedPad.pad){
		return hookedPad.EnumObjects(lpCallback, pvRef, dwFlags);
	}else
		return ProxyInterface->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputDevice8A::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return ProxyInterface->GetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDevice8A::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return ProxyInterface->SetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDevice8A::Acquire()
{
	return ProxyInterface->Acquire();
}

HRESULT m_IDirectInputDevice8A::Unacquire()
{
	return ProxyInterface->Unacquire();
}

HRESULT m_IDirectInputDevice8A::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	if(this == hookedPad.pad)
		return hookedPad.GetDeviceState(cbData, lpvData);
	else
		return ProxyInterface->GetDeviceState(cbData, lpvData);
}

HRESULT m_IDirectInputDevice8A::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	if(this == hookedPad.pad)
		return hookedPad.GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
	else
		return ProxyInterface->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT m_IDirectInputDevice8A::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	if(this == hookedPad.pad){
		return hookedPad.SetDataFormat(lpdf);
	}else
		return ProxyInterface->SetDataFormat(lpdf);
}

HRESULT m_IDirectInputDevice8A::SetEventNotification(HANDLE hEvent)
{
	return ProxyInterface->SetEventNotification(hEvent);
}

HRESULT m_IDirectInputDevice8A::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return ProxyInterface->SetCooperativeLevel(hwnd, dwFlags);
}

HRESULT m_IDirectInputDevice8A::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
	return ProxyInterface->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT m_IDirectInputDevice8A::GetDeviceInfo(LPDIDEVICEINSTANCEA pdidi)
{
	return ProxyInterface->GetDeviceInfo(pdidi);
}

HRESULT m_IDirectInputDevice8A::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return ProxyInterface->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT m_IDirectInputDevice8A::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return ProxyInterface->Initialize(hinst, dwVersion, rguid);
}

HRESULT m_IDirectInputDevice8A::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT * ppdeff, LPUNKNOWN punkOuter)
{
	HRESULT hr = ProxyInterface->CreateEffect(rguid, lpeff, ppdeff, punkOuter);

	if (SUCCEEDED(hr) && ppdeff)
	{
		*ppdeff = ProxyAddressLookupTable.FindAddress<m_IDirectInputEffect>(*ppdeff);
	}

	return hr;
}

HRESULT m_IDirectInputDevice8A::EnumEffects(LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return ProxyInterface->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT m_IDirectInputDevice8A::GetEffectInfo(LPDIEFFECTINFOA pdei, REFGUID rguid)
{
	return ProxyInterface->GetEffectInfo(pdei, rguid);
}

HRESULT m_IDirectInputDevice8A::GetForceFeedbackState(LPDWORD pdwOut)
{
	return ProxyInterface->GetForceFeedbackState(pdwOut);
}

HRESULT m_IDirectInputDevice8A::SendForceFeedbackCommand(DWORD dwFlags)
{
	return ProxyInterface->SendForceFeedbackCommand(dwFlags);
}

HRESULT m_IDirectInputDevice8A::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	if (!lpCallback)
	{
		return E_INVALIDARG;
	}

	ENUMEFFECT CallbackContext;
	CallbackContext.pvRef = pvRef;
	CallbackContext.lpCallback = lpCallback;

	return ProxyInterface->EnumCreatedEffectObjects(m_IDirectInputEnumEffect::EnumEffectCallback, &CallbackContext, fl);
}

HRESULT m_IDirectInputDevice8A::Escape(LPDIEFFESCAPE pesc)
{
	return ProxyInterface->Escape(pesc);
}

HRESULT m_IDirectInputDevice8A::Poll()
{
	return ProxyInterface->Poll();
}

HRESULT m_IDirectInputDevice8A::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	return ProxyInterface->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT m_IDirectInputDevice8A::EnumEffectsInFile(LPCSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	return ProxyInterface->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}

HRESULT m_IDirectInputDevice8A::WriteEffectToFile(LPCSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	return ProxyInterface->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT m_IDirectInputDevice8A::BuildActionMap(LPDIACTIONFORMATA lpdiaf, LPCSTR lpszUserName, DWORD dwFlags)
{
	return ProxyInterface->BuildActionMap(lpdiaf, lpszUserName, dwFlags);
}

HRESULT m_IDirectInputDevice8A::SetActionMap(LPDIACTIONFORMATA lpdiActionFormat, LPCSTR lptszUserName, DWORD dwFlags)
{
	return ProxyInterface->SetActionMap(lpdiActionFormat, lptszUserName, dwFlags);
}

HRESULT m_IDirectInputDevice8A::GetImageInfo(LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader)
{
	return ProxyInterface->GetImageInfo(lpdiDevImageInfoHeader);
}
