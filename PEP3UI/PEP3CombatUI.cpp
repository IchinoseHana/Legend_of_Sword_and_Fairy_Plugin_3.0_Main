#include "stdafx.h"

#include "PEP3CombatUI.h"

#include "..\..\pal3\ui\uistatic.h"
#include "..\..\pal3\combat\cbrolestate.h"
#include "..\Utility\PEP3UIUtil.h"
#include "..\Utility\PEP3Define.h"

using spcPEP3UIUtil::calCombatUIHorizontalMargin;
using spcPEP3UIUtil::calCombatUIVerticalScaledValue;
using spcPEP3UIUtil::rect;

// MARK: 仙灵、武灵UI

PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundSpiritUI* battlegroundSpiritUIInstance = new PEP3BattlegroundSpiritUI();
PEP3BattlegroundSpiritUI* PEP3BattlegroundSpiritUI::sharedInstance()
{
	return battlegroundSpiritUIInstance;
}

PEP3BattlegroundSpiritUI::PEP3BattlegroundSpiritUI()
{
	spiritSlot = new UIStatic;
	spiritNumber = new UIStatic;
	spiritUsingStatus = new UIStatic;
}

PEP3BattlegroundSpiritUI::~PEP3BattlegroundSpiritUI()
{
	delete spiritSlot;
	delete spiritNumber;
	delete spiritUsingStatus;
}

void PEP3BattlegroundSpiritUI::create(UIWnd *ui)
{
	int leftMargin = calCombatUIHorizontalMargin();

	RECT pRcSlot = rect(leftMargin, 40, 256, 16);
	spiritSlot->Create(0, pRcSlot, ui);
	spiritSlot->SetBk("UI\\skillbar0.tga");

	RECT pRcNumber = rect(leftMargin + 260, 32, 45, 45);
	spiritNumber->Create(0, pRcNumber, ui);
	gbColorQuad color(0, 255, 255, 255);
	spiritNumber->SetFontColor(color);
	spiritNumber->SetText("0");

	RECT pRcUsingStatus = rect(leftMargin, 70, 32, 32);
	spiritUsingStatus->Create(0, pRcUsingStatus, ui);
	spiritUsingStatus->SetBk("UI\\spiritIdle.tga");
}

void PEP3BattlegroundSpiritUI::update(int spiritNumber, bool isUsingSpirit)
{
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };
	sprintf(fileName, "UI\\SkillBar\\skillbar%d.tga", spiritNumber);
	spiritSlot->SetBk(fileName);

	char numberText[3] = { 0 };
	sprintf(numberText, "%d", abs(spiritNumber));
	this->spiritNumber->SetText(numberText);

	spiritUsingStatus->SetBk(isUsingSpirit ? "UI\\spiritUse.tga" : "UI\\spiritIdle.tga");
}

void PEP3BattlegroundSpiritUI::setVisibility(bool visibility)
{
	spiritSlot->ShowWindow(visibility);
	spiritNumber->ShowWindow(visibility);
}

// MARK: 战场状态、战场属性UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundStateUI* battlegroundStateUIInstance = new PEP3BattlegroundStateUI();
PEP3BattlegroundStateUI* PEP3BattlegroundStateUI::sharedInstance()
{
	return battlegroundStateUIInstance;
}

PEP3BattlegroundStateUI::PEP3BattlegroundStateUI()
{
	resurrectionIcon = new UIStatic;
	resurrectionNumber = new UIStatic;
	battlegroundStateIcon = new UIStatic;
	battlegroundStateNumber = new UIStatic;
	battlegroundPropertyIcon = new UIStatic;
	battlegroundPropertyNumber = new UIStatic;
}

PEP3BattlegroundStateUI::~PEP3BattlegroundStateUI()
{
	delete resurrectionIcon;
	delete resurrectionNumber;
	delete battlegroundStateIcon;
	delete battlegroundStateNumber;
	delete battlegroundPropertyIcon;
	delete battlegroundPropertyNumber;
}

void PEP3BattlegroundStateUI::create(UIWnd* ui)
{
	int leftMargin = calCombatUIHorizontalMargin();
	gbColorQuad color(0, 255, 255, 255);

	RECT pRCResIcon = rect(leftMargin + 53, 70, 32, 32);
	resurrectionIcon->Create(0, pRCResIcon, ui);
	resurrectionIcon->SetBk("UI\\battlegroundResurrection.tga");

	RECT pRcResNumber = rect(leftMargin + 92, 70, 45, 32);
	resurrectionNumber->Create(0, pRcResNumber, ui);
	resurrectionNumber->SetFontColor(color);
	resurrectionNumber->SetText("0");

	RECT pRCBatStateIcon = rect(leftMargin + 123, 70, 32, 32);
	battlegroundStateIcon->Create(0, pRCBatStateIcon, ui);
	battlegroundStateIcon->SetBk("UI\\battlegroundStateDefault.tga");

	RECT pRCBatStateNumber = rect(leftMargin + 161, 70, 45, 32);
	battlegroundStateNumber->Create(0, pRCBatStateNumber, ui);
	battlegroundStateNumber->SetFontColor(color);
	battlegroundStateNumber->SetText("000");

	RECT pRCBatPropertyIcon = rect(leftMargin + 206, 70, 32, 32);
	battlegroundPropertyIcon->Create(0, pRCBatPropertyIcon, ui);
	battlegroundPropertyIcon->SetBk("UI\\battlegroundStateDefault.tga");

	RECT pRCBatPropertyNumber = rect(leftMargin + 244, 70, 45, 32);
	battlegroundPropertyNumber->Create(0, pRCBatPropertyNumber, ui);
	battlegroundPropertyNumber->SetFontColor(color);
	battlegroundPropertyNumber->SetText("000");
}

void PEP3BattlegroundStateUI::update(int resurrectionNumber, int stateIndex, int stateNumber, int propertyIndex, int propertyNumnber)
{
	char numberText[3] = { 0 };
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };

	sprintf(numberText, "%d", abs(resurrectionNumber));
	this->resurrectionNumber->SetText(numberText);
	
	sprintf(fileName, "UI\\BattlegroundState\\battlejyoutai%d.tga", stateIndex);
	battlegroundStateIcon->SetBk(stateIndex <= 0 ? "UI\\battlegroundStateDefault.tga" : fileName);

	memset(numberText, '\0', sizeof(numberText));
	sprintf(numberText, "%03d", abs(stateNumber));
	battlegroundStateNumber->SetText(numberText);
	
	memset(fileName, '\0', sizeof(fileName));
	sprintf(fileName, "UI\\BattlegroundProperty\\battlezokusei%d.tga", propertyIndex);
	battlegroundPropertyIcon->SetBk(propertyIndex <= 0 ? "UI\\battlegroundStateDefault.tga" : fileName);
	
	memset(numberText, '\0', sizeof(numberText));
	sprintf(numberText, "%03d", abs(propertyNumnber));
	battlegroundPropertyNumber->SetText(numberText);
}

void PEP3BattlegroundStateUI::setVisibility(bool visibility)
{
	resurrectionIcon->ShowWindow(visibility);
	resurrectionNumber->ShowWindow(visibility);
	battlegroundStateIcon->ShowWindow(visibility);
	battlegroundStateNumber->ShowWindow(visibility);
	battlegroundPropertyIcon->ShowWindow(visibility);
	battlegroundPropertyNumber->ShowWindow(visibility);
}

// MARK: 暗器装填、合击UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundChargeUI* battlegroundChargeUIInstance = new PEP3BattlegroundChargeUI();
PEP3BattlegroundChargeUI* PEP3BattlegroundChargeUI::sharedInstance()
{
	return battlegroundChargeUIInstance;
}

PEP3BattlegroundChargeUI::PEP3BattlegroundChargeUI()
{
	battlegroundChargeIcon = new UIStatic;
	battlegroundChargeNumber = new UIStatic;
	battlegroundCoorperationAttackIcon = new UIStatic;
	battlegroundCoorperationAttackNumber = new UIStatic;
}

PEP3BattlegroundChargeUI::~PEP3BattlegroundChargeUI()
{
	delete battlegroundChargeIcon;
	delete battlegroundChargeNumber;
	delete battlegroundCoorperationAttackIcon;
	delete battlegroundCoorperationAttackNumber;
}

void PEP3BattlegroundChargeUI::create(UIWnd* ui)
{
	int rightMargin = ClientWidth() - calCombatUIHorizontalMargin();
	// 1024 * 768屏幕下，自定义界面上界为70(即行动条下方适合布局的起始点)
	int upperBound = calCombatUIVerticalScaledValue(70);
	gbColorQuad color(0, 255, 255, 255);
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };

	// 先处理合击，再处理暗器装填
	RECT pRcCoAttackIcon = rect(rightMargin - 100, upperBound, 32, 32);
	battlegroundCoorperationAttackIcon->Create(0, pRcCoAttackIcon, ui);
	battlegroundCoorperationAttackIcon->SetBk("UI\\battlegroundCoorperationAttack.tga");

	RECT pRcCoAttackNumber = rect(pRcCoAttackIcon.left + 46, upperBound, 45, 32);
	battlegroundCoorperationAttackNumber->Create(0, pRcCoAttackNumber, ui);
	battlegroundCoorperationAttackNumber->SetFontColor(color);
	battlegroundCoorperationAttackNumber->SetText("000");

	RECT pRcChargeIcon = rect(pRcCoAttackNumber.left - 145, upperBound, 32, 32);
	battlegroundChargeIcon->Create(0, pRcChargeIcon, ui);
	battlegroundChargeIcon->SetBk("UI\\battlegroundCharge.tga");

	RECT pRcChargeNumber = rect(pRcChargeIcon.left + 46, upperBound, 45, 32);
	battlegroundChargeNumber->Create(0, pRcChargeNumber, ui);
	battlegroundChargeNumber->SetFontColor(color);
	battlegroundChargeNumber->SetText("000");
}

void PEP3BattlegroundChargeUI::update(int chargeNumber, int cooperationAttackNumber)
{
	char numberText[3] = { 0 };

	sprintf(numberText, "%03d", abs(chargeNumber));
	battlegroundChargeNumber->SetText(numberText);

	memset(numberText, '\0', sizeof(cooperationAttackNumber));
	sprintf(numberText, "%03d", abs(cooperationAttackNumber));
	battlegroundCoorperationAttackNumber->SetText(numberText);
}

void PEP3BattlegroundChargeUI::setVisibility(bool visibility)
{
	battlegroundChargeIcon->ShowWindow(visibility);
	battlegroundChargeNumber->ShowWindow(visibility);
	battlegroundCoorperationAttackIcon->ShowWindow(visibility);
	battlegroundCoorperationAttackNumber->ShowWindow(visibility);
}

// MARK: 战场环境UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundEnvironmentUI* battlegroundEnvironmentUIInstance = new PEP3BattlegroundEnvironmentUI();
PEP3BattlegroundEnvironmentUI* PEP3BattlegroundEnvironmentUI::sharedInstance()
{
	return battlegroundEnvironmentUIInstance;
}

PEP3BattlegroundEnvironmentUI::PEP3BattlegroundEnvironmentUI()
{
	battlegroundEnvironmentIcon = new UIStatic[PEP3BattlegroundEnvironmentUIIconCount];
}

PEP3BattlegroundEnvironmentUI::~PEP3BattlegroundEnvironmentUI()
{
	delete[] battlegroundEnvironmentIcon;
}

void PEP3BattlegroundEnvironmentUI::create(UIWnd* ui)
{
	int rightMargin = ClientWidth() - calCombatUIHorizontalMargin();
	// 除了自定义布局上界，还要考虑暗器装填和合击占据的位置
	int upperBound = calCombatUIVerticalScaledValue(70) + 46;

	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		RECT pRcIcon = rect(rightMargin - 52 - (idx * 48), upperBound, 32, 32);
		battlegroundEnvironmentIcon[idx].Create(0, pRcIcon, ui);
		battlegroundEnvironmentIcon[idx].SetBk("UI\\battlegroundStateDefault.tga");
	}

	// 默认不显示，除非有值
	setVisibility(false);
}

void PEP3BattlegroundEnvironmentUI::update(int environmentIndex[], int environmentNumber[])
{
	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		if (environmentIndex[idx] != 0 && environmentNumber[idx] != 0)
		{
			char fileName[PEP3_MAX_FILEPATH_LENGTH];
			sprintf(fileName, "UI\\BattlegroundEnvironment\\battlekannkyou%d.tga", environmentIndex[idx]);
			battlegroundEnvironmentIcon[idx].SetBk(fileName);
			battlegroundEnvironmentIcon[idx].ShowWindow(true);
		}
		else
		{
			battlegroundEnvironmentIcon[idx].SetBk("UI\\battlegroundStateDefault.tga");
			battlegroundEnvironmentIcon[idx].ShowWindow(false);
		}
	}
}

void PEP3BattlegroundEnvironmentUI::setVisibility(bool visibility)
{
	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		battlegroundEnvironmentIcon[idx].ShowWindow(visibility);
	}
}

// MARK: 首领血条UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundBossHPBarUI* bossHPBarUIInstance = new PEP3BattlegroundBossHPBarUI();
PEP3BattlegroundBossHPBarUI* PEP3BattlegroundBossHPBarUI::sharedInstance()
{
	return bossHPBarUIInstance;
}

PEP3BattlegroundBossHPBarUI::PEP3BattlegroundBossHPBarUI()
{
	bossHPBar = new UIStatic[PEP3BattlegroundBossHPBarUIBarCount];
	bossHPBarBackground = new UIStatic;
}

PEP3BattlegroundBossHPBarUI::~PEP3BattlegroundBossHPBarUI()
{
	delete[] bossHPBar;
	delete bossHPBarBackground;
}

void PEP3BattlegroundBossHPBarUI::create(UIWnd* ui)
{
	// 对于非纯色图片支持不佳，需要保证长度和宽度是16的倍数，好在可以使用Alpha通道
	RECT pRcBarBkg = rect(ClientWidth() / 2 - 256, 120, 512, 16);
	bossHPBarBackground->Create(0, pRcBarBkg, ui);
	bossHPBarBackground->SetBk("UI\\HPBar\\combat_bossHPBK.tga");

	for (int idx = 0; idx < PEP3BattlegroundBossHPBarUIBarCount; ++idx)
	{
		RECT pRcBar = rect(ClientWidth() / 2 - 253, 123, 506, 3);;
		bossHPBar[idx].Create(0, pRcBar, ui);
		char fileName[PEP3_MAX_FILEPATH_LENGTH];
		sprintf(fileName, "UI\\HPBar\\combat_bossHP%d.tga", idx + 1);
		bossHPBar[idx].SetBk(fileName);
	}

	// 默认不显示，除非有值
	setVisibility(false);
}

void PEP3BattlegroundBossHPBarUI::update(int totalHP, int currentHP, int stageNumber)
{
	if (currentHP <= 0)
	{
		// 剩余血量为0，不显示
		setVisibility(false);
		return;
	}
	bossHPBarBackground->ShowWindow(true);

	// 每一阶段的血量
	double interval = totalHP / stageNumber;
	// 剩余完整阶段数
	int completeStage = currentHP / interval;
	// 当前阶段剩余血量
	double curStageRemaining = currentHP - completeStage * interval;
	// 当前阶段剩余血量所占比例
	double curStageRatio = curStageRemaining / interval;
	int idx = 0;

	// 对于完整的阶段，正常进行布局
	for (idx = 0; idx < completeStage; ++idx)
	{
		RECT pRcBar = rect(ClientWidth() / 2 - 253, 123, 506, 3);
		bossHPBar[idx].SetRect(pRcBar);
		bossHPBar[idx].ShowWindow(true);
	}
	// 对于当前阶段，按照剩余血量比例进行布局
	RECT pRcCurBar = rect(ClientWidth() / 2 - 253, 123, 506 * curStageRatio, 3);
	// 上一轮循环退出后刚好位于下一个索引
	if (idx < PEP3BattlegroundBossHPBarUIBarCount)
	{
		bossHPBar[idx].SetRect(pRcCurBar);
		bossHPBar[idx].ShowWindow(true);
	}
	// 后续阶段不显示，包括已经消耗掉的和不存在的阶段
	for (idx += 1; idx < PEP3BattlegroundBossHPBarUIBarCount; ++idx)
	{
		bossHPBar[idx].ShowWindow(false);
	}
}

void PEP3BattlegroundBossHPBarUI::setVisibility(bool visibility)
{
	bossHPBarBackground->ShowWindow(visibility);
	for (int idx = 0; idx < PEP3BattlegroundBossHPBarUIBarCount; ++idx)
	{
		bossHPBar[idx].ShowWindow(visibility);
	}
}

// MARK: 信息面板UI
void PEP3BattlegroundInformationBoardUITextElement::Create(UINT id, const RECT& rect, UIWnd* pfather)
{
	gbColorQuad textColor(87, 65, 20, 255);
	UIStatic::Create(id, rect, pfather);
	UIStatic::SetFont(true);
	UIStatic::SetFontColor(textColor);
	UIStatic::SetText("", true);
}

PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundInformationBoardUI* battlegroundInformationBoardUIInstance = new PEP3BattlegroundInformationBoardUI();
PEP3BattlegroundInformationBoardUI* PEP3BattlegroundInformationBoardUI::sharedInstance()
{
	return battlegroundInformationBoardUIInstance;
}

PEP3BattlegroundInformationBoardUI::PEP3BattlegroundInformationBoardUI()
{
	visibility = false;

	informationBoardBackground = new UIStatic;
	enemyID = new PEP3BattlegroundInformationBoardUITextElement;
	enemyName = new PEP3BattlegroundInformationBoardUITextElement;
	enemyType = new PEP3BattlegroundInformationBoardUITextElement;
	enemyLevel = new PEP3BattlegroundInformationBoardUITextElement;
	enemyMoney = new PEP3BattlegroundInformationBoardUITextElement;
	enemyExperience = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAttack = new PEP3BattlegroundInformationBoardUITextElement;
	enemyDefence = new PEP3BattlegroundInformationBoardUITextElement;
	enemyHP = new PEP3BattlegroundInformationBoardUITextElement;
	enemyHPBarBackground = new UIStatic;
	enemyHPBar = new UIStatic;
	enemySpeed = new PEP3BattlegroundInformationBoardUITextElement;
	enemyLuck = new PEP3BattlegroundInformationBoardUITextElement;
	enemyMP = new PEP3BattlegroundInformationBoardUITextElement;
	enemyMPBarBackground = new UIStatic;
	enemyMPBar = new UIStatic;
	enemyWater = new PEP3BattlegroundInformationBoardUITextElement;
	enemyNormalAttack = new PEP3BattlegroundInformationBoardUITextElement;
	enemyNormalAttackGPRecover = new PEP3BattlegroundInformationBoardUITextElement;
	enemyFire = new PEP3BattlegroundInformationBoardUITextElement;
	enemyDrop = new PEP3BattlegroundInformationBoardUITextElement;
	enemyDropAmount = new PEP3BattlegroundInformationBoardUITextElement;
	enemyWind = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAdditionalDrop = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAdditionalDropAmount = new PEP3BattlegroundInformationBoardUITextElement;
	enemyThunder = new PEP3BattlegroundInformationBoardUITextElement;
	enemySteal = new PEP3BattlegroundInformationBoardUITextElement;
	enemyStealCount = new PEP3BattlegroundInformationBoardUITextElement;
	enemyEarth = new PEP3BattlegroundInformationBoardUITextElement;
	enemyInitialState = new PEP3BattlegroundInformationBoardUITextElement;
	enemyInitialStateDuration = new PEP3BattlegroundInformationBoardUITextElement;
	enemySpecificDrop = new PEP3BattlegroundInformationBoardUITextElement;
	enemySpecificSkillName = new PEP3BattlegroundInformationBoardUITextElement;
	enemySpecificDropPercentage = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAdditionalSpecificDrop = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAdditionalSpecificSkillName = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAdditionalSpecificDropPercentage = new PEP3BattlegroundInformationBoardUITextElement;
	enemyAction = new PEP3BattlegroundInformationBoardUITextElement[PEP3BattlegroundInformationBoardUIActionCount];
	enemyStatus = new PEP3BattlegroundInformationBoardUITextElement[PEP3BattlegroundInformationBoardUIStatusCount];
}

PEP3BattlegroundInformationBoardUI::~PEP3BattlegroundInformationBoardUI()
{
	delete informationBoardBackground;
	delete enemyID;
	delete enemyName;
	delete enemyType;
	delete enemyLevel;
	delete enemyMoney;
	delete enemyExperience;
	delete enemyAttack;
	delete enemyDefence;
	delete enemyHP;
	delete enemyHPBarBackground;
	delete enemyHPBar;
	delete enemySpeed;
	delete enemyLuck;
	delete enemyMP;
	delete enemyMPBarBackground;
	delete enemyMPBar;
	delete enemyWater;
	delete enemyNormalAttack;
	delete enemyNormalAttackGPRecover;
	delete enemyFire;
	delete enemyDrop;
	delete enemyDropAmount;
	delete enemyWind;
	delete enemyAdditionalDrop;
	delete enemyAdditionalDropAmount;
	delete enemyThunder;
	delete enemySteal;
	delete enemyStealCount;
	delete enemyEarth;
	delete enemyInitialState;
	delete enemyInitialStateDuration;
	delete enemySpecificDrop;
	delete enemySpecificSkillName;
	delete enemySpecificDropPercentage;
	delete enemyAdditionalSpecificDrop;
	delete enemyAdditionalSpecificSkillName;
	delete enemyAdditionalSpecificDropPercentage;
	delete[] enemyAction;
	delete[] enemyStatus;
}

void PEP3BattlegroundInformationBoardUI::create(UIWnd* ui)
{
	int idx;

	// 背景
	RECT pRcBack = rect(ClientWidth() - 1064, 40, 1024, 1024);
	gbColorQuad textColor(87, 65, 20, 255);
	informationBoardBackground->Create(0, pRcBack, ui);
	informationBoardBackground->SetBk("UI\\combatinformation.tga");

	// 主面板
	RECT pRcElement;
	pRcElement = rect(ClientWidth() - 712, 104, 258, 64);
	enemyID->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 328, 104, 258, 64);
	enemyName->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 168, 96, 64);
	enemyType->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 168, 96, 64);
	enemyLevel->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 328, 168, 96, 64);
	enemyMoney->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 168, 96, 64);
	enemyExperience->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 232, 96, 64);
	enemyAttack->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 232, 96, 64);
	enemyDefence->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 232, 232, 192, 64);
	enemyHP->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 328, 261, 96, 6);
	enemyHPBarBackground->Create(0, pRcElement, ui);
	enemyHPBarBackground->SetBk("UI\\HPBar\\combat_bossHP0.tga");
	pRcElement = rect(ClientWidth() - 328, 261, 96, 6);
	enemyHPBar->Create(0, pRcElement, ui);
	enemyHPBar->SetBk("UI\\HPBar\\combat_bossHP1.tga");
	pRcElement = rect(ClientWidth() - 712, 296, 96, 64);
	enemySpeed->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 296, 96, 64);
	enemyLuck->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 232, 296, 192, 64);
	enemyMP->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 328, 325, 96, 6);
	enemyMPBarBackground->Create(0, pRcElement, ui);
	enemyMPBarBackground->SetBk("UI\\HPBar\\combat_bossHP0.tga");
	pRcElement = rect(ClientWidth() - 328, 325, 96, 6);
	enemyMPBar->Create(0, pRcElement, ui);
	enemyMPBar->SetBk("UI\\HPBar\\combat_bossHP4.tga");
	pRcElement = rect(ClientWidth() - 712, 360, 96, 64);
	enemyWater->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 360, 288, 64);
	enemyNormalAttack->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 360, 96, 64);
	enemyNormalAttackGPRecover->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 424, 96, 64);
	enemyFire->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 424, 288, 64);
	enemyDrop->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 424, 96, 64);
	enemyDropAmount->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 488, 96, 64);
	enemyWind->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 488, 288, 64);
	enemyAdditionalDrop->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 488, 96, 64);
	enemyAdditionalDropAmount->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 552, 96, 64);
	enemyThunder->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 552, 288, 64);
	enemySteal->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 552, 96, 64);
	enemyStealCount->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 616, 96, 64);
	enemyEarth->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 520, 616, 288, 64);
	enemyInitialState->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 616, 96, 64);
	enemySpecificDrop->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 680, 192, 64);
	enemySpecificDrop->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 424, 680, 192, 64);
	enemySpecificSkillName->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 680, 96, 64);
	enemySpecificDropPercentage->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 712, 744, 192, 64);
	enemyAdditionalSpecificDrop->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 424, 744, 192, 64);
	enemyAdditionalSpecificSkillName->Create(0, pRcElement, ui);
	pRcElement = rect(ClientWidth() - 136, 744, 96, 64);
	enemyAdditionalSpecificDropPercentage->Create(0, pRcElement, ui);
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIActionCount; ++idx)
	{
		pRcElement = rect(ClientWidth() - 712, 808 + 64 * idx, 672, 64);
		enemyAction[idx].Create(0, pRcElement, ui);
	}

	// 状态栏
	RECT pRcStatusItem;
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIStatusCount; ++idx)
	{
		pRcStatusItem = rect(ClientWidth() - 969, 40 + 106 * idx, 161, 53);
		enemyStatus[idx].Create(0, pRcStatusItem, ui);
	}

	// 默认隐藏
	setVisibility(false);
}

void PEP3BattlegroundInformationBoardUI::update(int pageNumber, string information[], CCBRoleState *roleState, int roleIndex, string customizedHPText, string customizedMPText, string statusName[])
{
	int idx;

	// 先更新数据库中的静态数据
    enemyID->SetText((char*)information[0].c_str(), true);
	enemyName->SetText((char*)information[1].c_str(), true);
	enemyType->SetText((char*)information[2].c_str(), true);
	enemyLevel->SetText((char*)information[3].c_str(), true);
	enemyMoney->SetText((char*)information[4].c_str(), true);
	enemyExperience->SetText((char*)information[5].c_str(), true);
	enemyAttack->SetText((char*)information[6].c_str(), true);
	enemyDefence->SetText((char*)information[7].c_str(), true);
	enemyHP->SetText((char*)information[8].c_str(), true);
	enemySpeed->SetText((char*)information[9].c_str(), true);
	enemyLuck->SetText((char*)information[10].c_str(), true);
	enemyMP->SetText((char*)information[11].c_str(), true);
	enemyWater->SetText((char*)information[12].c_str(), true);
	enemyNormalAttack->SetText((char*)information[13].c_str(), true);
	enemyNormalAttackGPRecover->SetText((char*)information[14].c_str(), true);
	enemyFire->SetText((char*)information[15].c_str(), true);
	enemyDrop->SetText((char*)information[16].c_str(), true);
	enemyDropAmount->SetText((char*)information[17].c_str(), true);
	enemyWind->SetText((char*)information[18].c_str(), true);
	enemyAdditionalDrop->SetText((char*)information[19].c_str(), true);
	enemyAdditionalDropAmount->SetText((char*)information[20].c_str(), true);
	enemyThunder->SetText((char*)information[21].c_str(), true);
	enemySteal->SetText((char*)information[22].c_str(), true);
	enemyStealCount->SetText((char*)information[23].c_str(), true);
	enemyEarth->SetText((char*)information[24].c_str(), true);
	enemyInitialState->SetText((char*)information[25].c_str(), true);
	enemyInitialStateDuration->SetText((char*)information[26].c_str(), true);
	enemySpecificDrop->SetText((char*)information[27].c_str(), true);
	enemySpecificSkillName->SetText((char*)information[28].c_str(), true);
	enemySpecificDropPercentage->SetText((char*)information[29].c_str(), true);
	enemyAdditionalSpecificDrop->SetText((char*)information[30].c_str(), true);
	enemyAdditionalSpecificSkillName->SetText((char*)information[31].c_str(), true);
	enemyAdditionalSpecificDropPercentage->SetText((char*)information[32].c_str(), true);
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIActionCount; ++idx)
	{
		enemyAction[idx].SetText((char*)information[33 + idx].c_str(), true);
	}

	// 再更新当前的实际数据
	char stringBuffer[256];
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nLevel);
	enemyLevel->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nAttack);
	enemyAttack->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nDefence);
	enemyDefence->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nHP);
	enemyHP->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nSpeed);
	enemySpeed->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nLuck);
	enemyLuck->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetRole(roleIndex)->nMP);
	enemyMP->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetAttackFiveMagic(roleIndex, CBFM_Water));
	enemyWater->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetAttackFiveMagic(roleIndex, CBFM_Fire));
	enemyFire->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetAttackFiveMagic(roleIndex, CBFM_Wind));
	enemyWind->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetAttackFiveMagic(roleIndex, CBFM_Thunder));
	enemyThunder->SetText(stringBuffer, true);
	sprintf(stringBuffer, "%d", roleState->GetAttackFiveMagic(roleIndex, CBFM_Earth));
	enemyEarth->SetText(stringBuffer, true);

	// 如果有需要显示的特殊信息，则更新
	if (customizedHPText != "")
	{
		enemyHP->SetText((char*)customizedHPText.c_str(), true);
	}
	if (customizedMPText != "")
	{
		enemyMP->SetText((char*)customizedMPText.c_str(), true);
	}

	// 处理生命槽和魔力槽
	RECT pRcElement;
	pRcElement = rect(ClientWidth() - 328, 261, roleState->GetRole(roleIndex)->nFullHP <= 0 ? 0 : 96 * ((double)(roleState->GetRole(roleIndex)->nHP) / roleState->GetRole(roleIndex)->nFullHP), 6);
	enemyHPBar->SetRect(pRcElement);
	pRcElement = rect(ClientWidth() - 328, 325, roleState->GetRole(roleIndex)->nFullMP <= 0 ? 0 : 96 * ((double)(roleState->GetRole(roleIndex)->nMP) / roleState->GetRole(roleIndex)->nFullMP), 6);
	enemyMPBar->SetRect(pRcElement);

	// 处理状态
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIStatusCount; ++idx)
	{
		enemyStatus[idx].SetText((char*)statusName[idx].c_str(), true);
	}
}

void PEP3BattlegroundInformationBoardUI::setVisibility(bool visibility)
{
	int idx;

	this->visibility = visibility;

	informationBoardBackground->ShowWindow(visibility);
	enemyID->ShowWindow(visibility);
	enemyName->ShowWindow(visibility);
	enemyType->ShowWindow(visibility);
	enemyLevel->ShowWindow(visibility);
	enemyMoney->ShowWindow(visibility);
	enemyExperience->ShowWindow(visibility);
	enemyAttack->ShowWindow(visibility);
	enemyDefence->ShowWindow(visibility);
	enemyHP->ShowWindow(visibility);
	enemyHPBar->ShowWindow(visibility);
	enemyHPBarBackground->ShowWindow(visibility);
	enemySpeed->ShowWindow(visibility);
	enemyLuck->ShowWindow(visibility);
	enemyMP->ShowWindow(visibility);
	enemyMPBar->ShowWindow(visibility);
	enemyMPBarBackground->ShowWindow(visibility);
	enemyWater->ShowWindow(visibility);
	enemyNormalAttack->ShowWindow(visibility);
	enemyNormalAttackGPRecover->ShowWindow(visibility);
	enemyFire->ShowWindow(visibility);
	enemyDrop->ShowWindow(visibility);
	enemyDropAmount->ShowWindow(visibility);
	enemyWind->ShowWindow(visibility);
	enemyAdditionalDrop->ShowWindow(visibility);
	enemyAdditionalDropAmount->ShowWindow(visibility);
	enemyThunder->ShowWindow(visibility);
	enemySteal->ShowWindow(visibility);
	enemyStealCount->ShowWindow(visibility);
	enemyEarth->ShowWindow(visibility);
	enemyInitialState->ShowWindow(visibility);
	enemyInitialStateDuration->ShowWindow(visibility);
	enemySpecificDrop->ShowWindow(visibility);
	enemySpecificSkillName->ShowWindow(visibility);
	enemySpecificDropPercentage->ShowWindow(visibility);
	enemyAdditionalSpecificDrop->ShowWindow(visibility);
	enemyAdditionalSpecificSkillName->ShowWindow(visibility);
	enemyAdditionalSpecificDropPercentage->ShowWindow(visibility);
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIActionCount; ++idx)
	{
		enemyAction[idx].ShowWindow(visibility);
	}
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIStatusCount; ++idx)
	{
		enemyStatus[idx].ShowWindow(visibility);
	}
}

bool PEP3BattlegroundInformationBoardUI::getVisibility()
{
	return visibility;
}

