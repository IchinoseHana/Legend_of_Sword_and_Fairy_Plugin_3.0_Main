#include "stdafx.h"

#include "PEP3UIStaticMouseTrace.h"
#include "..\Utility\PEP3UIUtil.h"

#include <sstream>
#include <string>

PEP3UIStaticMouseTraceType PEP3UIStaticMouseTrace::getMouseType()
{
	POINT mousept;
	g_input.GetMousePos(mousept);
	if (!spcPEP3UIUtil::screenPtToClientPt(mousept))
	{
		return PEP3UIStaticMouseTraceTypeNone;
	}

	RECT rect = GetWindowRect();

	if (::PtInRect(&rect, mousept))
	{
		if (g_input._ClickOnce(PALKEY_LBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeLeftClicked;
		}
		else if (g_input._ClickOnce(PALKEY_RBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeRightClicked;
		}
		else if (g_input._ClickDouble(PALKEY_LBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeLeftDoubleClicked;
		}
		else if (g_input._ClickDouble(PALKEY_RBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeRightDoubleClicked;
		}
		else if (g_input._Pressed(PALKEY_LBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeLeftPressed;
		}
		else if (g_input._Pressed(PALKEY_RBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeRightPressed;
		}
		else if (g_input._Release(PALKEY_LBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeLeftReleased;
		}
		else if (g_input._Release(PALKEY_RBUTTON))
		{
			return PEP3UIStaticMouseTraceTypeRightReleased;
		}
		else
		{
			return PEP3UIStaticMouseTraceTypePointed;
		}
	}
	else
	{
		return PEP3UIStaticMouseTraceTypeNone;
	}
}