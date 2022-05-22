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
  OnShow = FormShow
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
    object bOk: TButton
      Left = 16
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Ok'
      ModalResult = 1
      TabOrder = 0
    end
    object Button2: TButton
      Left = 112
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Cancel'
      ModalResult = 2
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
