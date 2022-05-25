object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
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
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 608
    Height = 385
  end
  object Button1: TButton
    Left = 8
    Top = 408
    Width = 115
    Height = 25
    Caption = 'Previous'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 504
    Top = 408
    Width = 115
    Height = 25
    Caption = 'Close'
    TabOrder = 1
    OnClick = Button2Click
  end
end
