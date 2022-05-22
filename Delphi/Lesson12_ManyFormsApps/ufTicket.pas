unit ufTicket;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TfTicket = class(TForm)
    pBottom: TPanel;
    Panel1: TPanel;
    eTicketNumber: TEdit;
    Label1: TLabel;
    bOk: TButton;
    Button2: TButton;
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  fTicket: TfTicket;

implementation

{$R *.dfm}

procedure TfTicket.FormShow(Sender: TObject);
begin
  eTicketNumber.Text := '';
  eTicketNumber.SetFocus;
end;

end.
