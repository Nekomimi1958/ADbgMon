//----------------------------------------------------------------------//
// Auto Debug Monitor													//
//																		//
//----------------------------------------------------------------------//
#include "usr_env.h"
#include "usr_str.h"
#include "usr_ctrl.h"
#include "usr_file_ex.h"
#include "usr_misc.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TADbgMonFrm *ADbgMonFrm;

//---------------------------------------------------------------------------
__fastcall TADbgMonFrm::TADbgMonFrm(TComponent *Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FormCreate(TObject *Sender)
{
	Watching   = false;
	Monitoring    = false;
	Capturing  = false;

	TargetPID  = 0;
	TargetHWnd = NULL;

	LastTopIndex = -1;
	LogBuffer1 = new TStringList();

	crTarget = (TCursor)6;
	Screen->Cursors[crTarget] = (HCURSOR)::LoadImage(HInstance, _T("TARGET_TOOL"), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE);

	Caption = "Auto Debug Monitor - V" + get_version_str();

	IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FormShow(TObject *Sender)
{
	load_form_pos(this, IniFile, 680, 500);

	UnicodeString sct = "General";
	MatchPanel1->Height = IniFile->ReadInteger(sct, "MatchList1Height",	150);

	sct = "Option";
	TimeRadioGroup->ItemIndex = IniFile->ReadInteger(sct, "TimeMode",	0);
	TopMostAction->Checked = IniFile->ReadBool(sct, "TopMost", false);
	set_TopMost(this, TopMostAction->Checked);
	TransBar->Position = IniFile->ReadInteger(sct, "AlphaBlend",	255);
	ClassEdit1->Text   = IniFile->ReadString( sct, "LastClass",		EmptyStr);
	TextEdit1->Text    = IniFile->ReadString( sct, "LastText",		EmptyStr);
	Em1Edit->Text      = IniFile->ReadString( sct, "EmMatchStr1",	EmptyStr);
	Em2Edit->Text      = IniFile->ReadString( sct, "EmMatchStr2",	EmptyStr);
	Em3Edit->Text      = IniFile->ReadString( sct, "EmMatchStr3",	EmptyStr);
	Em4Edit->Text      = IniFile->ReadString( sct, "EmMatchStr4",	EmptyStr);
	ExlcudeEdit->Text  = IniFile->ReadString( sct, "ExcludePtn",	"recv msg;attach;detach");
	DeltaEdit->Text    = IniFile->ReadString( sct, "SeparateDelta",	"1000");

	SndMatchEdit->Text = IniFile->ReadString( sct, "SoundMatched",	EmptyStr);
	SndMatchEdit->Hint = SndMatchEdit->Text;
	SndFoundEdit->Text = IniFile->ReadString( sct, "SoundFound",	EmptyStr);
	SndFoundEdit->Hint = SndFoundEdit->Text;
	SndLostEdit->Text  = IniFile->ReadString( sct, "SoundLost",		EmptyStr);
	SndLostEdit->Hint  = SndLostEdit->Text;

	sct = "Color";
	col_fgEm1  = (TColor)IniFile->ReadInteger(sct, "fgEm1",	0x33cc33);
	col_fgEm2  = (TColor)IniFile->ReadInteger(sct, "fgEm2",	0x999999);
	col_fgEm3  = (TColor)IniFile->ReadInteger(sct, "fgEm3",	0x993333);
	col_fgEm4  = (TColor)IniFile->ReadInteger(sct, "fgEm4",	0x333399);
	col_fgMark = (TColor)IniFile->ReadInteger(sct, "fgMark",0xcc33cc);

	ColorListBox->Items->Text =
		"Highlight Color 1\r\n"
		"Highlight Color 2\r\n"
		"Highlight Color 3\r\n"
		"Highlight Color 4\r\n"
		"Matched Line\r\n";

	load_ComboBoxItems(MatchComboBox1,	IniFile, "MatchHistory1",	20);
	if (MatchComboBox1->Items->Count>0) MatchComboBox1->ItemIndex = 0;

	VirtualImageList2->GetBitmap(0, CapToolImage1->Picture->Bitmap);
	CapToolImage1->Repaint();

	UnicodeString ptn_hint = "Specify multiple by separating with ';' (/re/)";
	ExlcudeEdit->Hint    = ptn_hint;
	MatchComboBox1->Hint = ptn_hint;
	PtnGroupBox->Hint    = ptn_hint;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (Monitoring) {
		Watching = Monitoring = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (!OpePanel->Visible) ShowOpePanelAction->Execute();

	save_form_pos(this, IniFile);

	UnicodeString sct = "General";
	IniFile->WriteInteger(sct, "MatchList1Height",	MatchPanel1->Height);

	sct = "Option";
	IniFile->WriteInteger(sct, "TimeMode",		TimeRadioGroup->ItemIndex);
	IniFile->WriteBool(   sct, "TopMost",		TopMostAction->Checked);
	IniFile->WriteInteger(sct, "AlphaBlend",	TransBar->Position);
	IniFile->WriteString( sct, "LastClass",		ClassEdit1->Text);
	IniFile->WriteString( sct, "LastText",		TextEdit1->Text);
	IniFile->WriteString( sct, "EmMatchStr1",	Em1Edit->Text);
	IniFile->WriteString( sct, "EmMatchStr2",	Em2Edit->Text);
	IniFile->WriteString( sct, "EmMatchStr3",	Em3Edit->Text);
	IniFile->WriteString( sct, "EmMatchStr4",	Em4Edit->Text);
	IniFile->WriteString( sct, "ExcludePtn",	ExlcudeEdit->Text);
	IniFile->WriteString( sct, "SeparateDelta",	DeltaEdit->Text);
	IniFile->WriteString( sct, "SoundMatched",	SndMatchEdit->Text);
	IniFile->WriteString(  sct, "SoundFound",	SndFoundEdit->Text);
	IniFile->WriteString(  sct, "SoundLost",	SndLostEdit->Text);

	sct = "Color";
	IniFile->WriteInteger(sct, "fgEm1",		(int)col_fgEm1);
	IniFile->WriteInteger(sct, "fgEm2",		(int)col_fgEm2);
	IniFile->WriteInteger(sct, "fgEm3",		(int)col_fgEm3);
	IniFile->WriteInteger(sct, "fgEm4",		(int)col_fgEm4);
	IniFile->WriteInteger(sct, "fgMark",	(int)col_fgMark);

	save_ComboBoxItems(MatchComboBox1,	IniFile, "MatchHistory1",	20);
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FormDestroy(TObject *Sender)
{
	delete LogBuffer1;
	delete IniFile;
}

//---------------------------------------------------------------------------
//タイマー処理	(Interval = 250ms)
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;

	if (Watching) {
		std::unique_ptr<TList> hlst(new TList());
		if (!Monitoring && GetHwndList(ClassEdit1->Text, TextEdit1->Text, hlst.get())) {
			PrepareTarget((HWND)hlst->Items[0]);
			StartAction->Execute();
		}
	}

	//対象ウィンドウの取得
	if (Capturing) {
		HWND hWnd = GetTopWindow(NULL);
		do {
			if (GetWindowLong(hWnd, GWL_HWNDPARENT)!=0 || !IsWindowVisible(hWnd)) continue;
			TRect rc;
			GetWindowRect(hWnd, &rc);
			if (rc.PtInRect(Mouse->CursorPos)) {
				ClassEdit1->Text = get_ClassName(hWnd);
				TextEdit1->Text  = get_WindowText(hWnd);
				PrepareTarget(hWnd);
				break;
			}
		} while (hWnd = GetNextWindow(hWnd, GW_HWNDNEXT));
	}

	SetEditColor(PidEdit1);
	SetEditColor(HWndEdit1);

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
//プロセス指定情報をクリア
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ClearID()
{
	TargetPID      = 0;
	TargetHWnd     = NULL;
	TTargetFname    = EmptyStr;
	PidEdit1->Text  = EmptyStr;
	HWndEdit1->Text = EmptyStr;
	SetEditColor(PidEdit1);
	SetEditColor(HWndEdit1);
	GroupBox1->Caption = get_tkn(GroupBox1->Caption, " -");
}
//---------------------------------------------------------------------------
//ハンドルから対象プロセスを準備
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::PrepareTarget(HWND hWnd)
{
	if (hWnd) {
		DWORD pid;
		DWORD tid = ::GetWindowThreadProcessId(hWnd, &pid);
		PidEdit1->Text  = pid;
		HWndEdit1->Text = (NativeInt)hWnd;

		HANDLE hProc = ::OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
		if (hProc) {
			_TCHAR sbuf[MAX_PATH];
			DWORD sz = MAX_PATH;
			UnicodeString fnam = ::QueryFullProcessImageName(hProc, 0, sbuf, &sz)? sbuf : _T("");
			TTargetFname = fnam;
			TGroupBox *gp = GroupBox1;
			UnicodeString s = get_tkn(gp->Caption, " -");
			gp->Caption = s.cat_sprintf(_T(" - %s"), ExtractFileName(fnam).c_str());
		}

		SetEditColor(PidEdit1);
		SetEditColor(HWndEdit1);
	}
	else {
		ClearID();
	}
}

//---------------------------------------------------------------------------
//プロセスの監視
//---------------------------------------------------------------------------
bool __fastcall TADbgMonFrm::WaitOutputDebugStr(DWORD pid, HWND hWnd)
{
	if (pid==0) return false;

	try {
		TargetPID  = pid;
		TargetHWnd = hWnd;
		Monitoring  = true;
		SetEditColor(PidEdit1);
		SetEditColor(HWndEdit1);

		if (TargetPID!=0) AddLog(">>> Found - " + ExtractFileName(TTargetFname), Now(), 1);
		UpdateActions();

		SECURITY_ATTRIBUTES sa;
		SECURITY_DESCRIPTOR sd;
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.bInheritHandle = TRUE;
		sa.lpSecurityDescriptor = &sd;

		if (!InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION))
			throw EAbort("Failed : InitializeSecurityDescriptor");
		if (!SetSecurityDescriptorDacl(&sd, TRUE, (PACL)NULL, FALSE))
			throw EAbort("Failed : SetSecurityDescriptorDacl");
		HANDLE hEvAck = CreateEvent(&sa, FALSE, FALSE, _T("DBWIN_BUFFER_READY"));
		if (!hEvAck) 	throw EAbort("Failed : CreateEvent - BUFFER_READY");
		HANDLE hEvReady = CreateEvent(&sa, FALSE, FALSE, _T("DBWIN_DATA_READY"));
		if (!hEvReady)	throw EAbort("Failed : CreateEvent - DATA_READY");
		HANDLE hMapFile = CreateFileMapping((HANDLE)0xFFFFFFFF, &sa, PAGE_READWRITE, 0, 4096, _T("DBWIN_BUFFER"));
		if (!hMapFile) 	throw EAbort("Failed : CreateFileMapping");
		LPVOID pMem = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 4096);
		if (!pMem) 		throw EAbort("Failed : MapViewOfFile");

		LPDWORD pPID = (LPDWORD)pMem;
		LPSTR pSTR = (LPSTR)(pPID + 1);
		UnicodeString msg;

		int last_cnt = GetTickCount();
		SetEvent(hEvAck);
		while (Monitoring && (TargetPID>0)) {
			Application->ProcessMessages();
			UpdateActions();

			switch (WaitForSingleObject(hEvReady, 100)) {
			case WAIT_OBJECT_0:
				msg = pSTR;
				msg = get_tkn(msg, "\r");
				if (!ptn_match_str(ExlcudeEdit->Text, msg).IsEmpty()) msg = EmptyStr;
				if (!msg.IsEmpty()) {
					TDateTime t = Now();
					if (TargetPID == *pPID) AddLog(msg, t);
				}
				if (TargetPID>0) SetEvent(hEvAck);
				break;

			case WAIT_FAILED:
				msgbox_ERR(SysErrorMessage(GetLastError()));
				Monitoring = false;
				break;
			}

			//プロセスの存在チェック
			HANDLE hProc = ::OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, TargetPID);
			if (hProc) {
			    DWORD dwExitCode;
				if (::GetExitCodeProcess(hProc, &dwExitCode)) {
					if (dwExitCode==STILL_ACTIVE) {
						if ((GetTickCount() - last_cnt) > 1000) {
							PROCESS_MEMORY_COUNTERS pmc = {0};
							if (::GetProcessMemoryInfo(hProc, &pmc, sizeof(pmc))) {
								StatusBar1->Panels->Items[0]->Text =
									"WS: " + get_size_str_K(pmc.WorkingSetSize) +
									" / PF: " + get_size_str_K(pmc.PagefileUsage);
							}
							last_cnt = GetTickCount();
						}
					}
					else {
						StatusBar1->Panels->Items[0]->Text = EmptyStr;
						AddLog("<<< Lost  - " + ExtractFileName(TTargetFname), Now(), 2);
						Monitoring = false;
						ClearID();
						play_sound(SndLostEdit->Text);
					}
				}
				else {
					msgbox_ERR(SysErrorMessage(GetLastError()));
					Monitoring = false;
				}
				::CloseHandle(hProc);
			}
		}

		::UnmapViewOfFile(pMem);
		::CloseHandle(hMapFile);
		::CloseHandle(hEvAck);
		::CloseHandle(hEvReady);

		if (!MatchComboBox1->Text.IsEmpty()) add_ComboBox_history(MatchComboBox1, MatchComboBox1->Text);

		Monitoring = false;
		return true;
	}
	catch (EAbort &e) {
		msgbox_ERR(e.Message);
		Monitoring = Watching = false;
		return false;
	}
	catch (...) {
		msgbox_ERR(SysErrorMessage(EVENT_E_INTERNALEXCEPTION));
		Monitoring = Watching = false;
		return false;
	}
}
//---------------------------------------------------------------------------
//ログの追加
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::AddLog(UnicodeString s, TDateTime t, int flag)
{
	UnicodeString lbuf = FormatDateTime("hh:nn:ss.zzz ", t) + s;
	LogBuffer1->AddObject(lbuf, (TObject*)flag);

	TListBox *lp  = LogListBox1;
	int  last_idx = lp->ItemIndex;
	int  last_top = lp->TopIndex;
	bool is_btm   = (last_idx == lp->Count - 1);

	LogListBox1->LockDrawing();
	lp->Count = LogBuffer1->Count;
	if (is_btm) {
		lp->ItemIndex = lp->Count - 1;
	}
	else {
		lp->ItemIndex = last_idx;
		lp->TopIndex  = last_top;
	}
	LogListBox1->UnlockDrawing();

	TopOfLog1Action->Update();
	EndOfLog1Action->Update();

	UnicodeString ptn = MatchComboBox1->Text;
	if (!ptn_match_str(ptn, s).IsEmpty()) play_sound(SndMatchEdit->Text);
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::CapToolImage1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (Button==mbLeft && !Watching && !Capturing) {
		Screen->Cursor = crTarget;
		TImage *ip = CapToolImage1;
		VirtualImageList2->GetBitmap(1, ip->Picture->Bitmap);
		ip->Repaint();
		Capturing  = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::CapToolImage1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (!Capturing) return;

	// マウス位置のウィンドウを取得
	if (Button == mbLeft) {
		Capturing = false;
		Screen->Cursor = crDefault;
		TImage *ip = CapToolImage1;
		VirtualImageList2->GetBitmap(0, ip->Picture->Bitmap);
		ip->Repaint();
	}
}
//---------------------------------------------------------------------------
// 検索
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FindActionExecute(TObject *Sender)
{
	std::unique_ptr<TList> hlst(new TList());
	if (GetHwndList(ClassEdit1->Text, TextEdit1->Text, hlst.get())) {
		PrepareTarget((HWND)hlst->Items[0]);
	}
	else {
		ClearID();
		::MessageBeep(MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::FindActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	ap->Enabled = !Watching;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TimeRadioGroupClick(TObject *Sender)
{
	LogListBox1->Repaint();
}

//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::LogListBoxData(TWinControl *Control, int Index, UnicodeString &Data)
{
	Data = LogBuffer1->Strings[Index];
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::LogListBoxDataObject(TWinControl *Control, int Index, TObject *&DataObject)
{
	DataObject = LogBuffer1->Objects[Index];
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::LogListBoxDrawItem(TWinControl *Control, int Index,
	TRect &Rect, TOwnerDrawState State)
{
	TListBox *lp = (TListBox *)Control;
	int flag = (int)lp->Items->Objects[Index];

	TCanvas  *cv = lp->Canvas;
	cv->Brush->Color = State.Contains(odSelected)? clHighlight :
										(flag==1)? clWebLightGreen :		//Found
										(flag==2)? clWebPink : clWindow;	//Lost
	cv->FillRect(Rect);

	UnicodeString lbuf = lp->Items->Strings[Index];
	int xp = Rect.Left + SCALED_THIS(2);

	cv->Font->Color = State.Contains(odSelected)? clHighlightText : clDkGray;
	UnicodeString ts  = get_tkn(lbuf, " ");
	UnicodeString ts0 = (Index>0)? get_tkn(lp->Items->Strings[Index - 1], " ") : ts;
	int   delta = MilliSecondsBetween(TTime(ts), TTime(ts0));
	bool add_sp = delta > DeltaEdit->Text.ToIntDef(0);

	if (TimeRadioGroup->ItemIndex==1 || TimeRadioGroup->ItemIndex==2) {
		//Time
		if (TimeRadioGroup->ItemIndex==2) {
			cv->TextOut(xp, Rect.Top, ts);
			xp += cv->TextWidth(ts + " ");
		}
		//Delta
		UnicodeString ds;
		try {
			ds.sprintf(_T("%7.3f"), delta/1000.0);
			if (ds.Length()>7) ds = ts.SubString(1, 7);
		}
		catch (...) {
			ds = "       ";
		}
		int dw = cv->TextWidth("999.999 ");
		cv->TextOut(xp + dw - cv->TextWidth(ds + " "), Rect.Top, ds);
		xp += dw;
	}
	else {
		//Time
		cv->TextOut(xp, Rect.Top, ts);
		xp += cv->TextWidth(ts + " ");
	}

	//Message
	UnicodeString s = get_tkn_r(lbuf, " ");
	cv->Font->Color = State.Contains(odSelected)? clHighlightText :
		!ptn_match_str(MatchComboBox1->Text, s).IsEmpty()? col_fgMark :
		!ptn_match_str(Em1Edit->Text, s).IsEmpty()? col_fgEm1 :
		!ptn_match_str(Em2Edit->Text, s).IsEmpty()? col_fgEm2 :
		!ptn_match_str(Em3Edit->Text, s).IsEmpty()? col_fgEm3 :
		!ptn_match_str(Em4Edit->Text, s).IsEmpty()? col_fgEm4 : clWindowText;
	cv->TextOut(xp, Rect.Top, s);

	//Saparate Line
	if (add_sp) {
		cv->Pen->Color = clDkGray;
		cv->Pen->Style = psSolid;
		cv->Pen->Width = 1;
		cv->MoveTo(Rect.Left, Rect.Top);
		cv->LineTo(Rect.Right + SCALED_THIS(1), Rect.Top);
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::LogListBox1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Shift.Contains(ssCtrl) && Key=='C') {
		TListBox *lp = LogListBox1;
		if (lp->SelCount>0) {
			std::unique_ptr<TStringList> sbuf(new TStringList());
			for (int i=0; i<lp->Count; i++) {
				if (lp->Selected[i]) sbuf->Add(lp->Items->Strings[i]);
			}
			lp->ClearSelection();
			Clipboard()->AsText = sbuf->Text;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::MatchListBoxClick(TObject *Sender)
{
	TListBox *mp = MatchListBox1;
	int idx = mp->ItemIndex;	if (idx==-1) return;
	UnicodeString s = mp->Items->Strings[idx];

	TListBox *lp = LogListBox1;
	for (int i=0; i<lp->Count; i++) {
		if (SameText(s, lp->Items->Strings[i])) {
			lp->ItemIndex = i;
			lp->TopIndex  = i - 4;
			break;
		}
	}
}
//---------------------------------------------------------------------------
//マーク行強調
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::MatchStrChange(TObject *Sender)
{
	LogListBox1->Invalidate();
}

//---------------------------------------------------------------------------
// 開始
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::StartWatchActionExecute(TObject *Sender)
{
	Watching = true;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::StartWatchActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	ap->Enabled = !Watching;
    RefSndFoundBtn->Enabled = !Watching;
    RefSndLostBtn->Enabled  = !Watching;
    RefSndWatchBtn->Enabled = !Watching;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::StartActionExecute(TObject *Sender)
{
	play_sound(SndFoundEdit->Text);
	WaitOutputDebugStr(PidEdit1->Text.ToIntDef(0), (HWND)HWndEdit1->Text.ToIntDef(0));
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::StartActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	ap->Enabled = !Monitoring;

	GroupBox1->Enabled = !Monitoring;

	SetEditColor(PidEdit1);
	SetEditColor(HWndEdit1);
}
//---------------------------------------------------------------------------
//停止
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::StopActionExecute(TObject *Sender)
{
	Monitoring = Watching = false;
	ClearID();
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::StopActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	ap->Enabled = Monitoring || Watching;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ShowOpePanelActionExecute(TObject *Sender)
{
    int w_wd = ClientWidth;
    int o_wd = OpePanel->Width;
    OpePanel->Visible = !OpePanel->Visible;
    if (OpePanel->Visible)
        ClientWidth += o_wd;
    else
        ClientWidth -= o_wd;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ShowOpePanelActionUpdate(TObject *Sender)
{
    OpePanelBtn->ImageIndex = OpePanel->Visible? 7 : 8;
}
//---------------------------------------------------------------------------
//アプリケーションを閉じる
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::CloseActionExecute(TObject *Sender)
{
	::PostMessage(TargetHWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
	ClearID();
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::CloseActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction*)Sender;
	ap->Enabled = (TargetPID > 0);
}
//---------------------------------------------------------------------------
//プロセスの強制終了
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TerminateActionExecute(TObject *Sender)
{
	HANDLE hProc = ::OpenProcess(PROCESS_TERMINATE, FALSE, TargetPID);
	if (hProc) {
		if (::TerminateProcess(hProc, 0)) {
			ClearID();
		}
		else {
			msgbox_ERR("Failed!");
		}
		::CloseHandle(hProc);
		UpdateActions();
	}
	else {
		msgbox_ERR(SysErrorMessage(GetLastError()));
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TerminateActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction*)Sender;
	ap->Enabled = (TargetPID > 0);
}

//---------------------------------------------------------------------------
// ログを保存
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::SaveLogActionExecute(TObject *Sender)
{
	SaveDialog1->Filter     = "ログ (*.log)|*.LOG";
	SaveDialog1->DefaultExt = "LOG";
	SaveDialog1->FileName   = FormatDateTime("yyyymmddhhnnss'_1.log'", Now());
	SaveDialog1->InitialDir = ExtractFileDir(Application->ExeName);
	SaveDialog1->Options.Clear();
	SaveDialog1->Options << ofOverwritePrompt;
	if (SaveDialog1->Execute()) {
		TStringList *sp = LogBuffer1;
		for (int i=0; i<sp->Count; i++) {
			UnicodeString lbuf = sp->Strings[i];
			UnicodeString ts   = get_tkn(lbuf, " ");
			UnicodeString ts0  = (i>0)? get_tkn(sp->Strings[i - 1], " ") : ts;
			UnicodeString ds;
			try {
				ds.sprintf(_T("%7.3f"), MilliSecondsBetween(TTime(ts), TTime(ts0))/1000.0);
				if (ds.Length()>7) ds = ds.SubString(1, 7);
			}
			catch (...) {
				ds = "       ";
			}
			sp->Strings[i] = ts + " " + ds + " " + get_tkn_r(lbuf, " ");
		}
		sp->SaveToFile(SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::SaveLogActionUpdate(TObject *Sender)
{
	((TAction *)Sender)->Enabled = !Monitoring && (LogListBox1->Count > 0);
}
//---------------------------------------------------------------------------
// ログをクリア
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ClearLogActionExecute(TObject *Sender)
{
	LogListBox1->Count = 0;
	LogBuffer1->Clear();
	MatchListBox1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ClearLogActionUpdate(TObject *Sender)
{
	((TAction *)Sender)->Enabled = (LogListBox1->Count > 0);
}
//---------------------------------------------------------------------------
//ログの先頭に移動
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TopOfLogActionExecute(TObject *Sender)
{
	LogListBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TopOfLogActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = (LogListBox1->Count>0);
}
//---------------------------------------------------------------------------
//ログの最後に移動
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::EndOfLogActionExecute(TObject *Sender)
{
	LogListBox1->ItemIndex = LogListBox1->Count - 1;
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::EndOfLogActionUpdate(TObject *Sender)
{
	TListBox *lp =LogListBox1;
	((TAction*)Sender)->Enabled = (lp->Count>1 && lp->ItemIndex<lp->Count-1);
}
//---------------------------------------------------------------------------
//マッチリストを更新
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ReMatchActionExecute(TObject *Sender)
{
	TComboBox *cp = MatchComboBox1;
	TStringList *sp = LogBuffer1;
	TListBox *mp = MatchListBox1;
	mp->Clear();
	for (int i=0; i<sp->Count; i++) {
		UnicodeString lbuf = sp->Strings[i];
		UnicodeString s = get_tkn_r(lbuf, " ");
		if (!ptn_match_str(cp->Text, s).IsEmpty()) mp->Items->AddObject(lbuf, (TObject*)i);
	}
	if (mp->Count>0) add_ComboBox_history(cp, cp->Text);
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ReMatchActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction*)Sender;
	ap->Enabled = !MatchComboBox1->Text.IsEmpty();
}
//---------------------------------------------------------------------------
// 透明度
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TransBarChange(TObject *Sender)
{
	AlphaBlendValue = TransBar->Position;
}
//---------------------------------------------------------------------------
// 常に手前に
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TopMostActionExecute(TObject *Sender)
{
	TAction *ap = (TAction*)Sender;
	ap->Checked = !ap->Checked;
	set_TopMost(this, ap->Checked);
}

//---------------------------------------------------------------------------
//配色
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ColorListBoxDrawItem(TWinControl *Control, int Index,
	TRect &Rect, TOwnerDrawState State)
{
	TColor col = clNone;
	switch (Index) {
	case  0: col = col_fgEm1;	break;
	case  1: col = col_fgEm2;	break;
	case  2: col = col_fgEm3;	break;
	case  3: col = col_fgEm4;	break;
	case  4: col = col_fgMark;	break;
	}

	TListBox *cp = (TListBox *)Control;
	draw_ColorItem(col, cp->Items->Strings[Index], cp->Canvas, Rect, State.Contains(odSelected));
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::ColorListBoxDblClick(TObject *Sender)
{
	TListBox *lp = ColorListBox;
	int idx = lp->ItemIndex;	if (idx==-1) return;

	switch (idx) {
	case  0: ColorDialog1->Color = col_fgEm1;	break;
	case  1: ColorDialog1->Color = col_fgEm2;	break;
	case  2: ColorDialog1->Color = col_fgEm3;	break;
	case  3: ColorDialog1->Color = col_fgEm4;	break;
	case  4: ColorDialog1->Color = col_fgMark;	break;
	}

	if (ColorDialog1->Execute()) {
		switch (idx) {
		case 0: col_fgEm1  = ColorDialog1->Color;	break;
		case 1: col_fgEm2  = ColorDialog1->Color;	break;
		case 2: col_fgEm3  = ColorDialog1->Color;	break;
		case 3: col_fgEm4  = ColorDialog1->Color;	break;
		case 4: col_fgMark = ColorDialog1->Color;	break;
		}
	}
}

//---------------------------------------------------------------------------
//Select Sound
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::RefSndBtnClick(TObject *Sender)
{
	int tag = ((TComponent*)Sender)->Tag;
	OpenDialog1->Title		= "Select Sound File";
	OpenDialog1->FileName	= EmptyStr;
	OpenDialog1->InitialDir = ExtractFileDir(Application->ExeName);
	OpenDialog1->Filter 	= "WAV File|*.WAV";
	OpenDialog1->DefaultExt = "wav";
	if (OpenDialog1->Execute()) {
		TLabeledEdit *ep = (tag==1)? SndLostEdit : (tag==2)? SndMatchEdit : SndFoundEdit;
		ep->Text = OpenDialog1->FileName;
		ep->Hint = ep->Text;
		play_sound(ep->Text);
	}
}
//---------------------------------------------------------------------------
void __fastcall TADbgMonFrm::TestSndBtnClick(TObject *Sender)
{
	int tag = ((TComponent*)Sender)->Tag;
	play_sound(((tag==1)? SndLostEdit : (tag==2)? SndMatchEdit : SndFoundEdit)->Text);
}
//---------------------------------------------------------------------------
