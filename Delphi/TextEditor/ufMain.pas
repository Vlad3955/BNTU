unit ufMain;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.Menus, Vcl.StdCtrls, Vcl.ExtCtrls, IniFiles;

type
  TForm1 = class(TForm)
    MainMenu: TMainMenu;
    File1: TMenuItem;
    Save1: TMenuItem;
    Open1: TMenuItem;
    Settings1: TMenuItem;
    Font1: TMenuItem;
    Font2: TMenuItem;
    Memo: TMemo;
    OpenDialog: TOpenDialog;
    SaveDialog: TSaveDialog;
    FontDialog: TFontDialog;
    ColorDialog: TColorDialog;
    Edit1: TMenuItem;
    SearchandReplace1: TMenuItem;
    pReplace: TPanel;
    Label1: TLabel;
    eFind: TEdit;
    eReplace: TEdit;
    Label2: TLabel;
    bReplace: TButton;
    bClose: TButton;
    procedure Save1Click(Sender: TObject);
    procedure Open1Click(Sender: TObject);
    procedure Font1Click(Sender: TObject);
    procedure Font2Click(Sender: TObject);
    procedure SearchandReplace1Click(Sender: TObject);
    procedure bCloseClick(Sender: TObject);
    procedure bReplaceClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    { Private declarations }
  public

    Ini: TIniFile;
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.bCloseClick(Sender: TObject);
begin
  pReplace.Hide;
end;

procedure TForm1.bReplaceClick(Sender: TObject);
var count, k: integer;
    txt: string;
begin
  count := 0;
  txt := Memo.Text;
  k := Pos(eFind.Text, txt);
  while k > 0 do
  begin
    Delete(txt, k, Length(eFind.Text));
    Insert(eReplace.Text, txt, k);
    count := count + 1;
    k := Pos(eFind.Text, txt);
  end;
  if count > 0 then
  begin
    Memo.Text := txt;
    ShowMessage('Text rsplaces ' + IntToStr(count) + ' times.')
  end;
end;

procedure TForm1.Font1Click(Sender: TObject);
begin
  if FontDialog.Execute()	then
  begin
    Memo.Font := FontDialog.Font;
    Ini.WriteString('Main', 'FontFamily', Memo.Font.Name);
    Ini.WriteInteger('Main', 'FontSize', Memo.Font.Size);
    Ini.WriteInteger('Main', 'FontColor', Memo.Font.Color);
  end;
end;

procedure TForm1.Font2Click(Sender: TObject);
begin
  if ColorDialog.Execute() then
  begin
    Memo.Color := ColorDialog.Color;
    Ini.WriteInteger('Main', 'Color', Memo.Color);
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  str: string;
begin
  str := ExtractFileDir(Application.ExeName) + '\config.ini';
  Ini := TIniFile.Create(str);
  Memo.Font.Name := Ini.ReadString('Main', 'FontFamily', Memo.Font.Name);
  Memo.Font.Size := Ini.ReadInteger('Main', 'FontSize', Memo.Font.Size);
  Memo.Font.Color := Ini.ReadInteger('Main', 'FontColor', Memo.Font.Color);
  Memo.Color := Ini.ReadInteger('Main', 'Color', Memo.Color);
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  Ini.Free;
end;

procedure TForm1.Open1Click(Sender: TObject);
begin
  if OpenDialog.Execute()	 then
    Memo.Lines.LoadFromFile(OpenDialog.FileName);
end;

procedure TForm1.Save1Click(Sender: TObject);
begin
  if SaveDialog.Execute() then
  begin
    if Pos('.txt', SaveDialog.FileName) > 0 then
      Memo.Lines.SaveToFile(SaveDialog.FileName)
    else
      Memo.Lines.SaveToFile(SaveDialog.FileName	+ '.txt');
  end;
end;

procedure TForm1.SearchandReplace1Click(Sender: TObject);
begin
  pReplace.Show;
  eFind.Text := '';
  eReplace.Text := '';
  eFind.SetFocus;
end;

end.
