========================================================================
       MICROSOFT FOUNDATION CLASS BIBLIOTHEK : GK
========================================================================


Diese GK-Anwendung hat der Klassen-Assistent für Sie erstellt. Diese Anwendung
zeigt nicht nur die prinzipielle Verwendung der Microsoft Foundation Classes, 
sondern dient auch als Ausgangspunkt für die Erstellung Ihrer eigenen DLLs.

Diese Datei enthält die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre GK-Anwendung bilden.

GK.dsp
    Diese Datei (Projektdatei) enthält Informationen auf Projektebene und wird zur
    Erstellung eines einzelnen Projekts oder Teilprojekts verwendet. Andere Benutzer können
    die Projektdatei (.dsp) gemeinsam nutzen, sollten aber die Makefiles lokal exportieren.

GK.h
    Hierbei handelt es sich um die Haupt-Header-Datei der Anwendung. Diese enthält 
	andere projektspezifische Header (einschließlich Resource.h) und deklariert die
	Anwendungsklasse CGKApp.

GK.cpp
    Hierbei handelt es sich um die Haupt-Quellcodedatei der Anwendung. Diese enthält die
    Anwendungsklasse CGKApp.

GK.rc
	Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
	vom Programm verwendet werden. Sie enthält die Symbole, Bitmaps und Cursors, die im 
	Unterverzeichnis RES abgelegt sind. Diese Datei lässt sich direkt in Microsoft
	Visual C++ bearbeiten.

GK.clw
    Diese Datei enthält Informationen, die vom Klassen-Assistenten verwendet wird, um bestehende
    Klassen zu bearbeiten oder neue hinzuzufügen.  Der Klassen-Assistent verwendet diese Datei auch,
    um Informationen zu speichern, die zum Erstellen und Bearbeiten von Nachrichtentabellen und
    Dialogdatentabellen benötigt werden und um Prototyp-Member-Funktionen zu erstellen.

res\GK.ico
    Dies ist eine Symboldatei, die als Symbol für die Anwendung verwendet wird. Dieses 
	Symbol wird durch die Haupt-Ressourcendatei GK.rc eingebunden.

res\GK.rc2
    Diese Datei enthält Ressourcen, die nicht von Microsoft Visual C++ bearbeitet wurden.
	In diese Datei werden alle Ressourcen abgelegt, die vom Ressourcen-Editor nicht bearbeitet 
	werden können.

GK.reg
    	Dies ist eine .REG-Beispieldatei, die Ihnen anzeigt, welche Registrierungseinstellungen 
	durch die Programmumgebung festlegt werden. Diese können Sie als .REG-
    	-Datei für Ihre Anwendung festlegen, oder diese löschen und die Standardregistrierung 
	RegisterShellFileTypes verwenden.



/////////////////////////////////////////////////////////////////////////////

Für das Hauptfenster:

MainFrm.h, MainFrm.cpp
    	Diese Dateien enthalten die Frame-Klasse CMainFrame, die von
    	CMDIFrameWnd abgeleitet wurde und alle MDI-Frame-Merkmale steuert.

res\Toolbar.bmp
    Diese Bitmap-Datei wird zum Erstellen unterteilter Bilder für die Symbolleiste verwendet.
    Die erste Symbol- und Statusleiste wird in der Klasse CMainFrame erstellt.
    Bearbeiten Sie diese Bitmap der Symbolleiste mit dem Ressourcen-Editor, und
    aktualisieren Sie IDR_MAINFRAME TOOLBAR in GK.rc, um Schaltflächen für die
    Symbolleiste hinzuzufügen.
/////////////////////////////////////////////////////////////////////////////

Für das untergeordnete Rahmenfenster:

ChildFrm.h, ChildFrm.cpp
    Diese Dateien definieren und implementieren die Klasse CChildFrame, die
    die untergeordneten Fenster in einer MDI-Anwendung unterstützt.

/////////////////////////////////////////////////////////////////////////////

Der Klassen-Assistent erstellt einen Dokumenttyp und eine Ansicht(View):

GKDoc.h, GKDoc.cpp - das Dokument
    	Diese Dateien enthalten die Klasse CGKDoc. Bearbeiten Sie diese Dateien,
  	um Ihre speziellen Dokumentdaten hinzuzufügen und das Speichern und Laden von 
	Dateien zu implementieren (mit Hilfe von CGKDoc::Serialize).

GKView.h, GKView.cpp - die Ansicht des Dokuments
    	Diese Dateien enthalten die Klasse CGKView.
    	CGKView-Objekte werden verwendet, um CGKDoc-Objekte anzuzeigen.

res\GKDoc.ico
    	Dies ist eine Symboldatei, die als Symbol für untergeordnete MDI-Fenster 
	der Klasse CGKDoc verwendet wird. Dieses Symbol wird durch die
	Haupt-Ressourcendatei GK.rc eingebunden.

/////////////////////////////////////////////////////////////////////////////

Darüber hinaus hat der Klassen-Assistent OLE-spezifische Klassen erzeugt.

CntrItem.h, CntrItem.cpp - diese Klasse wird zum Ändern von
	OLE-Objekten verwendet.  OLE-Objekte werden normalerweise von der Klasse
	CGKView angezeigt und als Teil der Klasse CGKDoc initialisiert.

/////////////////////////////////////////////////////////////////////////////

Hilfe-Unterstützung:

GK.hpj
    	Diese Datei ist die Hilfe-Projektdatei, die der Hilfe-Compiler für das 
	Erstellen der Hilfedatei Ihrer Anwendung verwendet.

hlp\*.bmp
    	Hierbei handelt es sich um Bitmap-Dateien, die für die Hilfethemen der 
	Standardbefehle der Microsoft Foundation Classes-Bibliothek erforderlich
	sind.

hlp\*.rtf
    	Diese Datei enthält die Hilfethemen für Standard-MFC-Befehle und 
    	Oberflächenobjekte.

/////////////////////////////////////////////////////////////////////////////
Andere Standarddateien:

StdAfx.h, StdAfx.cpp
    	Mit diesen Dateien werden vorkompilierte Header-Dateien (PCH) mit der Bezeichnung 
	GK.pch und eine vorkompilierte Typdatei mit der Bezeichnung StdAfx.obj
	erstellt.

Resource.h
    	Dies ist die Standard-Header-Datei, die neue Ressourcen-IDs definiert.
    	Microsoft Visual C++ liest und aktualisiert diese Datei.

/////////////////////////////////////////////////////////////////////////////
Weitere Hinweise:

Der Klassen-Assistent fügt "ZU ERLEDIGEN:" im Quellcode ein, um die Stellen anzuzeigen, 
an denen Sie Erweiterungen oder Anpassungen vornehmen können.

Wenn Ihre Anwendung die MFC in einer gemeinsam genutzten DLL verwendet und Ihre Anwendung
eine andere als die aktuell auf dem Betriebssystem eingestellte Sprache verwendet, muss 
die entsprechend lokalisierte Ressource MFC42XXX.DLL von der Microsoft Visual C++ CD-ROM 
in das Verzeichnis system oder system32 kopiert und in MFCLOC.DLL umbenannt werden ("XXX" 
steht für die Abkürzung der Sprache. So enthält beispielsweise MFC42DEU.DLL die ins Deutsche 
übersetzten Ressourcen). Anderenfalls erscheinen einige Oberflächenelemente Ihrer Anwendung 
in der Sprache des Betriebssystems.

/////////////////////////////////////////////////////////////////////////////
