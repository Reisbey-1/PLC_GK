// GKDoc.h : Schnittstelle der Klasse CGKDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GKDOC_H__50CC0FDC_5677_4DF0_BC94_E9BBF225D8C6__INCLUDED_)
#define AFX_GKDOC_H__50CC0FDC_5677_4DF0_BC94_E9BBF225D8C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGKDoc : public COleDocument
{
protected: // Nur aus Serialisierung erzeugen
	CGKDoc();
	DECLARE_DYNCREATE(CGKDoc)

// Attribute
public:

// Operationen
public:

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CGKDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CGKDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CGKDoc)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_GKDOC_H__50CC0FDC_5677_4DF0_BC94_E9BBF225D8C6__INCLUDED_)
