
// MFCSeaBattle.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFCSeaBattleApp:
// � ���������� ������� ������ ��. MFCSeaBattle.cpp
//

class CMFCSeaBattleApp : public CWinApp
{
public:
	CMFCSeaBattleApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFCSeaBattleApp theApp;