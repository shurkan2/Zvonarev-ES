unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.WinXCtrls, Vcl.StdCtrls, Math;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Button1: TButton;
    Button2: TButton;
    GroupBox1: TGroupBox;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Edit4: TEdit;
    LAnswer: TLabel;
    Label6: TLabel;
    Edit5: TEdit;
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Edit1KeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  l_0,v_0,w,A,e:real;
  t:real;

implementation

{$R *.dfm}
function func(x:real):real;
begin
  result:=-(A*sin(w*x)-l_0)/v_0;
end;

procedure TForm1.Button1Click(Sender: TObject);
var t1:real; n:integer;
begin
//тут метод Итераций. Его уравнение: t=(l_0-sin(wt))/v_0
try
  l_0 := StrToFloat(Edit1.Text);
  v_0 := StrToFloat(Edit2.Text);
  w := StrToFloat(Edit3.Text);
  e := power(10,-StrToFloat(Edit4.Text));
  A := StrToFloat(Edit5.Text);
except
 ShowMessage('Проверьте коректность введённых констант');
 exit;
end;
if (v_0=0) and (A<>0) and (abs(l_0)<=1.0) and (w<>0) then
  begin
    LAnswer.Caption := 'Точный ответ: '+ FloatToStr(Math.ArcSin(l_0/A)/w);
    exit;
  end
else if (l_0 = 0) and (A=0) then
  begin
    LAnswer.Caption := 'Точный ответ 0';
    exit
  end
else if (v_0 = 0) then
  begin
    LAnswer.Caption := 'Решение не может быт найено :(';
    exit
  end;
t:=0;
n:=0;
t1:=e+1;
while (abs(t-t1) > e) do
  begin
    t1:=t;
    t := func(t1);
    inc(n);
    if n=500 then break;
  end;
  if n=500 then LAnswer.Caption := 'Решение не может быт найено, превышено кколичесство итераций'
  else LAnswer.Caption := 'Ответ: t='+FloatToStr(t)+'.'+#13+'Число итераций: n='+IntToStr(n)+'.';


end;

function f(x:real):real;
begin
  result:=A*sin(w*x)+v_0*x-l_0;
end;

function df(x:real):real;
begin
  result:=A*w*cos(w*x)+v_0
end;

procedure TForm1.Button2Click(Sender: TObject);
var diriv, t1:real; n:integer;
begin
//тут метод Нютона. Его уравнение: 0=sin(wt)+v_0*t-l_0
try
  l_0 := StrToFloat(Edit1.Text);
  v_0 := StrToFloat(Edit2.Text);
  w := StrToFloat(Edit3.Text);
  e := power(10,-StrToFloat(Edit4.Text));
  A := StrToFloat(Edit5.Text);
except
 ShowMessage('Проверьте коректность введённых констант');
 exit;
end;
t:=0;
t1:=e+1;
n:=0;
while abs(t1-t) > e do
  begin
    t1:=t;
    diriv := df(t1);
    if diriv <> 0 then t:=t1-f(t1)/diriv
    else t:=t+0.1;
    inc(n);
    if n=750 then break;
  end;
  if n=750 then LAnswer.Caption := 'Решение не может быт найено, превышено кколичесство итераций'
  else LAnswer.Caption := 'Ответ: t='+FloatToStr(t)+'.'+#13+'Число итераций: n='+IntToStr(n)+'.';
end;

procedure TForm1.Edit1KeyPress(Sender: TObject; var Key: Char);   //Мааленькая антидурочка
 var s:string;
begin
s := (Sender as TEdit).text;
 case key of
 '0'..'9',#13,#8:;
 '.',',': begin
       if pos(',',s)<>0 then key:=chr(0)
       else key := ',';
       if (Sender as TEdit).Name = 'Edit4' then key:=chr(0);
      end;
 '-': begin
       if (pos('-',s)=0 ) and ((Sender as TEdit).Name <> 'Edit4') then
       else key:=chr(0);
      end
 else key:=chr(0);
 end;
end;

end.
