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
  object Label10: TLabel
    Left = 160
    Top = 90
    Width = 40
    Height = 15
    Caption = 'Label10'
  end
  object Label11: TLabel
    Left = 160
    Top = 142
    Width = 40
    Height = 15
    Caption = 'Label11'
  end
  object Label12: TLabel
    Left = 160
    Top = 200
    Width = 40
    Height = 15
    Caption = 'Label12'
  end
  object Label13: TLabel
    Left = 160
    Top = 256
    Width = 40
    Height = 15
    Caption = 'Label13'
  end
  object Label14: TLabel
    Left = 160
    Top = 311
    Width = 40
    Height = 15
    Caption = 'Label14'
  end
  object Label15: TLabel
    Left = 160
    Top = 363
    Width = 40
    Height = 15
    Caption = 'Label15'
  end
  object Label16: TLabel
    Left = 160
    Top = 417
    Width = 40
    Height = 15
    Caption = 'Label16'
  end
  object Label17: TLabel
    Left = 160
    Top = 466
    Width = 40
    Height = 15
    Caption = 'Label17'
  end
  object Label18: TLabel
    Left = 160
    Top = 529
    Width = 40
    Height = 15
    Caption = 'Label18'
  end
  object Chart1: TChart
    Left = 298
    Top = 72
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
  object BitBtn1: TBitBtn
    Left = 688
    Top = 544
    Width = 75
    Height = 25
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 1
  end
  object Button1: TButton
    Left = 408
    Top = 543
    Width = 153
    Height = 27
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
    TabOrder = 2
    OnClick = Button1Click
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 835
    Height = 46
    AutoSize = True
    ButtonHeight = 23
    ButtonWidth = 112
    Caption = 'ToolBar1'
    ShowCaptions = True
    TabOrder = 3
    object bXmin: TToolButton
      Left = 0
      Top = 0
      Caption = 'Xmin'
      ImageIndex = 0
      OnClick = bXminClick
    end
    object bXmax: TToolButton
      Left = 112
      Top = 0
      Caption = 'Xmax'
      ImageIndex = 1
      OnClick = bXmaxClick
    end
    object bYmin: TToolButton
      Left = 224
      Top = 0
      Caption = 'Ymin'
      ImageIndex = 2
      OnClick = bYminClick
    end
    object bYmax: TToolButton
      Left = 336
      Top = 0
      Caption = 'Ymax'
      ImageIndex = 3
      OnClick = bYmaxClick
    end
    object bY: TToolButton
      Left = 448
      Top = 0
      Caption = 'Y'
      ImageIndex = 4
      Wrap = True
      OnClick = bYClick
    end
    object bZ: TToolButton
      Left = 0
      Top = 23
      Caption = 'Z'
      ImageIndex = 5
      OnClick = bZClick
    end
    object ToolButton7: TToolButton
      Left = 112
      Top = 23
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 6
      Style = tbsSeparator
    end
    object bStepX: TToolButton
      Left = 120
      Top = 23
      Caption = #1064#1072#1075' '#1087#1086' X'
      ImageIndex = 6
      OnClick = bStepXClick
    end
    object bStepY: TToolButton
      Left = 232
      Top = 23
      Caption = #1064#1072#1075' '#1087#1086' Y'
      ImageIndex = 7
      OnClick = bStepYClick
    end
    object bH: TToolButton
      Left = 344
      Top = 23
      Caption = #1064#1072#1075' '#1088#1072#1089#1089#1095#1077#1090#1072' '#1090#1072#1073#1083'.'
      ImageIndex = 8
      OnClick = bHClick
    end
  end
  object ImageList1: TImageList
    Left = 768
    Top = 16
  end
end
