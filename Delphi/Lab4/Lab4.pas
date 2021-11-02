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
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;
    procedure FormCreate(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

 const
  Nmax = 10; // ������������ ����������� �������
type
  TMas1 = array[1..Nmax] of Extended; // ���������� ���� ����������� �������
  TMas2 = array[1..Nmax, 1..Nmax] of Extended; // ���������� ���� ���������� �������
var
  InputForm: TForm1;
  A : TMas2;       // ���������� ���������� �������
  B, Y : TMas1;  // ���������� ���������� ��������
  N, i, j : integer;

var
  Form1: TForm1;

implementation

{$R *.dfm}


procedure TForm1.FormCreate(Sender: TObject);
begin
  N := 3; // ����������� �������
  Edit1.Text := IntToStr(N);
// ������� ����� ����� � ��������
  StringGrid1.ColCount := N + 1;
  StringGrid1.RowCount := N + 1;
  StringGrid2.RowCount := N + 1;
  StringGrid3.RowCount := N + 1;
// ���� � ����� ������� ������ ������� �������� �������
  StringGrid1.Cells[0, 0] := '������ A';
  StringGrid2.Cells[0, 0] := '������ B';
  StringGrid3.Cells[0, 0] := '������ Y';
// ���������� �������� � ������ �������� ����������� ���������
  for i:=1 to N do
  begin
    StringGrid1.Cells[0, i] := 'i='+ IntToStr(i);
    StringGrid1.Cells[i, 0] := 'j='+ IntToStr(i);
  end;

end;


procedure TForm1.Button2Click(Sender: TObject);
begin
  N := StrToInt(Edit1.Text);
// ������� ����� ����� � �������� � ��������
  StringGrid1.ColCount := N + 1;
  StringGrid1.RowCount := N + 1;
  StringGrid2.RowCount := N + 1;
  StringGrid3.RowCount := N + 1;
// ���������� �������� � ������ �������� ����������� ���������
  for i:=1 to N do
  begin
    StringGrid1.Cells[0, i] := 'i=' + IntToStr(i);
    StringGrid1.Cells[i, 0] := 'j=' + IntToStr(i);
  end;

end;

procedure TForm1.Button1Click(Sender: TObject);
var
  s : extended;

begin
// ���������� ������� A ���������� �� ������� StringGrid1
  for i:=1 to N do
  for j:=1 to N do
    A[i, j] := StrToFloat(StringGrid1.Cells[j, i]);
// ���������� ������� B ���������� �� ������� StringGrid2
  for i:=1 to N do
    B[i] := StrToFloat(StringGrid2.Cells[0, i]);
// ��������� ������� A �� ������ B
  for i:=1 to N do
  begin
    s := 0;
    for j:=1 to N do
    s := s + A[i, j]*B[j];
    Y[i] := s;
// ����� ���������� � ������� StringGrid3
    StringGrid3.Cells[0, i] := FloatToStrF(Y[i], ffFixed, 6, 2);
  end;

end;

end.
