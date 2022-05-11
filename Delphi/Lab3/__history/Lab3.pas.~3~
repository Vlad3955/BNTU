unit Lab3;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, math;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Button1: TButton;
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
Edit1.Text:='0,1';
Edit2.Text:='1';
Edit3.Text:='14';
Edit4.Text:=FloatToStr((1-0.1)/14);
Memo1.Clear;
Memo1.Lines.Add('Результаты ст. гр. 41703120 Реут В.Л.');

end;

procedure TForm1.Button1Click(Sender: TObject);
 var
  x,Xk,Xn,x2n,h,S,Y,deltas, Yy : real;
  n,nf,i : int64;
Begin
  Xn:=StrToFloat(edit1.Text);
  Memo1.Lines.Add('Xn = ' + Edit1.Text);
  Xk:=StrToFloat(edit2.Text);
  //If x2<x1 Then
  //Begin
   // x:=x1;
    //x1:=x2;
   // x2:=x;
 // End;
  Memo1.Lines.Add('Xk = ' + Edit2.Text);
  n:=StrToInt(edit3.Text);
  Memo1.Lines.Add('N = ' + Edit3.Text);
  h:=(Xk-Xn)/n;
  edit4.Text:=FloatToStr(h);
  Memo1.Lines.Add('H = ' + Edit4.Text);
  x:=Xn;
  Repeat
    //Вычисление S
    S:=1;
    nf:=1;
    x2n:=1;
    For i:=1 To n Do
    Begin
      nf:=nf*i;     // n!
      x2n:=x2n*x*x; // x^(2*n)
      deltas:=(2*i+1)*x2n/nf;
      S:=S+deltas;
    End;
    //Вычисление Y
    Yy:=x*x;
    Y:=(1+2*Yy)*exp(Yy);

    Memo1.Lines.Add('Пpи x = ' + FloatToStrF(x, ffFixed,5,3)+
    '   S = ' + FloatToStrF(S, ffFixed,12,10)+ '    Y = '+
    FloatToStrF(Y, ffFixed,12,10));

    x:=x+h;
  Until x>Xk;
end;

end.
