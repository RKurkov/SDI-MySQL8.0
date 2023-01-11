// CSelectUser.cpp: файл реализации
//

#include "pch.h"
#include "SDIAppSQL.h"
#include "afxdialogex.h"
#include "CSelectUser.h"


// Диалоговое окно CSelectUser

IMPLEMENT_DYNAMIC(CSelectUser, CDialog)

CSelectUser::CSelectUser(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, SelUser(_T(""))
{

}

CSelectUser::~CSelectUser()
{
}

void CSelectUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SelUser);
}


BEGIN_MESSAGE_MAP(CSelectUser, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CSelectUser
