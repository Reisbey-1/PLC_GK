// GKView.h : Schnittstelle der Klasse CGKView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GKVIEW_H__8DD501C0_A83D_4790_83A3_22D3964E4632__INCLUDED_)
#define AFX_GKVIEW_H__8DD501C0_A83D_4790_83A3_22D3964E4632__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGKCntrItem;

class CGKView : public CListView
{
protected: // Nur aus Serialisierung erzeugen
	CGKView();
	DECLARE_DYNCREATE(CGKView)

// Attribute
public:
	CGKDoc* GetDocument();
	// m_pSelection enth�lt die Auswahl des aktuellen CGKCntrItem-Objekts.
	// F�r viele Anwendungen ist eine derartige Member-Variable nicht angemessen, um
	//  z.B. eine Mehrfachauswahl oder eine Auswahl von Objekten zu repr�sentieren,
	//  die keine CGKCntrItem-Objekte sind. Dieser Auswahlmechanismus
	//  dient nur dazu, Ihnen bei den ersten Schritten zu helfen.

	// ZU ERLEDIGEN: Ersetzen Sie diesen Auswahlmechanismus durch einen f�r Ihre Anwendung geeigneten.
	CGKCntrItem* m_pSelection;

// Operationen
public:

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CGKView)
	public:
	virtual void OnDraw(CDC* pDC);  // �berladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // das erste mal nach der Konstruktion aufgerufen
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CGKView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CGKView)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in GKView.cpp
inline CGKDoc* CGKView::GetDocument()
   { return (CGKDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_GKVIEW_H__8DD501C0_A83D_4790_83A3_22D3964E4632__INCLUDED_)
