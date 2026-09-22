#ifndef _PEP3UIUTIL_H_
#define _PEP3UIUTIL_H_

#pragma once

namespace spcPEP3UIUtil
{
	// Calculate the right margin for combat UI.
	// 计算战斗界面两边空白区域的宽度。
	int calCombatUIHorizontalMargin();
	// Calculate the scaled value at the current resolution for combat UI.
	// 计算战斗界面当前分辨率下经过缩放后的像素值。
	int calCombatUIVerticalScaledValue(int rawValue);
}

#endif
