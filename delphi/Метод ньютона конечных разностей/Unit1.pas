unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, VclTee.TeeGDIPlus, VCLTee.TeEngine,
  VCLTee.Series, Vcl.StdCtrls, Vcl.Grids, Vcl.ExtCtrls, VCLTee.TeeProcs,
  VCLTee.Chart;

type
  TForm1 = class(TForm)
    Chart1: TChart;
    StringGrid1: TStringGrid;
    Button1: TButton;
    Series1: TLineSeries;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

function Pright(i:integer; t:real):real;         //����������� ������� ��� ������� ������� �������
begin
  if i=0 then result:=1
  else if i = 1 then result:=t
  else result:=Pright(i-1,t)*(t+i-1)/i ;
end;

function PLeft(i:integer; t:real):real;          //��� ������ ������� �������
begin
  if i=0 then result:=1
  else if i = 1 then result:=t
  else result:=PLeft(i-1,t)*(t-i+1)/i ;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  i, n,j: Integer;
  g:array of array of real;
  xr,xmax,xmin,y:real;

function P(x:real):real;
var IsOnLeft:boolean; i:integer; sum:real;
begin
  sum:=0;
  if  (x>=xmin) and (x<=(xmin+xmax)/2) then IsOnLeft := true
  else if (x>(xmin+xmax)/2) and (x<=xmax) then IsOnLeft := false
  else begin result:=0; exit; end;

  for I := 0 to n-1 do
  begin
    if IsOnLeft then sum:=sum+PLeft(i,(x-xmin)/(g[1,0]-g[0,0]))*g[i,i+1]

    else if (not IsOnLeft) then sum:=sum+Pright(i,(x-xmax)/(g[1,0]-g[0,0]))*g[n-1,i+1];
  end;
  result:=sum;
end;

begin
 chart1.Series[0].Clear;
 n:=stringgrid1.ColCount;
 setlength(g,n);
 for I := 0 to n-1 do
  Setlength(g[i],n+1);

 for I := 0 to n-1 do
  begin
    g[i,0]:=StrToFloat(Stringgrid1.cells[i,0]); //��� xi
    g[i,1]:=StrToFloat(Stringgrid1.cells[i,1]); //��� yi
  end;
  // � ��� G - ������ �������� ���������. �������:
  for I := 1 to n do
    begin
      for j := i to n-1 do
        g[j,i+1]:=g[j,i]-g[j-1,i];
    end;

  //������ �� ��������� ��������� ������ G � ����� � ��� ��������, ��������� �������������
 xmin:=g[0,0];
 xmax:=g[n-1,0];
 xr:=xmin;
 while (xr<xmax) do
  begin
    y:=p(xr);
    Chart1.Series[0].AddXY(xr,y);
    xr:=xr+0.001;     //ifu cltkfnm 0,01
  end;

  g:=nil; //������� ������������ ������
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  stringgrid1.Cells[0,0]:= '1,8';
  stringgrid1.Cells[1,0]:= '1,83';
  stringgrid1.Cells[2,0]:= '1,86';
  stringgrid1.Cells[3,0]:= '1,89';
  stringgrid1.Cells[4,0]:= '1,92';
  stringgrid1.Cells[5,0]:= '1,95';
  stringgrid1.Cells[6,0]:= '1,98';

  stringgrid1.Cells[0,1]:= '-3,1107';
  stringgrid1.Cells[1,1]:= '-2,5626';
  stringgrid1.Cells[2,1]:= '-2,1197';
  stringgrid1.Cells[3,1]:= '-1,7525';
  stringgrid1.Cells[4,1]:= '-1,4417';
  stringgrid1.Cells[5,1]:= '-1,1738';
  stringgrid1.Cells[6,1]:= '-0,9396';
end;

end.
