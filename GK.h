// GK.h : Haupt-Header-Datei f�r die Anwendung GK
//

#if !defined(AFX_GK_H__1EB73DF0_8461_4D68_A428_A29372FBCC8F__INCLUDED_)
#define AFX_GK_H__1EB73DF0_8461_4D68_A428_A29372FBCC8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CGKApp:
// Siehe GK.cpp f�r die Implementierung dieser Klasse
//

class CGKApp : public CWinApp
{
public:
	CGKApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CGKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	//{{AFX_MSG(CGKApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_GK_H__1EB73DF0_8461_4D68_A428_A29372FBCC8F__INCLUDED_)
