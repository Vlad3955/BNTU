object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
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
    Width = 36
    Height = 15
    Caption = #1060'.'#1048'.'#1054'.'
  end
  object Label2: TLabel
    Left = 8
    Top = 50
    Width = 45
    Height = 15
    Caption = #1054#1094#1077#1085#1082#1080':'
  end
  object Label3: TLabel
    Left = 8
    Top = 82
    Width = 67
    Height = 15
    Caption = #1052#1072#1090#1077#1084#1072#1090#1080#1082#1072
  end
  object Label4: TLabel
    Left = 8
    Top = 132
    Width = 40
    Height = 15
    Caption = #1060#1080#1079#1080#1082#1072
  end
  object Label5: TLabel
    Left = 8
    Top = 180
    Width = 62
    Height = 15
    Caption = #1057#1086#1095#1080#1085#1077#1085#1080#1077
  end
  object Edit1: TEdit
    Left = 50
    Top = 8
    Width = 513
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 96
    Top = 79
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 96
    Top = 129
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 96
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
    Top = 248
    Width = 601
    Height = 129
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object Button1: TButton
    Left = 480
    Top = 208
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
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 376
    Top = 392
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 10
    OnClick = Button5Click
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '.dat'
    Filter = #1060#1072#1081#1083#1099' '#1076#1072#1085#1085#1099#1093'|*.dat|'#1042#1089#1077' '#1092#1072#1081#1083#1099'|*.*'
    Left = 384
    Top = 152
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.txt'
    Left = 408
    Top = 56
  end
end
