unit Lab2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, math;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Button1: TButton;
    Memo1: TMemo;
    RadioGroup1: TRadioGroup;
    Label1: TLabel;
    Label2: TLabel;
    procedure FormCreate(Sender: TObject);
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



procedure TForm1.FormCreate(Sender: TObject);
begin
Edit1.Text := '0.1';
Edit2.Text := '0.356';

Memo1.Clear;
Memo1.Lines.Add('Peç-òû ñò. ãð. 41703120 Ðåóòà Â.Ë.');


end;

procedure TForm1.Button1Click(Sender: TObject);
var
 x, f, e, i : real;
 //i : integer;
begin
   x := StrToFloat(Edit1.Text);
   Memo1.Lines.Add('x = ' + Edit1.Text);
   i := StrToFloat(Edit2.Text);
   Memo1.Lines.Add('i = ' + Edit2.Text);

   case RadioGroup1.ItemIndex of
     0: f := sinh(x);
     1: f := x*x;
     2: f := exp(x);
   end;

    if (x > 0) and (Odd(round(i)))
    then e := i * sqrt(f)
  else if (x < 0) and (NOT Odd(round(i)))
    then e := (i / 2) * sqrt(abs(f))
  else e:= sqrt(abs(i * (f)));

  Memo1.Lines.Add('e = ' + FloatToStrF(e, ffFixed, 8, 2));
end;

end.
