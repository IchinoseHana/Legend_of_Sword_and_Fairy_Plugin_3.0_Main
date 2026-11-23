#ifndef _PEP3COMBATSPECUI_H_
#define _PEP3COMBATSPECUI_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"
#include <vector>

using std::string;
using std::vector;

// - 特化战场UI

// 转盘UI
struct PEP3BattlegroundWheelUIRotatingSection
{
	int speed; // 旋转速度，单位：度/0.1秒
	double duration; // 旋转时间，与外部对update的调用绑定
};
class PEP3BattlegroundWheelUI
{
private:
	// Initial variables
	double currentDuration; // 当前旋转时间计数
	int currentSection; // 当前旋转阶段
	double elapsedTime; // 经过时间，用于计算是否需要更新图片
	bool isRotating; // 是否正在旋转
	vector<PEP3BattlegroundWheelUIRotatingSection> rotatingSection; // 旋转流程定义数组

	UIStatic* wheelBackground; // 转盘背景
	UIStatic* wheelPointer; // 转盘指针
	bool clockwise; // 是否顺时针
	double imageUpdatingInterval; // 图片更新时间间隔

public:
	int currentAngle; // 当前角度

	PEP3BattlegroundWheelUI();
	~PEP3BattlegroundWheelUI();

	static PEP3BattlegroundWheelUI* sharedInstance();
	void create(UIWnd* ui, vector<PEP3BattlegroundWheelUIRotatingSection> rotatingSection);
	void updateRotatingSection(vector<PEP3BattlegroundWheelUIRotatingSection> rotatingSection);
	void beginRotating(int initAngle, bool clockwise, double imageUpdatingInterval);
	bool update(double deltatime); // 需要外部自行更新。返回true表示旋转完成，false表示仍在旋转
	void setVisibility(bool visibility);
};

// 药水炼制UI
class PEP3BattlegroundPotionCraftingUI
{
private:
	UIStatic* background; // 背景

public:
	PEP3BattlegroundPotionCraftingUI();
	~PEP3BattlegroundPotionCraftingUI();

	static PEP3BattlegroundPotionCraftingUI* sharedInstance();
	void create(UIWnd* ui);
	void setVisibility(bool visibility);
};

#endif
