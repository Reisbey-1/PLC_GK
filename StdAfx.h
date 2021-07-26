// stdafx.h : Include-Datei für Standard-System-Include-Dateien,
//  oder projektspezifische Include-Dateien, die häufig benutzt, aber
//      in unregelmäßigen Abständen geändert werden.
//

#if !defined(AFX_STDAFX_H__43FD4A5B_6077_4160_9C2A_6B207DFE7E65__INCLUDED_)
#define AFX_STDAFX_H__43FD4A5B_6077_4160_9C2A_6B207DFE7E65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Selten verwendete Teile der Windows-Header nicht einbinden

#include <afxwin.h>         // MFC-Kern- und -Standardkomponenten
#include <afxext.h>         // MFC-Erweiterungen
#include <afxcview.h>
#include <afxole.h>         // MFC OLE-Klassen
#include <afxodlgs.h>       // MFC OLE-Dialogfeldklassen
#include <afxdisp.h>        // MFC Automatisierungsklassen
#include <afxdtctl.h>		// MFC-Unterstützung für allgemeine Steuerelemente von Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC-Unterstützung für gängige Windows-Steuerelemente
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "MdCommon.h"
using namespace MdCommon ;

#include "dvrdll.h"
using namespace dvr ;

#include "AlcoInclude.h"
using namespace alco ;

#include "BitmapLibInclude.h"
using namespace BitmapLib;
/**/

#include  "XmlDLLinclude.h"
using namespace XmlDll ;
/*


#include "LadderInclude.h"
using namespace LadderDll ;

//#include "comlib.h"

#import "../../bin/alco.tlb"   raw_interfaces_only, raw_native_types, named_guids// no_namespace
#import "../../bin/DPort.tlb"  raw_interfaces_only, raw_native_types, named_guids//, no_namespace
#import "../../bin/Dialogs.tlb"  raw_interfaces_only, raw_native_types, named_guids//, no_namespace
#import "../../bin/TelegramFabric.tlb"   raw_interfaces_only, raw_native_types,  named_guids , no_namespace




*/

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STDAFX_H__43FD4A5B_6077_4160_9C2A_6B207DFE7E65__INCLUDED_)
