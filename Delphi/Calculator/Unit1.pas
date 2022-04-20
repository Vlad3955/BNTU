unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.Imaging.pngimage, Vcl.ExtCtrls,
  Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Button1: TButton;
    eTotal: TEdit;
    Label4: TLabel;
    cbxProduct1: TCheckBox;
    cbxProduct2: TCheckBox;
    cbxProduct3: TCheckBox;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    procedure Button1Click(Sender: TObject);

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
var
  sum: double;
begin
  sum := 0;
  if cbxProduct1.Checked then
    sum := sum + StrToFloat(Edit1.Text);

  if cbxProduct2.Checked then
    sum := sum + StrToFloat(Edit2.Text);

  if cbxProduct3.Checked then
    sum := sum + StrToFloat(Edit3.Text);

  eTotal.Text	:= FloatToStr(sum);
end;

end.
