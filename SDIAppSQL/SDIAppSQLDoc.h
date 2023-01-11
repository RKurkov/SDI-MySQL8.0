
// SDIAppSQLDoc.h: интерфейс класса CSDIAppSQLDoc 
//

#pragma once

#include <mysql.h>

class CSDIAppSQLView;
class CMyTreeView;
class CMyListView;

class COrder 
{
public:
	COrder();
	COrder(CString new_ord, CString new_pos, CString new_price);
	CString ord_id;
	CString pos_id;
	CString price;

};

class CUser
{
public:
	CUser();
	CUser(CString search);
	CString param_search;
};


class CSDIAppSQLDoc : public CDocument
{
protected: // создать только из сериализации
	CSDIAppSQLDoc() noexcept;
	DECLARE_DYNCREATE(CSDIAppSQLDoc)

// Атрибуты
public:
	MYSQL* conn;
	CMyTreeView* m_pTreeView;
	CSDIAppSQLView* m_pView;
	CMyListView* m_pListView;

	bool m_bOrders, m_bPositions, m_bPositions_orders, m_bUsers;

	int t_nom;

// Операции
public:
	void ReadNomber(int n);
	void InsertOrderTable(COrder info);
	void UserTableWhere(CUser inform);

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSDIAppSQLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnInsertOrder();
	afx_msg void OnSearchUs();
};
