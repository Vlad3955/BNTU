object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 442
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
    Left = 48
    Top = 65
    Width = 21
    Height = 17
    Caption = 'X ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 110
    Width = 16
    Height = 17
    Caption = 'i ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 72
    Top = 62
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 72
    Top = 107
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit2'
  end
  object Button1: TButton
    Left = 184
    Top = 408
    Width = 75
    Height = 25
    Caption = #1042#1099#1095#1077#1089#1083#1080#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 16
    Top = 184
    Width = 409
    Height = 209
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object RadioGroup1: TRadioGroup
    Left = 240
    Top = 46
    Width = 185
    Height = 105
    Caption = 'f(x)'
    Items.Strings = (
      'sh(x)'
      'x^2'
      'exp(x)')
    TabOrder = 4
  end
end
