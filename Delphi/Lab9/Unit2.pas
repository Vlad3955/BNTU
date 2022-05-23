unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TForm2 = class(TForm)
    Panel1: TPanel;
    ScrollBar1: TScrollBar;
    ScrollBar2: TScrollBar;
    ScrollBar3: TScrollBar;
    Panel2: TPanel;
    Panel3: TPanel;
    Panel4: TPanel;
    Panel5: TPanel;
    GroupBox1: TGroupBox;
    Panel6: TPanel;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    RadioGroup1: TRadioGroup;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    CheckBox3: TCheckBox;
    Button1: TButton;
    procedure ScrollBar1Change(Sender: TObject);
    procedure ScrollBar2Change(Sender: TObject);
    procedure ScrollBar3Change(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure RadioGroup1Click(Sender: TObject);
    procedure CheckBox1Click(Sender: TObject);
    procedure CheckBox2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;

implementation

{$R *.dfm}


procedure TForm2.ScrollBar1Change(Sender: TObject);
begin
  Edit1.Text := IntToStr(ScrollBar1.Position);
  Panel3.Color := RGB(ScrollBar1.Position, 0, 0);
  Panel6.Color := RGB(ScrollBar1.Position, ScrollBar2.Position, ScrollBar3.Position);
end;

procedure TForm2.ScrollBar2Change(Sender: TObject);
begin
  Edit2.Text := IntToStr(ScrollBar2.Position);
  Panel4.Color := RGB(0, ScrollBar2.Position, 0);
  Panel6.Color := RGB(ScrollBar1.Position, ScrollBar2.Position, ScrollBar3.Position);
end;

procedure TForm2.ScrollBar3Change(Sender: TObject);
begin
  Edit3.Text := IntToStr(ScrollBar3.Position);
  Panel5.Color := RGB(0, 0, ScrollBar3.Position);
  Panel6.Color := RGB(ScrollBar1.Position, ScrollBar2.Position, ScrollBar3.Position);
end;

procedure TForm2.FormActivate(Sender: TObject);
begin
  Edit1.Text := IntToStr(ScrollBar1.Position);
  Panel3.Color := RGB(ScrollBar1.Position, 0, 0);
  Edit2.Text := IntToStr(ScrollBar2.Position);
  Panel4.Color := RGB(ScrollBar2.Position, 0, 0);
  Edit3.Text := IntToStr(ScrollBar3.Position);
  Panel5.Color := RGB(ScrollBar3.Position, 0, 0);
  Panel6.Color := RGB(ScrollBar1.Position, ScrollBar2.Position, ScrollBar3.Position);
  CheckBox1.Checked := true;
  CheckBox2.Checked := true;
  CheckBox3.Checked := true;
end;

procedure TForm2.RadioGroup1Click(Sender: TObject);
begin
  case RadioGroup1.ItemIndex of
    0: Panel2.Visible := true;
    1: Panel2.Visible := false;
  end;
end;

procedure TForm2.CheckBox1Click(Sender: TObject);
begin
  if CheckBox1.Checked then
  begin
    ScrollBar1.Enabled := true;
    Edit1.Enabled := true;
  end
  else
  begin
    ScrollBar1.Enabled := false;
    Edit1.Enabled := false;
  end;
end;

procedure TForm2.CheckBox2Click(Sender: TObject);
begin
  if CheckBox2.Checked then
  begin
    ScrollBar2.Enabled := true;
    Edit2.Enabled := true;
  end
  else
  begin
    ScrollBar2.Enabled := false;
    Edit2.Enabled := false;
  end;
end;

end.
