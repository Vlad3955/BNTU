object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 447
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  PixelsPerInch = 96
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 416
    Width = 115
    Height = 25
    Caption = 'Load'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 256
    Top = 416
    Width = 115
    Height = 25
    Caption = 'Close'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 501
    Top = 416
    Width = 115
    Height = 25
    Caption = 'Next'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 600
    Height = 400
    TabOrder = 3
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 598
      Height = 398
      Align = alClient
      ExplicitWidth = 606
      ExplicitHeight = 368
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 432
    Top = 240
  end
end
