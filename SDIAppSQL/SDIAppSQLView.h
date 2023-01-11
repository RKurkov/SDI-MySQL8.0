
// SDIAppSQLView.h: интерфейс класса CSDIAppSQLView
//

#pragma once

#include "SDIAppSQLDoc.h"

class CSDIAppSQLView : public CView
{
protected: // создать только из сериализации
	CSDIAppSQLView() noexcept;
	DECLARE_DYNCREATE(CSDIAppSQLView)

// Атрибуты
public:
	CSDIAppSQLDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSDIAppSQLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в SDIAppSQLView.cpp
inline CSDIAppSQLDoc* CSDIAppSQLView::GetDocument() const
   { return reinterpret_cast<CSDIAppSQLDoc*>(m_pDocument); }
#endif

