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
    Left = 24
    Top = 8
    Width = 79
    Height = 15
    Caption = 'Phone number'
  end
  object Label2: TLabel
    Left = 424
    Top = 8
    Width = 32
    Height = 15
    Caption = 'Result'
  end
  object eSearchField: TEdit
    Left = 24
    Top = 29
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object mPhonesForSearch: TMemo
    Left = 24
    Top = 58
    Width = 185
    Height = 255
    TabOrder = 1
  end
  object bSearch: TButton
    Left = 134
    Top = 336
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 2
    OnClick = bSearchClick
  end
  object mPhonesAfterSearch: TMemo
    Left = 368
    Top = 29
    Width = 185
    Height = 284
    TabOrder = 3
  end
  object bClear: TButton
    Left = 368
    Top = 336
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 4
    OnClick = bClearClick
  end
end
