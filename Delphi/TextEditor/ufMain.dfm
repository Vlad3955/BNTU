object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'MyNote'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu
  PixelsPerInch = 96
  TextHeight = 15
  object Memo: TMemo
    Left = 0
    Top = 0
    Width = 436
    Height = 441
    Align = alClient
    ScrollBars = ssBoth
    TabOrder = 0
    ExplicitWidth = 624
  end
  object pReplace: TPanel
    AlignWithMargins = True
    Left = 439
    Top = 0
    Width = 185
    Height = 441
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alRight
    BevelKind = bkFlat
    BevelOuter = bvNone
    TabOrder = 1
    Visible = False
    ExplicitLeft = 442
    ExplicitTop = -5
    object Label1: TLabel
      Left = 8
      Top = 1
      Width = 35
      Height = 15
      Caption = 'Search'
    end
    object Label2: TLabel
      Left = 8
      Top = 49
      Width = 41
      Height = 15
      Caption = 'Replace'
    end
    object eFind: TEdit
      Left = 8
      Top = 22
      Width = 121
      Height = 23
      TabOrder = 0
    end
    object eReplace: TEdit
      Left = 8
      Top = 70
      Width = 121
      Height = 23
      TabOrder = 1
    end
    object bReplace: TButton
      Left = 9
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Replace'
      TabOrder = 2
      OnClick = bReplaceClick
    end
    object bClose: TButton
      Left = 97
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Close'
      TabOrder = 3
      OnClick = bCloseClick
    end
  end
  object MainMenu: TMainMenu
    Left = 56
    Top = 136
    object File1: TMenuItem
      Caption = 'File'
      object Save1: TMenuItem
        Caption = 'Save'
        ShortCut = 16467
        OnClick = Save1Click
      end
      object Open1: TMenuItem
        Caption = 'Open'
        ShortCut = 16463
        OnClick = Open1Click
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object SearchandReplace1: TMenuItem
        Caption = 'Search and Replace'
        ShortCut = 16466
        OnClick = SearchandReplace1Click
      end
    end
    object Settings1: TMenuItem
      Caption = 'Settings'
      object Font1: TMenuItem
        Caption = 'Font'
        OnClick = Font1Click
      end
      object Font2: TMenuItem
        Caption = 'Background color'
        OnClick = Font2Click
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099'(*.txt)|*.txt|'#1042#1089#1077' '#1092#1072#1081#1083#1099'(*.*)|*.*'
    Left = 128
    Top = 136
  end
  object SaveDialog: TSaveDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099'(*.txt)|*.txt|'#1042#1089#1077' '#1092#1072#1081#1083#1099'(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 192
    Top = 136
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Left = 264
    Top = 136
  end
  object ColorDialog: TColorDialog
    Left = 336
    Top = 136
  end
end
