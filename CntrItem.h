// CntrItem.h : Schnittstelle der Klasse CGKCntrItem
//

#if !defined(AFX_CNTRITEM_H__12FDD6B2_AD13_4986_BDD5_561AE11680E5__INCLUDED_)
#define AFX_CNTRITEM_H__12FDD6B2_AD13_4986_BDD5_561AE11680E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGKDoc;
class CGKView;

class CGKCntrItem : public COleDocObjectItem
{
	DECLARE_SERIAL(CGKCntrItem)

// Konstruktoren
public:
	CGKCntrItem(CGKDoc* pContainer = NULL);
		// Hinweis: pContainer darf auch NULL sein, um IMPLEMENT_SERIALIZE zuzulassen.
		//  IMPLEMENT_SERIALIZE verlangt, dass die Klasse einen Konstruktor mit
		//  null Argumenten besitzt. Normalerweise werden OLE-Elemente mit einem 
		//  Dokumentzeiger konstruiert, der ungleich Null ist.

// Attribute
public:
	CGKDoc* GetDocument()
		{ return (CGKDoc*)COleDocObjectItem::GetDocument(); }
	CGKView* GetActiveView()
		{ return (CGKView*)COleDocObjectItem::GetActiveView(); }

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CGKCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementierung
public:
	~CGKCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_CNTRITEM_H__12FDD6B2_AD13_4986_BDD5_561AE11680E5__INCLUDED_)
