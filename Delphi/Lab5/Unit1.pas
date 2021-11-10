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
  ComboBox1.SetFocus; //Передача фокуса ComboBox1
end;

 procedure TForm1.ComboBox1KeyPress(Sender: TObject; var Key: Char);
begin
   if Key =#13 then //Если нажата клавиша Enter то...
  begin
//  Строка из окна редактирования заносится в список выборa
    ComboBox1.Items.Add(ComboBox1.Text);
    ComboBox1.Text := ''; //Очистка окна редактирования
  end;

end;

procedure TForm1.ComboBox1Click(Sender: TObject);
var
  St : string;
  n, i, nst, ind  : integer;
begin
   n   := 0; //Содержит число слов выбранной строки
  ind := 0; //Содержит число слов
//Определение номера выбранной строки
  nSt := ComboBox1.ItemIndex;
//Занесение выбранной строки в переменную st
  St := ComboBox1.Items[nst];
//Просмотр всех символов строки st
  for i := 1 to Length(St) do
  begin
    Case ind of
      0: if St[i] <>' ' then
         begin
             //Если встретился символ после пробела
             //число слов увеличивается на единицу
             ind := 1;
             inc(n);
         end;
// Если встретился пробел после символов
      1: if St[i] =' ' then ind := 0;
     end; //Case
   Label3.Caption := IntToStr(n); //Вывод числа слов в Label3

end;

end;

end.
