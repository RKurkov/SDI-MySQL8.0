
// SDIAppSQLDoc.cpp: реализация класса CSDIAppSQLDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SDIAppSQL.h"
#endif

#include "SDIAppSQLDoc.h"

#include <propkey.h>

#include "MainFrm.h"
#include "MyTreeView.h"
#include "MyListView.h"
#include "COrderDlg.h"
#include "CSelectUser.h"
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSDIAppSQLDoc

IMPLEMENT_DYNCREATE(CSDIAppSQLDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDIAppSQLDoc, CDocument)
	ON_COMMAND(ID_INSERT_ORDER, &CSDIAppSQLDoc::OnInsertOrder)
	ON_COMMAND(ID_SEARCH_US, &CSDIAppSQLDoc::OnSearchUs)
END_MESSAGE_MAP()


// Создание или уничтожение CSDIAppSQLDoc

CSDIAppSQLDoc::CSDIAppSQLDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CSDIAppSQLDoc::~CSDIAppSQLDoc()
{
}

COrder::COrder()
{

}

COrder::COrder(CString new_ord, CString new_pos, CString new_price)
{
	ord_id = new_ord;
	pos_id = new_pos;
	price = new_price;
}

CUser::CUser()
{

}

CUser::CUser(CString search)
{
	param_search = search;
}

BOOL CSDIAppSQLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, "127.0.0.1", "root", "Q2er0w0Q2", "stock", NULL, NULL, 0))
	{
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке

		MessageBox(NULL, L"ERROR", L"INFO", MB_OK);
		return 0;
	}

	mysql_set_character_set(conn, "utf8");

	CWnd* MainWnd = AfxGetMainWnd();

	if (MainWnd)
	{
		m_pTreeView = (CMyTreeView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 0);
		m_pListView = (CMyListView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 1);
		m_pTreeView->m_pDoc = this;
	}

	m_pTreeView->FillTree();
	m_bOrders = m_bPositions = m_bPositions_orders = m_bUsers = false;

	return TRUE;
}




// Сериализация CSDIAppSQLDoc

void CSDIAppSQLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSDIAppSQLDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CSDIAppSQLDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSDIAppSQLDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CSDIAppSQLDoc

#ifdef _DEBUG
void CSDIAppSQLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDIAppSQLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CSDIAppSQLDoc

void CSDIAppSQLDoc::ReadNomber(int n)
{
	t_nom = n;

	if (t_nom == 1)
		m_pListView->ReadTable(1);

	if (t_nom == 2)
		m_pListView->ReadTable(2);

	if (t_nom == 3)
		m_pListView->ReadTable(3);

	if (t_nom == 4)
		m_pListView->ReadTable(4);

}

void CSDIAppSQLDoc::OnInsertOrder()
{
	// TODO: добавьте свой код обработчика команд

	COrderDlg dlg;
	if (dlg.DoModal() != IDOK)
		return;
	COrder ordernew(dlg.orderField, dlg.positionField, dlg.priceField);
	InsertOrderTable(ordernew);
}

void CSDIAppSQLDoc::InsertOrderTable(COrder info)
{
	std::string idord = CStringA(info.ord_id);
	std::string idpos = CStringA(info.pos_id);
	std::string nprice = CStringA(info.price);
	std::string p = "'";
	std::string sql = "INSERT INTO orders VALUES(" + idord + "," + idpos + "," + nprice + ");";
	int query_state = mysql_query(conn, sql.c_str());
	if (query_state == 0)
	{
		MessageBox(NULL, L"Заказ добавлен", L"INFO", MB_OK);
	}
}


void CSDIAppSQLDoc::OnSearchUs()
{
	// TODO: добавьте свой код обработчика команд

	CSelectUser dlg;
	if (dlg.DoModal() != IDOK)
		return;
	CUser usernew(dlg.SelUser);
	UserTableWhere(usernew);
	
}

void CSDIAppSQLDoc::UserTableWhere(CUser inform)
{
	CString s_param = inform.param_search;
	m_pListView->SearchTable(s_param);
}

