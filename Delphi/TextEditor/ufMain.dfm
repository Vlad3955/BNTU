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
  Menu = MainMenu
  PixelsPerInch = 96
  TextHeight = 15
  object Memo: TMemo
    Left = 0
    Top = 0
    Width = 624
    Height = 441
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 232
    ExplicitTop = 208
    ExplicitWidth = 185
    ExplicitHeight = 89
  end
  object MainMenu: TMainMenu
    Left = 56
    Top = 136
    object File1: TMenuItem
      Caption = 'File'
      object Save1: TMenuItem
        Caption = 'Save'
        ShortCut = 16467
      end
      object Open1: TMenuItem
        Caption = 'Open'
        ShortCut = 16463
      end
    end
    object Settings1: TMenuItem
      Caption = 'Settings'
      object Font1: TMenuItem
        Caption = 'Font'
      end
      object Font2: TMenuItem
        Caption = 'Background color'
      end
    end
  end
end
