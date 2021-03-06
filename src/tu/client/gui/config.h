#ifndef TU_CLIENT_GUI_CONFIG_H
#define TU_CLIENT_GUI_CONFIG_H

#include <engine/graphics.h>
#include <tu/client/assetpath.h>

class IGraphics;
class ITextRender;
class CRenderTools;
class IInput;

namespace tu
{
	
class CClient_Graphics;

namespace gui
{

enum
{
	TEXTSTYLE_NORMAL = 0,
	TEXTSTYLE_HEADER,
	TEXTSTYLE_HEADER2,
	NUM_TEXTSTYLES,
};

typedef void (*CShowHintFunc)(const char*, void*);

class CConfig
{
public:
	enum
	{
		BUTTONSTYLE_DEFAULT = 0,
		BUTTONSTYLE_DEFAULT_HIGHLIGHT,
		BUTTONSTYLE_LINK,
		BUTTONSTYLE_LINK_HIGHLIGHT,
		NUM_BUTTONSTYLES,
	};
	
	enum
	{
		LAYOUTSTYLE_DEFAULT = 0,
		LAYOUTSTYLE_NONE,
		NUM_LAYOUTSTYLES,
	};
	
	enum
	{
		TABSTYLE_DEFAULT = 0,
		NUM_TABSTYLES,
	};
	
	class CButtonStyle
	{
	public:
		CAssetPath m_StylePath_Normal;
		CAssetPath m_StylePath_UnderMouse;
	};
	
	class CLayoutStyle
	{
	public:
		CAssetPath m_StylePath;
		int m_Padding;
		int m_Spacing;
	};
	
	class CTabStyle
	{
	public:
		CAssetPath m_StylePath_Content;
		CAssetPath m_StylePath_Button;
		CAssetPath m_StylePath_ButtonHighlight;
	};
	
public:
	IGraphics *m_pGraphics;
	CClient_Graphics *m_pTUGraphics;
	ITextRender *m_pTextRender;
	CRenderTools *m_pRenderTools;
	IInput *m_pInput;
	
	IGraphics::CTextureHandle m_Texture;
	
	CButtonStyle m_ButtonStyles[NUM_BUTTONSTYLES];
	CLayoutStyle m_LayoutStyles[NUM_LAYOUTSTYLES];
	CTabStyle m_TabStyles[NUM_TABSTYLES];
	
	float m_TextSize[NUM_TEXTSTYLES];
	vec4 m_TextColor[NUM_TEXTSTYLES];
	
	int m_IconSize;
	int m_LabelMargin;
	int m_ButtonHeight;
	int m_SliderWidth;
	int m_SliderHeight;
	int m_LayoutSpacing;
	int m_LayoutMargin;
	int m_ExpandShift;
	int m_ExpandSpacing;
	
	CShowHintFunc m_fShowHint;
	void* m_pShowHintData;
	
public:
	CConfig(CClient_Graphics *pTUGraphics, CRenderTools *pRenderTools, ITextRender *pTextRender, IInput *pInput, IGraphics::CTextureHandle Texture);
	void ShowHind(const char* pText);
};

}

}

#endif
