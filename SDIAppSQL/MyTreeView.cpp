// MyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "SDIAppSQL.h"
#include "MyTreeView.h"

#include "SDIAppSQLDoc.h"
#include "MyListView.h"
#include "SDIAppSQLView.h"

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	m_hStock = tree.InsertItem(L"Склад", -1, -1, NULL, TVI_FIRST);

	m_hUsers = tree.InsertItem(L"Клиенты", -1, -1, m_hStock, TVI_FIRST);
	m_hPositions_orders = tree.InsertItem(L"Позиции в товарах", -1, -1, m_hStock, TVI_FIRST);
	m_hPositions = tree.InsertItem(L"Товары", -1, -1, m_hStock, TVI_FIRST);
	m_hOrders = tree.InsertItem(L"Заказы", -1, -1, m_hStock, TVI_FIRST);

	tree.Expand(m_hStock, TVE_EXPAND);
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView



void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CTreeCtrl& tree = GetTreeCtrl();
	CTreeView::OnLButtonDown(nFlags, point);

	CRect rc;

	tree.GetItemRect(m_hStock, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hStock);

	tree.GetItemRect(m_hOrders, &rc, false);

	if (rc.PtInRect(point)) 
	{
		tree.SelectItem(m_hOrders);
		m_pDoc->ReadNomber(1);
	}

	tree.GetItemRect(m_hPositions, &rc, false);

	if (rc.PtInRect(point)) 
	{
		tree.SelectItem(m_hPositions);
		m_pDoc->ReadNomber(2);
	}

	tree.GetItemRect(m_hPositions_orders, &rc, false);

	if (rc.PtInRect(point)) 
	{
		tree.SelectItem(m_hPositions_orders);
	    m_pDoc->ReadNomber(3);
    }

	tree.GetItemRect(m_hUsers, &rc, false);

	if (rc.PtInRect(point)) 
	{
		tree.SelectItem(m_hUsers);
		m_pDoc->ReadNomber(4);
	}


	if (tree.GetSelectedItem() == m_hStock)
	{
		bool check = tree.GetCheck(m_hStock);
		tree.SetCheck(m_hOrders, check);
		tree.SetCheck(m_hPositions, check);
		tree.SetCheck(m_hPositions_orders, check);
		tree.SetCheck(m_hUsers, check);

	}
	else
		tree.SetCheck(m_hStock, false);

	m_pDoc->m_bOrders = tree.GetCheck(m_hOrders);
	m_pDoc->m_bPositions = tree.GetCheck(m_hPositions);
	m_pDoc->m_bPositions_orders = tree.GetCheck(m_hPositions_orders);
	m_pDoc->m_bUsers = tree.GetCheck(m_hUsers);

	m_pDoc->m_pListView->Invalidate();

}



int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS 
		                  | TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}
