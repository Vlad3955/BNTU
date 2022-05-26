object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 582
  ClientWidth = 835
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 15
  object Label9: TLabel
    Left = 24
    Top = 466
    Width = 7
    Height = 15
    Caption = 'Z'
  end
  object Label8: TLabel
    Left = 22
    Top = 311
    Width = 7
    Height = 15
    Caption = 'Y'
  end
  object Label7: TLabel
    Left = 21
    Top = 529
    Width = 122
    Height = 15
    Caption = #1064#1072#1075' '#1088#1072#1089#1095#1077#1090#1072' '#1090#1072#1073#1083#1080#1094#1099':'
  end
  object Label6: TLabel
    Left = 24
    Top = 417
    Width = 106
    Height = 15
    Caption = #1064#1072#1075' '#1088#1072#1079#1084#1077#1090#1082#1080' '#1087#1086' Y:'
  end
  object Label5: TLabel
    Left = 21
    Top = 363
    Width = 106
    Height = 15
    Caption = #1064#1072#1075' '#1088#1072#1079#1084#1077#1090#1082#1080' '#1087#1086' X:'
  end
  object Label4: TLabel
    Left = 24
    Top = 256
    Width = 32
    Height = 15
    Caption = 'Ymax:'
  end
  object Label3: TLabel
    Left = 24
    Top = 200
    Width = 30
    Height = 15
    Caption = 'Ymin:'
  end
  object Label2: TLabel
    Left = 21
    Top = 142
    Width = 33
    Height = 15
    Caption = 'Xmax:'
  end
  object Label1: TLabel
    Left = 21
    Top = 90
    Width = 31
    Height = 15
    Caption = 'Xmin:'
  end
  object Chart1: TChart
    Left = 280
    Top = 64
    Width = 529
    Height = 456
    Legend.TextStyle = ltsXAndValue
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082#1080' '#1092#1091#1085#1082#1094#1080#1081)
    View3D = False
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      2
      15
      2)
    ColorPaletteIndex = 13
    object Series1: TLineSeries
      HoverElement = [heCurrent]
      Title = 'sin(x)'
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      HoverElement = [heCurrent]
      Title = 'cos(x)'
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Edit9: TEdit
    Left = 200
    Top = 463
    Width = 74
    Height = 23
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 688
    Top = 544
    Width = 75
    Height = 25
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 2
  end
  object Edit8: TEdit
    Left = 168
    Top = 308
    Width = 106
    Height = 23
    TabOrder = 3
  end
  object Edit7: TEdit
    Left = 208
    Top = 526
    Width = 74
    Height = 23
    TabOrder = 4
  end
  object Edit6: TEdit
    Left = 200
    Top = 414
    Width = 74
    Height = 23
    TabOrder = 5
  end
  object Edit5: TEdit
    Left = 200
    Top = 360
    Width = 74
    Height = 23
    TabOrder = 6
  end
  object Edit4: TEdit
    Left = 168
    Top = 253
    Width = 106
    Height = 23
    TabOrder = 7
  end
  object Edit3: TEdit
    Left = 168
    Top = 197
    Width = 106
    Height = 23
    TabOrder = 8
  end
  object Edit2: TEdit
    Left = 168
    Top = 139
    Width = 106
    Height = 23
    TabOrder = 9
  end
  object Edit1: TEdit
    Left = 168
    Top = 87
    Width = 106
    Height = 23
    TabOrder = 10
  end
  object Button1: TButton
    Left = 408
    Top = 543
    Width = 153
    Height = 27
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
    TabOrder = 11
    OnClick = Button1Click
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 835
    Height = 23
    AutoSize = True
    ButtonHeight = 23
    ButtonWidth = 77
    Caption = 'ToolBar1'
    ShowCaptions = True
    TabOrder = 12
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = 'Xmin'
      ImageIndex = 0
    end
    object ToolButton2: TToolButton
      Left = 77
      Top = 0
      Caption = 'Xmax'
      ImageIndex = 1
    end
    object ToolButton3: TToolButton
      Left = 154
      Top = 0
      Caption = 'Ymin'
      ImageIndex = 2
    end
    object ToolButton4: TToolButton
      Left = 231
      Top = 0
      Caption = 'Ymax'
      ImageIndex = 3
    end
    object ToolButton6: TToolButton
      Left = 308
      Top = 0
      Caption = 'ToolButton6'
      ImageIndex = 4
    end
    object ToolButton5: TToolButton
      Left = 385
      Top = 0
      Caption = 'ToolButton5'
      ImageIndex = 5
    end
    object ToolButton7: TToolButton
      Left = 462
      Top = 0
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 6
      Style = tbsSeparator
    end
    object ToolButton8: TToolButton
      Left = 470
      Top = 0
      Caption = 'ToolButton8'
      ImageIndex = 6
    end
    object ToolButton9: TToolButton
      Left = 547
      Top = 0
      Caption = 'ToolButton9'
      ImageIndex = 7
    end
    object ToolButton10: TToolButton
      Left = 624
      Top = 0
      Caption = 'ToolButton10'
      ImageIndex = 8
    end
  end
  object ImageList1: TImageList
    Left = 768
    Top = 16
  end
end
