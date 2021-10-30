unit Lab1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Memo1: TMemo;
    Button1: TButton;
    Label4: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}


procedure TForm1.FormCreate(Sender: TObject);
begin
Edit1.Text := '3,4';
Edit2.Text := '0,74';
Edit3.Text := '19,43';
Memo1.Clear;
Memo1.Lines.Add('���.���.�1. ��. 41703120 ���� �.�.');
end;

     procedure TForm1.Button1Click(Sender: TObject);
var
x, y, z : real;
a, b, c, u : real;
begin
   x := StrToFloat(Edit1.Text);   // ����������� �������� x
// ����� x � ���� Memo1
  Memo1.Lines.Add('x = ' + Edit1.Text);
  y := StrToFloat(Edit2.Text);   // ����������� �������� y
// ����� y � ���� Memol
  Memo1.Lines.Add('y =' + Edit2.Text);
  z := StrToFloat(Edit3.Text);  // ����������� �������� z
// ����� z � ���� Memo1
  Memo1.Lines.Add('z = ' + Edit3.Text);
// ��������� �������������� ���������
  a := Sqr(Sin(x+y) / Cos(x+y));
  b := Exp(y-z);
  c := Sqrt(Cos(Sqr(x))+Sin(Sqr(z)));
  u:= a - b*c;
//������� ��������� � ���� Memo1
  Memo1.Lines.Add('��������� u:= ' + FloatToStrF(u, ffFixed, 8, 3));

end;

end.
