object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 493
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
    Top = 24
    Width = 149
    Height = 15
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1085#1072#1095#1072#1083#1086' '#1080#1085#1090#1077#1088#1074#1072#1083#1072':'
  end
  object Label2: TLabel
    Left = 8
    Top = 60
    Width = 142
    Height = 15
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1082#1086#1085#1077#1094' '#1080#1085#1090#1077#1088#1074#1072#1083#1072':'
  end
  object Label3: TLabel
    Left = 8
    Top = 98
    Width = 71
    Height = 15
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1096#1072#1075':'
  end
  object Edit1: TEdit
    Left = 192
    Top = 21
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 192
    Top = 57
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 192
    Top = 95
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object RadioGroup1: TRadioGroup
    Left = 352
    Top = 21
    Width = 113
    Height = 105
    Caption = #1060#1091#1085#1082#1094#1080#1103
    Items.Strings = (
      'Tg(x)'
      'Ch(x)'
      'Sin(x)*Sin(x)')
    TabOrder = 3
  end
  object Memo1: TMemo
    Left = 16
    Top = 160
    Width = 457
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object Button1: TButton
    Left = 104
    Top = 399
    Width = 89
    Height = 34
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 288
    Top = 399
    Width = 89
    Height = 34
    Caption = 'Close'
    TabOrder = 6
    OnClick = Button2Click
  end
end
