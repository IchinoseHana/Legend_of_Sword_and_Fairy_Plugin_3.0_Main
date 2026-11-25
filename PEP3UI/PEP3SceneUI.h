#ifndef _PEP3SCENEUI_H_
#define _PEP3SCENEUI_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"
#include "..\ClassExtension\PEP3UIStaticMouseTrace.h"

using std::string;

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
	PEP3UIStaticMouseTrace *entranceIcon; // 入口图标

	PEP3SceneMenuEntranceUIIconStatus mouseTypeToStatus();

public:
	PEP3SceneMenuEntranceUI();
	~PEP3SceneMenuEntranceUI();

	static PEP3SceneMenuEntranceUI* sharedInstance();
	void create(UIWnd *ui);
	bool PEP3SceneMenuEntranceUI::update(); // 返回：当前鼠标事件是否需要被消费
	void setVisibility(bool visibility);
};

#endif
