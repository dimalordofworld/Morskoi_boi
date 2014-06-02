
// MFCSeaBattle.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCSeaBattleApp:
// О реализации данного класса см. MFCSeaBattle.cpp
//

class CMFCSeaBattleApp : public CWinApp
{
public:
	CMFCSeaBattleApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCSeaBattleApp theApp;