unit ufMain;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, Vcl.Buttons, ufTicket;

type
  TfMain = class(TForm)
    Panel1: TPanel;
    lbTickets: TListBox;
    SpeedButton1: TSpeedButton;
    bAddTicket: TButton;
    procedure bAddTicketClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  fMain: TfMain;

implementation

{$R *.dfm}

procedure TfMain.bAddTicketClick(Sender: TObject);
var
  s: String;
  res: Integer;
begin
  res := fTicket.ShowModal;
  if res = mrOk then
  begin
  s := fTicket.eTicketNumber.Text;
  if s <> '' then
    lbTickets.Items.Add(s);
  end;
end;

end.
