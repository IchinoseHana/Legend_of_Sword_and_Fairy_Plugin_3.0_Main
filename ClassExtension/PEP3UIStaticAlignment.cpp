#include "stdafx.h"

#include "PEP3UIStaticAlignment.h"

void PEP3UIStaticAlignment::setAlignment(PEP3UIStaticAlignmentType alignment)
{
	UIStatic::m_align = (int)alignment;
}

void PEP3UIStaticAlignment::SetText(LPCTSTR text)
{
	ASSERT(text != NULL);
	if (text == NULL)
		return;

	m_text.assign(text);
}