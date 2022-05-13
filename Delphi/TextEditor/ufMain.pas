unit ufMain;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.Menus, Vcl.StdCtrls, Vcl.ExtCtrls;

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
  private
    { Private declarations }
  public
    { Public declarations }
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
  txt := Memo.Text;
  k := Pos(eFind.Text, txt);
end;

procedure TForm1.Font1Click(Sender: TObject);
begin
  if FontDialog.Execute()	then
    Memo.Font := FontDialog.Font;

end;

procedure TForm1.Font2Click(Sender: TObject);
begin
  if ColorDialog.Execute() then
    Memo.Color := ColorDialog.Color;
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
