unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Buttons;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    BitBtn1: TBitBtn;
    ComboBox1: TComboBox;
    Label3: TLabel;
    procedure FormActivate(Sender: TObject);
    procedure ComboBox1Click(Sender: TObject);
    procedure ComboBox1KeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}


   var
  Unit1_5: Tform1;




procedure TForm1.FormActivate(Sender: TObject);
begin
  ComboBox1.SetFocus; //�������� ������ ComboBox1
end;

 procedure TForm1.ComboBox1KeyPress(Sender: TObject; var Key: Char);
begin
   if Key =#13 then //���� ������ ������� Enter ��...
  begin
//  ������ �� ���� �������������� ��������� � ������ �����a
    ComboBox1.Items.Add(ComboBox1.Text);
    ComboBox1.Text := ''; //������� ���� ��������������
  end;

end;

procedure TForm1.ComboBox1Click(Sender: TObject);
const
  D = ['0', '1'];
var
  St : string;
  i, Len, Cnt, Cnt1, CntRes, nSt  : integer;
begin
//����������� ������ ��������� ������
  nSt := ComboBox1.ItemIndex;
//��������� ��������� ������ � ���������� st
  St := ComboBox1.Items[nst];
  Len := Length(St);
  Cnt := 0;
  Cnt1 := 0;
  CntRes := 0;
//�������� ���� �������� ������ st
  for i := 1 to Len do
  begin

     // ���������� ������� �� ������������� ��������� D.
     if not (St[i] in D) then
     begin
     Continue;
     end;

     // ������� ��������� � ������.
     Inc(Cnt);

     // ������� ������ � ������.
     if (St[i] = '1') then
     begin
     Inc(Cnt1);
     end;

     // ����� ��������� ������.
     if (i = Len) or (not (St[i + 1] in D)) then // ���� i = ������ ������,
     // ��� ��������� ����� i ������ �� �������� ���������� D.
     begin
       if (Cnt mod 2 <> 0) then
       begin
       CntRes := CntRes + Cnt1;
       end;

       Cnt := 0;
       Cnt1 := 0;
     end;
  end;
   Label3.Caption := IntToStr(CntRes); //����� ����� ���� � Label3

end;

end.
