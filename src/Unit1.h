//----------------------------------------------------------------------//
// Auto Debug Monitor													//
//																		//
//----------------------------------------------------------------------//
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <System.IniFiles.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>
#include <Vcl.VirtualImageList.hpp>

//---------------------------------------------------------------------------
class TADbgMonFrm : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TAction *ClearLog2Action;
	TAction *ClearLogAction;
	TAction *Close2Action;
	TAction *CloseAction;
	TAction *EndOfLog1Action;
	TAction *EndOfLog2Action;
	TAction *Find2Action;
	TAction *FindAction;
	TAction *ReMatch1Action;
	TAction *ReMatch2Action;
	TAction *SaveLog2Action;
	TAction *SaveLogAction;
	TAction *ShowOpePanelAction;
	TAction *StartAction;
	TAction *StartWatchAction;
	TAction *StopAction;
	TAction *Terminate2Action;
	TAction *TerminateAction;
	TAction *TopMostAction;
	TAction *TopOfLog1Action;
	TAction *TopOfLog2Action;
	TActionList *ActionList1;
	TButton *Button1;
	TButton *Button2;
	TButton *RefSndFoundBtn;
	TButton *RefSndLostBtn;
	TButton *RefSndWatchBtn;
	TButton *SearchBtn1;
	TButton *TestSndFondBtn;
	TButton *TestSndLostBtn;
	TButton *TestSndWatchBtn;
	TCheckBox *TopMostCheckBox;
	TColorDialog *ColorDialog1;
	TComboBox *MatchComboBox1;
	TGroupBox *ColorGroupBox;
	TGroupBox *GroupBox1;
	TGroupBox *PtnGroupBox;
	TGroupBox *SndWatchGroupBox;
	TImage *CapToolImage1;
	TImageCollection *ImageCollection1;
	TImageCollection *ImageCollection2;
	TLabel *Label1;
	TLabeledEdit *ClassEdit1;
	TLabeledEdit *DeltaEdit;
	TLabeledEdit *Em1Edit;
	TLabeledEdit *Em2Edit;
	TLabeledEdit *Em3Edit;
	TLabeledEdit *Em4Edit;
	TLabeledEdit *ExlcudeEdit;
	TLabeledEdit *HWndEdit1;
	TLabeledEdit *PidEdit1;
	TLabeledEdit *SndFoundEdit;
	TLabeledEdit *SndLostEdit;
	TLabeledEdit *SndMatchEdit;
	TLabeledEdit *TextEdit1;
	TListBox *ColorListBox;
	TListBox *LogListBox1;
	TListBox *MatchListBox1;
	TOpenDialog *OpenDialog1;
	TPageControl *PageControl1;
	TPanel *LogPanel1;
	TPanel *MatchPanel1;
	TPanel *OpePanel;
	TPanel *Panel1;
	TPanel *TargetPanel1;
	TRadioGroup *TimeRadioGroup;
	TSaveDialog *SaveDialog1;
	TSpeedButton *SpeedButton1;
	TSplitter *Splitter2;
	TTabSheet *MonitorSheet;
	TTabSheet *OptionSheet;
	TTimer *Timer1;
	TTimer *Timer2;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *OpePanelBtn;
	TToolButton *ToolButton5;
	TToolButton *ToolButton7;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton13;
	TToolButton *ToolButton15;
	TTrackBar *TransBar;
	TVirtualImageList *VirtualImageList1;
	TVirtualImageList *VirtualImageList2;
	TStatusBar *StatusBar1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall CapToolImage1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall CapToolImage1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall FindActionExecute(TObject *Sender);
	void __fastcall FindActionUpdate(TObject *Sender);
	void __fastcall TimeRadioGroupClick(TObject *Sender);
	void __fastcall LogListBoxData(TWinControl *Control, int Index, UnicodeString &Data);
	void __fastcall LogListBoxDataObject(TWinControl *Control, int Index, TObject *&DataObject);
	void __fastcall LogListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall LogListBox1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall MatchListBoxClick(TObject *Sender);
	void __fastcall MatchStrChange(TObject *Sender);
	void __fastcall StartWatchActionExecute(TObject *Sender);
	void __fastcall StartWatchActionUpdate(TObject *Sender);
	void __fastcall StartActionExecute(TObject *Sender);
	void __fastcall StartActionUpdate(TObject *Sender);
	void __fastcall StopActionExecute(TObject *Sender);
	void __fastcall StopActionUpdate(TObject *Sender);
	void __fastcall ShowOpePanelActionExecute(TObject *Sender);
	void __fastcall ShowOpePanelActionUpdate(TObject *Sender);
	void __fastcall CloseActionExecute(TObject *Sender);
	void __fastcall CloseActionUpdate(TObject *Sender);
	void __fastcall TerminateActionExecute(TObject *Sender);
	void __fastcall TerminateActionUpdate(TObject *Sender);
	void __fastcall SaveLogActionExecute(TObject *Sender);
	void __fastcall SaveLogActionUpdate(TObject *Sender);
	void __fastcall ClearLogActionExecute(TObject *Sender);
	void __fastcall ClearLogActionUpdate(TObject *Sender);
	void __fastcall TopOfLogActionExecute(TObject *Sender);
	void __fastcall TopOfLogActionUpdate(TObject *Sender);
	void __fastcall EndOfLogActionExecute(TObject *Sender);
	void __fastcall EndOfLogActionUpdate(TObject *Sender);
	void __fastcall ReMatchActionExecute(TObject *Sender);
	void __fastcall ReMatchActionUpdate(TObject *Sender);
	void __fastcall TransBarChange(TObject *Sender);
	void __fastcall TopMostActionExecute(TObject *Sender);
	void __fastcall ColorListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall ColorListBoxDblClick(TObject *Sender);
	void __fastcall RefSndBtnClick(TObject *Sender);
	void __fastcall TestSndBtnClick(TObject *Sender);

private:	// ユーザー宣言
	TIniFile *IniFile;

	TCursor crTarget;

	bool Watching;
	bool Monitoring;
	bool Capturing;

	HWND  TargetHWnd;
	DWORD TargetPID;
	UnicodeString TTargetFname;

	TColor col_fgEm1;
	TColor col_fgEm2;
	TColor col_fgEm3;
	TColor col_fgEm4;
	TColor col_fgMark;

	TStringList *LogBuffer1;
	int LastTopIndex;

	void __fastcall SetEditColor(TLabeledEdit *ep)
	{
		ep->Color = ep->Text.IsEmpty()? clLtGray : Monitoring? clWebLightGreen : clWindow;
	}

	void __fastcall ClearID();
	void __fastcall PrepareTarget(HWND hWnd);
	bool __fastcall WaitOutputDebugStr(DWORD pid, HWND hWnd);
	void __fastcall AddLog(UnicodeString s, TDateTime t, int flag = 0);

public:		// ユーザー宣言
	__fastcall TADbgMonFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TADbgMonFrm *ADbgMonFrm;
//---------------------------------------------------------------------------
#endif
