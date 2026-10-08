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
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundInformationBoardUI* battlegroundInformationBoardUIInstance = new PEP3BattlegroundInformationBoardUI();
PEP3BattlegroundInformationBoardUI* PEP3BattlegroundInformationBoardUI::sharedInstance()
{
	return battlegroundInformationBoardUIInstance;
}

PEP3BattlegroundInformationBoardUI::PEP3BattlegroundInformationBoardUI()
{
	this->enrmyID = new UIStatic;
	this->enrmyName = new UIStatic;
	this->enrmyType = new UIStatic;
	this->enrmyLevel = new UIStatic;
	this->enrmyMoney = new UIStatic;
	this->enrmyExperience = new UIStatic;
	this->enrmyAttack = new UIStatic;
	this->enrmyDefence = new UIStatic;
	this->enrmySpeed = new UIStatic;
	this->enemyHPBar = new UIStatic;
	this->enemyHPBarBackground = new UIStatic;
	this->enrmyLuck = new UIStatic;
	this->enemyMPBar = new UIStatic;
	this->enemyMPBarBackground = new UIStatic;
	this->enrmyWater = new UIStatic;
	this->enrmyNormalAttack = new UIStatic;
	this->enrmyNormalAttackGPRecover = new UIStatic;
	this->enrmyFire = new UIStatic;
	this->enrmyDrop = new UIStatic;
	this->enrmyDropAmount = new UIStatic;
	this->enrmyWind = new UIStatic;
	this->enrmyAdditionalDrop = new UIStatic;
	this->enrmyAdditionalDropAmount = new UIStatic;
	this->enrmyThunder = new UIStatic;
	this->enrmySteal = new UIStatic;
	this->enrmyStealCount = new UIStatic;
	this->enrmyEarth = new UIStatic;
	this->enrmyInitialState = new UIStatic;
	this->enrmyInitialStateDuration = new UIStatic;
	this->enrmySpecificDrop = new UIStatic;
	this->enrmySpecificSkillName = new UIStatic;
	this->enrmySpecificDropPercentage = new UIStatic;
	this->enrmyAdditionalSpecificDrop = new UIStatic;
	this->enrmyAdditionalSpecificSkillName = new UIStatic;
	this->enrmyAdditionalSpecificDropPercentage = new UIStatic;
	this->enrmyAction = new UIStatic[PEP3BattlegroundInformationBoardUIActionCount];
}

PEP3BattlegroundInformationBoardUI::~PEP3BattlegroundInformationBoardUI()
{
	delete this->enrmyID;
	delete this->enrmyName;
	delete this->enrmyType;
	delete this->enrmyLevel;
	delete this->enrmyMoney;
	delete this->enrmyExperience;
	delete this->enrmyAttack;
	delete this->enrmyDefence;
	delete this->enrmySpeed;
	delete this->enemyHPBar;
	delete this->enemyHPBarBackground;
	delete this->enrmyLuck;
	delete this->enemyMPBar;
	delete this->enemyMPBarBackground;
	delete this->enrmyWater;
	delete this->enrmyNormalAttack;
	delete this->enrmyNormalAttackGPRecover;
	delete this->enrmyFire;
	delete this->enrmyDrop;
	delete this->enrmyDropAmount;
	delete this->enrmyWind;
	delete this->enrmyAdditionalDrop;
	delete this->enrmyAdditionalDropAmount;
	delete this->enrmyThunder;
	delete this->enrmySteal;
	delete this->enrmyStealCount;
	delete this->enrmyEarth;
	delete this->enrmyInitialState;
	delete this->enrmyInitialStateDuration;
	delete this->enrmySpecificDrop;
	delete this->enrmySpecificSkillName;
	delete this->enrmySpecificDropPercentage;
	delete this->enrmyAdditionalSpecificDrop;
	delete this->enrmyAdditionalSpecificSkillName;
	delete this->enrmyAdditionalSpecificDropPercentage;
	delete[] this->enrmyAction;
}

void PEP3BattlegroundInformationBoardUI::create(UIWnd* ui)
{
	//敌人信息
	////背景
	//RECT barRect;
	//gbColorQuad ci(87, 65, 20, 255);
	//pRc9.top = 40;
	//pRc9.left = ClientWidth() - 1064;
	//pRc9.right = pRc9.left + 1024;
	//pRc9.bottom = pRc9.top + 1024;
	//m_InformationEnemyBK.Create(0, pRc9, this);
	//m_InformationEnemyBK.SetBk("UI\\combatinformation.tga");

	////逐个创建条目内容
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 258;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[0].Create(0, pRc9, this);
	//pRc9.left += 384;
	//pRc9.right = pRc9.left + 258;
	//m_InformationEnemy[1].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[2].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[3].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[4].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[5].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[6].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[7].Create(0, pRc9, this);
	//pRc9.left += 288;
	//pRc9.right = pRc9.left + 192;
	//m_InformationEnemy[8].Create(0, pRc9, this);
	////进度条
	//barRect.top = pRc9.top + 29;
	//barRect.left = ClientWidth() - 808 + 480;
	//barRect.right = barRect.left + 96;
	//barRect.bottom = barRect.top + 6;
	//m_InformationEnemyBarBK[0].Create(0, barRect, this);
	//m_InformationEnemyBarBK[0].SetBk("UI\\combat_bossHPBK.tga");
	//m_InformationEnemyBar[0].Create(0, barRect, this);
	//m_InformationEnemyBar[0].SetBk("UI\\combat_bossHP.tga");
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[9].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[10].Create(0, pRc9, this);
	//pRc9.left += 288;
	//pRc9.right = pRc9.left + 192;
	//m_InformationEnemy[11].Create(0, pRc9, this);
	////进度条
	//barRect.top = barRect.top + 64;
	//barRect.bottom = barRect.top + 6;
	//m_InformationEnemyBarBK[1].Create(0, barRect, this);
	//m_InformationEnemyBarBK[1].SetBk("UI\\combat_bossHPBK.tga");
	//m_InformationEnemyBar[1].Create(0, barRect, this);
	//m_InformationEnemyBar[1].SetBk("UI\\combat_bossHP4.tga");
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[12].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 288;
	//m_InformationEnemy[13].Create(0, pRc9, this);
	//pRc9.left += 384;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[14].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[15].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 288;
	//m_InformationEnemy[16].Create(0, pRc9, this);
	//pRc9.left += 384;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[17].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[18].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 288;
	//m_InformationEnemy[19].Create(0, pRc9, this);
	//pRc9.left += 384;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[20].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[21].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 288;
	//m_InformationEnemy[22].Create(0, pRc9, this);
	//pRc9.left += 384;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[23].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 96;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[24].Create(0, pRc9, this);
	//pRc9.left += 192;
	//pRc9.right = pRc9.left + 288;
	//m_InformationEnemy[25].Create(0, pRc9, this);
	//pRc9.left += 384;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[26].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 192;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[27].Create(0, pRc9, this);
	//pRc9.left += 288;
	//pRc9.right = pRc9.left + 192;
	//m_InformationEnemy[28].Create(0, pRc9, this);
	//pRc9.left += 288;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[29].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 192;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[30].Create(0, pRc9, this);
	//pRc9.left += 288;
	//pRc9.right = pRc9.left + 192;
	//m_InformationEnemy[31].Create(0, pRc9, this);
	//pRc9.left += 288;
	//pRc9.right = pRc9.left + 96;
	//m_InformationEnemy[32].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 672;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[33].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 672;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[34].Create(0, pRc9, this);
	//pRc9.top += 64;
	//pRc9.left = ClientWidth() - 808 + 96;
	//pRc9.right = pRc9.left + 672;
	//pRc9.bottom = pRc9.top + 64;
	//m_InformationEnemy[35].Create(0, pRc9, this);
	////状态栏
	//pRc9.top = 40;
	//pRc9.left = ClientWidth() - 1064 + 95;
	//pRc9.right = pRc9.left + 161;
	//pRc9.bottom = pRc9.top + 53;
	//m_InformationEnemyStatus[0].Create(0, pRc9, this);
	//pRc9.top += 106;
	//pRc9.bottom = pRc9.top + 53;
	//m_InformationEnemyStatus[1].Create(0, pRc9, this);
	//pRc9.top += 106;
	//pRc9.bottom = pRc9.top + 53;
	//m_InformationEnemyStatus[2].Create(0, pRc9, this);
	//pRc9.top += 106;
	//pRc9.bottom = pRc9.top + 53;
	//m_InformationEnemyStatus[3].Create(0, pRc9, this);

	////条目内容的统一部分
	//for (int a = 0; a < 36; a++)
	//{
	//	m_InformationEnemy[a].SetFont(true);
	//	m_InformationEnemy[a].SetFontColor(ci);
	//	m_InformationEnemy[a].SetText("", true);
	//}
	//for (a = 0; a < 4; a++)
	//{
	//	m_InformationEnemyStatus[a].SetFont(true);
	//	m_InformationEnemyStatus[a].SetFontColor(ci);
	//	m_InformationEnemyStatus[a].SetText("", true);
	//}

	//m_InformationEnemyBK.ShowWindow(false);
	//m_InformationEnemyBarBK[0].ShowWindow(false);
	//m_InformationEnemyBarBK[1].ShowWindow(false);
	//m_InformationEnemyBar[0].ShowWindow(false);
	//m_InformationEnemyBar[1].ShowWindow(false);
	//for (a = 0; a < 36; a++) m_InformationEnemy[a].ShowWindow(false);
	//for (a = 0; a < 4; a++) m_InformationEnemyStatus[a].ShowWindow(false);
}

void PEP3BattlegroundInformationBoardUI::update(int pageNumber)
{
	
}

void PEP3BattlegroundInformationBoardUI::setVisibility(bool visibility)
{
	
}
