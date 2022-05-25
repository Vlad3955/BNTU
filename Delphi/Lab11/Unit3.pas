unit Unit3;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls;

type
  TForm3 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Image1: TImage;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form3: TForm3;

implementation

uses Unit1, Unit2;

{$R *.dfm}

procedure TForm3.Button1Click(Sender: TObject);
begin
 Form3.Visible:=false;
 Form2.Visible:=True;

end;

procedure TForm3.Button2Click(Sender: TObject);
begin
  Form1.close();
end;

procedure TForm3.FormCreate(Sender: TObject);
begin
  //Form3.Image1.Canvas.Brush.Color := clBlack;
  //Form3.Image1.Canvas.Rectangle(150,50, 250,330);// полотно

  //Form3.Image1.Canvas.Brush.Color := clRed;
  //Form3.Image1.Canvas.Ellipse(165,60,235,135);// геометр. фигуры

  //Form3.Image1.Canvas.Brush.Color := clYellow;
  //Form3.Image1.Canvas.Ellipse(165,150,235,225);

  //Form3.Image1.Canvas.Brush.Color := clGreen;
  //Form3.Image1.Canvas.Ellipse(165,240,235,315);

  //Form3.Image1.Canvas.Brush.Color := clBlack; // светофор
  //Form3.Image1.Canvas.Rectangle(185,330, 215,370);

  Form3.Image1.Canvas.Brush.Color := clBlack;
  Form3.Image1.Canvas.Rectangle(200,0, 0, 600);// полотно

  Form3.Image1.Canvas.Brush.Color := clRed;
  Form3.Image1.Canvas.Ellipse(165,60,235,135);// геометр. фигуры

  Form3.Image1.Canvas.Brush.Color := clYellow;
  Form3.Image1.Canvas.Ellipse(165,150,235,225);

  Form3.Image1.Canvas.Brush.Color := clGreen;
  Form3.Image1.Canvas.Ellipse(165,240,235,315);

  Form3.Image1.Canvas.Brush.Color := clBlack; // светофор
  Form3.Image1.Canvas.Rectangle(185,600, 600,600);
end;

end.
