// MyListView.cpp: файл реализации
//

#include "pch.h"
#include "SDIAppSQL.h"
#include "MyListView.h"

#include "SDIAppSQLDoc.h"
#include "SDIAppSQLView.h"
#include <mysql.h>
#include <string>



// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CListView)

CMyListView::CMyListView()
{

}

CMyListView::~CMyListView()
{
}

BEGIN_MESSAGE_MAP(CMyListView, CListView)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// Диагностика CMyListView

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyListView


void CMyListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: добавьте специализированный код или вызов базового класса

	DWORD style = GetWindowLong(this->GetListCtrl().m_hWnd, GWL_STYLE);

	CSDIAppSQLDoc* pDoc = GetDocument();
	pDoc->m_pListView = this;

	SetWindowLong(this->GetListCtrl().m_hWnd, GWL_STYLE, (style & ~LVS_TYPEMASK) | LVS_REPORT);

}

CSDIAppSQLDoc* CMyListView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIAppSQLDoc)));
	return (CSDIAppSQLDoc*)m_pDocument;
}

void CMyListView::ReadTable(int type)
{
	s_table = type;

	GetListCtrl().DeleteAllItems();

	GetListCtrl().DeleteColumn(0);
	GetListCtrl().DeleteColumn(0);
	GetListCtrl().DeleteColumn(0);
	GetListCtrl().DeleteColumn(0);

	MYSQL* conn = mysql_init(NULL);
	MYSQL_RES* reslogon;
	MYSQL_ROW row;

	mysql_set_character_set(conn, "utf8");

	conn = mysql_real_connect(conn, "localhost", "root", "Q2er0w0Q2", "stock", 0, NULL, 0);
	std::string sql;
	
	if (s_table == 1)
	{
		GetListCtrl().InsertColumn(0, L"order_id", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(1, L"user_id", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(2, L"price", LVCFMT_LEFT, 200, 0);

		sql = "SELECT * FROM orders;";
		mysql_query(conn, sql.c_str());

		if (reslogon = mysql_store_result(conn)) 
		{
			while (row = mysql_fetch_row(reslogon)) {
				CString order_id(row[0]);
				CString user_id(row[1]);
				CString price(row[2]);

				int nItem = 0;
				nItem = this->GetListCtrl().InsertItem(0, order_id);
				this->GetListCtrl().SetItemText(nItem, 1, user_id);
				this->GetListCtrl().SetItemText(nItem, 2, price);

			}
		}
	}

	if (s_table == 2)
	{
		GetListCtrl().InsertColumn(0, L"position_id", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(1, L"position_name", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(2, L"position_kg", LVCFMT_LEFT, 200, 0);

		sql = "SELECT * FROM positions;";
		mysql_query(conn, sql.c_str());

		if (reslogon = mysql_store_result(conn)) 
		{
			while (row = mysql_fetch_row(reslogon)) {
				CString position_id(row[0]);
				CString position_name(row[1]);
				CString position_kg(row[2]);

				int nItem = 0;
				nItem = this->GetListCtrl().InsertItem(0, position_id);
				this->GetListCtrl().SetItemText(nItem, 1, position_name);
				this->GetListCtrl().SetItemText(nItem, 2, position_kg);

			}
		}
	}

	if (s_table == 3)
	{
		GetListCtrl().InsertColumn(0, L"order_id", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(1, L"position_id", LVCFMT_LEFT, 200, 0);

		sql = "SELECT * FROM positions_orders;";
		mysql_query(conn, sql.c_str());

		if (reslogon = mysql_store_result(conn)) 
		{
			while (row = mysql_fetch_row(reslogon)) {
				CString order_id(row[0]);
				CString position_id(row[1]);

				int nItem = 0;
				nItem = this->GetListCtrl().InsertItem(0, order_id);
				this->GetListCtrl().SetItemText(nItem, 1, position_id);

			}
		}
	}

	if (s_table == 4)
	{
		GetListCtrl().InsertColumn(0, L"user_id", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(1, L"user_name", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(2, L"user_login", LVCFMT_LEFT, 200, 0);
		GetListCtrl().InsertColumn(2, L"user_password", LVCFMT_LEFT, 200, 0);

		sql = "SELECT * FROM users;";
		mysql_query(conn, sql.c_str());

		if (reslogon = mysql_store_result(conn)) 
		{
			while (row = mysql_fetch_row(reslogon)) {
				CString user_id(row[0]);
				CString user_name(row[1]);
				CString user_login(row[2]);
				CString user_password(row[3]);

				int nItem = 0;
				nItem = this->GetListCtrl().InsertItem(0, user_id);
				this->GetListCtrl().SetItemText(nItem, 1, user_name);
				this->GetListCtrl().SetItemText(nItem, 2, user_login);
				this->GetListCtrl().SetItemText(nItem, 3, user_password);

			}
		}
	}
}

void CMyListView::SearchTable(CString inform)
{
	std::string s_param = CStringA(inform);


	GetListCtrl().DeleteAllItems();

	GetListCtrl().DeleteColumn(0);
	GetListCtrl().DeleteColumn(0);
	GetListCtrl().DeleteColumn(0);
	GetListCtrl().DeleteColumn(0);

	MYSQL* conn = mysql_init(NULL);
	MYSQL_RES* reslogon;
	MYSQL_ROW row;

	mysql_set_character_set(conn, "utf8");

	conn = mysql_real_connect(conn, "localhost", "root", "Q2er0w0Q2", "stock", 0, NULL, 0);
	std::string sql;

	GetListCtrl().InsertColumn(0, L"user_id", LVCFMT_LEFT, 200, 0);
	GetListCtrl().InsertColumn(1, L"user_name", LVCFMT_LEFT, 200, 0);
	GetListCtrl().InsertColumn(2, L"user_login", LVCFMT_LEFT, 200, 0);
	GetListCtrl().InsertColumn(2, L"user_password", LVCFMT_LEFT, 200, 0);

    std::string p = "'";

	sql = "SELECT * FROM users WHERE user_id = (" + s_param + ") or user_name = (" + p + s_param + p + ") or user_login = (" + p + s_param + p + ") or user_password = (" + p + s_param + p + "); ";
	mysql_query(conn, sql.c_str());

	if (reslogon = mysql_store_result(conn)) 
	{
		while (row = mysql_fetch_row(reslogon)) {
			CString user_id(row[0]);
			CString user_name(row[1]);
			CString user_login(row[2]);
			CString user_password(row[3]);

			int nItem = 0;
			nItem = this->GetListCtrl().InsertItem(0, user_id);
			this->GetListCtrl().SetItemText(nItem, 1, user_name);
			this->GetListCtrl().SetItemText(nItem, 2, user_login);
			this->GetListCtrl().SetItemText(nItem, 3, user_password);

		}
	}
	else 
	{ 
		sql = "SELECT * FROM users WHERE user_id = (" + p + s_param + p + ") or user_name = (" + p + s_param + p + ") or user_login = (" + p + s_param + p + ") or user_password = (" + p + s_param + p + "); ";
		mysql_query(conn, sql.c_str());

		if (reslogon = mysql_store_result(conn)) {
			while (row = mysql_fetch_row(reslogon)) {
				CString user_id(row[0]);
				CString user_name(row[1]);
				CString user_login(row[2]);
				CString user_password(row[3]);

				int nItem = 0;
				nItem = this->GetListCtrl().InsertItem(0, user_id);
				this->GetListCtrl().SetItemText(nItem, 1, user_name);
				this->GetListCtrl().SetItemText(nItem, 2, user_login);
				this->GetListCtrl().SetItemText(nItem, 3, user_password);

			}
		}
	}
}


void CMyListView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MAINFRAME);

	CMenu* SubMenu = MainMenu.GetSubMenu(5);

	ClientToScreen(&point);
	SubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);


	CListView::OnRButtonDown(nFlags, point);
}
