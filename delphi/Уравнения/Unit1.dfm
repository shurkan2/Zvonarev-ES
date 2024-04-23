object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1053#1077#1083#1080#1085#1077#1081#1085#1099#1077' '#1091#1088#1072#1074#1085#1077#1085#1080#1103
  ClientHeight = 332
  ClientWidth = 866
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 32
    Width = 105
    Height = 13
    Caption = 'l_0 - t*v_0 = sin(w*t)'
  end
  object LAnswer: TLabel
    Left = 384
    Top = 40
    Width = 43
    Height = 13
    Caption = 'Answer: '
  end
  object Button1: TButton
    Left = 168
    Top = 255
    Width = 121
    Height = 33
    Caption = #1052#1077#1090#1086#1076#1086#1084' '#1048#1090#1077#1088#1072#1094#1080#1081
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 255
    Width = 121
    Height = 33
    Caption = #1052#1077#1090#1086#1076#1086#1084' '#1053#1102#1090#1086#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 80
    Width = 281
    Height = 169
    Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1099#1077
    TabOrder = 2
    object Label2: TLabel
      Left = 16
      Top = 27
      Width = 89
      Height = 13
      Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' l_0 = '
    end
    object Label3: TLabel
      Left = 16
      Top = 51
      Width = 123
      Height = 13
      Caption = 'C'#1082#1086#1088#1086#1089#1090#1100' '#1090#1077#1083#1072' B, v_0 = '
    end
    object Label4: TLabel
      Left = 16
      Top = 81
      Width = 165
      Height = 13
      Caption = #1063#1072#1089#1090#1086#1090#1072' '#1082#1086#1083#1077#1073#1072#1085#1080#1081' '#1090#1086#1095#1082#1080' A, w='
    end
    object Label5: TLabel
      Left = 16
      Top = 136
      Width = 129
      Height = 13
      Caption = #1058#1086#1095#1085#1086#1089#1090#1100' e=10^(-n), n = '
    end
    object Label6: TLabel
      Left = 16
      Top = 108
      Width = 84
      Height = 13
      Caption = #1055#1086#1089#1090#1086#1103#1085#1085#1072#1103' A = '
    end
    object Edit1: TEdit
      Left = 116
      Top = 24
      Width = 65
      Height = 21
      TabOrder = 0
      Text = '20'
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 145
      Top = 51
      Width = 65
      Height = 21
      TabOrder = 1
      Text = '5'
      OnKeyPress = Edit1KeyPress
    end
    object Edit3: TEdit
      Left = 203
      Top = 78
      Width = 65
      Height = 21
      TabOrder = 2
      Text = '1'
      OnKeyPress = Edit1KeyPress
    end
    object Edit4: TEdit
      Left = 160
      Top = 129
      Width = 65
      Height = 21
      TabOrder = 3
      Text = '3'
      OnKeyPress = Edit1KeyPress
    end
    object Edit5: TEdit
      Left = 116
      Top = 102
      Width = 65
      Height = 21
      TabOrder = 4
      Text = '1'
      OnKeyPress = Edit1KeyPress
    end
  end
end
