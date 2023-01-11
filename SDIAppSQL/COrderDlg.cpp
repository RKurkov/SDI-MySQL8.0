// COrderDlg.cpp: файл реализации
//

#include "pch.h"
#include "SDIAppSQL.h"
#include "afxdialogex.h"
#include "COrderDlg.h"


// Диалоговое окно COrderDlg

IMPLEMENT_DYNAMIC(COrderDlg, CDialog)

COrderDlg::COrderDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, orderField(_T(""))
	, positionField(_T(""))
	, priceField(_T(""))
{

}

COrderDlg::~COrderDlg()
{
}

void COrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, orderField);
	DDX_Text(pDX, IDC_EDIT2, positionField);
	DDX_Text(pDX, IDC_EDIT3, priceField);
}


BEGIN_MESSAGE_MAP(COrderDlg, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений COrderDlg
