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
	// ZU ERLEDIGEN: Hier Code für One-Time-Konstruktion einfügen
	
}

CGKCntrItem::~CGKCntrItem()
{
	// ZU ERLEDIGEN: Hier Bereinigungscode hinzufügen
	
}

void CGKCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleDocObjectItem::OnChange(nCode, dwParam);

	// Wird ein Element bearbeitet (entweder direkt oder voll geöffnet),
	//  sendet es OnChange-Benachrichtigungen für Änderungen im Status des
	//  Elements oder im visuellen Erscheinungsbild seines Inhalts.

	// ZU ERLEDIGEN: Element ungültig machen, indem Sie UpdateAllViews aufrufen
	//  (mit auf Ihre Anwendung zugeschnittenen Tips)

	GetDocument()->UpdateAllViews(NULL);
		// im Moment aktualisieren Sie einfach ALLE Ansichten/keine Tips
}

BOOL CGKCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// Während einer direkten Aktivierung wird CGKCntrItem::OnChangeItemPosition
	//  vom Server aufgerufen, um die Position des In-Place-Fensters 
	//  zu ändern. Üblicherweise ist dies ein Ergebnis von Datenänderungen 
	//  im Server-Dokument, etwa ein geändertes Extent oder als Ergebnis
	//  direkter Größenänderungen.
	//
	// Standardmäßig wird hier die Basisklasse aufgerufen, die wiederum 
	//  COleDocObjectItem::SetItemRects zum Bewegen des Elements
	//  an die neue Position aufruft.

	if (!COleDocObjectItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// ZU ERLEDIGEN: Aktualisieren Sie alle für das Rechteck/das Extent dieses Elements angelegten Caches

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
	// Da dies den von CGKCntrItem::GetDocument zurückgegebenen
	//  m_pDocument-Zeiger einrichtet, es ist ratsam, zuerst die Basisklasse 
	//  Serialize aufzurufen.
	COleDocObjectItem::Serialize(ar);

	// jetzt die speziellen Daten für CGKCntrItem einlesen/speichern
	if (ar.IsStoring())
	{
		// ZU ERLEDIGEN: Hier Code zum Speichern einfügen
	}
	else
	{
		// ZU ERLEDIGEN: Hier Code zum Laden einfügen
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
