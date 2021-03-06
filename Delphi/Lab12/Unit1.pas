unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls, Vcl.Menus,
  Vcl.Imaging.jpeg, math, VclTee.TeeGDIPlus, VCLTee.TeEngine, VCLTee.Series,
  VCLTee.TeeProcs, VCLTee.Chart, Vcl.Buttons, Vcl.ComCtrls, Vcl.ToolWin,
  System.ImageList, Vcl.ImgList, Unit2, Unit3, Unit4, Unit5, Unit6, Unit7, Unit8, Unit9, Unit10;

type
  TForm1 = class(TForm)
    Chart1: TChart;
    Series1: TLineSeries;
    Series2: TLineSeries;
    BitBtn1: TBitBtn;
    Button1: TButton;
    Label9: TLabel;
    Label8: TLabel;
    Label7: TLabel;
    Label6: TLabel;
    Label5: TLabel;
    Label4: TLabel;
    Label3: TLabel;
    Label2: TLabel;
    Label1: TLabel;
    ToolBar1: TToolBar;
    bXmin: TToolButton;
    bXmax: TToolButton;
    bYmin: TToolButton;
    bYmax: TToolButton;
    bY: TToolButton;
    bZ: TToolButton;
    ToolButton7: TToolButton;
    bStepX: TToolButton;
    bStepY: TToolButton;
    bH: TToolButton;
    ImageList1: TImageList;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    Label15: TLabel;
    Label16: TLabel;
    Label17: TLabel;
    Label18: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure bXminClick(Sender: TObject);
    procedure bXmaxClick(Sender: TObject);
    procedure bYminClick(Sender: TObject);
    procedure bYmaxClick(Sender: TObject);
    procedure bYClick(Sender: TObject);
    procedure bZClick(Sender: TObject);
    procedure bStepXClick(Sender: TObject);
    procedure bStepYClick(Sender: TObject);
    procedure bHClick(Sender: TObject);
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

procedure TForm1.bXmaxClick(Sender: TObject);
begin
  Form3.Visible := True;
end;

procedure TForm1.bXminClick(Sender: TObject);
begin
  Form2.Visible := True;
end;

procedure TForm1.bYClick(Sender: TObject);
begin
  Form6.Visible := True;
end;

procedure TForm1.bYmaxClick(Sender: TObject);
begin
  Form5.Visible := True;
end;

procedure TForm1.bYminClick(Sender: TObject);
begin
  Form4.Visible := True;
end;

procedure TForm1.bZClick(Sender: TObject);
begin
  Form7.Visible := True;
end;

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

  Label10.Caption := '-5';
  Label11.Caption := '5';
  Label12.Caption := '-1';
  Label13.Caption := '1';
  Label14.Caption := '2';
  Label15.Caption := '0.5';
  Label16.Caption := '0.5';
  Label17.Caption := '1';
  Label18.Caption := '0.0001';
  Button1Click(Sender);
end;

procedure TForm1.bHClick(Sender: TObject);
begin
  Form10.Visible := True;
end;

procedure TForm1.bStepXClick(Sender: TObject);
begin
  Form8.Visible := True;
end;

procedure TForm1.bStepYClick(Sender: TObject);
begin
  Form9.Visible := True;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  x,y1,a,b,c:extended;
begin
  Series1.Clear;
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
