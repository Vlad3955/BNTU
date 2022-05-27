unit Unit9;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm9 = class(TForm)
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
  Form9: TForm9;

implementation

uses Unit1;

{$R *.dfm}

procedure TForm9.Button1Click(Sender: TObject);
begin
  Hy := StrToFloat(Edit1.Text);
  Form1.label16.Caption := FloatToStr(Hy);
  Form9.Close;
end;

procedure TForm9.FormCreate(Sender: TObject);
begin
  Edit1.Text := FloatToStr(Hy);
end;

end.
