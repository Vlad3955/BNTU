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
    FIO  : string[40];               //Поле Ф.И.О.
    otc  : array[1..3] of word;  //Поле массива оценок
    sball  : extended;               //Поле среднего балла
  end;

var
  Fz   : file of TStudent;                  //Файл типа запись
  Ft   : TextFile;                              //Текстовой файл
  Stud : array[1..100] of TStudent; //Массив записей
  Nzap : integer;                             //Номер записи
  FileNameZ, FileNameT : string; //Имена файлов


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
  Button1.Hide; //Сделать невидимой кнопку "Ввести запись"
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

  Write(fz, Stud[nzap]);   //Запись в файл
  Edit1.Text := '';
  Edit2.Text := '';
  Edit3.Text := '';
  Edit4.Text := '';
end;

 procedure TForm1.Button2Click(Sender: TObject);
begin
  OpenDialog1.Title := 'Создать новый файл';
// Изменение заголовка окна диалога
   if OpenDialog1.Execute then
// Выполнение стандартного диалога выбора имени файла
  begin
    FileNameZ := OpenDialog1.FileName;
//  Возвращение имени дискового файла
    AssignFile(Fz, FileNameZ);
//  Связывание файловой переменной Fz с именем файла
    Rewrite(Fz);  //Создание нового файла
    Button1.Show; //Сделать видимой кнопку "Ввести запись"
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  if OpenDialog1.Execute then
//Выполнение стандартного диалога выбора имени файла
  begin
    FileNameZ := OpenDialog1.FileName;
//  Возвращение имени дискового файла
    AssignFile(Fz, FileNameZ);
//  Связывание файловой переменной Fz с именем файла
    Reset(Fz); //Открытие существующего файла
  end;

  While not EOF(fz) do
  begin
    nzap := nzap + 1;
    Read(fz, stud[nzap]);  //Чтение записи из файла
    with stud[nzap] do
      Memo1.Lines.Add(fio + '' + IntToStr(otc[1]) +
      ' ' + IntToStr(otc[2]) + '' + IntToStr(otc[3]));
    end;
    Button1.Show; //Сделать видимой кнопку "Ввести запись"
end;


procedure TForm1.Button4Click(Sender: TObject);
  // Сортировка записей
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
// Вывод в окно Memo1 отсортированных записей
  with stud[i] do
    Memo1.Lines.Add(IntToStr(i) + ' ' +
    fio + ' ' + FloatToStrF(sball, ffFixed, 4, 2));
end;


procedure TForm1.Button5Click(Sender: TObject);
  // Сохраниение результатов сортировки в текстовом файле
var
  i : word;

begin
  if SaveDialog1.Execute then
// Выполнение стандартного диалога выбора имени файла
  begin
    FileNameT := SaveDialog1.FileName;
//  Возвращение имени дискового файла
    AssignFile(Ft, FileNameT);
//  Связывание файловой переменной Ft с именем файла
    Rewrite(Ft); //Открытие нового текстового файла
  end;

  for i:=1 to nzap do
  with stud[i] do
    Writeln(Ft, i:4, '.', fio, sball:8:2);
//  Запись в текстовой файл
    CloseFile(Ft); //Закрытие текстового файла
end;

 procedure TForm1.BitBtn1Click(Sender: TObject);
begin
   if SaveDialog1.Execute then
  CloseFile(fz);
// Закрытие файла записей при нажатии на кнопку "Close"
end;

end.
