program ProjectLab3;

uses
  Vcl.Forms,
  Lab3 in 'Lab3.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
