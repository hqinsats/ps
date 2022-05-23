//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Label1->Font->Color = clBlack;
        Image2->Picture->LoadFromFile("k2_2.jpg"); //�������� ��� ������� �� ������
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Label1->Font->Color = clInfoBk;
        Image2->Picture->LoadFromFile("k1_2.jpg");  //��������� ��������
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2Click(TObject *Sender)
{
        Form3->ShowModal(); //������ ������� ����� ��� ������� �� image
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label1Click(TObject *Sender)
{
       Form3->ShowModal();//������ ������� ����� ��� ������� �� �����
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
        Resize = False;
}
//---------------------------------------------------------------------------

