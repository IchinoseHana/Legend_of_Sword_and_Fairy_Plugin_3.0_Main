#ifndef _PEP3COMBATUI_H_
#define _PEP3COMBATUI_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"
#include "..\..\pal3\ui\UIStaticEX.h"
#include "..\ClassExtension\PEP3UIStaticAlignment.h"

using std::string;

// - 通用UI

// 仙灵、武灵UI
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

// 战场状态、战场属性UI
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

// 暗器装填、合击UI
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

// 战场环境UI
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

// 首领血条UI
static const int PEP3BattlegroundBossHPBarUIBarCount = 5;
class PEP3BattlegroundBossHPBarUI
{
private:
	// Initial variables
	bool visibility;

	UIStatic* bossHPBarBackground; // 首领血条背景
	UIStatic* bossHPBar; // 首领血条

public:
	PEP3BattlegroundBossHPBarUI();
	~PEP3BattlegroundBossHPBarUI();

	static PEP3BattlegroundBossHPBarUI* sharedInstance();
	void create(UIWnd* ui);
	void update(int totalHP, int currentHP, int stageNumber);
	void setVisibility(bool visibility);
	void setVisibilityIfNeeded(bool visibility);
};

// 评分UI
enum PEP3BattlegroundRankUIRankType
{
	PEP3BattlegroundRankUIRankTypeRankA,
	PEP3BattlegroundRankUIRankTypeRankB,
	PEP3BattlegroundRankUIRankTypeRankC,
	PEP3BattlegroundRankUIRankTypeRankD,
	PEP3BattlegroundRankUIRankTypeRankE
};

class PEP3BattlegroundRankUI
{
private:
	UIStatic* rankIcon; // 等级图标

public:
	PEP3BattlegroundRankUI();
	~PEP3BattlegroundRankUI();

	static PEP3BattlegroundRankUI* sharedInstance();
	void create(UIWnd* ui);
	void update(PEP3BattlegroundRankUIRankType rank);
	void setVisibility(bool visibility);
};

// 技能说明UI
class PEP3BattlegroundSkillInformationUI
{
private:
	UIStatic* informationBackground; // 背景
	UIStatic* upperText; // 上半部分描述
	UIStatic* lowerText; // 下半部分描述
	UIStatic* additionalText; // 附加描述


public:
	PEP3BattlegroundSkillInformationUI();
	~PEP3BattlegroundSkillInformationUI();

	static PEP3BattlegroundSkillInformationUI* sharedInstance();
	void create(UIWnd* ui);
	void update(string upperText, string lowerText);
	void update(string upperText, string lowerText, string additionalText);
	void setVisibility(bool visibility);
};

// 武器技UI
class PEP3BattlegroundWeaponSkillUI
{
private:
	UIStatic* skillBackground; // 背景
	UIStatic* skillName; // 技能名称

public:
	PEP3BattlegroundWeaponSkillUI();
	~PEP3BattlegroundWeaponSkillUI();

	static PEP3BattlegroundWeaponSkillUI* sharedInstance();
	void create(UIWnd* ui);
	void update(string name, bool forbid);
	void setVisibility(bool visibility);
};

// 附加信息UI
class PEP3BattlegroundAdditionalInformationUI
{
private:
	PEP3UIStaticAlignment* text; // 文本

public:
	PEP3BattlegroundAdditionalInformationUI();
	~PEP3BattlegroundAdditionalInformationUI();

	static PEP3BattlegroundAdditionalInformationUI* sharedInstance();
	void create(UIWnd* ui);
	void update(string text);
	void setVisibility(bool visibility);
};

// 对话UI
class PEP3BattlegroundChatUI
{
private:
	UIStatic* chatBackground; // 背景
	UIStatic* chatText; // 文本

public:
	PEP3BattlegroundChatUI();
	~PEP3BattlegroundChatUI();

	static PEP3BattlegroundChatUI* sharedInstance();
	void create(UIWnd* ui);
	void update(string text);
	void setVisibility(bool visibility);
};

// 信息面板UI
class CCBRoleState;

enum PEP3BattlegroundInformationBoardUIPageType
{
	PEP3BattlegroundInformationBoardUIPageTypeInformation,
	PEP3BattlegroundInformationBoardUIPageTypeStatus,
	PEP3BattlegroundInformationBoardUIPageTypeAction
};

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
	// Page 1 - PEP3BattlegroundInformationBoardUIPageTypeInformation
	PEP3BattlegroundInformationBoardUITextElement* enemyID; // ID
	PEP3BattlegroundInformationBoardUITextElement* enemyName; // 名称
	PEP3BattlegroundInformationBoardUITextElement* enemyType; // 类型
	PEP3BattlegroundInformationBoardUITextElement* enemyLevel; // 等级
	PEP3BattlegroundInformationBoardUITextElement* enemyMoney; // 金钱
	PEP3BattlegroundInformationBoardUITextElement* enemyExperience; // 经验
	PEP3BattlegroundInformationBoardUITextElement* enemyAttack; // 攻击力
	PEP3BattlegroundInformationBoardUITextElement* enemyDefence; // 防御力
	PEP3BattlegroundInformationBoardUITextElement* enemyHP; // 生命值
	UIStatic* enemyHPBarBackground; // 生命槽背景
	UIStatic* enemyHPBar; // 生命槽
	PEP3BattlegroundInformationBoardUITextElement* enemySpeed;
	PEP3BattlegroundInformationBoardUITextElement* enemyLuck;
	PEP3BattlegroundInformationBoardUITextElement* enemyMP;
	UIStatic* enemyMPBarBackground; // 魔力槽背景
	UIStatic* enemyMPBar; // 魔力槽
	PEP3BattlegroundInformationBoardUITextElement* enemyWater; // 水
	PEP3BattlegroundInformationBoardUITextElement* enemyNormalAttack; // 普通攻击类型
	PEP3BattlegroundInformationBoardUITextElement* enemyNormalAttackGPRecover; // 普通攻击回复气
	PEP3BattlegroundInformationBoardUITextElement* enemyFire; // 火
	PEP3BattlegroundInformationBoardUITextElement* enemyDrop; // 掉落物品ID
	PEP3BattlegroundInformationBoardUITextElement* enemyDropAmount; // 掉落物品数量
	PEP3BattlegroundInformationBoardUITextElement* enemyWind; // 风
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalDrop; // 次要掉落物品ID
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalDropAmount; // 次要掉落物品数量
	PEP3BattlegroundInformationBoardUITextElement* enemyThunder; // 雷
	PEP3BattlegroundInformationBoardUITextElement* enemySteal; // 偷窃物品ID
	PEP3BattlegroundInformationBoardUITextElement* enemyStealCount; // 偷窃物品数量
	PEP3BattlegroundInformationBoardUITextElement* enemyEarth; // 土
	PEP3BattlegroundInformationBoardUITextElement* enemyInitialState; // 初始状态
	PEP3BattlegroundInformationBoardUITextElement* enemyInitialStateDuration; // 初始状态持续时间
	PEP3BattlegroundInformationBoardUITextElement* enemySpecificDrop; // 特殊掉落物品ID
	PEP3BattlegroundInformationBoardUITextElement* enemySpecificSkillName; // 特殊掉落物品需求技能ID
	PEP3BattlegroundInformationBoardUITextElement* enemySpecificDropPercentage; // 特殊掉落物品概率
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalSpecificDrop; // 次要特殊掉落物品ID
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalSpecificSkillName; // 次要特殊掉落物品需求技能ID
	PEP3BattlegroundInformationBoardUITextElement* enemyAdditionalSpecificDropPercentage; // 次要特殊掉落物品概率
	PEP3BattlegroundInformationBoardUITextElement* enemyAction; // 行动模式

	// Status Items
	PEP3BattlegroundInformationBoardUITextElement* enemyStatus; // 当前状态

public:
	PEP3BattlegroundInformationBoardUI();
	~PEP3BattlegroundInformationBoardUI();

	static PEP3BattlegroundInformationBoardUI* sharedInstance();
	void create(UIWnd* ui);
	void update(PEP3BattlegroundInformationBoardUIPageType pageType, string information[], CCBRoleState* roleState, int roleIndex, string customizedHPText, string customizedMPText, string statusName[]);
	void setVisibility(bool visibility);
	bool getVisibility();
};

// - 非通用UI

// 转盘UI
class PEP3BattlegroundWheelUI
{
	typedef void (*rotatingFinishFunc)(int);

private:
	// Initial variables
	int isRotating; // 是否正在旋转

	UIStatic* wheelBackground; // 转盘背景
	UIStatic* wheelPointer; // 转盘指针

public:
	rotatingFinishFunc finishFunc; // 旋转完成后的回调

	PEP3BattlegroundWheelUI();
	~PEP3BattlegroundWheelUI();

	static PEP3BattlegroundWheelUI* sharedInstance();
	void create(UIWnd* ui);
	void update(string name, bool forbid);
	void setVisibility(bool visibility);
};

#endif
