#include "stdafx.h"

#include "PEP3CombatUI.h"

#include "..\..\pal3\ui\uistatic.h"
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
	this->spiritSlot = new UIStatic;
	this->spiritNumber = new UIStatic;
	this->spiritUsingStatus = new UIStatic;
}

PEP3BattlegroundSpiritUI::~PEP3BattlegroundSpiritUI()
{
	delete this->spiritSlot;
	delete this->spiritNumber;
	delete this->spiritUsingStatus;
}

void PEP3BattlegroundSpiritUI::create(UIWnd *ui)
{
	int leftMargin = calCombatUIHorizontalMargin();

	RECT pRcSlot = rect(leftMargin, 40, 256, 16);
	this->spiritSlot->Create(0, pRcSlot, ui);
	this->spiritSlot->SetBk("UI\\skillbar0.tga");

	RECT pRcNumber = rect(leftMargin + 260, 32, 45, 45);
	this->spiritNumber->Create(0, pRcNumber, ui);
	gbColorQuad color(0, 255, 255, 255);
	this->spiritNumber->SetFontColor(color);
	this->spiritNumber->SetText("0");

	RECT pRcUsingStatus = rect(leftMargin, 70, 32, 32);
	this->spiritUsingStatus->Create(0, pRcUsingStatus, ui);
	this->spiritUsingStatus->SetBk("UI\\spiritIdle.tga");
}

void PEP3BattlegroundSpiritUI::update(int spiritNumber, bool isUsingSpirit)
{
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };
	sprintf(fileName, "UI\\SkillBar\\skillbar%d.tga", spiritNumber);
	this->spiritSlot->SetBk(fileName);

	char numberText[3] = { 0 };
	sprintf(numberText, "%d", abs(spiritNumber));
	this->spiritNumber->SetText(numberText);

	this->spiritUsingStatus->SetBk(isUsingSpirit ? "UI\\spiritUse.tga" : "UI\\spiritIdle.tga");
}

void PEP3BattlegroundSpiritUI::setVisibility(bool visibility)
{
	this->spiritSlot->ShowWindow(visibility);
	this->spiritNumber->ShowWindow(visibility);
}

// MARK: 战场状态、战场属性UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundStateUI* battlegroundStateUIInstance = new PEP3BattlegroundStateUI();
PEP3BattlegroundStateUI* PEP3BattlegroundStateUI::sharedInstance()
{
	return battlegroundStateUIInstance;
}

PEP3BattlegroundStateUI::PEP3BattlegroundStateUI()
{
	this->resurrectionIcon = new UIStatic;
	this->resurrectionNumber = new UIStatic;
	this->battlegroundStateIcon = new UIStatic;
	this->battlegroundStateNumber = new UIStatic;
	this->battlegroundPropertyIcon = new UIStatic;
	this->battlegroundPropertyNumber = new UIStatic;
}

PEP3BattlegroundStateUI::~PEP3BattlegroundStateUI()
{
	delete this->resurrectionIcon;
	delete this->resurrectionNumber;
	delete this->battlegroundStateIcon;
	delete this->battlegroundStateNumber;
	delete this->battlegroundPropertyIcon;
	delete this->battlegroundPropertyNumber;
}

void PEP3BattlegroundStateUI::create(UIWnd* ui)
{
	int leftMargin = calCombatUIHorizontalMargin();
	gbColorQuad color(0, 255, 255, 255);

	RECT pRCResIcon = rect(leftMargin + 53, 70, 32, 32);
	this->resurrectionIcon->Create(0, pRCResIcon, ui);
	this->resurrectionIcon->SetBk("UI\\battlegroundResurrection.tga");

	RECT pRcResNumber = rect(leftMargin + 92, 70, 45, 45);
	this->resurrectionNumber->Create(0, pRcResNumber, ui);
	this->resurrectionNumber->SetFontColor(color);
	this->resurrectionNumber->SetText("0");

	RECT pRCBatStateIcon = rect(leftMargin + 123, 70, 32, 32);
	this->battlegroundStateIcon->Create(0, pRCBatStateIcon, ui);
	this->battlegroundStateIcon->SetBk("UI\\battlegroundStateDefault.tga");

	RECT pRCBatStateNumber = rect(leftMargin + 161, 70, 45, 45);
	this->battlegroundStateNumber->Create(0, pRCBatStateNumber, ui);
	this->battlegroundStateNumber->SetFontColor(color);
	this->battlegroundStateNumber->SetText("000");

	RECT pRCBatPropertyIcon = rect(leftMargin + 206, 70, 32, 32);
	this->battlegroundPropertyIcon->Create(0, pRCBatPropertyIcon, ui);
	this->battlegroundPropertyIcon->SetBk("UI\\battlegroundStateDefault.tga");

	RECT pRCBatPropertyNumber = rect(leftMargin + 244, 70, 45, 45);
	this->battlegroundPropertyNumber->Create(0, pRCBatPropertyNumber, ui);
	this->battlegroundPropertyNumber->SetFontColor(color);
	this->battlegroundPropertyNumber->SetText("000");
}

void PEP3BattlegroundStateUI::update(int resurrectionNumber, int stateIndex, int stateNumber, int propertyIndex, int propertyNumnber)
{
	char numberText[3] = { 0 };
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };

	sprintf(numberText, "%d", abs(resurrectionNumber));
	this->resurrectionNumber->SetText(numberText);
	
	sprintf(fileName, "UI\\BattlegroundState\\battlejyoutai%d.tga", stateIndex);
	this->battlegroundStateIcon->SetBk(stateIndex <= 0 ? "UI\\battlegroundStateDefault.tga" : fileName);

	memset(numberText, '\0', sizeof(numberText));
	sprintf(numberText, "%03d", abs(stateNumber));
	this->battlegroundStateNumber->SetText(numberText);
	
	memset(fileName, '\0', sizeof(fileName));
	sprintf(fileName, "UI\\BattlegroundProperty\\battlezokusei%d.tga", propertyIndex);
	this->battlegroundPropertyIcon->SetBk(propertyIndex <= 0 ? "UI\\battlegroundStateDefault.tga" : fileName);
	
	memset(numberText, '\0', sizeof(numberText));
	sprintf(numberText, "%03d", abs(propertyNumnber));
	this->battlegroundPropertyNumber->SetText(numberText);
}

void PEP3BattlegroundStateUI::setVisibility(bool visibility)
{
	this->resurrectionIcon->ShowWindow(visibility);
	this->resurrectionNumber->ShowWindow(visibility);
	this->battlegroundStateIcon->ShowWindow(visibility);
	this->battlegroundStateNumber->ShowWindow(visibility);
	this->battlegroundPropertyIcon->ShowWindow(visibility);
	this->battlegroundPropertyNumber->ShowWindow(visibility);
}

// MARK: 暗器装填、合击UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundChargeUI* battlegroundChargeUIInstance = new PEP3BattlegroundChargeUI();
PEP3BattlegroundChargeUI* PEP3BattlegroundChargeUI::sharedInstance()
{
	return battlegroundChargeUIInstance;
}

PEP3BattlegroundChargeUI::PEP3BattlegroundChargeUI()
{
	this->battlegroundChargeIcon = new UIStatic;
	this->battlegroundChargeNumber = new UIStatic;
	this->battlegroundCoorperationAttackIcon = new UIStatic;
	this->battlegroundCoorperationAttackNumber = new UIStatic;
}

PEP3BattlegroundChargeUI::~PEP3BattlegroundChargeUI()
{
	delete this->battlegroundChargeIcon;
	delete this->battlegroundChargeNumber;
	delete this->battlegroundCoorperationAttackIcon;
	delete this->battlegroundCoorperationAttackNumber;
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
	this->battlegroundCoorperationAttackIcon->Create(0, pRcCoAttackIcon, ui);
	this->battlegroundCoorperationAttackIcon->SetBk("UI\\battlegroundCoorperationAttack.tga");

	RECT pRcCoAttackNumber = rect(pRcCoAttackIcon.left + 48, upperBound, 32, 32);
	this->battlegroundCoorperationAttackNumber->Create(0, pRcCoAttackNumber, ui);
	this->battlegroundCoorperationAttackNumber->SetFontColor(color);
	this->battlegroundCoorperationAttackNumber->SetText("00");

	RECT pRcChargeIcon = rect(pRcCoAttackNumber.left - 144, upperBound, 32, 32);
	this->battlegroundChargeIcon->Create(0, pRcChargeIcon, ui);
	this->battlegroundChargeIcon->SetBk("UI\\battlegroundCharge.tga");

	RECT pRcChargeNumber = rect(pRcChargeIcon.left + 48, upperBound, 32, 32);
	this->battlegroundChargeNumber->Create(0, pRcChargeNumber, ui);
	this->battlegroundChargeNumber->SetFontColor(color);
	this->battlegroundChargeNumber->SetText("00");
}

void PEP3BattlegroundChargeUI::update(int chargeNumber, int cooperationAttackNumber)
{
	char numberText[3] = { 0 };

	sprintf(numberText, "%02d", abs(chargeNumber));
	this->battlegroundChargeNumber->SetText(numberText);

	memset(numberText, '\0', sizeof(cooperationAttackNumber));
	sprintf(numberText, "%02d", abs(cooperationAttackNumber));
	this->battlegroundCoorperationAttackNumber->SetText(numberText);
}

void PEP3BattlegroundChargeUI::setVisibility(bool visibility)
{
	this->battlegroundChargeIcon->ShowWindow(visibility);
	this->battlegroundChargeNumber->ShowWindow(visibility);
	this->battlegroundCoorperationAttackIcon->ShowWindow(visibility);
	this->battlegroundCoorperationAttackNumber->ShowWindow(visibility);
}

// MARK: 战场环境UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundEnvironmentUI* battlegroundEnvironmentUIInstance = new PEP3BattlegroundEnvironmentUI();
PEP3BattlegroundEnvironmentUI* PEP3BattlegroundEnvironmentUI::sharedInstance()
{
	return battlegroundEnvironmentUIInstance;
}

PEP3BattlegroundEnvironmentUI::PEP3BattlegroundEnvironmentUI()
{
	this->battlegroundEnvironmentIcon = new UIStatic[PEP3BattlegroundEnvironmentUIIconCount];
}

PEP3BattlegroundEnvironmentUI::~PEP3BattlegroundEnvironmentUI()
{
	delete[] this->battlegroundEnvironmentIcon;
}

void PEP3BattlegroundEnvironmentUI::create(UIWnd* ui)
{
	int rightMargin = ClientWidth() - calCombatUIHorizontalMargin();
	// 除了自定义布局上界，还要考虑暗器装填和合击占据的位置
	int upperBound = calCombatUIVerticalScaledValue(70) + 46;

	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		RECT pRcIcon = rect(rightMargin - 52 - (idx * 48), upperBound, 32, 32);
		this->battlegroundEnvironmentIcon[idx].Create(0, pRcIcon, ui);
		this->battlegroundEnvironmentIcon[idx].SetBk("UI\\battlegroundStateDefault.tga");
	}

	// 默认不显示，除非有值
	this->setVisibility(false);
}

void PEP3BattlegroundEnvironmentUI::update(int environmentIndex[], int environmentNumber[])
{
	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		if (environmentIndex[idx] != 0 && environmentNumber[idx] != 0)
		{
			char fileName[PEP3_MAX_FILEPATH_LENGTH];
			sprintf(fileName, "UI\\BattlegroundEnvironment\\battlekannkyou%d.tga", environmentIndex[idx]);
			this->battlegroundEnvironmentIcon[idx].SetBk(fileName);
			this->battlegroundEnvironmentIcon[idx].ShowWindow(true);
		}
		else
		{
			this->battlegroundEnvironmentIcon[idx].SetBk("UI\\battlegroundStateDefault.tga");
			this->battlegroundEnvironmentIcon[idx].ShowWindow(false);
		}
	}
}

void PEP3BattlegroundEnvironmentUI::setVisibility(bool visibility)
{
	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		this->battlegroundEnvironmentIcon[idx].ShowWindow(visibility);
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
	this->bossHPBar = new UIStatic[PEP3BattlegroundBossHPBarUIBarCount];
	this->bossHPBarBackground = new UIStatic;
}

PEP3BattlegroundBossHPBarUI::~PEP3BattlegroundBossHPBarUI()
{
	delete[] this->bossHPBar;
	delete this->bossHPBarBackground;
}

void PEP3BattlegroundBossHPBarUI::create(UIWnd* ui)
{
	// 对于非纯色图片支持不佳，需要保证长度和宽度是16的倍数，好在可以使用Alpha通道
	RECT pRcBarBkg = rect(ClientWidth() / 2 - 256, 120, 512, 16);
	this->bossHPBarBackground->Create(0, pRcBarBkg, ui);
	this->bossHPBarBackground->SetBk("UI\\HPBar\\combat_bossHPBK.tga");

	for (int idx = 0; idx < PEP3BattlegroundBossHPBarUIBarCount; ++idx)
	{
		RECT pRcBar = rect(ClientWidth() / 2 - 253, 123, 506, 3);;
		this->bossHPBar[idx].Create(0, pRcBar, ui);
		char fileName[PEP3_MAX_FILEPATH_LENGTH];
		sprintf(fileName, "UI\\HPBar\\combat_bossHP%d.tga", idx + 1);
		this->bossHPBar[idx].SetBk(fileName);
	}

	// 默认不显示，除非有值
	this->setVisibility(false);
}

void PEP3BattlegroundBossHPBarUI::update(int totalHP, int currentHP, int stageNumber)
{
	if (currentHP <= 0)
	{
		// 剩余血量为0，不显示
		this->setVisibility(false);
		return;
	}
	this->bossHPBarBackground->ShowWindow(true);

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
		this->bossHPBar[idx].SetRect(pRcBar);
		this->bossHPBar[idx].ShowWindow(true);
	}
	// 对于当前阶段，按照剩余血量比例进行布局
	RECT pRcCurBar = rect(ClientWidth() / 2 - 253, 123, 506 * curStageRatio, 3);
	// 上一轮循环退出后刚好位于下一个索引
	if (idx < PEP3BattlegroundBossHPBarUIBarCount)
	{
		this->bossHPBar[idx].SetRect(pRcCurBar);
		this->bossHPBar[idx].ShowWindow(true);
	}
	// 后续阶段不显示，包括已经消耗掉的和不存在的阶段
	for (idx += 1; idx < PEP3BattlegroundBossHPBarUIBarCount; ++idx)
	{
		this->bossHPBar[idx].ShowWindow(false);
	}
}

void PEP3BattlegroundBossHPBarUI::setVisibility(bool visibility)
{
	this->bossHPBarBackground->ShowWindow(visibility);
	for (int idx = 0; idx < PEP3BattlegroundBossHPBarUIBarCount; ++idx)
	{
		this->bossHPBar[idx].ShowWindow(visibility);
	}
}

// MARK: 信息面板UI
void PEP3BattlegroundInformationBoardUIElement::Create(UINT id, const RECT& rect, UIWnd* pfather)
{
	UIStatic::Create(id, rect, pfather);
	this->SetFont(true);
	this->SetFontColor(textColor);
	this->SetText("", true);
}

PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundInformationBoardUI* battlegroundInformationBoardUIInstance = new PEP3BattlegroundInformationBoardUI();
PEP3BattlegroundInformationBoardUI* PEP3BattlegroundInformationBoardUI::sharedInstance()
{
	return battlegroundInformationBoardUIInstance;
}

PEP3BattlegroundInformationBoardUI::PEP3BattlegroundInformationBoardUI()
{
	this->enemyID = new UIStatic;
	this->enemyName = new UIStatic;
	this->enemyType = new UIStatic;
	this->enemyLevel = new UIStatic;
	this->enemyMoney = new UIStatic;
	this->enemyExperience = new UIStatic;
	this->enemyAttack = new UIStatic;
	this->enemyDefence = new UIStatic;
	this->enemyHP = new UIStatic;
	this->enemyHPBar = new UIStatic;
	this->enemyHPBarBackground = new UIStatic;
	this->enemySpeed = new UIStatic;
	this->enemyLuck = new UIStatic;
	this->enemyMP = new UIStatic;
	this->enemyMPBar = new UIStatic;
	this->enemyMPBarBackground = new UIStatic;
	this->enemyWater = new UIStatic;
	this->enemyNormalAttack = new UIStatic;
	this->enemyNormalAttackGPRecover = new UIStatic;
	this->enemyFire = new UIStatic;
	this->enemyDrop = new UIStatic;
	this->enemyDropAmount = new UIStatic;
	this->enemyWind = new UIStatic;
	this->enemyAdditionalDrop = new UIStatic;
	this->enemyAdditionalDropAmount = new UIStatic;
	this->enemyThunder = new UIStatic;
	this->enemySteal = new UIStatic;
	this->enemyStealCount = new UIStatic;
	this->enemyEarth = new UIStatic;
	this->enemyInitialState = new UIStatic;
	this->enemyInitialStateDuration = new UIStatic;
	this->enemySpecificDrop = new UIStatic;
	this->enemySpecificSkillName = new UIStatic;
	this->enemySpecificDropPercentage = new UIStatic;
	this->enemyAdditionalSpecificDrop = new UIStatic;
	this->enemyAdditionalSpecificSkillName = new UIStatic;
	this->enemyAdditionalSpecificDropPercentage = new UIStatic;
	this->enemyAction = new UIStatic[PEP3BattlegroundInformationBoardUIActionCount];
	this->statusItems = new UIStatic[PEP3BattlegroundInformationBoardUIStatusItemCount];
}

PEP3BattlegroundInformationBoardUI::~PEP3BattlegroundInformationBoardUI()
{
	delete this->enemyID;
	delete this->enemyName;
	delete this->enemyType;
	delete this->enemyLevel;
	delete this->enemyMoney;
	delete this->enemyExperience;
	delete this->enemyAttack;
	delete this->enemyDefence;
	delete this->enemyHP;
	delete this->enemyHPBar;
	delete this->enemyHPBarBackground;
	delete this->enemySpeed;
	delete this->enemyLuck;
	delete this->enemyMP;
	delete this->enemyMPBar;
	delete this->enemyMPBarBackground;
	delete this->enemyWater;
	delete this->enemyNormalAttack;
	delete this->enemyNormalAttackGPRecover;
	delete this->enemyFire;
	delete this->enemyDrop;
	delete this->enemyDropAmount;
	delete this->enemyWind;
	delete this->enemyAdditionalDrop;
	delete this->enemyAdditionalDropAmount;
	delete this->enemyThunder;
	delete this->enemySteal;
	delete this->enemyStealCount;
	delete this->enemyEarth;
	delete this->enemyInitialState;
	delete this->enemyInitialStateDuration;
	delete this->enemySpecificDrop;
	delete this->enemySpecificSkillName;
	delete this->enemySpecificDropPercentage;
	delete this->enemyAdditionalSpecificDrop;
	delete this->enemyAdditionalSpecificSkillName;
	delete this->enemyAdditionalSpecificDropPercentage;
	delete[] this->enemyAction;
	delete[] this->statusItems;
}

void PEP3BattlegroundInformationBoardUI::create(UIWnd* ui)
{
	int idx;

	// 背景
	RECT pRcBack = rect(ClientWidth() - 1064, 40, 1024, 1024);
	gbColorQuad textColor(87, 65, 20, 255);
	this->informationBoardBackground.Create(0, pRcBack, this);
	this->informationBoardBackground.SetBk("UI\\combatinformation.tga");

	// 主面板
	RECT pRcElement;
	pRcElement = rect(ClientWidth() - 712, 104, 258, 64);
	this->enemyID->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 328, 104, 258, 64);
	this->enemyName->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 168, 96, 64);
	this->enemyType->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 168, 96, 64);
	this->enemyLevel->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 328, 168, 96, 64);
	this->enemyMoney->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 168, 96, 64);
	this->enemyExperience->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 232, 96, 64);
	this->enemyAttack->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 232, 96, 64);
	this->enemyDefence->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 232, 232, 192, 64);
	this->enemyHP->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 328, 261, 96, 6);
	this->enemyHPBar->Create(0, pRcElement, this);
	this->enemyHPBar->SetBk("UI\\HPBar\\combat_bossHP.tga");
	pRcElement = rect(ClientWidth() - 328, 261, 96, 6);
	this->enemyHPBarBackground->Create(0, pRcElement, this);
	this->enemyHPBarBackground->SetBk("UI\\HPBar\\combat_bossHPBK.tga");
	pRcElement = rect(ClientWidth() - 712, 296, 96, 64);
	this->enemySpeed->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 296, 96, 64);
	this->enemyLuck->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 232, 296, 192, 64);
	this->enemyMP->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 328, 325, 96, 6);
	this->enemyMPBar->Create(0, pRcElement, this);
	this->enemyMPBar->SetBk("UI\\HPBar\\combat_bossHP4.tga");
	pRcElement = rect(ClientWidth() - 328, 325, 96, 6);
	this->enemyMPBarBackground->Create(0, pRcElement, this);
	this->enemyMPBarBackground->SetBk("UI\\HPBar\\combat_bossHPBK.tga");
	pRcElement = rect(ClientWidth() - 712, 360, 96, 64);
	this->enemyWater->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 360, 288, 64);
	this->enemyNormalAttack->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 360, 96, 64);
	this->enemyNormalAttackGPRecover->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 424, 96, 64);
	this->enemyFire->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 424, 288, 64);
	this->enemyDrop->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 424, 96, 64);
	this->enemyDropAmount->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 488, 96, 64);
	this->enemyWind->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 488, 288, 64);
	this->enemyAdditionalDrop->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 488, 96, 64);
	this->enemyAdditionalDropAmount->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 552, 96, 64);
	this->enemyThunder->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 552, 288, 64);
	this->enemySteal->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 552, 96, 64);
	this->enemyStealCount->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 616, 96, 64);
	this->enemyEarth->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 520, 616, 288, 64);
	this->enemyInitialState->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 616, 96, 64);
	this->enemySpecificDrop->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 680, 192, 64);
	this->enemySpecificDrop->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 424, 680, 192, 64);
	this->enemySpecificSkillName->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 680, 96, 64);
	this->enemySpecificDropPercentage->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 712, 744, 192, 64);
	this->enemyAdditionalSpecificDrop->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 424, 744, 192, 64);
	this->enemyAdditionalSpecificSkillName->Create(0, pRcElement, this);
	pRcElement = rect(ClientWidth() - 136, 744, 96, 64);
	this->enemyAdditionalSpecificDropPercentage->Create(0, pRcElement, this);
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIActionCount; ++idx)
	{
		pRcElement = rect(ClientWidth() - 712, 808 + 64 * idx, 672, 64);
		this->enemyAction[idx].Create(0, pRcElement, this);
	}

	//状态栏
	RECT pRcStatusItem;
	for (idx = 0; idx < PEP3BattlegroundInformationBoardUIStatusItemCount; ++idx)
	{
		pRcStatusItem = rect(ClientWidth() - 969, 40 + 106 * idx, 161, 53);
		this->statusItems[idx].Create(0, pRcStatusItem, this);
	}

	//条目内容的统一部分

	m_InformationEnemyBK.ShowWindow(false);
	m_InformationEnemyBarBK[0].ShowWindow(false);
	m_InformationEnemyBarBK[1].ShowWindow(false);
	m_InformationEnemyBar[0].ShowWindow(false);
	m_InformationEnemyBar[1].ShowWindow(false);
	for (a = 0; a < 36; a++) m_InformationEnemy[a].ShowWindow(false);
	for (a = 0; a < 4; a++) m_InformationEnemyStatus[a].ShowWindow(false);
}

void PEP3BattlegroundInformationBoardUI::update(int pageNumber)
{
	
}

void PEP3BattlegroundInformationBoardUI::setVisibility(bool visibility)
{
	
}

void PEP3BattlegroundInformationBoardUI::create(int pageNumber)
{

}
