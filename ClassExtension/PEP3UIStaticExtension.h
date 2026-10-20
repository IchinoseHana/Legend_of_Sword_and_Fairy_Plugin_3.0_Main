#ifndef _PEP3UISTATICEXTENSION_H_
#define _PEP3UISTATICEXTENSION_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"

// 指定枚举值主要是为了兼容原版UIStatic的参数设定
enum PEP3UIStaticAlignmentType
{
	PEP3UIStaticAlignmentTypeHorizontalLeftVerticalUp = 0, // 左上
	PEP3UIStaticAlignmentTypeHorizontalLeftVerticalCenter = 3, // 左中
	PEP3UIStaticAlignmentTypeHorizontalLeftVerticalDown = 4, // 左下
	PEP3UIStaticAlignmentTypeHorizontalCenterVerticalUp = 5, // 中上
	PEP3UIStaticAlignmentTypeHorizontalCenterVerticalCenter = 1, // 中中
	PEP3UIStaticAlignmentTypeHorizontalCenterVerticalDown = 6, // 中下
	PEP3UIStaticAlignmentTypeHorizontalRightVerticalUp = 7, // 右上
	PEP3UIStaticAlignmentTypeHorizontalRightVerticalCenter = 8, // 右中
	PEP3UIStaticAlignmentTypeHorizontalRightVerticalDown = 2 // 右下
};
class PEP3UIStaticAlignment : public UIStatic
{
public:
	void setAlignment(PEP3UIStaticAlignmentType alignment);
	void SetText(LPCTSTR text);
};

#endif