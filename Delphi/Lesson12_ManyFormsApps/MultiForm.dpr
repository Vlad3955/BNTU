program MultiForm;

uses
  Vcl.Forms,
  ufMain in 'ufMain.pas' {fMain},
  ufTicket in 'ufTicket.pas' {fTicket};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TfMain, fMain);
  Application.CreateForm(TfTicket, fTicket);
  Application.Run;
end.
