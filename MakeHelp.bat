@echo off
REM -- Zuerst Zuordnungsdatei der mit Microsoft Visual C++ erzeugten resource.h erstellen
echo // Von MAKEHELP.BAT erzeugte Hilfe-Zuordnungsdatei. Wird verwendet von GK.HPJ. >"hlp\GK.hm"
echo. >>"hlp\GK.hm"
echo // Befehle (ID_* und IDM_*) >>"hlp\GK.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\GK.hm"
echo. >>"hlp\GK.hm"
echo // Eingabeaufforderungen (IDP_*) >>"hlp\GK.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\GK.hm"
echo. >>"hlp\GK.hm"
echo // Ressourcen (IDR_*) >>"hlp\GK.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\GK.hm"
echo. >>"hlp\GK.hm"
echo // Dialogfelder (IDD_*) >>"hlp\GK.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\GK.hm"
echo. >>"hlp\GK.hm"
echo // Rahmen-Steuerelemente (IDW_*) >>"hlp\GK.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\GK.hm"
REM -- Hilfe erstellen für Projekt GK


echo Erstelle Win32-Hilfedateien
start /wait hcw /C /E /M "hlp\GK.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\GK.hlp" goto :Error
if not exist "hlp\GK.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\GK.hlp" Debug
if exist Debug\nul copy "hlp\GK.cnt" Debug
if exist Release\nul copy "hlp\GK.hlp" Release
if exist Release\nul copy "hlp\GK.cnt" Release
echo.
goto :done

:Error
echo hlp\GK.hpj(1) : Fehler: Problem beim Erstellen der Hilfedatei festgestellt

:done
echo.
