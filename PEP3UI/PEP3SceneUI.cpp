#include "stdafx.h"

#include "PEP3SceneUI.h"

#include "..\..\pal3\ui\uistatic.h"
#include "..\..\pal3\combat\cbrolestate.h"
#include "..\Utility\PEP3UIUtil.h"
#include "..\Utility\PEP3Define.h"

#define PEP3CombatUIImageFilePathMenuEntranceIdle "ui\\scene\\PEP3MenuEntrance\\entrance1.tga"
#define PEP3CombatUIImageFilePathMenuEntrancePointed "ui\\scene\\PEP3MenuEntrance\\entrance2.tga"
#define PEP3CombatUIImageFilePathMenuEntranceClicked "ui\\scene\\PEP3MenuEntrance\\entrance3.tga"
#define PEP3CombatUIImageFilePathMainMenuBackgroundMask "ui\\scene\\PEP3MainMenu\\mainMenuBackgroundMask.tga"
#define PEP3CombatUIImageFilePathMainMenuBackground "ui\\scene\\PEP3MainMenu\\mainMenuBackground.tga"
#define PEP3CombatUIImageFilePathMainMenuGem "ui\\scene\\PEP3MainMenu\\mainMenuButton1.tga"
#define PEP3CombatUIImageFilePathMainMenuStatistics "ui\\scene\\PEP3MainMenu\\mainMenuButton2.tga"
#define PEP3CombatUIImageFilePathMainMenuExit "ui\\scene\\PEP3MainMenu\\mainMenuButton3.tga"
#define PEP3CombatUIImageFilePathMainMenuInformation "ui\\scene\\PEP3MainMenu\\mainMenuButton4.tga"
#define PEP3CombatUIImageFilePathMainMenuShop "ui\\scene\\PEP3MainMenu\\mainMenuButton5.tga"
#define PEP3CombatUIImageFilePathMainMenuMaterial "ui\\scene\\PEP3MainMenu\\mainMenuButton6.tga"

using spcPEP3UIUtil::rect;

// 菜单入口UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3SceneMenuEntranceUI* sceneMenuEntranceUIInstance = new PEP3SceneMenuEntranceUI();
PEP3SceneMenuEntranceUI* PEP3SceneMenuEntranceUI::sharedInstance()
{
	return sceneMenuEntranceUIInstance;
}

PEP3SceneMenuEntranceUI::PEP3SceneMenuEntranceUI()
{
	visibility = false;

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
	// 如果不可见，则不影响下层UI交互
	if (!visibility)
	{
		return false;
	}

	// 根据点击状态设置背景
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
		// 如果检测到鼠标释放事件，返回回调
		if (callback != NULL)
		{
			callback();
		}
		return true;
		break;
	}

	return false;
}

void PEP3SceneMenuEntranceUI::setVisibility(bool visibility)
{
	this->visibility = visibility;

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

// 主菜单UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3SceneMainMenuUI* sceneMainMenuUIInstance = new PEP3SceneMainMenuUI();
PEP3SceneMainMenuUI* PEP3SceneMainMenuUI::sharedInstance()
{
	return sceneMainMenuUIInstance;
}

PEP3SceneMainMenuUI::PEP3SceneMainMenuUI()
{
	visibility = false;

	menuBackgroundMask = new UIStatic();
	menuBackground = new UIStatic();
	buttonGem = new PEP3UIStaticMouseTrace();
	buttonMaterial = new PEP3UIStaticMouseTrace();
	buttonShop = new PEP3UIStaticMouseTrace();
	buttonStatistics = new PEP3UIStaticMouseTrace();
	buttonInformation = new PEP3UIStaticMouseTrace();
	buttonExit = new PEP3UIStaticMouseTrace();
}

PEP3SceneMainMenuUI::~PEP3SceneMainMenuUI()
{
	delete menuBackgroundMask;
	delete menuBackground;
	delete buttonGem;
	delete buttonMaterial;
	delete buttonShop;
	delete buttonStatistics;
	delete buttonInformation;
	delete buttonExit;
}

void PEP3SceneMainMenuUI::create(UIWnd* ui)
{
	RECT pRcMask = rect(0, 0, ClientWidth(), ClientHeight());
	menuBackgroundMask->Create(0, pRcMask, ui);
	menuBackgroundMask->SetBk(PEP3CombatUIImageFilePathMainMenuBackgroundMask);
	RECT pRcZone = rect(ClientWidth() / 2 - 256, ClientHeight() / 2 - 256, 512, 512);
	menuBackground->Create(0, pRcZone, ui);
	menuBackground->SetBk(PEP3CombatUIImageFilePathMainMenuBackground);
	buttonGem->Create(0, pRcZone, ui);
	buttonGem->SetBk(PEP3CombatUIImageFilePathMainMenuGem);
	buttonMaterial->Create(0, pRcZone, ui);
	buttonMaterial->SetBk(PEP3CombatUIImageFilePathMainMenuMaterial);
	buttonShop->Create(0, pRcZone, ui);
	buttonShop->SetBk(PEP3CombatUIImageFilePathMainMenuShop);
	buttonStatistics->Create(0, pRcZone, ui);
	buttonStatistics->SetBk(PEP3CombatUIImageFilePathMainMenuStatistics);
	buttonInformation->Create(0, pRcZone, ui);
	buttonInformation->SetBk(PEP3CombatUIImageFilePathMainMenuInformation);
	buttonExit->Create(0, pRcZone, ui);
	buttonExit->SetBk(PEP3CombatUIImageFilePathMainMenuExit);

	setVisibility(false);
}

bool PEP3SceneMainMenuUI::update()
{
	// 如果不可见，则不影响下层UI交互
	if (!visibility)
	{
		return false;
	}
	return true;
}

void PEP3SceneMainMenuUI::setVisibility(bool visibility)
{
	this->visibility = visibility;

	menuBackgroundMask->ShowWindow(visibility);
	menuBackground->ShowWindow(visibility);
	buttonGem->ShowWindow(visibility);
	buttonMaterial->ShowWindow(visibility);
	buttonShop->ShowWindow(visibility);
	buttonStatistics->ShowWindow(visibility);
	buttonInformation->ShowWindow(visibility);
	buttonExit->ShowWindow(visibility);
}

bool PEP3SceneMainMenuUI::getVisibility()
{
	return visibility;
}