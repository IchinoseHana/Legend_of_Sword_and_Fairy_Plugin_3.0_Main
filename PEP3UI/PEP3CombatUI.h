#ifndef _PEP3COMBATUI_H_
#define _PEP3COMBATUI_H_

#pragma once

#include "..\..\pal3\ui\uiwnd.h"

class UIStatic;

// MARK: 仙灵、武灵UI
class PEP3BattlegroundSpiritUI
{
private:
	UIStatic *spiritSlot; // 仙灵槽
	UIStatic *spiritNumber; // 仙灵数字
	UIStatic *spiritUsingStatus; // 仙灵使用状态

public:
	PEP3BattlegroundSpiritUI();
	~PEP3BattlegroundSpiritUI();

	static PEP3BattlegroundSpiritUI* sharedInstance();
	void create(UIWnd *ui);
	void update(int spiritNumber, bool isUsingSpirit);
	void setVisibility(bool visibility);
};

// MARK: 战场状态、战场属性UI
class PEP3BattlegroundStateUI
{
private:
	UIStatic* resurrectionIcon; // 复活计数图标
	UIStatic* resurrectionNumber; // 复活计数数字
	UIStatic* battlegroundStateIcon; // 战场状态
	UIStatic* battlegroundStateNumber; // 战场状态数字
	UIStatic* battlegroundPropertyIcon; // 战场属性
	UIStatic* battlegroundPropertyNumber; // 战场属性数字

public:
	PEP3BattlegroundStateUI();
	~PEP3BattlegroundStateUI();

	static PEP3BattlegroundStateUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int resurrectionNumber, int stateIndex, int stateNumber, int propertyIndex, int propertyNumnber);
	void setVisibility(bool visibility);
};

// MARK: 暗器装填、合击UI
class PEP3BattlegroundChargeUI
{
private:
	UIStatic* battlegroundChargeIcon; //暗器装填图标
	UIStatic* battlegroundChargeNumber; //暗器装填数字
	UIStatic* battlegroundCoorperationAttackIcon; //合击图标
	UIStatic* battlegroundCoorperationAttackNumber; //合击数字

public:
	PEP3BattlegroundChargeUI();
	~PEP3BattlegroundChargeUI();

	static PEP3BattlegroundChargeUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int chargeNumber, int cooperationAttackNumber);
	void setVisibility(bool visibility);
};

// MARK: 战场环境UI
static const int PEP3BattlegroundEnvironmentUIIconCount = 3;
class PEP3BattlegroundEnvironmentUI
{
private:
	UIStatic* battlegroundEnvironmentIcon; // 战场环境图标

public:
	PEP3BattlegroundEnvironmentUI();
	~PEP3BattlegroundEnvironmentUI();

	static PEP3BattlegroundEnvironmentUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int environmentIndex[], int environmentNumber[]);
	void setVisibility(bool visibility);
};

// MARK: 首领血条UI
static const int PEP3BattlegroundBossHPBarCount = 5;
class PEP3BattlegroundBossHPBarUI
{
private:
	UIStatic* battlegroundBossHPBarBackground; // 首领血条背景
	UIStatic* battlegroundBossHPBar; // 首领血条

public:
	PEP3BattlegroundBossHPBarUI();
	~PEP3BattlegroundBossHPBarUI();

	static PEP3BattlegroundBossHPBarUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int totalHP, int currentHP, int stageNumber);
	void setVisibility(bool visibility);
};

#endif
