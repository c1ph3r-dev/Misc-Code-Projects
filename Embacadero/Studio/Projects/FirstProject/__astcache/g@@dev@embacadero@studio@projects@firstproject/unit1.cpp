//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddTaskBtnClick(TObject *Sender)
{
	String task_text = TaskInput->Text;
    if(task_text == "") return;
	TaskList->Items->Add(task_text);
    TaskInput->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TaskListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	int index = Item->Index;
    TaskList->Items->Delete(index);
}
//---------------------------------------------------------------------------

