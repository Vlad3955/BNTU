unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, MatFunc;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Memo1: TMemo;
    Button1: TButton;
    Button2: TButton;
    RadioGroup1: TRadioGroup;


    Procedure FormCreate(Sender: TObject);
    Procedure Button1Click(Sender: TObject);
    Procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

  type
  func = function(x:extended) : extended;

var
  Form1: TForm1;

implementation

{$R *.dfm}

  procedure TForm1.FormCreate(Sender: TObject);
begin
  Edit1.Text := '0';
  Edit2.Text := '2';
  Edit3.Text := '0,2';
  Memo1.Clear;
  RadioGroup1.ItemIndex := 0;
end;

procedure Tabl(f: func; xn, xk, h: extended);
var
  x, y : extended;
begin
  x := xn;
  Repeat
    y := f(x);
    Form1.Memo1.Lines.Add('x=' + FloatToStrF(x,ffFixed, 8, 2) +
                        '  y=' + FloatToStrF(y, ffFixed, 8, 2));
    x := x + h;
  Until (x > xk);
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  xn, xk, h : extended;
begin
  xn := StrToFloat(Edit1.Text);
  xk := StrToFloat(Edit2.Text);
  h  := StrToFloat(Edit3.Text);

  Case RadioGroup1.ItemIndex of
    0 : Tabl(tg, xn, xk, h);
    1 : Tabl(ch, xn, xk, h);
    2 : Tabl(sin2, xn, xk, h);
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Halt; //Завершение приложения
end;

end.
