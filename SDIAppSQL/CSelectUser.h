#pragma once
#include "afxdialogex.h"


// Диалоговое окно CSelectUser

class CSelectUser : public CDialog
{
	DECLARE_DYNAMIC(CSelectUser)

public:
	CSelectUser(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CSelectUser();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString SelUser;
};
