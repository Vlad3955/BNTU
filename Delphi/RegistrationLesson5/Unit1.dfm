object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Registration'
  ClientHeight = 355
  ClientWidth = 223
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
    Top = 8
    Width = 52
    Height = 15
    Caption = 'Full name'
  end
  object Label2: TLabel
    Left = 8
    Top = 58
    Width = 52
    Height = 15
    Caption = 'Registred:'
  end
  object lCount: TLabel
    Left = 122
    Top = 59
    Width = 7
    Height = 15
    Alignment = taRightJustify
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object eFullName: TEdit
    Left = 8
    Top = 29
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object bRegistration: TButton
    Left = 135
    Top = 28
    Width = 75
    Height = 25
    Caption = 'Registration'
    TabOrder = 1
    OnClick = bRegistrationClick
  end
  object Button1: TButton
    Left = 8
    Top = 81
    Width = 202
    Height = 25
    Caption = 'Passagers list'
    TabOrder = 2
    OnClick = Button1Click
  end
  object mInfo: TMemo
    Left = 8
    Top = 112
    Width = 202
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 3
  end
end
