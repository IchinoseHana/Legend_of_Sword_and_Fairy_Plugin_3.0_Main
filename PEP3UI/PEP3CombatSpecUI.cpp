#include "stdafx.h"

#include "PEP3CombatSpecUI.h"

#include "..\..\pal3\ui\uistatic.h"
#include "..\Utility\PEP3UIUtil.h"
#include "..\Utility\PEP3Define.h"

#define PEP3CombatUIImageFilePathWheelPointer "ui\\combat\\PEP3Wheel\\mahounotanepointer.tga"
#define PEP3CombatUIImageFilePathWheelDefault "ui\\combat\\PEP3Wheel\\magicwheel0.tga"
#define PEP3CombatUIImageFilePathWheel "ui\\combat\\PEP3Wheel\\magicwheel%d.tga"
#define PEP3CombatUIImageFilePathPotionCrafting "ui\\combat\\PEP3PotionCrafting\\battletia.tga"
#define PEP3CombatUIImageFilePathLogoDefault "ui\\combat\\PEP3Logo\\battlelogo1.tga"
#define PEP3CombatUIImageFilePathLogo "ui\\combat\\PEP3Logo\\battlelogo%d.tga"

using spcPEP3UIUtil::calCombatUIHorizontalMargin;
using spcPEP3UIUtil::calUIVerticalScaledValue;
using spcPEP3UIUtil::rect;

// 转盘UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundWheelUI* battlegroundWheelUIInstance = new PEP3BattlegroundWheelUI();
PEP3BattlegroundWheelUI* PEP3BattlegroundWheelUI::sharedInstance()
{
	return battlegroundWheelUIInstance;
}

PEP3BattlegroundWheelUI::PEP3BattlegroundWheelUI()
{
	currentDuration = 0.0;
	currentSection = 0;
	elapsedTime = 0.0;
	isRotating = false;

	wheelBackground = new UIStatic;
	wheelPointer = new UIStatic;
	clockwise = false;
	imageUpdatingInterval = 0;

	currentAngle = 0;
}

PEP3BattlegroundWheelUI::~PEP3BattlegroundWheelUI()
{
	delete wheelBackground;
	delete wheelPointer;
}

void PEP3BattlegroundWheelUI::create(UIWnd* ui, vector<PEP3BattlegroundWheelUIRotatingSection> rotatingSection)
{
	RECT pRcBackground = rect(ClientWidth() / 2 - 128, ClientHeight() / 2 - 128, 256, 256);
	wheelBackground->Create(0, pRcBackground, ui);
	wheelBackground->SetBk(PEP3CombatUIImageFilePathWheelDefault);
	wheelBackground->SetSizeRatio(2, 2);

	RECT pRcPointer = rect(ClientWidth() / 2 - 15, ClientHeight() / 2 - 248, 32, 256);
	wheelPointer->Create(0, pRcPointer, ui);
	wheelPointer->SetBk(PEP3CombatUIImageFilePathWheelPointer);

	this->rotatingSection = rotatingSection;

	setVisibility(false);
}

void PEP3BattlegroundWheelUI::updateRotatingSection(vector<PEP3BattlegroundWheelUIRotatingSection> rotatingSection)
{
	this->rotatingSection = rotatingSection;
}

void PEP3BattlegroundWheelUI::beginRotating(int initAngle, bool clockwise, double imageUpdatingInterval)
{
	setVisibility(true);

	this->currentAngle = initAngle;
	this->clockwise = clockwise;
	this->imageUpdatingInterval = imageUpdatingInterval;

	currentDuration = 0.0;
	currentSection = 0;
	elapsedTime = 0.0;
	isRotating = true;
}

bool PEP3BattlegroundWheelUI::update(double deltatime)
{
	if (!isRotating)
	{
		return false;
	}

	// 当前阶段执行完毕，进入下一阶段
	if (currentDuration >= rotatingSection[currentSection].duration)
	{
		currentDuration = 0.0;
		++currentSection;
	}

	// 所有阶段执行完毕，结束
	if (currentSection >= rotatingSection.size())
	{
		setVisibility(false);

		isRotating = false;
		return true;
	}

	// 将当前计数进行增加
	currentDuration += deltatime;

	// 更新图片
	elapsedTime += deltatime;
	if (elapsedTime >= imageUpdatingInterval)
	{
		elapsedTime -= imageUpdatingInterval;
		currentAngle += clockwise ? rotatingSection[currentSection].speed : -rotatingSection[currentSection].speed;
	}

	if (currentAngle >= 360)
	{
		currentAngle -= 360;
	}
	if (currentAngle < 0)
	{
		currentAngle += 360;
	}

	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };
	sprintf(fileName, PEP3CombatUIImageFilePathWheel, currentAngle);
	wheelBackground->SetBk(fileName);

	return false;
}

void PEP3BattlegroundWheelUI::setVisibility(bool visibility)
{
	wheelBackground->ShowWindow(visibility);
	wheelPointer->ShowWindow(visibility);
}

// 药水炼制UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundPotionCraftingUI* battlegroundPotionCraftingUIInstance = new PEP3BattlegroundPotionCraftingUI();
PEP3BattlegroundPotionCraftingUI* PEP3BattlegroundPotionCraftingUI::sharedInstance()
{
	return battlegroundPotionCraftingUIInstance;
}

PEP3BattlegroundPotionCraftingUI::PEP3BattlegroundPotionCraftingUI()
{
	background = new UIStatic;
}

PEP3BattlegroundPotionCraftingUI::~PEP3BattlegroundPotionCraftingUI()
{
	delete background;
}

void PEP3BattlegroundPotionCraftingUI::create(UIWnd* ui)
{
	RECT pRcBackground = rect((ClientWidth() - 1024) / 2, (ClientHeight() - 512) / 2, 1024, 512);
	background->Create(0, pRcBackground, ui);
	background->SetBk(PEP3CombatUIImageFilePathPotionCrafting);

	setVisibility(false);
}

void PEP3BattlegroundPotionCraftingUI::setVisibility(bool visibility)
{
	background->ShowWindow(visibility);
}

// 标识UI
PAL3HOOK_VERIFIED_DATAVAR static PEP3BattlegroundLogoUI* battlegroundLogoUIInstance = new PEP3BattlegroundLogoUI();
PEP3BattlegroundLogoUI* PEP3BattlegroundLogoUI::sharedInstance()
{
	return battlegroundLogoUIInstance;
}

PEP3BattlegroundLogoUI::PEP3BattlegroundLogoUI()
{
	logo = new UIStatic;
	speed = 0;
	stayDuration = 0.0;
	imageUpdatingInterval = 0;

	currentDuration = 0.0;
	currentStayDuration = 0.0;
	elapsedTime = 0.0;
	isMoving = false;
}

PEP3BattlegroundLogoUI::~PEP3BattlegroundLogoUI()
{
	delete logo;
}

void PEP3BattlegroundLogoUI::create(UIWnd* ui)
{
	RECT pRcLogo = rect(0, -256, 512, 256);
	logo->Create(0, pRcLogo, ui);
	logo->SetBk(PEP3CombatUIImageFilePathLogoDefault);

	setVisibility(false);
}

void PEP3BattlegroundLogoUI::updateLogoIndex(int index)
{
	char fileName[PEP3_MAX_FILEPATH_LENGTH] = { 0 };
	sprintf(fileName, PEP3CombatUIImageFilePathLogo, index);
	logo->SetBk(fileName);
}

void PEP3BattlegroundLogoUI::beginMoving(int speed, double stayDuration, double imageUpdatingInterval)
{
	setVisibility(true);

	this->speed = speed;
	this->stayDuration = stayDuration;
	this->imageUpdatingInterval = imageUpdatingInterval;

	currentDuration = 0.0;
	currentStayDuration = 0.0;
	elapsedTime = 0.0;
	isMoving = true;

	RECT pRcLogo = rect(0, -256, 512, 256);
	logo->SetRect(pRcLogo);
}

bool PEP3BattlegroundLogoUI::update(double deltatime)
{
	if (!isMoving)
	{
		return false;
	}

	// 将当前计数进行增加
	currentDuration += deltatime;

	// 决定是否更新图片
	bool needUpdate = false;
	elapsedTime += deltatime;
	if (elapsedTime >= imageUpdatingInterval)
	{
		elapsedTime -= imageUpdatingInterval;
		needUpdate = true;
	}

	if (needUpdate)
	{
		if (logo->GetWindowRect().top < 0 && currentStayDuration <= 0)
		{
			// 第一阶段：向下运动，-256 -> 0
			// 注意GetWindowRect()的底层实现比较反直觉，需要加上自身坐标
			logo->MoveWindow(0, logo->GetWindowRect().top + speed);
		}
		else
		{
			// 第二阶段：停留
			currentStayDuration += deltatime;
			if (currentStayDuration >= stayDuration)
			{
				// 第三阶段：向上运动，0 -> -256
				logo->MoveWindow(0, logo->GetWindowRect().top - speed);
				if (logo->GetWindowRect().top <= -256)
				{
					// 运动结束
					setVisibility(true);

					isMoving = false;
					return true;
				}
			}
		}
	}

	return false;
}

void PEP3BattlegroundLogoUI::setVisibility(bool visibility)
{
	logo->ShowWindow(visibility);
}

