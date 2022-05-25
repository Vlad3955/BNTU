object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
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
  object Shape1: TShape
    Left = 144
    Top = 24
    Width = 441
    Height = 353
  end
  object Button1: TButton
    Left = 16
    Top = 24
    Width = 113
    Height = 25
    Caption = 'Rectangle'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 80
    Width = 113
    Height = 25
    Caption = 'Square'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 16
    Top = 144
    Width = 113
    Height = 25
    Caption = 'Circle'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 16
    Top = 208
    Width = 113
    Height = 25
    Caption = 'Elipse'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 16
    Top = 392
    Width = 113
    Height = 25
    Caption = 'Previous'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 472
    Top = 392
    Width = 113
    Height = 25
    Caption = 'Next'
    TabOrder = 5
    OnClick = Button6Click
  end
end
