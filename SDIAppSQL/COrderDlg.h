#pragma once
#include "afxdialogex.h"


// Диалоговое окно COrderDlg

class COrderDlg : public CDialog
{
	DECLARE_DYNAMIC(COrderDlg)

public:
	COrderDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~COrderDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString orderField;
	CString positionField;
	CString priceField;
};
