#include "PEP3CombatUI.h"
#include "stdafx.h"

#include "..\pal3\GameBase\Pal3.h"

namespace spcPEP3CombatUI
{
	int calHorizontalMargin()
	{
		// 界面按照4:3的比例进行布局，如果界面太宽，超出的部分就是空白区域宽度，左右两边都存在
		// 不考虑游戏界面太高的情况
		return (ClientWidth() - ClientHeight() / 3 * 4) / 2;
	}

	int calVerticalScaledValue(int rawValue)
	{
		// 按照系统默认的1024 * 768分辨率来进行缩放
		return rawValue * ClientHeight() / 768;
	}
}