#include "stdafx.h"

#include "PEP3SceneUI.h"

#include "..\..\pal3\ui\uistatic.h"
#include "..\..\pal3\combat\cbrolestate.h"
#include "..\Utility\PEP3UIUtil.h"
#include "..\Utility\PEP3Define.h"

#define PEP3CombatUIImageFilePathMenuEntranceIdle "ui\\scene\\PEP3MenuEntrance\\entrance1.tga"
#define PEP3CombatUIImageFilePathMenuEntrancePointed "ui\\scene\\PEP3MenuEntrance\\entrance2.tga"
#define PEP3CombatUIImageFilePathMenuEntranceClicked "ui\\scene\\PEP3MenuEntrance\\entrance3.tga"

using spcPEP3UIUtil::rect;

// 菜单入口UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3SceneMenuEntranceUI* sceneMenuEntranceUIInstance = new PEP3SceneMenuEntranceUI();
PEP3SceneMenuEntranceUI* PEP3SceneMenuEntranceUI::sharedInstance()
{
	return sceneMenuEntranceUIInstance;
}

PEP3SceneMenuEntranceUI::PEP3SceneMenuEntranceUI()
{
	entranceIcon = new PEP3UIStaticMouseTrace();
}

PEP3SceneMenuEntranceUI::~PEP3SceneMenuEntranceUI()
{
	delete entranceIcon;
}

void PEP3SceneMenuEntranceUI::create(UIWnd *ui)
{
	RECT pRcIcon = rect(ClientWidth() - 128, ClientHeight() - 128, 128, 128);
	entranceIcon->Create(0, pRcIcon, ui);
	entranceIcon->SetBk(PEP3CombatUIImageFilePathMenuEntranceIdle);

	setVisibility(false);
}

bool PEP3SceneMenuEntranceUI::update()
{
	switch (mouseTypeToStatus())
	{
	case PEP3SceneMenuEntranceUIIconStatusIdle:
		entranceIcon->SetBk(PEP3CombatUIImageFilePathMenuEntranceIdle);
		return false;
		break;
	case PEP3SceneMenuEntranceUIIconStatusPointed:
		entranceIcon->SetBk(PEP3CombatUIImageFilePathMenuEntrancePointed);
		return true;
		break;
	case PEP3SceneMenuEntranceUIIconStatusClicked:
		entranceIcon->SetBk(PEP3CombatUIImageFilePathMenuEntranceClicked);
		return true;
		break;
	}
}

void PEP3SceneMenuEntranceUI::setVisibility(bool visibility)
{
	entranceIcon->ShowWindow(visibility);
}

PEP3SceneMenuEntranceUIIconStatus PEP3SceneMenuEntranceUI::mouseTypeToStatus()
{
	PEP3UIStaticMouseTraceType mouseType = entranceIcon->getMouseType();

	switch (mouseType)
	{
	case PEP3UIStaticMouseTraceTypeNone:
		return PEP3SceneMenuEntranceUIIconStatusIdle;
	case PEP3UIStaticMouseTraceTypePointed:
		return PEP3SceneMenuEntranceUIIconStatusPointed;
	case PEP3UIStaticMouseTraceTypeLeftClicked:
	case PEP3UIStaticMouseTraceTypeRightClicked:
	case PEP3UIStaticMouseTraceTypeLeftDoubleClicked:
	case PEP3UIStaticMouseTraceTypeRightDoubleClicked:
	case PEP3UIStaticMouseTraceTypeLeftPressed:
	case PEP3UIStaticMouseTraceTypeRightPressed:
	case PEP3UIStaticMouseTraceTypeLeftReleased:
	case PEP3UIStaticMouseTraceTypeRightReleased:
		return PEP3SceneMenuEntranceUIIconStatusClicked;
	default:
		return PEP3SceneMenuEntranceUIIconStatusIdle;
	}
}

// TODO: Aya 交互，点击之后弹出菜单，建议sleep0.5秒