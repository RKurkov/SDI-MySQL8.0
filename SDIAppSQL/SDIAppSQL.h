
// SDIAppSQL.h: основной файл заголовка для приложения SDIAppSQL
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSDIAppSQLApp:
// Сведения о реализации этого класса: SDIAppSQL.cpp
//

class CSDIAppSQLApp : public CWinApp
{
public:
	CSDIAppSQLApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIAppSQLApp theApp;
