unit Lab1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, math;

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
Memo1.Lines.Add('Лаб.раб.№1. гр. 41703120 Реут В.Л.');
end;

     procedure TForm1.Button1Click(Sender: TObject);
var
x, y, z : real;
d, b, c, a : real;
begin
   x := StrToFloat(Edit1.Text);   // Считывается значение x
// Вывод x в окно Memo1
  Memo1.Lines.Add('x = ' + Edit1.Text);
  y := StrToFloat(Edit2.Text);   // Считывается значение y
// Вывод y в окно Memol
  Memo1.Lines.Add('y =' + Edit2.Text);
  z := StrToFloat(Edit3.Text);  // Считывается значение z
// Вывод z в окно Memo1
  Memo1.Lines.Add('z = ' + Edit3.Text);
// Вычисляем арифметическое выражение
  a := ln(power(y, -abs(x)));
  b := x - (y / 2);
  c := sin(sqr(2)) * arctan(z);
  d:= a * b + c;
//Выводим результат в окно Memo1
  Memo1.Lines.Add('Результат d:= ' + FloatToStrF(d, ffFixed, 8, 3));

end;

end.
