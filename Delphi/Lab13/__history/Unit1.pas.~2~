unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls, Vcl.Menus,
  Vcl.Imaging.jpeg, math, VclTee.TeeGDIPlus, VCLTee.TeEngine, VCLTee.Series,
  VCLTee.TeeProcs, VCLTee.Chart, Vcl.Buttons, Vcl.ComCtrls;

type
  TForm1 = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Edit10: TEdit;
    Edit11: TEdit;
    Edit12: TEdit;
    Edit13: TEdit;
    Button2: TButton;
    TabSheet2: TTabSheet;
    Chart2: TChart;
    LineSeries1: TLineSeries;
    LineSeries2: TLineSeries;
    Label14: TLabel;
    Label15: TLabel;
    Label16: TLabel;
    Label17: TLabel;
    Label18: TLabel;
    Edit14: TEdit;
    Edit15: TEdit;
    Edit16: TEdit;
    Edit17: TEdit;
    Edit18: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure PageControl1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
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

procedure TForm1.Button1Click(Sender: TObject);
var
  x,y1,a,b,c:extended;
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

procedure TForm1.FormCreate(Sender: TObject);
begin
  Form1.PageControl1Chenge(sender);
end;

procedure TForm1.PageControl1Change(Sender: TObject);
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
end;

end.
