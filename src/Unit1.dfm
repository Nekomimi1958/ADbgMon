object ADbgMonFrm: TADbgMonFrm
  Left = 0
  Top = 0
  AlphaBlend = True
  Caption = 'Auto Debug Monitor'
  ClientHeight = 489
  ClientWidth = 664
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  ShowHint = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  TextHeight = 15
  object OpePanel: TPanel
    Left = 0
    Top = 0
    Width = 273
    Height = 489
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 273
      Height = 489
      ActivePage = MonitorSheet
      Align = alClient
      TabOrder = 0
      TabWidth = 100
      object MonitorSheet: TTabSheet
        Caption = 'Monitor'
        DesignSize = (
          265
          459)
        object Label1: TLabel
          Left = 217
          Top = 227
          Width = 28
          Height = 15
          Caption = 'msec'
        end
        object Button1: TButton
          Left = 29
          Top = 264
          Width = 90
          Height = 24
          Action = StartWatchAction
          TabOrder = 2
        end
        object Button2: TButton
          Left = 136
          Top = 264
          Width = 90
          Height = 24
          Action = StopAction
          TabOrder = 3
        end
        object GroupBox1: TGroupBox
          Left = 3
          Top = 3
          Width = 259
          Height = 110
          Anchors = [akLeft, akTop, akRight]
          Caption = 'Process'
          TabOrder = 0
          DesignSize = (
            259
            110)
          object PidEdit1: TLabeledEdit
            Left = 36
            Top = 78
            Width = 60
            Height = 23
            TabStop = False
            Alignment = taRightJustify
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 18
            EditLabel.Height = 23
            EditLabel.Caption = 'PID'
            LabelPosition = lpLeft
            NumbersOnly = True
            ReadOnly = True
            TabOrder = 2
            Text = ''
          end
          object SearchBtn1: TButton
            Left = 214
            Top = 78
            Width = 38
            Height = 24
            Action = FindAction
            Caption = 'Find'
            ImageName = 'glass'
            TabOrder = 5
          end
          object TargetPanel1: TPanel
            Left = 216
            Top = 24
            Width = 34
            Height = 34
            BevelOuter = bvLowered
            TabOrder = 4
            object CapToolImage1: TImage
              Left = 1
              Top = 1
              Width = 32
              Height = 32
              Hint = 'Find Window'#39's Process (drag over window)'
              Align = alClient
              OnMouseDown = CapToolImage1MouseDown
              OnMouseUp = CapToolImage1MouseUp
              ExplicitLeft = 8
              ExplicitTop = 8
              ExplicitWidth = 105
              ExplicitHeight = 105
            end
          end
          object TextEdit1: TLabeledEdit
            Left = 35
            Top = 49
            Width = 175
            Height = 23
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 21
            EditLabel.Height = 23
            EditLabel.Caption = 'Text'
            LabelPosition = lpLeft
            TabOrder = 1
            Text = ''
          end
          object ClassEdit1: TLabeledEdit
            Left = 36
            Top = 24
            Width = 174
            Height = 23
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 27
            EditLabel.Height = 23
            EditLabel.Caption = 'Class'
            LabelPosition = lpLeft
            TabOrder = 0
            Text = ''
          end
          object HWndEdit1: TLabeledEdit
            Left = 150
            Top = 78
            Width = 60
            Height = 23
            TabStop = False
            Alignment = taRightJustify
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 38
            EditLabel.Height = 23
            EditLabel.Caption = 'Handle'
            LabelPosition = lpLeft
            NumbersOnly = True
            ReadOnly = True
            TabOrder = 3
            Text = ''
          end
        end
        object TimeRadioGroup: TRadioGroup
          Left = 3
          Top = 120
          Width = 259
          Height = 44
          Caption = 'Time Display Mode'
          Columns = 3
          Items.Strings = (
            'Time'
            'Delta'
            'Both')
          TabOrder = 1
          OnClick = TimeRadioGroupClick
        end
        object ExlcudeEdit: TLabeledEdit
          Left = 9
          Top = 191
          Width = 243
          Height = 23
          Hint = 'specify multiple by separating with '#39';'#39' (/re/)'
          EditLabel.Width = 82
          EditLabel.Height = 15
          EditLabel.Caption = 'Exclude Pattern'
          TabOrder = 4
          Text = ''
        end
        object DeltaEdit: TLabeledEdit
          Left = 153
          Top = 224
          Width = 60
          Height = 23
          Alignment = taRightJustify
          EditLabel.Width = 100
          EditLabel.Height = 23
          EditLabel.Caption = 'Delta Separate Line'
          LabelPosition = lpLeft
          NumbersOnly = True
          TabOrder = 5
          Text = ''
        end
      end
      object OptionSheet: TTabSheet
        Caption = 'Option'
        ImageIndex = 1
        object TopMostCheckBox: TCheckBox
          Left = 146
          Top = 8
          Width = 110
          Height = 17
          Action = TopMostAction
          TabOrder = 1
        end
        object TransBar: TTrackBar
          Left = 9
          Top = 6
          Width = 120
          Height = 35
          Hint = 'Opacity'
          Max = 255
          Min = 64
          Frequency = 32
          Position = 64
          TabOrder = 0
          OnChange = TransBarChange
        end
        object ColorGroupBox: TGroupBox
          Left = 8
          Top = 190
          Width = 248
          Height = 116
          Caption = 'Colors'
          TabOrder = 3
          DesignSize = (
            248
            116)
          object ColorListBox: TListBox
            Left = 10
            Top = 24
            Width = 229
            Height = 84
            Style = lbOwnerDrawFixed
            Anchors = [akLeft, akTop, akRight, akBottom]
            ItemHeight = 15
            TabOrder = 0
            OnDblClick = ColorListBoxDblClick
            OnDrawItem = ColorListBoxDrawItem
          end
        end
        object PtnGroupBox: TGroupBox
          Left = 8
          Top = 45
          Width = 248
          Height = 137
          Hint = 'specify multiple by separating with '#39';'#39' (/re/)'
          Caption = 'Highlight Pattern '
          TabOrder = 2
          DesignSize = (
            248
            137)
          object Em1Edit: TLabeledEdit
            Left = 19
            Top = 24
            Width = 219
            Height = 23
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 6
            EditLabel.Height = 23
            EditLabel.Caption = '1'
            LabelPosition = lpLeft
            TabOrder = 0
            Text = ''
          end
          object Em2Edit: TLabeledEdit
            Left = 19
            Top = 51
            Width = 219
            Height = 23
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 6
            EditLabel.Height = 23
            EditLabel.Caption = '2'
            LabelPosition = lpLeft
            TabOrder = 1
            Text = ''
          end
          object Em3Edit: TLabeledEdit
            Left = 19
            Top = 78
            Width = 219
            Height = 23
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 6
            EditLabel.Height = 23
            EditLabel.Caption = '3'
            LabelPosition = lpLeft
            TabOrder = 2
            Text = ''
          end
          object Em4Edit: TLabeledEdit
            Left = 19
            Top = 105
            Width = 219
            Height = 23
            Anchors = [akLeft, akTop, akRight]
            EditLabel.Width = 6
            EditLabel.Height = 23
            EditLabel.Caption = '4'
            LabelPosition = lpLeft
            TabOrder = 3
            Text = ''
          end
        end
        object SndWatchGroupBox: TGroupBox
          Left = 8
          Top = 312
          Width = 248
          Height = 115
          Caption = 'Sound'
          TabOrder = 4
          DesignSize = (
            248
            115)
          object RefSndWatchBtn: TButton
            Tag = 2
            Left = 176
            Top = 83
            Width = 36
            Height = 22
            Hint = #21442#29031
            Anchors = [akTop, akRight]
            Caption = '...'
            TabOrder = 0
            OnClick = RefSndBtnClick
          end
          object TestSndWatchBtn: TButton
            Tag = 2
            Left = 216
            Top = 83
            Width = 22
            Height = 22
            Hint = 'Test'
            Anchors = [akTop, akRight]
            Caption = '>'
            TabOrder = 1
            OnClick = TestSndBtnClick
          end
          object SndMatchEdit: TLabeledEdit
            Tag = 2
            Left = 49
            Top = 82
            Width = 123
            Height = 23
            EditLabel.Width = 34
            EditLabel.Height = 23
            EditLabel.Caption = 'Match'
            LabelPosition = lpLeft
            TabOrder = 2
            Text = ''
          end
          object TestSndFondBtn: TButton
            Left = 216
            Top = 25
            Width = 22
            Height = 22
            Hint = 'Test'
            Anchors = [akTop, akRight]
            Caption = '>'
            TabOrder = 3
            OnClick = TestSndBtnClick
          end
          object RefSndFoundBtn: TButton
            Left = 176
            Top = 25
            Width = 36
            Height = 22
            Hint = #21442#29031
            Anchors = [akTop, akRight]
            Caption = '...'
            TabOrder = 4
            OnClick = RefSndBtnClick
          end
          object SndFoundEdit: TLabeledEdit
            Left = 49
            Top = 24
            Width = 123
            Height = 23
            EditLabel.Width = 34
            EditLabel.Height = 23
            EditLabel.Caption = 'Found'
            LabelPosition = lpLeft
            TabOrder = 5
            Text = ''
          end
          object SndLostEdit: TLabeledEdit
            Tag = 1
            Left = 49
            Top = 53
            Width = 123
            Height = 23
            EditLabel.Width = 22
            EditLabel.Height = 23
            EditLabel.Caption = 'Lost'
            LabelPosition = lpLeft
            TabOrder = 6
            Text = ''
          end
          object RefSndLostBtn: TButton
            Tag = 1
            Left = 176
            Top = 54
            Width = 36
            Height = 22
            Hint = #21442#29031
            Anchors = [akTop, akRight]
            Caption = '...'
            TabOrder = 7
            OnClick = RefSndBtnClick
          end
          object TestSndLostBtn: TButton
            Tag = 1
            Left = 216
            Top = 54
            Width = 22
            Height = 22
            Hint = 'Test'
            Anchors = [akTop, akRight]
            Caption = '>'
            TabOrder = 8
            OnClick = TestSndBtnClick
          end
        end
      end
    end
  end
  object LogPanel1: TPanel
    Left = 273
    Top = 0
    Width = 391
    Height = 489
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Splitter2: TSplitter
      Left = 0
      Top = 332
      Width = 391
      Height = 4
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 301
      ExplicitWidth = 185
    end
    object LogListBox1: TListBox
      Left = 0
      Top = 29
      Width = 391
      Height = 303
      Style = lbVirtualOwnerDraw
      Align = alClient
      DoubleBuffered = False
      MultiSelect = True
      ParentDoubleBuffered = False
      TabOrder = 0
      OnData = LogListBoxData
      OnDataObject = LogListBoxDataObject
      OnDrawItem = LogListBoxDrawItem
      OnKeyDown = LogListBox1KeyDown
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 391
      Height = 29
      ButtonHeight = 26
      ButtonWidth = 51
      Caption = 'ToolBar1'
      Flat = False
      Images = VirtualImageList1
      List = True
      AllowTextButtons = True
      TabOrder = 1
      object OpePanelBtn: TToolButton
        Left = 0
        Top = 0
        Hint = 'Show/Hide the Operation panel'
        Action = ShowOpePanelAction
        ImageIndex = 7
        ImageName = 'i_left_t'
      end
      object ToolButton2: TToolButton
        Left = 28
        Top = 0
        Width = 16
        Caption = 'ToolButton2'
        ImageIndex = 6
        ImageName = '06_ref'
        Style = tbsSeparator
      end
      object ToolButton7: TToolButton
        Left = 44
        Top = 0
        Action = CloseAction
        ImageName = '02_x'
      end
      object ToolButton9: TToolButton
        Left = 72
        Top = 0
        Action = TerminateAction
        ImageName = '03_x_r'
      end
      object ToolButton10: TToolButton
        Left = 100
        Top = 0
        Width = 8
        Caption = 'ToolButton10'
        ImageIndex = 2
        ImageName = '02_x'
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 108
        Top = 0
        Action = SaveLogAction
        ImageName = '00_save'
      end
      object ToolButton5: TToolButton
        Left = 136
        Top = 0
        Action = ClearLogAction
        ImageName = '01_trash'
      end
      object ToolButton15: TToolButton
        Left = 164
        Top = 0
        Width = 8
        Caption = 'ToolButton15'
        ImageIndex = 6
        ImageName = '06_ref'
        Style = tbsSeparator
      end
      object ToolButton13: TToolButton
        Left = 172
        Top = 0
        Action = TopOfLog1Action
        ImageName = '04_up'
      end
      object ToolButton1: TToolButton
        Left = 200
        Top = 0
        Action = EndOfLog1Action
        ImageName = '05_dwn'
      end
    end
    object MatchPanel1: TPanel
      Left = 0
      Top = 336
      Width = 391
      Height = 153
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
      object MatchListBox1: TListBox
        Left = 0
        Top = 25
        Width = 391
        Height = 109
        Style = lbOwnerDrawFixed
        Align = alClient
        DoubleBuffered = False
        ParentDoubleBuffered = False
        TabOrder = 0
        OnClick = MatchListBoxClick
        OnDrawItem = LogListBoxDrawItem
        ExplicitHeight = 128
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 391
        Height = 25
        Align = alTop
        AutoSize = True
        BevelOuter = bvLowered
        TabOrder = 1
        object SpeedButton1: TSpeedButton
          Left = 367
          Top = 1
          Width = 23
          Height = 23
          Action = ReMatch1Action
          Align = alRight
          ImageName = '06_ref'
          Images = VirtualImageList1
          ExplicitLeft = 176
          ExplicitTop = 2
          ExplicitHeight = 22
        end
        object MatchComboBox1: TComboBox
          Left = 1
          Top = 1
          Width = 366
          Height = 23
          Hint = 'specify multiple by separating with '#39';'#39' (/re/)'
          Align = alClient
          TabOrder = 0
          OnChange = MatchStrChange
        end
      end
      object StatusBar1: TStatusBar
        Left = 0
        Top = 134
        Width = 391
        Height = 19
        Panels = <
          item
            Width = 200
          end
          item
            Width = 50
          end>
        ExplicitLeft = 224
        ExplicitTop = 136
        ExplicitWidth = 0
      end
    end
  end
  object ActionList1: TActionList
    Left = 304
    Top = 40
    object FindAction: TAction
      Hint = 'Find Process'
      OnExecute = FindActionExecute
      OnUpdate = FindActionUpdate
    end
    object Find2Action: TAction
      Tag = 1
      Hint = 'Find Process'
      OnExecute = FindActionExecute
      OnUpdate = FindActionUpdate
    end
    object StartAction: TAction
      Caption = 'Start'
      OnExecute = StartActionExecute
      OnUpdate = StartActionUpdate
    end
    object StopAction: TAction
      Caption = 'Stop'
      OnExecute = StopActionExecute
      OnUpdate = StopActionUpdate
    end
    object CloseAction: TAction
      Hint = 'Close Handle'
      ImageIndex = 2
      OnExecute = CloseActionExecute
      OnUpdate = CloseActionUpdate
    end
    object Close2Action: TAction
      Tag = 1
      Hint = 'Close Handle'
      ImageIndex = 2
      OnExecute = CloseActionExecute
      OnUpdate = CloseActionUpdate
    end
    object TerminateAction: TAction
      Hint = 'Kill Process'
      ImageIndex = 3
      OnExecute = TerminateActionExecute
      OnUpdate = TerminateActionUpdate
    end
    object Terminate2Action: TAction
      Tag = 1
      Hint = 'Kill Process'
      ImageIndex = 3
      OnExecute = TerminateActionExecute
      OnUpdate = TerminateActionUpdate
    end
    object SaveLogAction: TAction
      Hint = 'Save Log As...'
      ImageIndex = 0
      OnExecute = SaveLogActionExecute
      OnUpdate = SaveLogActionUpdate
    end
    object SaveLog2Action: TAction
      Tag = 1
      Hint = 'Save Log As...'
      ImageIndex = 0
      OnExecute = SaveLogActionExecute
      OnUpdate = SaveLogActionUpdate
    end
    object ClearLogAction: TAction
      Hint = 'Clear Log'
      ImageIndex = 1
      OnExecute = ClearLogActionExecute
      OnUpdate = ClearLogActionUpdate
    end
    object ClearLog2Action: TAction
      Tag = 1
      Hint = 'Clear Log'
      ImageIndex = 1
      OnExecute = ClearLogActionExecute
      OnUpdate = ClearLogActionUpdate
    end
    object TopMostAction: TAction
      Caption = 'Always On Top'
      OnExecute = TopMostActionExecute
    end
    object TopOfLog1Action: TAction
      Caption = 'TopOfLog1Action'
      Hint = 'Top of Log'
      ImageIndex = 4
      OnExecute = TopOfLogActionExecute
      OnUpdate = TopOfLogActionUpdate
    end
    object TopOfLog2Action: TAction
      Tag = 1
      Caption = 'TopOfLog2Action'
      Hint = 'Top of Log'
      ImageIndex = 4
      OnExecute = TopOfLogActionExecute
      OnUpdate = TopOfLogActionUpdate
    end
    object EndOfLog1Action: TAction
      Hint = 'End of Log'
      ImageIndex = 5
      OnExecute = EndOfLogActionExecute
      OnUpdate = EndOfLogActionUpdate
    end
    object EndOfLog2Action: TAction
      Tag = 1
      Hint = 'End of Log'
      ImageIndex = 5
      OnExecute = EndOfLogActionExecute
      OnUpdate = EndOfLogActionUpdate
    end
    object ReMatch1Action: TAction
      Hint = 'Update Matching List'
      ImageIndex = 6
      OnExecute = ReMatchActionExecute
      OnUpdate = ReMatchActionUpdate
    end
    object ReMatch2Action: TAction
      Tag = 1
      Hint = 'Update Matching List'
      ImageIndex = 6
      OnExecute = ReMatchActionExecute
      OnUpdate = ReMatchActionUpdate
    end
    object StartWatchAction: TAction
      Caption = 'Start'
      OnExecute = StartWatchActionExecute
      OnUpdate = StartWatchActionUpdate
    end
    object ShowOpePanelAction: TAction
      Caption = #9664
      OnExecute = ShowOpePanelActionExecute
      OnUpdate = ShowOpePanelActionUpdate
    end
  end
  object Timer1: TTimer
    Interval = 250
    OnTimer = Timer1Timer
    Left = 384
    Top = 40
  end
  object SaveDialog1: TSaveDialog
    Left = 512
    Top = 40
  end
  object ColorDialog1: TColorDialog
    Left = 600
    Top = 40
  end
  object OpenDialog1: TOpenDialog
    Left = 510
    Top = 104
  end
  object Timer2: TTimer
    Interval = 100
    Left = 385
    Top = 104
  end
  object VirtualImageList1: TVirtualImageList
    AutoFill = True
    Images = <
      item
        CollectionIndex = 0
        CollectionName = '00_save'
        Name = '00_save'
      end
      item
        CollectionIndex = 1
        CollectionName = '01_trash'
        Name = '01_trash'
      end
      item
        CollectionIndex = 2
        CollectionName = '02_x'
        Name = '02_x'
      end
      item
        CollectionIndex = 3
        CollectionName = '03_x_r'
        Name = '03_x_r'
      end
      item
        CollectionIndex = 4
        CollectionName = '04_up'
        Name = '04_up'
      end
      item
        CollectionIndex = 5
        CollectionName = '05_dwn'
        Name = '05_dwn'
      end
      item
        CollectionIndex = 6
        CollectionName = '06_ref'
        Name = '06_ref'
      end
      item
        CollectionIndex = 7
        CollectionName = 'i_left_t'
        Name = 'i_left_t'
      end
      item
        CollectionIndex = 8
        CollectionName = 'i_right_t'
        Name = 'i_right_t'
      end>
    ImageCollection = ImageCollection1
    Width = 20
    Height = 20
    Left = 313
    Top = 176
  end
  object ImageCollection1: TImageCollection
    Images = <
      item
        Name = '00_save'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E70909052F1B293F9F0B000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000099494441
              5478DAD594090AC0200C04B3C57FEBD3FC59DAD88378F4B04DA15D8910892359
              513031596A30A5BD0124562384C069A923648F66407B0849530E623EF616006D
              B5C4386819745D756D03D873EB752D16DFCCE464F2DE67DE9CF9B76BC0B47728
              1704361B7E4F95874F604D60D9AE1CB0C615B9164C437BFD74166DE62DAA9152
              E225E667B5E6A218638AB24E337EF63958E8FB1FEC084C1788CD9731B1F40000
              000049454E44AE426082}
          end>
      end
      item
        Name = '01_trash'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E7090905272929314483000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC61050000008B494441
              5478DAE554ED0AC02008D4B1E736F2C55DB60F581FDA8F06C18C48F2B88E4343
              018199B14D65FB8270F70008F8F224598426BEF4B024F0A27CA0524844C0CCF9
              B4E2C170FD42B5F43A8145A0BDB4A698566DC8C35BADAAF23C5CBF6DD62044EC
              DB384468114C5128D2EF7DB76D729BC4338F57622936090385B6146B38AD49B0
              766F92F07F1FEC011CE26BCAC17907490000000049454E44AE426082}
          end>
      end
      item
        Name = '02_x'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E7090905280605786515000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC61050000006F494441
              5478DAED94D10A8030084535FA6EC7FC71CB1E22A4EBF620D1C39431B8720F6E
              826C6454195B296D01EF68D2CC0F326575D8A1AAD29BC935AFC1309022E230F3
              3BD362426004CCC086C0277406E6593EE5EF9E5C3A94CC3882EEE82B4E0375ED
              1CF54B13BCA278ADAFFF010FC98D09C56A8834380000000049454E44AE426082}
          end>
      end
      item
        Name = '03_x_r'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E7090905282CDEC3ACC3000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000060494441
              5478DAED94C10A002008435BFFFFCF4674B1706520D1C14110E45ECA22489112
              A91A4A4BA012642C267E7EE8D03261FB2C08506003F45ED74C15BB0B593736CC
              31B265E43007F05EAF42598D7D4C16940BC8D23C43C343417E5FFF011BE35F20
              20BC4FB3FE0000000049454E44AE426082}
          end>
      end
      item
        Name = '04_up'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E70909052939AA057969000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000090494441
              5478DAC5D4010A80200C0550ED381ED26167F43E2B8581986BDF302C06C1B787
              329C67C76EE5732CD5B68114894B41221B6F8C91EBB2BBCAB7B51EC6A488883F
              812D1642A885A0109673AE85A0102619823E40F9A9C564875A6E1ED902DA7CAA
              CBFD11B55D41608FA128849546BD350B6ACAE87620E8F455B3723F9A873208D2
              99BC362CB47C08FE3EBEB6821742F5EFA7A8B12D960000000049454E44AE4260
              82}
          end>
      end
      item
        Name = '05_dwn'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E70909052A1CCA2CFEED000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000094494441
              5478DACDD40D0A80200C0650ED381E726267F43E2B03416C3F5F24512244DB1E
              D86A91038795D7B654FB0CCC94B96DADC88CF3B48888AFC7E76EF74FE337B0D6
              CA2925B168C45A4ECB75410D453015945004334109F530F3C8BDB0A32336C6E1
              A66880143741EBE55B5F807964094530B329338A606E974714C15C10F9D5E615
              9179D80741D94BF47221F0F5F8FA157800F21AF091E51378E20000000049454E
              44AE426082}
          end>
      end
      item
        Name = '06_ref'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D0000000774494D4507E70909052A30F8F4920E000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000161494441
              5478DACD54B18E8240109DBD5C4287A127682F1DB54189F11A4AF42C883F4062
              638F3D26F67CC4D9DB10AFB2828486C6D2FB013BBA39D828C7CA4238E3253793
              CD8679338FDDD999210808CF9497A7B2FD05E16B13B8FBD8611CC79024094892
              04E3F11866EF3372C387FA90E6EBF079286C8035BA5C2E91C29CE5791E5E738F
              BAAE63398E4B560E1645115555C56EB7CB90DAB68DAD08E7F37911E4BA2EE37C
              3C1E71301830C48D84FBFDBE70B42C8B710C8280FE205F8BC5A21DE176BBA54E
              9D4E07EF4F9E13F2F2794FC8BC72188674EFF57A0071F5D533527E39182DCBA6
              2C236344CADF6B775DB4D828536ED9345DB9AC51141557DE6C368C2FD329FD7E
              9FEE97CB05A6D6B4B6C97DDFFFB9AD61B0E06FCA2657C7710A7CB55A5570C29B
              3624375F252B6C5014050821703A9D204D536A976519CE5F6752097EA4F54CD3
              ACCD31F78437290F07411040D3349AE7C9DB84D4C534123E22FF7FC07E03D21B
              57D84181B9830000000049454E44AE426082}
          end>
      end
      item
        Name = 'i_left_t'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D00000006624B474400FF00FF00FFA0BDA79300000194494441543811636020
              138436ECE7C1A695099B2021B1B0BA9DBEFFFEFF5E884D1DC90686B51C88E411
              129CCBCCCC2A49B181112D7B4B8404F92669A8A98962330C24C6022288C1A14D
              7BDB4545C4D2E4E46585F0A927CAC0B0A63DB3A5A5A442A5A425F9F1190692C3
              6B60434303D33526DBE5405779898B89618D559021C818A78169696758AF317D
              58AFA4A8E8282C22C485AC091F1BAB81A185AB383F087EDAAEAAAA62212020C0
              8ECF0074390C033D1BB6F1313273ECD6505731E4E5E56345D740888F910ED919
              7E82C458FEFF6704D184F463C86368DAD010F8E1FFDF3796376EDEDCFFE6CDDB
              EF183A080860180852BFBA21EC17C3E5771EF7EFDFDFF6FAD5EBCF2031623156
              03419A57AF0EFBBBAACE39F4C1C3472B9F3E7BF60124460CC669204433E37FA0
              A1A94F1F3F9FF1F0C1E3B71031FC240103219A57373857BE7AFDBAEBEEDD7BAF
              FEFF8788E122893210A479559D53D7EB37EF8A6FDDBAFD9C8101B7A9441B0832
              746D83CB92771FDF155EBB7EEB31888F0D936420C88075F5EE2BBF7CFA14F5F7
              EFAFFB203ED530AE2A0000EB257D25E63843540000000049454E44AE426082}
          end>
      end
      item
        Name = 'i_right_t'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000140000001408060000008D891D
              0D00000006624B474400FF00FF00FFA0BDA793000001A44944415438116360C0
              01421BF6F3E090C22BCC844BF6F7DF9FA7021B768AE192C7258ED3404E767631
              203E1254B5431297666CE2380D646165F9AEABA3A3CAC5C77D38B066B72636CD
              D8C4701A0852CCC2C2C2A0A3A3ADCCC3C7B93DB87A9709488C10C66B20483333
              3313838EB6963CB700CF86C0E6BD4E20317C98099F244C8E890964A886B40017
              F7D290867D4130716C345106823432323231686AAA4B0808704F0F6FDA9B0212
              C386893610A499919191414D4D5D4C4050A023A4695719480C1D9364204833D0
              4C06151565614931C9F2D0C63D5D2031644CB28130CDFFFEFF070602031B8C0F
              A359600CE2E9FF0CB76EDD7DFDE9E3C7A695F52E53D0F59164E0FF7FFF196EDC
              B8F1F2CBF76F85ABEA9C97A31B06E2136DE0BF7FFF18AE5EBDFEE4DBB7AFC96B
              1ADC76813463C34419F8E7EF5F86AB97AF3DFCFEED5BF8DA66F793D80C828911
              34F0F7EFDF0C57AE5CBFFBFBD717BFB5CD5ED7601A71D1780DFCF5F317C395AB
              D7AE7DFCF6D56B5BABF7435C86208BE34C367F7EFFE1BC7CE5DAA5CFDF3EBB11
              6B18C8609C2EFCF1EBE743969FCC4E5B3A7D3F8214528CC9AD020011227EDCD3
              C62C5C0000000049454E44AE426082}
          end>
      end>
    Left = 313
    Top = 232
  end
  object VirtualImageList2: TVirtualImageList
    AutoFill = True
    Images = <
      item
        CollectionIndex = 0
        CollectionName = 'target'
        Name = 'target'
      end
      item
        CollectionIndex = 1
        CollectionName = 'target2'
        Name = 'target2'
      end
      item
        CollectionIndex = 2
        CollectionName = 'glass'
        Name = 'glass'
      end>
    ImageCollection = ImageCollection2
    Width = 32
    Height = 32
    Left = 425
    Top = 176
  end
  object ImageCollection2: TImageCollection
    Images = <
      item
        Name = 'target'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000020000000200802000000FC18ED
              A30000000774494D4507E7090906141C89AF5BC9000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC6105000003E2494441
              5478DAAD964B28AD5114C7BF73AF89646820250385AB23CF4C94C7C0802B0C0C
              2E33919228033291991818480A2529240344068AE43190479E176520E551EE88
              81E1BDBFBBD7B9CB3E9FC3F9E8AEC139FFBDF75A6BEF6FADB5FF6B3BBF3DCBD1
              D151A9118077AB2F8E37797E7EBEB9B9110C60E8D1D0C726EF2CFF34B2B9B979
              7979E95A4A4C4CCCCBCBFB66E4331BECEEEECECCCC9C9E9E863D636A6A6A5555
              557676F60736181A1A5A5858B067929292525252E6E6E6C01515156767671717
              17B642595959434383A70DEAEBEBEFEEEE04272727171717F31B1F1F7F7C7C3C
              3939C9647575B5DFEFBFBEBE3E3F3F5F5E5EE65794636363474646C26CD0D6D6
              46D005E3BAB9B9396C88FAFBFBD94630F9E8EDEDB55783AA68757555BDF7F4F4
              B8BCF305DF8D00EC79D450168C394E426F707575D5D7D72778787898D4853DBB
              0ACA9808C609AE74E96B5757972E48E8C9414E4E8E6D3F3131313E3E3E3D3D2D
              C3959595FDFDFD878787B4B434D5898E8E8E8A8A621E7C7F7F5F585818F40514
              A5ACA5A7A7979797DBDE1B1B1BA7A6A6C864424282CC001832C992AD8921E600
              5CE1306883BDBD3D01050505B64D676727D502282929D12A043004B08482ADAF
              E6EAF0E50B0450EC7664E4B31617175D8765C8A41C566AD7651EF4054F4F4F12
              7D8A2C2E2E4EB5B7B6B6F86D6D6DD5991F4674284B1089CE602ECC8143DC0222
              A839098263AE2B432E911422F399999931313132F41B114D996109053E421500
              38915A5F5F5FE77AFAA05FFBDB51EAEEEEA6D85D85C8C16B6A6AECE89164970E
              41EBE8E870DD12AF74FD69F1D13DE0F7818101C7B0586E6EAE8688E350915A3C
              1A1F0D916368916BC5476B88B6B7B785139B9A9A484904B330BB6C0047D6D5D5
              A92F388E7ADFD8D89012C298D3F87C3E4DC6E0E020DE51D3BD0163636382F3F3
              F3232323FF86883FF600C0C09A7024232383DFA5A5259D21EE7651CA92A88960
              2E348E43DCBEE480DE2440B91721AB9401809CBB288CA114020A76F2D55C1D06
              36D0B6A7C42B42102844C730150D4E2601428B2CA160EBDBBC2D20407654F4E1
              E121FCF5CB08A9561B688B9EF1F8F8A8A7E3127170D8A2A5A5C5F64E6320C38E
              21579A526056DF173B3B3BA5FFE4E4E4E4A3CF164CD41C57219E2D746DFAAAE0
              F6F6F6DBDB5BEFC58E32268271623F00DC2DD36EC86017758794F9F9796DC5AF
              DB7288A66FB765F81D068623B932AEA6CFF5E4DEACADAD1D1C1C68625D0DD979
              EBD942156AFB5463586C7676165C595949B1EB214460D6A2A2A2D7AEDE7C7871
              45474747A51FBC2F146B6D6DADF63BAF1B88D037E84DFC6A62540837C9CCCACA
              7AEB4D17108F8F64EE016C2C550860F89F5FD73C1A84361C430F0C3D1AFE014E
              40204B9BFD77600000000049454E44AE426082}
          end>
      end
      item
        Name = 'target2'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000020000000200802000000FC18ED
              A30000000774494D4507E70909061401EAA93710000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000381494441
              5478DA9D96494B72611480AF1FD9224A89D252B0221A08051B6927541BA11FD0
              5FAC1F10B4A9A05D345124D9403491654A34AC6C51CF77CFD7E97833BD5F67A1
              E73DEF19DE33DFC0FBFBBBE30F8AC5E2FAFA3AC8CCCC4C341AF529F5C727DFDB
              DBDBCBCB8BE0201C7D0A06EA7BF0F0F0502A95AEAFAF1F1F1F3D57EDEDED8944
              A2B3B3331289FCC640A150383A3AC240C3376260646424168BFD8781DDDDDDD3
              D3534BE9E8E8E0B1C7C7C7E0C3C3C3B8552E972DC3E0E0E0F8F8B82F03CBCBCB
              AFAFAFAAB7BFBF9FDF70384C9273B91CC4643249929F9E9EB0717E7EAE965A5B
              5BE7E7E71B18585D5DE57582A37A6A6AAA6188B6B6B63023385ECECDCDFD68E0
              E2E262737353F0D9D9594FF6EA9429A95A5B5B137C7A7ABAAFAF4FAFBECA1497
              553B9ED6AF0D0FC0ACC14109AA6A78B0B1B141E5808C8D8D0D0D0D59F9C3C3C3
              BBBB3B9B55B2D2DDDD9D4AA52CDBC9C9C9DEDE1E081595C964AA3C28B800D2D5
              D5E5D1BEB2B2426ED14E9E8502C2112257961341C4ADB62A0382F4F6F65A19DC
              127F070606B40A41384A5461B0FC2AFEA301CAC04646E80B0B0B131313561147
              8822089BD255BCCA40A55291C2E7BAADAD4DB96F6E6EA42A949274418F72256C
              02888B0D14A216A489E27B7E7ED6D471A404F9950890AE96961639465D104EA1
              7005038F5506109448275D5D5D8542A1C0E2E2A2F51D26CA7C6969C953883CDC
              D60C6191AEB640D0681431A6E0775CFF1A02F7F7F7CCF7EDED6DC79D62F1785C
              43C473A8482D1EDBBDFA4CC62291C4690DD1EDEDADCCC4C9C94952D20495C92E
              0688DDE8E8A8EA229AD43BCB404AA8E8824DC6CECE0EDA6153DB2007070782F7
              F4F40483C1BF21E20F1B20A8B35D4EAFF27B7676A6949C0B7A942B61139011EB
              B8EB08B55F3960370962E7015995EE25E7CC411B598E520830D8E4ABB82AFC67
              401B4407AF40369B9555C508CBE7F3420491B1C8150C96DFCEED2A031117E409
              CC772BC3D8A24679A936270847883AD10410140F541BD0A4D7EC55D9C0BC8281
              6EC775CA85FA9F2DC8EAF351A5F4AF3EC05FF6AAE06C0FDD9A7E00665D3828B1
              1F00DE956917F2F7C55013740D38B5D6728DA56FD732F39D092C43D0B3F4694F
              D82E2F2F69554DAC67213B3F7DB6D8E5ACC234947EB6904C7D848067153730E0
              B82DB3BFBFAF95530788783A9DD67DE7D78040E113BEE79C70C73EA18E8680CF
              AF6BB607F39DE1E3B8EB8C39D3DCDCEC47D0EFB8461DDB4370109FDA810F1E3C
              3A40D179D3F60000000049454E44AE426082}
          end>
      end
      item
        Name = 'glass'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000020000000200802000000FC18ED
              A30000000774494D4507E70909061431CC7007BC000000097048597300001EC1
              00001EC101C36954530000000467414D410000B18F0BFC610500000226494441
              5478DADD96BBCBB1611CC75F22E47CC8843020C4A01C061B4A0E03FF83CD6435
              3049495824424959484A4A945191E40F30586CC6D761B9DFEFF358DEF77D3C6E
              B7589EEFF04B97EB7B7DEEFB77B8A01104F1EB9DA2BFF5F49F0D582E97B95C4E
              AFD7CBE572168B25954ACD66733C1E5F2C16D408C42DF5FB7D8D46C36030BEEE
              57ABD5C9649278583700E9749AC964B2D96CB7DBDD6C36F1C8585CAFD7954A25
              1008D068346062B1D89380D96CC6E1707044B158BC69C8643248179FCF47029F
              0120D130B75AAD3B9E6EB74BA77F146FB55A5103D4EB7564C6EFF793DA902B00
              52A91435C0D556AD56496DC3E190CBE5A248A43BFF69D3ED768B683299487B8F
              FFA9D3E9446D0E76BB1DA2CBE57A10703E9FA901944A25E266B321B5FDFE14B2
              440D60B55A11E7F339A96DBFDF1F0E07A150480DE0F3F9D04583C180D4D6E974
              8EC7A3CD6623DDF9FF1CD8ED76CC2AA6E94E63140A0518753A1D690B115F070D
              3D0AB34C266B341A370DB55A4DA150A0C2A552E9190094CD660100C6E17094CB
              E5F1788C9B753299E4F379E410EB028100D1E9743E0980DAEDB6582CFE28119D
              2E1289B45AAD4422B9A6D46030204560E37324122105D088EF7F935189D16884
              69BA5C2E3C1E4FA552A1AA8944E2FA6D341AEDF57A58C1FB512832255DBB281C
              0E534ED1E30A854260582C967701A0EB787E7707BF0000E174308C46E3BB00D0
              F50EF67ABDEF02401E8F078C6030F82E0084D3A7D3E9DF2BF7E6E025FAC17F1D
              5FA53F1277AE119AE999DA0000000049454E44AE426082}
          end>
      end>
    Left = 425
    Top = 232
  end
end
