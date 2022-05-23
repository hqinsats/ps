//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Label1->Font->Color = clBlack;
        Image2->Picture->LoadFromFile("k2.jpg");//анимация при нажатии на кнопку
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Label1->Font->Color = clInfoBk;
        Image2->Picture->LoadFromFile("k1.jpg"); //статичная анимация

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
        Form2->ShowModal(); //запуск второй формы при нажатии на image
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
      Form2->ShowModal();//запуск второй формы при нажатии на текст
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
        Resize = False;
}
//---------------------------------------------------------------------------

