#pragma once
#include <afxcview.h>

class CSDIAppSQLDoc;

// Просмотр CMyTreeView

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:
	HTREEITEM m_hStock, m_hOrders, m_hPositions, m_hPositions_orders, m_hUsers;
	void FillTree();

	CSDIAppSQLDoc* m_pDoc;


#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


