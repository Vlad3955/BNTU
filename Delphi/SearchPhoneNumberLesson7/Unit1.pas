unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    eSearchField: TEdit;
    mPhonesForSearch: TMemo;
    bSearch: TButton;
    Label2: TLabel;
    mPhonesAfterSearch: TMemo;
    bClear: TButton;
    procedure bSearchClick(Sender: TObject);
    procedure bClearClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.bClearClick(Sender: TObject);
begin
  mPhonesAfterSearch.Clear;
end;

procedure TForm1.bSearchClick(Sender: TObject);
var
  numString, numPos: integer;
  s: string;
begin
  for numString := 0 to mPhonesForSearch.Lines.Count - 1 do
  begin
    s := mPhonesForSearch.Lines.Strings[numString];
    numPos := pos(eSearchField.Text, s);

    if numPos <> 0 then
    begin
      mPhonesAfterSearch.Lines.Add(s);
    end
  end;
end;

end.
