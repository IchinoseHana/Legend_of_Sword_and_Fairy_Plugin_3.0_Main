#ifndef _PEP3UIUTIL_H_
#define _PEP3UIUTIL_H_

#pragma once

namespace spcPEP3UIUtil
{
	// 计算战斗界面两边空白区域的宽度。
	int calCombatUIHorizontalMargin();

	// 计算当前分辨率下经过缩放后的像素值。注意：游戏中的UI定位存在误差。
	int calUIVerticalScaledValue(int rawValue);

	// 计算当前分辨率下的屏幕长宽比。
	double getScreenRatio();

	// 生成一个RECT对象
	RECT rect(int left, int top, int width, int height);
}

#endif