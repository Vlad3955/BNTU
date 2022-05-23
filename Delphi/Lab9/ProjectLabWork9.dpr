program ProjectLabWork9;

uses
  Vcl.Forms,
  LabWork9 in 'LabWork9.pas' {Form1},
  MatFunc in 'MatFunc.pas',
  Unit2 in 'Unit2.pas' {Form2};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
