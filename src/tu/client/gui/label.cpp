#include <engine/graphics.h>
#include <engine/textrender.h>
#include <game/client/render.h>

#include "label.h"

namespace tu
{
	
namespace gui
{

CLabel::CLabel(CConfig *pConfig, const char* pText, int Style) :
	CWidget(pConfig),
	m_TextStyle(Style)
{	
	SetText(pText);
}

void CLabel::SetText(const char* pText)
{
	str_copy(m_aText, pText, sizeof(m_aText));
	
	m_Rect.w = 2*m_pConfig->m_LabelMargin + TextRender()->TextWidth(0, m_pConfig->m_TextSize[m_TextStyle], m_aText, -1);
	m_Rect.h = 2*m_pConfig->m_LabelMargin + m_pConfig->m_TextSize[m_TextStyle];
}
	
void CLabel::Render()
{
	CTextCursor Cursor;
	TextRender()->SetCursor(&Cursor, m_Rect.x + m_pConfig->m_LabelMargin, m_Rect.y - m_pConfig->m_TextSize[m_TextStyle]/4 + m_pConfig->m_LabelMargin, m_pConfig->m_TextSize[m_TextStyle], TEXTFLAG_RENDER);
	TextRender()->TextColor(m_pConfig->m_TextColor[m_TextStyle].x, m_pConfig->m_TextColor[m_TextStyle].y, m_pConfig->m_TextColor[m_TextStyle].z, m_pConfig->m_TextColor[m_TextStyle].w);
	TextRender()->TextEx(&Cursor, m_aText, -1);
}

}

}
