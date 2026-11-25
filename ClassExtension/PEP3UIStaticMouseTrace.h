#ifndef _PEP3UIStaticMouseTrace_H_
#define _PEP3UIStaticMouseTrace_H_

#pragma once

#include "..\..\pal3\ui\uistatic.h"

enum PEP3UIStaticMouseTraceType
{
	PEP3UIStaticMouseTraceTypeNone = 0, // 无
	PEP3UIStaticMouseTraceTypePointed, // 鼠标指针在UI上
	PEP3UIStaticMouseTraceTypeLeftClicked, // 鼠标在UI上左单击
	PEP3UIStaticMouseTraceTypeRightClicked, // 鼠标在UI上右单击
	PEP3UIStaticMouseTraceTypeLeftDoubleClicked, // 鼠标在UI上左双击
	PEP3UIStaticMouseTraceTypeRightDoubleClicked, // 鼠标在UI上右双击
	PEP3UIStaticMouseTraceTypeLeftPressed, // 鼠标在UI上左按下
	PEP3UIStaticMouseTraceTypeRightPressed, // 鼠标在UI上右按下
	PEP3UIStaticMouseTraceTypeLeftReleased, // 鼠标在UI上左释放
	PEP3UIStaticMouseTraceTypeRightReleased // 鼠标在UI上右释放
};

// 支持获取鼠标状态的UIStatic控件
class PEP3UIStaticMouseTrace : public UIStatic
{
public:
	PEP3UIStaticMouseTraceType getMouseType();
};

#endif