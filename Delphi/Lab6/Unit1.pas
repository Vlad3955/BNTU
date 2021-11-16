unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Buttons;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    BitBtn1: TBitBtn;
    OpenDialog1: TOpenDialog;
    SaveDialog1: TSaveDialog;
    Memo1: TMemo;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;


Type
  TStudent = record
    FIO  : string[40];               //���� �.�.�.
    otc  : array[1..3] of word;  //���� ������� ������
    sball  : extended;               //���� �������� �����
  end;

var
  Fz   : file of TStudent;                  //���� ���� ������
  Ft   : TextFile;                              //��������� ����
  Stud : array[1..100] of TStudent; //������ �������
  Nzap : integer;                             //����� ������
  FileNameZ, FileNameT : string; //����� ������


var
  Form1: TForm1;

implementation

{$R *.dfm}









procedure TForm1.FormCreate(Sender: TObject);
begin
  Edit1.Text := '';
  Edit2.Text := '';
  Edit3.Text := '';
  Edit4.Text := '';
  Memo1.Clear;
  Button1.Hide; //������� ��������� ������ "������ ������"
  Nzap := 0;
end;



procedure TForm1.Button1Click(Sender: TObject);
begin
    nzap := nzap + 1;
  with stud[nzap] do
  begin
    FIO    := Edit1.Text;
    otc[1] := StrToInt(Edit2.Text);
    otc[2] := StrToInt(Edit3.Text);
    otc[3] := StrToInt(Edit4.Text);
    sball  := (otc[1] + otc[2] + otc[3])/3;
    Memo1.Lines.Add(fio + ' ' + IntToStr(otc[1 ]) +
      ' ' + IntToStr(otc[2]) + ' ' + IntToStr(otc[3]));
  end;

  Write(fz, Stud[nzap]);   //������ � ����
  Edit1.Text := '';
  Edit2.Text := '';
  Edit3.Text := '';
  Edit4.Text := '';
end;

 procedure TForm1.Button2Click(Sender: TObject);
begin
  OpenDialog1.Title := '������� ����� ����';
// ��������� ��������� ���� �������
   if OpenDialog1.Execute then
// ���������� ������������ ������� ������ ����� �����
  begin
    FileNameZ := OpenDialog1.FileName;
//  ����������� ����� ��������� �����
    AssignFile(Fz, FileNameZ);
//  ���������� �������� ���������� Fz � ������ �����
    Rewrite(Fz);  //�������� ������ �����
    Button1.Show; //������� ������� ������ "������ ������"
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  if OpenDialog1.Execute then
//���������� ������������ ������� ������ ����� �����
  begin
    FileNameZ := OpenDialog1.FileName;
//  ����������� ����� ��������� �����
    AssignFile(Fz, FileNameZ);
//  ���������� �������� ���������� Fz � ������ �����
    Reset(Fz); //�������� ������������� �����
  end;

  While not EOF(fz) do
  begin
    nzap := nzap + 1;
    Read(fz, stud[nzap]);  //������ ������ �� �����
    with stud[nzap] do
      Memo1.Lines.Add(fio + '' + IntToStr(otc[1]) +
      ' ' + IntToStr(otc[2]) + '' + IntToStr(otc[3]));
    end;
    Button1.Show; //������� ������� ������ "������ ������"
end;


procedure TForm1.Button4Click(Sender: TObject);
  // ���������� �������
var
  i, j : word;
  st   : Tstudent;

begin
  for i := 1 to nzap-1 do
  for j := i + 1 to nzap do
  if Stud[i].sball < Stud[j].sball then
  begin
    st := Stud[i];
    Stud[i] := Stud[j];
    Stud[j] := st;
  end;

  Memo1.Clear;
  for i := 1 to nzap do
// ����� � ���� Memo1 ��������������� �������
  with stud[i] do
    Memo1.Lines.Add(IntToStr(i) + ' ' +
    fio + ' ' + FloatToStrF(sball, ffFixed, 4, 2));
end;


procedure TForm1.Button5Click(Sender: TObject);
  // ����������� ����������� ���������� � ��������� �����
var
  i : word;

begin
  if SaveDialog1.Execute then
// ���������� ������������ ������� ������ ����� �����
  begin
    FileNameT := SaveDialog1.FileName;
//  ����������� ����� ��������� �����
    AssignFile(Ft, FileNameT);
//  ���������� �������� ���������� Ft � ������ �����
    Rewrite(Ft); //�������� ������ ���������� �����
  end;

  for i:=1 to nzap do
  with stud[i] do
    Writeln(Ft, i:4, '.', fio, sball:8:2);
//  ������ � ��������� ����
    CloseFile(Ft); //�������� ���������� �����
end;

 procedure TForm1.BitBtn1Click(Sender: TObject);
begin
   if SaveDialog1.Execute then
  CloseFile(fz);
// �������� ����� ������� ��� ������� �� ������ "Close"
end;

end.
