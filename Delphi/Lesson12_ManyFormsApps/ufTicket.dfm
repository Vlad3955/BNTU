object fTicket: TfTicket
  Left = 0
  Top = 0
  Caption = 'fTicket'
  ClientHeight = 121
  ClientWidth = 209
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 15
  object pBottom: TPanel
    Left = 0
    Top = 80
    Width = 209
    Height = 41
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    ExplicitLeft = 498
    ExplicitTop = 0
    ExplicitWidth = 409
    object Button1: TButton
      Left = 16
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Ok'
      TabOrder = 0
    end
    object Button2: TButton
      Left = 112
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Cancel'
      TabOrder = 1
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 209
    Height = 80
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    ExplicitTop = -6
    ExplicitWidth = 539
    ExplicitHeight = 368
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 76
      Height = 15
      Caption = 'Ticket number'
    end
    object eTicketNumber: TEdit
      Left = 8
      Top = 37
      Width = 121
      Height = 23
      TabOrder = 0
    end
  end
end
