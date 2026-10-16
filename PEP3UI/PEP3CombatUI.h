#ifndef _PEP3COMBATUI_H_
#define _PEP3COMBATUI_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"

using std::string;

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
static const int PEP3BattlegroundBossHPBarUIBarCount = 5;
class PEP3BattlegroundBossHPBarUI
{
private:
	UIStatic* bossHPBarBackground; // 首领血条背景
	UIStatic* bossHPBar; // 首领血条

public:
	PEP3BattlegroundBossHPBarUI();
	~PEP3BattlegroundBossHPBarUI();

	static PEP3BattlegroundBossHPBarUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int totalHP, int currentHP, int stageNumber);
	void setVisibility(bool visibility);
};

// MARK: 信息面板UI
class CCBRoleState;
class PEP3BattlegroundInformationBoardUITextElement : public UIStatic
{
public:
	void PEP3BattlegroundInformationBoardUITextElement::Create(UINT id, const RECT& rect, UIWnd* pfather);
};

static const int PEP3BattlegroundInformationBoardUIActionCount = 3;
static const int PEP3BattlegroundInformationBoardUIStatusCount = 4;
class PEP3BattlegroundInformationBoardUI
{
private:
	// Initial variables
	bool visibility;

	// Background
	UIStatic* informationBoardBackground;

	// Element
	// Page 1
	PEP3BattlegroundInformationBoardUITextElement* enemyID;
	PEP3BattlegroundInformationBoardUITextElement* enemyName;
	PEP3BattlegroundInformationBoardUITextElement* enemyType;
	PEP3BattlegroundInformationBoardUITextElement* enemyLevel;
	PEP3BattlegroundInformationBoardUITextElement* enemyMoney;
	PEP3BattlegroundInformationBoardUITextElement* enemyExperience;
	PEP3BattlegroundInformationBoardUITextElement* enemyAttack;
	PEP3BattlegroundInformationBoardUITextElement* enemyDefence;
	PEP3BattlegroundInformationBoardUITextElement* enemyHP;
	UIStatic* enemyHPBarBackground;
	UIStatic* enemyHPBar;
	PEP3BattlegroundInformationBoardUITextElement* enemySpeed;
	PEP3BattlegroundInformationBoardUITextElement* enemyLuck;
	PEP3BattlegroundInformationBoardUITextElement* enemyMP;
	UIStatic* enemyMPBarBackground;
	UIStatic* enemyMPBar;
	PEP3BattlegroundInformationBoardUITextElement* enemyWater;
	PEP3BattlegroundInformationBoardUITextElement* enemyNormalAttack;
	PEP3BattlegroundInformationBoardUITextElement* enemyNormalAttackGPRecover;
	PEP3BattlegroundInformationBoardUITextElement* enemyFire;
	PEP3BattlegroundInformationBoardUITextElement* enemyDrop;
	PEP3BattlegroundInformationBoardUITextElement* enemyDropAmount;
	PEP3BattlegroundInformationBoardUITextElement* enemyWind;
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalDrop;
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalDropAmount;
	PEP3BattlegroundInformationBoardUITextElement* enemyThunder;
	PEP3BattlegroundInformationBoardUITextElement* enemySteal;
	PEP3BattlegroundInformationBoardUITextElement* enemyStealCount;
	PEP3BattlegroundInformationBoardUITextElement* enemyEarth;
	PEP3BattlegroundInformationBoardUITextElement* enemyInitialState;
	PEP3BattlegroundInformationBoardUITextElement* enemyInitialStateDuration;
	PEP3BattlegroundInformationBoardUITextElement* enemySpecificDrop;
	PEP3BattlegroundInformationBoardUITextElement* enemySpecificSkillName;
	PEP3BattlegroundInformationBoardUITextElement* enemySpecificDropPercentage;
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalSpecificDrop;
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalSpecificSkillName;
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalSpecificDropPercentage;
	PEP3BattlegroundInformationBoardUITextElement* enemyAction;

	// Status Items
	PEP3BattlegroundInformationBoardUITextElement* enemyStatus;

public:
	PEP3BattlegroundInformationBoardUI();
	~PEP3BattlegroundInformationBoardUI();

	static PEP3BattlegroundInformationBoardUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int pageNumber, string information[], CCBRoleState* roleState, int roleIndex, string customizedHPText, string customizedMPText, string statusName[]);
	void setVisibility(bool visibility);
	bool getVisibility();
};

#endif
