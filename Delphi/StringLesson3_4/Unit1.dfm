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
    Width = 6
    Height = 15
    Caption = '0'
  end
  object Label2: TLabel
    Left = 199
    Top = 85
    Width = 76
    Height = 15
    Caption = 'Text for search'
  end
  object Label3: TLabel
    Left = 199
    Top = 149
    Width = 80
    Height = 15
    Caption = 'Text for replace'
  end
  object Memo1: TMemo
    Left = 8
    Top = 24
    Width = 185
    Height = 193
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Button1: TButton
    Left = 199
    Top = 23
    Width = 75
    Height = 25
    Caption = 'Upper Case'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 199
    Top = 54
    Width = 75
    Height = 25
    Caption = 'Lower Case'
    TabOrder = 2
    OnClick = Button2Click
  end
  object eTextToFind: TEdit
    Left = 199
    Top = 106
    Width = 121
    Height = 23
    TabOrder = 3
  end
  object Button3: TButton
    Left = 326
    Top = 105
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 4
    OnClick = Button3Click
  end
  object eTextToReplace: TEdit
    Left = 199
    Top = 170
    Width = 121
    Height = 23
    TabOrder = 5
  end
  object Button4: TButton
    Left = 326
    Top = 169
    Width = 75
    Height = 25
    Caption = 'Replace'
    TabOrder = 6
    OnClick = Button4Click
  end
end
