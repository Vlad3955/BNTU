program ProjectLab4;

uses
  Vcl.Forms,
  Lab4 in 'Lab4.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
