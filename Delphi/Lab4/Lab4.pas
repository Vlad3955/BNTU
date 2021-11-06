unit Lab4;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.Grids, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    StringGrid1: TStringGrid;
    Edit2: TEdit;
    Edit3: TEdit;
    Label2: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

 const
  Nmax = 10; // Максимальная размерность массива
  Mmax = 10;
  Rmax = 100; // Максимально значение в таблице
type
  TMas2 = array[1..Nmax, 1..Mmax] of integer; // Объявление типа двумерного массива
var
  InputForm: TForm1;
  A : TMas2;       // Объявление двумерного массива
  N, M, i, j : integer;

var
  Form1: TForm1;

implementation

{$R *.dfm}


procedure TForm1.FormCreate(Sender: TObject);
begin
  M := 10;
  N := 10; // Размерность массива
  Edit1.Text := IntToStr(N);
  Edit2.Text := IntToStr(M);
  Edit3.Text := ''; // оставляем поле пустым, пока не нажмем Выполнить
// Задание числа строк и столбцов
  StringGrid1.ColCount := N + 1;
  StringGrid1.RowCount := M + 1;
// Ввод в левую верхнюю ячейку таблицы названия массива
  StringGrid1.Cells[0, 0] := 'Массив A';
// Заполнение верхнего и левого столбцов поясняющими подписями
  for i:=1 to N do
    for j:=1 to M do
  begin
    StringGrid1.Cells[0, i] := 'i='+ IntToStr(i);
    StringGrid1.Cells[i, 0] := 'j='+ IntToStr(i);
  end;
  {Заполение матрицы и TStringGrid случайными числами}
  for i:=1 to N do
    for j:=1 to M do
      begin
        A[i,j]:= random(RMax);
        StringGrid1.Cells[i,j] := IntToStr(A[i,j]);
      end;
end;

 // Процедура изменения разменрности массива
procedure TForm1.Button2Click(Sender: TObject);
begin
  Edit3.Text := ''; // очищаем поле
  N:=StrToInt(Edit1.Text);
  M:=StrToInt(Edit2.Text);
 {Задание числа строк и столбцов в таблицах}
  StringGrid1.ColCount := N+1;
  StringGrid1.RowCount := M+1;
  {Заполнение верхнего и левого столбцов поясняющими подписями}
  for i:=1 to N do
    for j:=1 to M do
      begin
        StringGrid1.Cells[0,i] := ' i = '+IntToStr(i);
        StringGrid1.Cells[i,0] := ' j = '+IntToStr(i);
      end;
      //Заполение матрицы и TStringGrid случайными числами
  for i := 1 to N do
    for j := 1 to M do
      begin
        A[i,j] := random(RMax);
        StringGrid1.Cells[i,j] := IntToStr(A[i,j]);
      end;
end;

//Ищем особые элементы
procedure TForm1.Button1Click(Sender: TObject);
  var
  i, j, k : Integer;
begin
  k := 0;
       For i := 1 To N Do
        For j := 2 To M - 1 Do
           Begin
             If (A[i, j] >A [i, j-1]) And (A[i, j] < A[i, j + 1])
             Then Inc(k);
           End;
  Edit3.Text := 'В матрице А :  ' + IntToStr(k) + ' "особых" элементов';
  end;

end.
