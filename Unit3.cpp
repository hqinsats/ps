//---------------------------------------------------------------------------
#include <string.h>

#include <stdio.h>
#include <fstream>

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
i=1;
clickmouse = 0;
chisotv = 0;
}
//---------------------------------------------------------------------------
//��������� ����� ����, �. �. ������� ��������
void __fastcall TForm3::Image3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        SpeedButton1->Font->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        SpeedButton1->Font->Color = clMaroon;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        SpeedButton2->Font->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        SpeedButton2->Font->Color = clMaroon;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image5MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        SpeedButton3->Font->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        SpeedButton3->Font->Color = clMaroon;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
 //�� ������� ������. �������� �� �/�-���� ��������
 if(i <= 3) //���� ������� ������ 3
   {
    i++; //����������. �������� ��������
    Label4->Caption = IntToStr(i); //������ �������� � �����3
    Application->ProcessMessages();//���� �� �������� �� ����� �����
   }
 if(i == 4) // ����� ���������� i ����� ��������� 4
   {
   //�������� ������� �������
   SpeedButton1->Visible=true;
   SpeedButton2->Visible=true;
   SpeedButton3->Visible=true;
   //���������� ������
   Timer1->Enabled = false;
   //��������� �������� �������
   i=1;
   Label4->Caption="";
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormActivate(TObject *Sender)
{
//��� ������� ������� �����, ���������� ������ ��������� ������� �� ������ � ������ �� ������
TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[0];

TStringList* l2 = new TStringList;
l2->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l2.txt");
SpeedButton2->Caption = l2->Strings[0];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[0];


   Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
   Timer1->Enabled = true; //�������� ������

}
//---------------------------------------------------------------------------


void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
//���������� ��������� � UNIT3.H. ��� ������������� ��� ���������� ����������
nasv1=SpeedButton1->Caption;

//���������: ���� � ���������� nasv1 ����� ��������� � �������, �� ����������� ������
//� ���������� o1, ��������� �������� ��� ����. ������, ������ �� ����� ����. ������
//�� �������

if(nasv1 == "������"){
o1 = "��� �����, ��� ��, ������� ��������� �������: �� �� ��������� �������� �� ������ � ����������, ������ ��� ����� �������� � ������ ��������. ������������� ����� ��� � �������������� ������� �������� ��� � �������� ������� �������, �� ��� ��� ��-�� ������������ �������� �� ����� ��������� �� ���� ������� � ��������. ";
Image2->Picture->LoadFromFile("02.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[1];

SpeedButton2->Visible=false; //

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[1];

Label4->Caption = IntToStr(i); //�������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv1 == "�������"){
o2 = "��� ���� ����, ��� ����� �� ��������� � ����� �����. ��� ������ ��������� �������� ���� �����, � � ������� ����� ��� ����������� ���-�� �������. ������ ����� �������� ����� ���� � ������ � ����. �������� ������� � ����. ������ � ����� ����� ������� ����������, ���� ����������� �. ";
Image2->Picture->LoadFromFile("03.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[2];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[2];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;

}

if(nasv1 == "��������"){
o3 = "�� ����� ��������� � ������ ���������� ����� � ����� �����. �� ����� ���������, ��� ������ �������� � �����������. ��� ����� ������ ������������� �� ������ � ������ ���������� ��������. ";
Image2->Picture->LoadFromFile("04.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[3];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[3];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv1 == "������"){
o4 = "�� ������������ � ������ ������������. ��� ���� �� ����� ������� � ����. ������ �� ���������� �������� �������������, �� ���� ������������ ��� �������! ";
Image2->Picture->LoadFromFile("05.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[4];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[4];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv1 == "�������"){
o5 = "���� �������� ��������� ���� ������ ��� ������� ��������� � �����. �� �� ������ �������� �� ���� ��������, �� ��� ������� ��� �������, ���� �� ������ �������� ������. ����� �� � ���������, ����� ���������� �� ���� ������ ������. ";
Image2->Picture->LoadFromFile("06.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[5];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[5];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv1 == "����"){
o6 = " �� � ����������, ���������� �������� ����������� ����. ��� ��� ����� ����� ���������� � ��������� ���������� �����, ������� ������������ ���, � �� ���������.  ";
Image2->Picture->LoadFromFile("07.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[6];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[6];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv1 == "�����"){
o7 = "�� ������ � ����� ���������� � �������. ������ � ���, �� ��������� ��������� ������������� �����, � ������, ��� ����� �������� �����. �� �� �������������� �� ������������, ��� ��� ������ ����� ��� ����, � �� ���������. ������ �� ���� ������� � ��� �� ������������ ��������� �������. �� ������� ���������, ���� �� �������� � ����� ����.";
Form3->SpeedButton1->Caption=" ";
Form3->SpeedButton3->Caption=" ";

Form2->Label1->Visible=false;
Form2->Image2->Visible=false;
Form2->Image1->Picture->LoadFromFile("zak.jpg");

Form2->RichEdit1->Visible=true;
Form2->Label2->Visible=true;
Form2->RichEdit1->Lines->Text=o1+o2+o3+o4+o5+o6+o7;
Form2->Caption="���������";

Form3->Close();
}

clickmouse++;
Label5->Caption = IntToStr(clickmouse);



}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton2Click(TObject *Sender)
{
nasv2=SpeedButton2->Caption;

if(nasv2 == "�������"){
o1 = "� ��� ������� ������� ����������� � ��������. � ��� �� ������� ���������� �����, ������ ��������� ������ ��������. �� ����� �������� � ��� ������� ����������� � ���������� �������. ������, ������� ������� ������ ������, �� ������� ��������� ����� � ������ � �������. ";
Image2->Picture->LoadFromFile("02.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[1];

SpeedButton2->Visible=false;

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[1];
SpeedButton2->Visible=false;

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}



chisotv=2;
clickmouse++;
Label5->Caption = IntToStr(clickmouse);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton3Click(TObject *Sender)
{
nasv3=SpeedButton3->Caption;

if(nasv3 == "�����"){
o1 = "�� ������ �� ��������� � �����, ��� �������������, ���� �� ���� � ����� ���� ����� � �������� �������. ������, ���� ������� ������� ��� ������� ����������� � ��������������. ��������� �� ������� � ������ �� �����, � ������ � � ����� ��� ������ ���� �� �����! ";
Image2->Picture->LoadFromFile("02.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[1];

SpeedButton2->Visible=false;

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[1];
SpeedButton2->Visible=false;

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv3 == "�������"){
o2 = "������� � ����� ������ ����� ��������� ��������� � ����������� ������. ���� � ��� ��� ���� ���� � ��� ������������� ����� �������, �� ��������� ����� ����������� ������ ������ � �������������. �� � ���� �� � �������� ������, �� ����� �� ��������� ���� ������ ��������� � ���� ��������, � ������� ��� ��������� ������ � ���������� �����. �� ���������� ���! ";
Image2->Picture->LoadFromFile("03.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[2];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[2];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;

}

if(nasv3 == "�����"){
o3 = "� ��� ����������� �������������� � ������� � �� ������ �� ���������. �� ����� ��������� � ������ ������������ ���������� ������� ��� ���� �������.";
Image2->Picture->LoadFromFile("04.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[3];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[3];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv3 == "�������"){
o4 = "�� � ��������, ���������� ���������� ����������. �������� �� ���� ��������������, ���������� ��� �����. ��� ���� �� ������� �������� ������� � ������������.";
Image2->Picture->LoadFromFile("05.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[4];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[4];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv3 == "����"){
o5 = "���� �� ������� ������� ����� ���������, ������, �� � ��������� � ����������� �������. �� ����� ���������� ����� ����� ������ � ������ � ������� ������� �������� ��������� �����.";
Image2->Picture->LoadFromFile("06.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[5];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[5];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv3 == "����"){
o6 = "�� � ���������, ���������� ������� �������. ���� �� ���������� �� ������ ����������, �� ������� ������� ��������.";
Image2->Picture->LoadFromFile("07.jpg");

TStringList* l1 = new TStringList;
l1->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l1.txt");
SpeedButton1->Caption = l1->Strings[6];

TStringList* l3 = new TStringList;
l3->LoadFromFile(ExtractFilePath(ParamStr(0)) + "l3.txt");
SpeedButton3->Caption = l3->Strings[6];

Label4->Caption = IntToStr(i); //������ � ����� ��������� �������� ��������
SpeedButton1->Visible=false;
SpeedButton3->Visible=false;
Timer2->Enabled = true;
}

if(nasv3 == "�������"){
o7 = "�������, ���������� ������ � �����, ������������� ���������. ��������, �� ���������� � �� ������, ��� ������ ������. ���������, �� ����������� �������� ���� � �������. ������ �� �� � ������ �����. ������� �� ������� ���������� ���� �� �� ���� ���� � ��������� ���. ��������, ����� � ���� ���� �������, ������� �������� ���� �������. ������������ ��� ��������� � �� ������� ������������ � ������, ��������� � �������� ��� ������ ����.";
Form3->SpeedButton1->Caption=" ";
Form3->SpeedButton3->Caption=" ";

Form2->Label1->Visible=false;
Form2->Image2->Visible=false;
Form2->Image1->Picture->LoadFromFile("zak.jpg");

Form2->RichEdit1->Visible=true;
Form2->Label2->Visible=true;
Form2->RichEdit1->Lines->Text=o1+o2+o3+o4+o5+o6+o7;
Form2->Caption="���������";
Form3->Close();

}

chisotv=3;
clickmouse++;
Label5->Caption = IntToStr(clickmouse);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
if(i <= 3) //���� ������� ������ 3
   {
    i++; //����������. �������� ��������
    Label4->Caption = IntToStr(i); //������ �������� � �����3
    Application->ProcessMessages();//���� �� �������� �� ����� �����
   }
 if(i == 4) // ����� ���������� i ����� ��������� 4
   {
   //�������� ������� �������
   SpeedButton1->Visible=true;
   SpeedButton3->Visible=true;
   //���������� ������
   Timer2->Enabled = false;
   //��������� �������� �������
   i=1;
   Label4->Caption="";
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm3::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
        Resize = False;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        nasv1=SpeedButton1->Caption;
        nasv2=SpeedButton2->Caption;
        nasv3=SpeedButton3->Caption;

        if(nasv3 == " "&&nasv1 == " "){
        CanClose=true;
        }
        else{
        CanClose=false;
        }
}
//---------------------------------------------------------------------------

