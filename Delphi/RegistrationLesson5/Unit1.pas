unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    eFullName: TEdit;
    bRegistration: TButton;
    Label2: TLabel;
    lCount: TLabel;
    Button1: TButton;
    mInfo: TMemo;
    procedure bRegistrationClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  Passagers: array[1..10] of String;
  PassagersCount: integer;

implementation

{$R *.dfm}



procedure TForm1.bRegistrationClick(Sender: TObject);
begin
  PassagersCount := PassagersCount + 1;
  Passagers[PassagersCount] := eFullName.Text;
  lCount.Caption := IntToStr(PassagersCount);
  eFullName.Text := '';
  eFullName.SetFocus;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  i: integer;
begin
  mInfo.Clear;
  mInfo.Lines.Add('Passangers: ');
  //mInfo.Lines.Add(Passagers[1]);
  //mInfo.Lines.Add(Passagers[2]);
  for i := 1 to PassagersCount do
    mInfo.Lines.Add(Passagers[i]);
  Showmessage('End');
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  PassagersCount := 0;
end;

end.
