object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 424
  ClientWidth = 651
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
    Left = 8
    Top = 11
    Width = 25
    Height = 15
    Caption = #1044#1072#1090#1072
  end
  object Label3: TLabel
    Left = 8
    Top = 82
    Width = 61
    Height = 15
    Caption = #1050#1086#1076' '#1075#1086#1088#1086#1076#1072
  end
  object Label4: TLabel
    Left = 8
    Top = 132
    Width = 93
    Height = 15
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1075#1086#1088#1086#1076#1072
  end
  object Label5: TLabel
    Left = 8
    Top = 180
    Width = 94
    Height = 15
    Caption = #1042#1088#1077#1084#1103' '#1088#1072#1079#1075#1086#1074#1086#1088#1072
  end
  object Label6: TLabel
    Left = 360
    Top = 82
    Width = 35
    Height = 15
    Caption = #1058#1072#1088#1080#1092
  end
  object Label7: TLabel
    Left = 360
    Top = 132
    Width = 44
    Height = 15
    Caption = #1053#1086#1084#1077#1088'1'
  end
  object Label8: TLabel
    Left = 360
    Top = 180
    Width = 47
    Height = 15
    Caption = #1053#1086#1084#1077#1088' 2'
  end
  object Edit1: TEdit
    Left = 50
    Top = 8
    Width = 178
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 107
    Top = 79
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 107
    Top = 129
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 107
    Top = 177
    Width = 121
    Height = 23
    TabOrder = 3
  end
  object BitBtn1: TBitBtn
    Left = 504
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 4
    OnClick = BitBtn1Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 257
    Width = 313
    Height = 129
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object Button1: TButton
    Left = 542
    Top = 216
    Width = 99
    Height = 25
    Caption = #1042#1074#1077#1089#1090#1080' '#1079#1072#1087#1080#1089#1100
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 392
    Width = 75
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 128
    Top = 392
    Width = 75
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 248
    Top = 392
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 376
    Top = 392
    Width = 75
    Height = 25
    Caption = #1055#1086#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 10
    OnClick = Button5Click
  end
  object Edit5: TEdit
    Left = 424
    Top = 79
    Width = 121
    Height = 23
    TabOrder = 11
  end
  object Edit6: TEdit
    Left = 424
    Top = 129
    Width = 121
    Height = 23
    TabOrder = 12
  end
  object Edit7: TEdit
    Left = 424
    Top = 177
    Width = 121
    Height = 23
    TabOrder = 13
  end
  object Memo2: TMemo
    Left = 352
    Top = 257
    Width = 289
    Height = 129
    Lines.Strings = (
      'Memo2')
    TabOrder = 14
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '.dat'
    Filter = #1060#1072#1081#1083#1099' '#1076#1072#1085#1085#1099#1093'|*.dat|'#1042#1089#1077' '#1092#1072#1081#1083#1099'|*.*'
    Left = 568
    Top = 160
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.txt'
    Left = 568
    Top = 88
  end
end
