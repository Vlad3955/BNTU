object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1051#1072#1073'. '#1088#1072#1073'. '#8470'4 '#1089#1090'. '#1075#1088'. 41703120 '#1056#1077#1091#1090' '#1042'.'#1051'.'
  ClientHeight = 387
  ClientWidth = 466
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 25
    Top = 28
    Width = 20
    Height = 15
    Caption = 'N ='
  end
  object Label2: TLabel
    Left = 25
    Top = 57
    Width = 22
    Height = 15
    Caption = 'M ='
  end
  object Button1: TButton
    Left = 25
    Top = 354
    Width = 78
    Height = 25
    Caption = #1042#1099#1095#1077#1089#1083#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 40
    Width = 266
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1088#1072#1079#1084#1077#1088#1085#1086#1089#1090#1100' '#1084#1072#1089#1089#1080#1074#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 51
    Top = 25
    Width = 89
    Height = 23
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 25
    Top = 96
    Width = 417
    Height = 230
    ColCount = 2
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 51
    Top = 54
    Width = 89
    Height = 23
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 136
    Top = 356
    Width = 306
    Height = 23
    TabOrder = 5
  end
end
