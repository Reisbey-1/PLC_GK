// CntrItem.cpp : Implementierung der Klasse CGKCntrItem
//

#include "stdafx.h"
#include "GK.h"

#include "GKDoc.h"
#include "GKView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGKCntrItem Implementierung

IMPLEMENT_SERIAL(CGKCntrItem, COleDocObjectItem, 0)

CGKCntrItem::CGKCntrItem(CGKDoc* pContainer)
	: COleDocObjectItem(pContainer)
{
	// ZU ERLEDIGEN: Hier Code f�r One-Time-Konstruktion einf�gen
	
}

CGKCntrItem::~CGKCntrItem()
{
	// ZU ERLEDIGEN: Hier Bereinigungscode hinzuf�gen
	
}

void CGKCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleDocObjectItem::OnChange(nCode, dwParam);

	// Wird ein Element bearbeitet (entweder direkt oder voll ge�ffnet),
	//  sendet es OnChange-Benachrichtigungen f�r �nderungen im Status des
	//  Elements oder im visuellen Erscheinungsbild seines Inhalts.

	// ZU ERLEDIGEN: Element ung�ltig machen, indem Sie UpdateAllViews aufrufen
	//  (mit auf Ihre Anwendung zugeschnittenen Tips)

	GetDocument()->UpdateAllViews(NULL);
		// im Moment aktualisieren Sie einfach ALLE Ansichten/keine Tips
}

BOOL CGKCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// W�hrend einer direkten Aktivierung wird CGKCntrItem::OnChangeItemPosition
	//  vom Server aufgerufen, um die Position des In-Place-Fensters 
	//  zu �ndern. �blicherweise ist dies ein Ergebnis von Daten�nderungen 
	//  im Server-Dokument, etwa ein ge�ndertes Extent oder als Ergebnis
	//  direkter Gr��en�nderungen.
	//
	// Standardm��ig wird hier die Basisklasse aufgerufen, die wiederum 
	//  COleDocObjectItem::SetItemRects zum Bewegen des Elements
	//  an die neue Position aufruft.

	if (!COleDocObjectItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// ZU ERLEDIGEN: Aktualisieren Sie alle f�r das Rechteck/das Extent dieses Elements angelegten Caches

	return TRUE;
}


void CGKCntrItem::OnActivate()
{
}

void CGKCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleDocObjectItem::OnDeactivateUI(bUndoable);

    // Objekt ausblenden, wenn es kein Outside-In-Objekt ist
    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CGKCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Vor dem Lesen von Daten aus COleDocObjectItem zuerst Basisklasse aufrufen.
	// Da dies den von CGKCntrItem::GetDocument zur�ckgegebenen
	//  m_pDocument-Zeiger einrichtet, es ist ratsam, zuerst die Basisklasse 
	//  Serialize aufzurufen.
	COleDocObjectItem::Serialize(ar);

	// jetzt die speziellen Daten f�r CGKCntrItem einlesen/speichern
	if (ar.IsStoring())
	{
		// ZU ERLEDIGEN: Hier Code zum Speichern einf�gen
	}
	else
	{
		// ZU ERLEDIGEN: Hier Code zum Laden einf�gen
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGKCntrItem Diagnose

#ifdef _DEBUG
void CGKCntrItem::AssertValid() const
{
	COleDocObjectItem::AssertValid();
}

void CGKCntrItem::Dump(CDumpContext& dc) const
{
	COleDocObjectItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
