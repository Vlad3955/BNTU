object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 543
  ClientWidth = 826
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 826
    Height = 543
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Data'
      object Label10: TLabel
        Left = 22
        Top = 25
        Width = 31
        Height = 15
        Caption = 'Xmin:'
      end
      object Label11: TLabel
        Left = 20
        Top = 98
        Width = 33
        Height = 15
        Caption = 'Xmax:'
      end
      object Label12: TLabel
        Left = 20
        Top = 191
        Width = 30
        Height = 15
        Caption = 'Ymin:'
      end
      object Label13: TLabel
        Left = 20
        Top = 293
        Width = 32
        Height = 15
        Caption = 'Ymax:'
      end
      object Label14: TLabel
        Left = 404
        Top = 95
        Width = 106
        Height = 15
        Caption = #1064#1072#1075' '#1088#1072#1079#1084#1077#1090#1082#1080' '#1087#1086' X:'
      end
      object Label15: TLabel
        Left = 404
        Top = 164
        Width = 106
        Height = 15
        Caption = #1064#1072#1075' '#1088#1072#1079#1084#1077#1090#1082#1080' '#1087#1086' Y:'
      end
      object Label16: TLabel
        Left = 17
        Top = 440
        Width = 122
        Height = 15
        Caption = #1064#1072#1075' '#1088#1072#1089#1095#1077#1090#1072' '#1090#1072#1073#1083#1080#1094#1099':'
      end
      object Label17: TLabel
        Left = 404
        Top = 25
        Width = 7
        Height = 15
        Caption = 'Y'
      end
      object Label18: TLabel
        Left = 404
        Top = 275
        Width = 7
        Height = 15
        Caption = 'Z'
      end
      object Edit10: TEdit
        Left = 224
        Top = 22
        Width = 106
        Height = 23
        TabOrder = 0
      end
      object Edit11: TEdit
        Left = 224
        Top = 92
        Width = 106
        Height = 23
        TabOrder = 1
      end
      object Edit12: TEdit
        Left = 224
        Top = 188
        Width = 106
        Height = 23
        TabOrder = 2
      end
      object Edit13: TEdit
        Left = 224
        Top = 272
        Width = 106
        Height = 23
        TabOrder = 3
      end
      object Button2: TButton
        Left = 606
        Top = 430
        Width = 153
        Height = 27
        Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
        TabOrder = 4
        OnClick = Button1Click
      end
      object Edit14: TEdit
        Left = 684
        Top = 92
        Width = 74
        Height = 23
        TabOrder = 5
      end
      object Edit15: TEdit
        Left = 685
        Top = 161
        Width = 74
        Height = 23
        TabOrder = 6
      end
      object Edit16: TEdit
        Left = 256
        Top = 432
        Width = 74
        Height = 23
        TabOrder = 7
      end
      object Edit17: TEdit
        Left = 652
        Top = 22
        Width = 106
        Height = 23
        TabOrder = 8
      end
      object Edit18: TEdit
        Left = 685
        Top = 272
        Width = 74
        Height = 23
        TabOrder = 9
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Chart'
      ImageIndex = 1
      object Chart1: TChart
        Left = 3
        Top = 0
        Width = 654
        Height = 513
        Title.Text.Strings = (
          'TChart')
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TLineSeries
          HoverElement = [heCurrent]
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series2: TLineSeries
          HoverElement = [heCurrent]
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
  end
end
