
// SDIAppSQLView.cpp: реализация класса CSDIAppSQLView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SDIAppSQL.h"
#endif

#include "SDIAppSQLDoc.h"
#include "SDIAppSQLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIAppSQLView

IMPLEMENT_DYNCREATE(CSDIAppSQLView, CView)

BEGIN_MESSAGE_MAP(CSDIAppSQLView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CSDIAppSQLView

CSDIAppSQLView::CSDIAppSQLView() noexcept
{
	// TODO: добавьте код создания

}

CSDIAppSQLView::~CSDIAppSQLView()
{
}

BOOL CSDIAppSQLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CSDIAppSQLView

void CSDIAppSQLView::OnDraw(CDC* /*pDC*/)
{
	CSDIAppSQLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CSDIAppSQLView

BOOL CSDIAppSQLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSDIAppSQLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSDIAppSQLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CSDIAppSQLView

#ifdef _DEBUG
void CSDIAppSQLView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIAppSQLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIAppSQLDoc* CSDIAppSQLView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIAppSQLDoc)));
	return (CSDIAppSQLDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSDIAppSQLView

