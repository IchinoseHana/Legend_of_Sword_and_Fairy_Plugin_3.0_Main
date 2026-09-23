#include "stdafx.h"

#include "PEP3CombatUI.h"

#include "..\..\pal3\ui\uistatic.h"
#include "..\Utility\PEP3UIUtil.h"
#include "..\Utility\PEP3Define.h"

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
	int leftMargin = spcPEP3UIUtil::calCombatUIHorizontalMargin();

	RECT pRcSlot;
	pRcSlot.top = 40;
	pRcSlot.left = leftMargin;
	pRcSlot.right = pRcSlot.left + 256;
	pRcSlot.bottom = pRcSlot.top + 16;
	this->spiritSlot->Create(0, pRcSlot, ui);
	this->spiritSlot->SetBk("UI\\skillbar0.tga");

	RECT pRcNumber;
	pRcNumber.top = 32;
	pRcNumber.left = leftMargin + 260;
	pRcNumber.right = pRcNumber.left + 45;
	pRcNumber.bottom = pRcNumber.top + 45;
	this->spiritNumber->Create(0, pRcNumber, ui);
	gbColorQuad color(0, 255, 255, 255);
	this->spiritNumber->SetFontColor(color);
	this->spiritNumber->SetText("0");

	RECT pRcUsingStatus;
	pRcUsingStatus.top = 70;
	pRcUsingStatus.left = leftMargin;
	pRcUsingStatus.right = pRcUsingStatus.left + 32;
	pRcUsingStatus.bottom = pRcUsingStatus.top + 32;
	this->spiritUsingStatus->Create(0, pRcUsingStatus, ui);
	this->spiritUsingStatus->SetBk("UI\\picuseprogram1.tga");
}

void PEP3BattlegroundSpiritUI::update(int spiritNumber, bool isUsingSpirit)
{
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };
	sprintf(fileName, "UI\\SkillBar\\skillbar%d.tga", spiritNumber);
	this->spiritSlot->SetBk(fileName);

	char numberText[3] = { 0 };
	sprintf(numberText, "%d", abs(spiritNumber));
	this->spiritNumber->SetText(numberText);

	this->spiritUsingStatus->SetBk(isUsingSpirit ? "UI\\picuseprogram1.tga" : "UI\\picuseprogram2.tga");
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
	int leftMargin = spcPEP3UIUtil::calCombatUIHorizontalMargin();
	gbColorQuad color(0, 255, 255, 255);

	RECT pRCResIcon;
	pRCResIcon.top = 70;
	pRCResIcon.left = leftMargin + 53;
	pRCResIcon.right = pRCResIcon.left + 32;
	pRCResIcon.bottom = pRCResIcon.top + 32;
	this->resurrectionIcon->Create(0, pRCResIcon, ui);
	this->resurrectionIcon->SetBk("UI\\battlegroundResurrection.tga");

	RECT pRcResNumber;
	pRcResNumber.top = 70;
	pRcResNumber.left = leftMargin + 92;
	pRcResNumber.right = pRcResNumber.left + 45;
	pRcResNumber.bottom = pRcResNumber.top + 45;
	this->resurrectionNumber->Create(0, pRcResNumber, ui);
	this->resurrectionNumber->SetFontColor(color);
	this->resurrectionNumber->SetText("0");

	RECT pRCBatStateIcon;
	pRCBatStateIcon.top = 70;
	pRCBatStateIcon.left = leftMargin + 123;
	pRCBatStateIcon.right = pRCBatStateIcon.left + 32;
	pRCBatStateIcon.bottom = pRCBatStateIcon.top + 32;
	this->battlegroundStateIcon->Create(0, pRCBatStateIcon, ui);
	this->battlegroundStateIcon->SetBk("UI\\battlegroundStateDefault.tga");

	RECT pRCBatStateNumber;
	pRCBatStateNumber.top = 70;
	pRCBatStateNumber.left = leftMargin + 161;
	pRCBatStateNumber.right = pRCBatStateNumber.left + 45;
	pRCBatStateNumber.bottom = pRCBatStateNumber.top + 45;
	this->battlegroundStateNumber->Create(0, pRCBatStateNumber, ui);
	this->battlegroundStateNumber->SetFontColor(color);
	this->battlegroundStateNumber->SetText("000");

	RECT pRCBatPropertyIcon;
	pRCBatPropertyIcon.top = 70;
	pRCBatPropertyIcon.left = leftMargin + 206;
	pRCBatPropertyIcon.right = pRCBatPropertyIcon.left + 32;
	pRCBatPropertyIcon.bottom = pRCBatPropertyIcon.top + 32;
	this->battlegroundPropertyIcon->Create(0, pRCBatPropertyIcon, ui);
	this->battlegroundPropertyIcon->SetBk("UI\\battlegroundStateDefault.tga");

	RECT pRCBatPropertyNumber;
	pRCBatPropertyNumber.top = 70;
	pRCBatPropertyNumber.left = leftMargin + 244;
	pRCBatPropertyNumber.right = pRCBatPropertyNumber.left + 45;
	pRCBatPropertyNumber.bottom = pRCBatPropertyNumber.top + 45;
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
	int rightMargin = ClientWidth() - spcPEP3UIUtil::calCombatUIHorizontalMargin();
	// 1024 * 768屏幕下，自定义界面上界为70(即行动条下方适合布局的起始点)
	int upperBound = spcPEP3UIUtil::calCombatUIVerticalScaledValue(70);
	gbColorQuad color(0, 255, 255, 255);
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };

	// 先处理合击，再处理暗器装填
	RECT pRcCoAttackIcon;
	pRcCoAttackIcon.top = upperBound;
	pRcCoAttackIcon.left = rightMargin - 100;
	pRcCoAttackIcon.right = pRcCoAttackIcon.left + 32;
	pRcCoAttackIcon.bottom = pRcCoAttackIcon.top + 32;
	this->battlegroundCoorperationAttackIcon->Create(0, pRcCoAttackIcon, ui);
	this->battlegroundCoorperationAttackIcon->SetBk("UI\\battlegroundCoorperationAttack.tga");

	RECT pRcCoAttackNumber;
	pRcCoAttackNumber.top = pRcCoAttackIcon.top;
	pRcCoAttackNumber.left = pRcCoAttackIcon.left + 48;
	pRcCoAttackNumber.right = pRcCoAttackNumber.left + 45;
	pRcCoAttackNumber.bottom = pRcCoAttackIcon.bottom;
	this->battlegroundCoorperationAttackNumber->Create(0, pRcCoAttackNumber, ui);
	this->battlegroundCoorperationAttackNumber->SetFontColor(color);
	this->battlegroundCoorperationAttackNumber->SetText("00");

	RECT pRcChargeIcon;
	pRcChargeIcon.top = pRcCoAttackNumber.top;
	pRcChargeIcon.left = pRcCoAttackNumber.left - 144;
	pRcChargeIcon.right = pRcChargeIcon.left + 32;
	pRcChargeIcon.bottom = pRcCoAttackNumber.bottom;
	this->battlegroundChargeIcon->Create(0, pRcChargeIcon, ui);
	this->battlegroundChargeIcon->SetBk("UI\\battlegroundCharge.tga");

	RECT pRcChargeNumber;
	pRcChargeNumber.top = pRcChargeIcon.top;
	pRcChargeNumber.left = pRcChargeIcon.left + 48;
	pRcChargeNumber.right = pRcChargeNumber.left + 32;
	pRcChargeNumber.bottom = pRcChargeIcon.bottom;
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
	int rightMargin = ClientWidth() - spcPEP3UIUtil::calCombatUIHorizontalMargin();
	// 除了自定义布局上界，还要考虑暗器装填和合击占据的位置
	int upperBound = spcPEP3UIUtil::calCombatUIVerticalScaledValue(70) + 46;

	for (int idx = 0; idx < PEP3BattlegroundEnvironmentUIIconCount; ++idx)
	{
		RECT pRcIcon;
		pRcIcon.top = upperBound;
		pRcIcon.left = rightMargin - 52 - (idx * 48);
		pRcIcon.right = pRcIcon.left + 32;
		pRcIcon.bottom = pRcIcon.top + 32;
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
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundBossHPBarUI* battlegroundBossHPBarUIInstance = new PEP3BattlegroundBossHPBarUI();
PEP3BattlegroundBossHPBarUI* PEP3BattlegroundBossHPBarUI::sharedInstance()
{
	return battlegroundBossHPBarUIInstance;
}

PEP3BattlegroundBossHPBarUI::PEP3BattlegroundBossHPBarUI()
{
	this->battlegroundBossHPBar = new UIStatic[PEP3BattlegroundBossHPBarCount];
	this->battlegroundBossHPBarBackground = new UIStatic;
}

PEP3BattlegroundBossHPBarUI::~PEP3BattlegroundBossHPBarUI()
{
	delete[] this->battlegroundBossHPBar;
	delete this->battlegroundBossHPBarBackground;
}

void PEP3BattlegroundBossHPBarUI::create(UIWnd* ui)
{
	RECT pRcBarBkg;
	pRcBarBkg.top = 120;
	pRcBarBkg.left = ClientWidth() / 2 - 256;
	pRcBarBkg.right = pRcBarBkg.left + 512;
	// 对于非纯色图片支持不佳，需要保证长度和宽度是16的倍数，好在可以使用Alpha通道
	pRcBarBkg.bottom = pRcBarBkg.top + 16;
	this->battlegroundBossHPBarBackground->Create(0, pRcBarBkg, ui);
	this->battlegroundBossHPBarBackground->SetBk("UI\\HPBar\\combat_bossHPBK.tga");

	for (int idx = 0; idx < PEP3BattlegroundBossHPBarCount; ++idx)
	{
		RECT pRcBar;
		pRcBar.top = 123;
		pRcBar.left = ClientWidth() / 2 - 253;
		pRcBar.right = pRcBar.left + 506;
		pRcBar.bottom = pRcBar.top + 3;
		this->battlegroundBossHPBar[idx].Create(0, pRcBar, ui);
		char fileName[PEP3_MAX_FILEPATH_LENGTH];
		sprintf(fileName, "UI\\HPBar\\combat_bossHP%d.tga", idx + 1);
		this->battlegroundBossHPBar[idx].SetBk(fileName);
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
	this->battlegroundBossHPBarBackground->ShowWindow(true);

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
		RECT pRcBar;
		pRcBar.top = 123;
		pRcBar.left = ClientWidth() / 2 - 253;
		pRcBar.right = pRcBar.left + 506;
		pRcBar.bottom = pRcBar.top + 3;
		this->battlegroundBossHPBar[idx].SetRect(pRcBar);
		this->battlegroundBossHPBar[idx].ShowWindow(true);
	}
	// 对于当前阶段，按照剩余血量比例进行布局
	RECT pRcCurBar;
	pRcCurBar.top = 123;
	pRcCurBar.left = ClientWidth() / 2 - 253;
	pRcCurBar.right = pRcCurBar.left + 506 * curStageRatio;
	pRcCurBar.bottom = pRcCurBar.top + 3;
	// 上一轮循环退出后刚好位于下一个索引
	if (idx < PEP3BattlegroundBossHPBarCount)
	{
		this->battlegroundBossHPBar[idx].SetRect(pRcCurBar);
		this->battlegroundBossHPBar[idx].ShowWindow(true);
	}
	// 后续阶段不显示，包括已经消耗掉的和不存在的阶段
	for (idx += 1; idx < PEP3BattlegroundBossHPBarCount; ++idx)
	{
		this->battlegroundBossHPBar[idx].ShowWindow(false);
	}
}

void PEP3BattlegroundBossHPBarUI::setVisibility(bool visibility)
{
	this->battlegroundBossHPBarBackground->ShowWindow(visibility);
	for (int idx = 0; idx < PEP3BattlegroundBossHPBarCount; ++idx)
	{
		this->battlegroundBossHPBar[idx].ShowWindow(visibility);
	}
}
