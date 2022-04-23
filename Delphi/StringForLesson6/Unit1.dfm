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
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 3
    Width = 79
    Height = 15
    Caption = 'Phone number'
  end
  object Label2: TLabel
    Left = 344
    Top = 3
    Width = 39
    Height = 15
    Caption = 'Phones'
  end
  object ePhone: TEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object bAddPhone: TButton
    Left = 54
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = bAddPhoneClick
  end
  object mTruePhones: TMemo
    Left = 344
    Top = 24
    Width = 272
    Height = 89
    TabOrder = 2
  end
  object mPhoneList: TMemo
    Left = 8
    Top = 113
    Width = 217
    Height = 265
    TabOrder = 3
  end
  object bAddPhonesList: TButton
    Left = 120
    Top = 384
    Width = 105
    Height = 25
    Caption = 'Add phones list'
    TabOrder = 4
    OnClick = bAddPhonesListClick
  end
end
