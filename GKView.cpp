// GKView.cpp : Implementierung der Klasse CGKView
//

#include "stdafx.h"
#include "GK.h"

#include "GKDoc.h"
#include "CntrItem.h"
#include "GKView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGKView

IMPLEMENT_DYNCREATE(CGKView, CListView)

BEGIN_MESSAGE_MAP(CGKView, CListView)
	//{{AFX_MSG_MAP(CGKView)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGKView Konstruktion/Destruktion

CGKView::CGKView()
{
	m_pSelection = NULL;
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CGKView::~CGKView()
{
}

BOOL CGKView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGKView Zeichnen

void CGKView::OnDraw(CDC* pDC)
{
	CGKDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");
	// ZU ERLEDIGEN: Hier Code zum Zeichnen der ursprünglichen Daten hinzufügen
}

void CGKView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// ZU ERLEDIGEN: Sie können Elemente in Ihre ListView eintragen, indem Sie direkt 
	//  über einen Aufruf von GetListCtrl() auf ihre Listensteuerung zugreifen.

	// ZU ERLEDIGEN: Entfernen Sie diesen Code, sobald der endgültige Code für das Auswahlmodell geschrieben ist
	m_pSelection = NULL;    // Auswahl initialisieren

	//Active documents should always be activated
	COleDocument* pDoc = (COleDocument*) GetDocument();
	if (pDoc != NULL)
	{
		// activate the first one
		POSITION posItem = pDoc->GetStartPosition();
		if (posItem != NULL)
		{
			CDocItem* pItem = pDoc->GetNextItem(posItem);

			// only if it's an Active document
			COleDocObjectItem *pDocObjectItem =
				DYNAMIC_DOWNCAST(COleDocObjectItem, pItem);

			if (pDocObjectItem != NULL)
			{
				pDocObjectItem->DoVerb(OLEIVERB_SHOW, this);
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGKView Drucken

BOOL CGKView::OnPreparePrinting(CPrintInfo* pInfo)
{
	if (!CView::DoPreparePrinting(pInfo))
		return FALSE;
	
	if (!COleDocObjectItem::OnPreparePrinting(this, pInfo))
		return FALSE;

	return TRUE;
}

void CGKView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CGKView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einfügen
}

void CGKView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// ZU ERLEDIGEN: Benutzerdefinierten Code zum Ausdrucken hier einfügen
	if(pInfo->m_bDocObject)
		COleDocObjectItem::OnPrint(this, pInfo, TRUE);
	else
		CView::OnPrint(pDC, pInfo);
}

void CGKView::OnDestroy()
{
	// Das Element bei Destruktion deaktivieren; dies ist wichtig,
	// wenn eine Teilansicht (Splitter View) verwendet wird.
   CListView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE-Client-Unterstützung und -Befehle

BOOL CGKView::IsSelected(const CObject* pDocItem) const
{
	// Die nachfolgende Implementierung ist angemessen, wenn sich Ihre Auswahl nur aus
	//  CGKCntrItem-Objekten zusammensetzt. Zur Bearbeitung unterschiedlicher 
	//  Auswahlmechanismen sollte die hier gegebene Implementierung ersetzt werden.

	// ZU ERLEDIGEN: Implementieren Sie diese Funktion, die auf ein ausgewähltes OLE-Client-Element testet

	return pDocItem == m_pSelection;
}

void CGKView::OnInsertObject()
{
	// Standarddialogfeld zum Einfügen von Objekten aufrufen, um Infos abzufragen
	//  für neues CGKCntrItem-Objekt.
	COleInsertDialog dlg;
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;

	BeginWaitCursor();

	CGKCntrItem* pItem = NULL;
	TRY
	{
		// Neues, mit diesem Dokument verbundenes Element erzeugen.
		CGKDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CGKCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Element mit Dialogfelddaten initialisieren.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // Beliebige Ausnahme erzeugen
		ASSERT_VALID(pItem);

		pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// Die Größe wird hier willkürlich auf die Größe
		//  des zuletzt eingefügten Elements gesetzt.

		// ZU ERLEDIGEN: Implementieren Sie die Auswahl erneut in einer für Ihre Anwendung geeigneten Weise

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// Der folgende Befehls-Handler stellt die Standardtastatur als
//  Benutzerschnittstelle zum Abbruch der direkten Bearbeitungssitzung zur Verfügung. Hier
//  verursacht der Container (nicht der Server) die Deaktivierung.
void CGKView::OnCancelEditCntr()
{
	// Schließen aller direkt aktiven Elemente dieser Ansicht.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Für einen Container müssen OnSetFocus und OnSize speziell gehandhabt werden,
//  wenn ein Objekt direkt bearbeitet wird.
void CGKView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// dieses Element muss den Fokus erhalten, wenn es sich in der gleichen Ansicht befindet
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // kein Aufruf der Basisklasse
			return;
		}
	}

	CListView::OnSetFocus(pOldWnd);
}

void CGKView::OnSize(UINT nType, int cx, int cy)
{
	CListView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CGKView Diagnose

#ifdef _DEBUG
void CGKView::AssertValid() const
{
	CListView::AssertValid();
}

void CGKView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CGKDoc* CGKView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGKDoc)));
	return (CGKDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGKView Nachrichten-Handler
void CGKView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//ZU ERLEDIGEN: Code hinzufügen, der auf die Änderung des Benutzers des Ansichtsformats Ihres Fensters reagiert
}
