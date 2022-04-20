unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Label1: TLabel;
    Button1: TButton;
    Button2: TButton;
    Label2: TLabel;
    eTextToFind: TEdit;
    Button3: TButton;
    Label3: TLabel;
    eTextToReplace: TEdit;
    Button4: TButton;
    procedure Memo1Change(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}



procedure TForm1.Button1Click(Sender: TObject);
begin
  memo1.Lines.Text  := AnsiUpperCase(memo1.Lines.Text);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
memo1.Lines.Text  := AnsiLowerCase(memo1.Lines.Text);
end;

procedure TForm1.Button3Click(Sender: TObject);
var
 numPos: integer;
begin
  numPos := Pos(eTextToFind.Text, memo1.Lines.Text);

  if numPos = 0 then
  begin
    Showmessage('Nothing');
    Showmessage('Nooothing!');
  end
  else
  begin
    Showmessage('Bingo!');
    memo1.SetFocus;
    memo1.SelStart := numPos - 1;
    memo1.SelLength := Length(eTextToFind.Text);
  end;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  memo1.Lines.Text :=
     StringReplace(memo1.Lines.Text,
                   eTextToFind.Text,
                   eTextToReplace.Text,
                   [rfignoreCase, rfReplaceAll])//[rfignoreCace]-регистронезависимый поиск.
end;

procedure TForm1.Memo1Change(Sender: TObject);
begin
  Label1.Caption  := IntToStr(Length(Memo1.Lines.Text));
end;

end.
