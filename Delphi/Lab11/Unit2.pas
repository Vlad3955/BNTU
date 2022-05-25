unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls;

type
  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Shape1: TShape;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;

implementation

uses Unit1, Unit3;

{$R *.dfm}

procedure TForm2.Button1Click(Sender: TObject);
begin
  Shape1.Shape:=stRectangle;
end;

procedure TForm2.Button2Click(Sender: TObject);
begin
  Shape1.Shape:=stSquare;
end;

procedure TForm2.Button3Click(Sender: TObject);
begin
  Shape1.Shape:=stCircle;
end;

procedure TForm2.Button4Click(Sender: TObject);
begin
  Shape1.Shape:=stEllipse;
end;

procedure TForm2.Button5Click(Sender: TObject);
begin
  Form2.Visible:=false;
  Form1.Visible:=true;
end;

procedure TForm2.Button6Click(Sender: TObject);
begin
  Form2.Visible:=false;
  Form3.Visible:=true;
end;

end.
