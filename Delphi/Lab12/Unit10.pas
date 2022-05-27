unit Unit10;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm10 = class(TForm)
    Edit1: TEdit;
    Button1: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form10: TForm10;

implementation

uses Unit1;

{$R *.dfm}

procedure TForm10.Button1Click(Sender: TObject);
begin
  h := StrToFloat(Edit1.Text);
  Form1.label18.Caption := FloatToStr(h);
  Form10.Close;
end;

procedure TForm10.FormCreate(Sender: TObject);
begin
  Edit1.Text := FloatToStr(h);
end;

end.
