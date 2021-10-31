object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 448
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  PixelsPerInch = 96
  TextHeight = 15
  object Edit1: TEdit
    Left = 24
    Top = 38
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 24
    Top = 83
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 24
    Top = 128
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'Edit3'
  end
  object Button1: TButton
    Left = 168
    Top = 408
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
  end
  object Memo1: TMemo
    Left = 128
    Top = 296
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
  object CheckBox1: TCheckBox
    Left = 296
    Top = 16
    Width = 97
    Height = 17
    Caption = 'MaxAbs'
    TabOrder = 5
  end
  object RadioGroup1: TRadioGroup
    Left = 240
    Top = 46
    Width = 185
    Height = 105
    Caption = 'U(x)'
    Items.Strings = (
      'Cos(x)'
      'Sin(x)'
      'tg(x)')
    TabOrder = 6
  end
end
