// GKDoc.cpp : Implementierung der Klasse CGKDoc
//

#include "stdafx.h"
#include "GK.h"

#include "GKDoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGKDoc

IMPLEMENT_DYNCREATE(CGKDoc, COleDocument)

BEGIN_MESSAGE_MAP(CGKDoc, COleDocument)
	//{{AFX_MSG_MAP(CGKDoc)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
	// Zulassen der Standardimplementierung für OLE-Container
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGKDoc Konstruktion/Destruktion

CGKDoc::CGKDoc()
{
	// Verwenden Sie OLE-Compound-Dateien
	EnableCompoundFile();

	// ZU ERLEDIGEN: Hier Code für One-Time-Konstruktion einfügen

}

CGKDoc::~CGKDoc()
{
}

BOOL CGKDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGKDoc Serialisierung

void CGKDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// ZU ERLEDIGEN: Hier Code zum Speichern einfügen
	}
	else
	{
		// ZU ERLEDIGEN: Hier Code zum Laden einfügen
	}

	// Ein Aufruf der Basisklasse COleDocument ermöglicht die Serialisierung
	//  des Objekts COleClientItem des Container-Dokuments.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CGKDoc Diagnose

#ifdef _DEBUG
void CGKDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CGKDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGKDoc Befehle
