unit Lab8;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls, Vcl.Menus,
  Vcl.Imaging.jpeg, math, VclTee.TeeGDIPlus, VCLTee.TeEngine, VCLTee.Series,
  VCLTee.TeeProcs, VCLTee.Chart, Vcl.Buttons;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Chart1: TChart;
    Series1: TLineSeries;
    Series2: TLineSeries;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Edit8: TEdit;
    BitBtn1: TBitBtn;
    Edit9: TEdit;
    Label9: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
   Xmin, Xmax, Ymin, Ymax, Hx, Hy, h:extended;
  z,y:real;


implementation

{$R *.dfm}




procedure TForm1.FormCreate(Sender: TObject);
begin
  Xmin:=-5;
  Xmax:=5;
  Ymin:=-1;
  Ymax:=1;
  y:=2;
  z:=1;
  Hx:=0.5;
  Hy:=0.5;
  h:=0.0001;
  Edit1.Text:=FloatToStr(Xmin);
  Edit2.Text:=FloatToStr(Xmax);
  Edit3.Text:=FloatToStr(Ymin);
  Edit4.Text:=FloatToStr(Ymax);
  Edit5.Text:=FloatToStr(Hx);
  Edit6.Text:=FloatToStr(Hy);
  Edit7.Text:=FloatToStr(h);
  Edit8.Text:=FloatToStr(y);
  Edit9.Text:=FloatToStr(z);



  //Chart1.BottomAxis.Automatic := False;
  //Chart1.BottomAxis.Minimum := Xmin;
  //Chart1.BottomAxis.Maximum := Xmax;

  //Chart1.LeftAxis.Automatic := False;
  //Chart1.LeftAxis.Minimum   := Ymin;
  //Chart1.LeftAxis.Maximum   := Ymax;
  //Chart1.BottomAxis.Increment := Hx;
  //Chart1.LeftAxis.Increment   := Hy;
end;



procedure TForm1.Button1Click(Sender: TObject);
 var
  x,y,z,y1,a,b,c:extended;
begin
  Series1.Clear;
  Xmin:=StrToFloat(Edit1.Text);
  Xmax:=StrToFloat(Edit2.Text);
  y:=StrToFloat(Edit8.Text);
  z:=StrToFloat(Edit9.Text) ;
  h:=StrToFloat(Edit7.Text);
  x:=Xmin;
  Chart1.BottomAxis.Automatic := False;
  Chart1.BottomAxis.Minimum := Xmin;
  Chart1.BottomAxis.Maximum := Xmax;

  Chart1.LeftAxis.Automatic := False;
  Chart1.LeftAxis.Minimum   := Ymin;
  Chart1.LeftAxis.Maximum   := Ymax;
  Chart1.BottomAxis.Increment := Hx;
  Chart1.LeftAxis.Increment   := Hy;
  repeat
  a := ln(power(y, -abs(x)));
  b := x - (y / 2);
  c := sin(sqr(2)) * arctan(z);
  y1:= a * b + c;
    Series1.AddXY(x,y1,'',clTeeColor);
    x:=x+h;
  until (x>Xmax);

end;



 end.
