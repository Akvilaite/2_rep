; ============================================
; Inno Setup Script
; Studentų Valdymo Sistema v3.0
; ============================================

#define MyAppName "Studentu Valdymo Sistema"
#define MyAppVersion "3.0"
#define MyAppPublisher "Vilniaus Universitetas"
#define MyAppExeName "programa.exe"
#define MyAppVardas "AkvileBeinoriute"  ;

[Setup]
; Pagrindiniai nustatymai
AppId={{A1B2C3D4-E5F6-7890-ABCD-123456789ABC}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={commonpf}\VU\{#MyAppVardas}
DefaultGroupName=VU\{#MyAppVardas}
OutputDir=installer
OutputBaseFilename=StudentuSistema_v3.0_Setup
SetupIconFile=icon.ico
Compression=lzma2
SolidCompression=yes
PrivilegesRequired=admin
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64

; Licencija ir informacija
LicenseFile=LICENSE.txt
InfoBeforeFile=INSTALL_INFO.txt
InfoAfterFile=README.txt

; Išvaizda
WizardStyle=modern
DisableProgramGroupPage=yes
DisableWelcomePage=no

; Uninstaller
UninstallDisplayIcon={app}\{#MyAppExeName}
UninstallDisplayName={#MyAppName} v{#MyAppVersion}

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
; Pagrindiniai programos failai
Source: "build\Release\programa.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "build\Release\StudentuDLL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "README.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "LICENSE.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "NAUDOJIMOSI_INSTRUKCIJA.txt"; DestDir: "{app}"; Flags: ignoreversion

; Pavyzdiniai duomenų failai
Source: "data\*.txt"; DestDir: "{app}\data"; Flags: ignoreversion recursesubdirs createallsubdirs

; Dokumentacija (HTML)
Source: "doxygen\html\*"; DestDir: "{app}\docs"; Flags: ignoreversion recursesubdirs createallsubdirs

; Visual C++ Runtime (jei reikia)
Source: "redist\vc_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Icons]
; Start Menu nuorodos
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"; IconFilename: "{app}\{#MyAppExeName}"; Comment: "Paleisti {#MyAppName}"; Flags: runasadmin
Name: "{group}\Dokumentacija"; Filename: "{app}\docs\index.html"; Comment: "Programos dokumentacija"
Name: "{group}\Naudojimosi instrukcija"; Filename: "{app}\NAUDOJIMOSI_INSTRUKCIJA.txt"
Name: "{group}\README"; Filename: "{app}\README.txt"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"

; Desktop nuoroda (jei vartotojas pasirinko)
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon; WorkingDir: "{app}"; Flags: runasadmin

; Quick Launch nuoroda
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon; WorkingDir: "{app}"; Flags: runasadmin

[Run]
; Įdiegti Visual C++ Runtime (jei reikia)
Filename: "{tmp}\vc_redist.x64.exe"; Parameters: "/quiet /norestart"; StatusMsg: "Diegiama Visual C++ Runtime..."; Check: VCRedistNeedsInstall

; Pasiūlyti paleisti programą po įdiegimo
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent runasadmin

[Code]
function VCRedistNeedsInstall: Boolean;
var
  Version: String;
begin
  // Patikrinti ar VC++ Runtime jau įdiegtas
  if RegQueryStringValue(HKEY_LOCAL_MACHINE,
    'SOFTWARE\Microsoft\VisualStudio\14.0\VC\Runtimes\x64', 'Version', Version) then
    Result := False
  else
    Result := True;
end;

procedure CurStepChanged(CurStep: TSetupStep);
begin
  if CurStep = ssPostInstall then
  begin
    // Sukurti darbo katalogą rezultatams
    ForceDirectories(ExpandConstant('{app}\output'));
    
    // Nustatyti teises
    // Exec('icacls', ExpandConstant('"{app}" /grant Users:(OI)(CI)F /T'), '', SW_HIDE, ewWaitUntilTerminated, ResultCode);
  end;
end;

[UninstallDelete]
Type: filesandordirs; Name: "{app}\output"
Type: files; Name: "{app}\*.txt"

[Registry]
; Pridėti į PATH (pasirinktinai)
Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; ValueType: expandsz; ValueName: "Path"; ValueData: "{olddata};{app}"; Check: NeedsAddPath('{app}')

[Code]
function NeedsAddPath(Param: string): boolean;
var
  OrigPath: string;
begin
  if not RegQueryStringValue(HKEY_LOCAL_MACHINE,
    'SYSTEM\CurrentControlSet\Control\Session Manager\Environment',
    'Path', OrigPath)
  then begin
    Result := True;
    exit;
  end;
  Result := Pos(';' + Param + ';', ';' + OrigPath + ';') = 0;
end;