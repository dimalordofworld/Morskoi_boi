
// MFCSeaBattleDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CMFCSeaBattleDlg
class CMFCSeaBattleDlg : public CDialogEx
{
// ��������
public:
	CMFCSeaBattleDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_MFCSEABATTLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
