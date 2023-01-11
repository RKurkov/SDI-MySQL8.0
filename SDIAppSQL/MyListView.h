#pragma once
#include <afxcview.h>

class CSDIAppSQLDoc;

// Просмотр CMyListView

class CMyListView : public CListView
{
	DECLARE_DYNCREATE(CMyListView)

protected:
	CMyListView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyListView();
	int s_table = 0;

public:
	CSDIAppSQLDoc* m_pDoc;
	CSDIAppSQLDoc* GetDocument() const;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void CMyListView::ReadTable(int type);
	void CMyListView::SearchTable(CString param);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};


