unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Buttons;

type
  TForm1 = class(TForm)
    Label1: TLabel;
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
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Memo2: TMemo;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
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
  TATC=record
    data: string[40];           // ����
    numbers: array[1..2] of int64;      //������ �������
    tariff : extended;          // �����
    time:double;               //����� ���������
    cityname:string[40];    //�������� ������
    citycode:word;
  end;
Var
  Fz  : file of  TATC;      // ���� ���� ������
  Ft  : TextFile;           // ��������� ����
  ATC : array[1..100] of TATC;  // ������ �������
  nzap : integer;           // ����� ������
  FileNameZ, FileNameT : string;    // ��� �����


var
  Form1: TForm1;

implementation

{$R *.dfm}









procedure TForm1.FormCreate(Sender: TObject);
begin
  //Memo1.Clear;
  Button1.Hide; //������� ��������� ������ "������ ������"
end;



procedure TForm1.Button1Click(Sender: TObject);
  var
  I: integer;
begin
  nzap:=nzap+1;
  with ATC[nzap] do
  begin
           data:=Edit1.Text;
           numbers[1]:=StrToInt(Edit6.Text);
           numbers[2]:=StrToInt(Edit7.Text);
           citycode:=StrToInt(Edit2.Text);
           cityname:=Edit3.Text;
           time:=StrToFloat(Edit4.Text);
           tariff:=StrToFloat(Edit5.Text);
  Memo1.Lines.Add(data+'  '+IntToStr(numbers[1])+'  '+ IntToStr(numbers[2])+'   '+IntToStr(citycode)+'   '+cityname+'     '+FloatToStr(time)+'    '+FloatToStr(tariff));

  end;
     Write(fz,ATC[nzap]);                   // ������ � ����
   Edit1.Text:='';
   Edit2.Text:='';
   Edit3.Text:='';
   Edit4.Text:='';
   Edit5.Text:='';
   Edit6.Text:='';
   Edit7.Text:='';
end;

 procedure TForm1.Button2Click(Sender: TObject);
begin
  OpenDialog1.Title :='������� ����� ����';    // ��������� ��������� ���� �������
 if OpenDialog1.Execute then  // ���������� ������������ ������� ������ ����� �����
   begin
    FileNameZ:= OpenDialog1.FileName; // ����������� ����� ��������� �����
    AssignFile(Fz, FileNameZ);  // ���������� �������� ���������� Fz c ������ �����
     Rewrite(Fz);                         // �������� ������ �����
   end;
    Button1.Show;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
   if OpenDialog1.Execute then  // ���������� ������������ ������� ������ ����� �����
   begin
    FileNameZ:= OpenDialog1.FileName; // ����������� ����� ��������� �����
    AssignFile(Fz, FileNameZ);    // ���������� �������� ���������� Fz c ������ �����
     Reset(Fz);                                // �������� ������������� �����
   end;
  while not eof(fz) do begin
   nzap:=nzap+1;
      Read(fz,ATC[nzap]);                // ������ ������ �� �����
         with ATC[nzap] do
     Memo1.Lines.Add(data+'  '+IntToStr(numbers[1])+'  '+ IntToStr(numbers[2])+'   '+IntToStr(citycode)+'   '+cityname+'     '+FloatToStr(time)+'    '+FloatToStr(tariff));
end;
    Button1.Show; //������� ������� ������ "������ ������"
end;


procedure TForm1.Button4Click(Sender: TObject);
  // ���������� �������
var
  i  : word;
 begin
  if SaveDialog1.Execute then  // ���������� ������������ ������� ������ ����� �����
    begin
    FileNameT:= SaveDialog1.FileName; // ����������� ����� ��������� �����
    AssignFile(Ft, FileNameT);     // ���������� �������� ���������� Ft c ������ �����
      Rewrite(Ft);                           // �������� ������ ���������� �����
    end;
  for i:=1 to nzap do
         with ATC[i] do  Writeln(Ft,i:4,'. ',data,numbers[1],numbers[2],citycode,cityname,time,tariff);
                     // ������ � ��������� ����
  CloseFile(Ft);                             // �������� ���������� �����
end;


procedure TForm1.Button5Click(Sender: TObject);
 // ��������� ������ ��������� ���������� �� �������
var
  i,j,k:integer;
  temp,temp2,temp3:extended;
begin
 for i := 1 to nzap do
begin
Memo2.Lines.Add('�����: '+ATC[i].cityname);
Memo2.Lines.Add('����� �����: '+FloatToStr(ATC[i].time));
Memo2.Lines.Add('����� ����� : '+FloatToStr(ATC[i].time * ATC[i].tariff ));
end

end;

 procedure TForm1.BitBtn1Click(Sender: TObject);
begin
  //CloseFile(fz);
// �������� ����� ������� ��� ������� �� ������ "Close"
end;

end.
