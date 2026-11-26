#ifndef _PEP3SCENEUI_H_
#define _PEP3SCENEUI_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"
#include "..\ClassExtension\PEP3UIStaticMouseTrace.h"

// - 通用场景UI

// 菜单入口UI
enum PEP3SceneMenuEntranceUIIconStatus
{
	PEP3SceneMenuEntranceUIIconStatusIdle,
	PEP3SceneMenuEntranceUIIconStatusPointed,
	PEP3SceneMenuEntranceUIIconStatusClicked
};

class PEP3SceneMenuEntranceUI
{
private:
	// Initial variables
	bool visibility;

	PEP3UIStaticMouseTrace *entranceIcon; // 入口图标

	PEP3SceneMenuEntranceUIIconStatus mouseTypeToStatus();

public:
	typedef void (*buttonClickedCallback)();
	buttonClickedCallback callback; // 回调

	PEP3SceneMenuEntranceUI();
	~PEP3SceneMenuEntranceUI();

	static PEP3SceneMenuEntranceUI* sharedInstance();
	void create(UIWnd *ui);
	bool PEP3SceneMenuEntranceUI::update(); // 返回：当前鼠标事件是否需要被消费
	void setVisibility(bool visibility);
	bool getVisibility();
};

// 主菜单UI
enum PEP3SceneMainMenuUIButtonType
{
	PEP3SceneMainMenuUIButtonTypeGem,
	PEP3SceneMainMenuUIButtonTypeMaterial,
	PEP3SceneMainMenuUIButtonTypeShop,
	PEP3SceneMainMenuUIButtonTypeStatistics,
	PEP3SceneMainMenuUIButtonTypeInformation,
	PEP3SceneMainMenuUIButtonTypeInforExit
};

class PEP3SceneMainMenuUI
{
private:
	// Initial variables
	bool visibility;

	UIStatic* menuBackgroundMask; // 菜单背景蒙板
	UIStatic* menuBackground; // 菜单背景
	PEP3UIStaticMouseTrace* buttonGem; // 按钮：宝石镶嵌
	PEP3UIStaticMouseTrace* buttonMaterial; // 按钮：材料交换
	PEP3UIStaticMouseTrace* buttonShop; // 按钮：移动商店
	PEP3UIStaticMouseTrace* buttonStatistics; // 按钮：统计数据
	PEP3UIStaticMouseTrace* buttonInformation; // 按钮：额外信息
	PEP3UIStaticMouseTrace* buttonExit; // 按钮：退出菜单

public:
	PEP3SceneMainMenuUI();
	~PEP3SceneMainMenuUI();

	static PEP3SceneMainMenuUI* sharedInstance();
	void create(UIWnd* ui);
	bool PEP3SceneMainMenuUI::update(); // 返回：当前鼠标事件是否需要被消费
	void setVisibility(bool visibility);
	bool getVisibility();
};

#endif
