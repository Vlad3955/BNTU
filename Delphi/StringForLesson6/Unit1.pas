unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    ePhone: TEdit;
    Label1: TLabel;
    bAddPhone: TButton;
    mTruePhones: TMemo;
    Label2: TLabel;
    mPhoneList: TMemo;
    bAddPhonesList: TButton;
    procedure bAddPhoneClick(Sender: TObject);
    procedure bAddPhonesListClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.bAddPhoneClick(Sender: TObject);
var
  s: string;
begin
  s := ePhone.Text;
  if (s[1] <> '+') or (s[2] <> '3') then
  begin
    Showmessage('False');
    Exit;
  end;
  mTruePhones.Lines.Add(s);
end;

procedure TForm1.bAddPhonesListClick(Sender: TObject);
var
  s, s2: string;
  numString, numSymbol: integer;
begin
  for numString := 0 to mPhoneList.Lines.Count - 1 do
  begin
    s := mPhoneList.Lines.Strings[numString];

    s2 := '';
    for numSymbol := 1 to Length(s) do
      if (s[numSymbol] in ['0'..'9']) or ((s[numSymbol] = '+') and (numSymbol = 1)) then
      s2 := s2 + s[numSymbol];



    if (Length(s2) >= 2) and (s2[1] = '+') and (s2[2] = '3') then
    begin
      mTruePhones.Lines.Add(s2);
    end;
  end;
end;

end.
