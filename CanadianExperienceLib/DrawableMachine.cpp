/**
 * @file DrawableMachine.cpp
 * @author joeyv
 */

#include "pch.h"
#include "DrawableMachine.h"
#include "MainFrame.h"
#include <machine-api.h>


/**
* Decoctructor
*/
DrawableMachine::~DrawableMachine()
{
}

/**
 * Constructor
 * @param name name of the machine
 * @param machineNum machine number
 * @param resourceDir Resoruces directory
 * @param engine Audio engine
 */
DrawableMachine::DrawableMachine(std::wstring name, int machineNum, const std::wstring resourceDir, ma_engine *engine) :Drawable(name), mResourcesDir(resourceDir), mAudioEngine(engine)
{
    MachineSystemFactory factory(mResourcesDir, mAudioEngine);
    mMachine = factory.CreateMachineSystem();

}

/**
* Draw the drawable
 * @param graphics context to draw on
*/
void DrawableMachine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double scale = 0.75f;
    graphics->PushState();
    graphics->Translate(mPlacedPosition.x,mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachine->DrawMachine(graphics);
    graphics->PopState();

}

/**
* Test to see if clicked on machine
 * @param position Position to test
 * @return true if clicked
*/
bool DrawableMachine::HitTest(wxPoint position)
{
    if(position.x <= 200 || position.y <= 200)
    {
        return true;
    }
    return false;
}

/**
 * Set the position of the machine
 * @param position position to be set
 */
 void DrawableMachine::SetPosition(wxPoint position)
 {
     mMachine->SetLocation(position);
 }

 /**
  * Sets the dialog box
  * @param mainframe mainframe to pass into the dialog
  */
 void DrawableMachine::SetDialog(wxFrame* mainframe)
 {
     MachineDialog dlg(mainframe, mMachine);
     if (dlg.ShowModal() == wxID_OK)
     {
        //  A machine has been selected
         mMachine->SetLocation(wxPoint(100, 100));
         mainframe->Refresh();

     }

 }

 /**
  * Set the machine number
  * @param num number to be set
  */
void DrawableMachine::SetMachineNum(int num)
{
     mMachineNum = num;
     mMachine->SetMachineNumber(mMachineNum);
}


/**
* Set the machine frame.
* @param num the frame the machine will be set as
*/
void DrawableMachine::SetKeyFrame(int num)
{
    if(num < mStartTime)
    {
        mMachine->SetMachineFrame(0);
    }

    else if(num > mStartTime) {
        mMachine->SetMachineFrame(num - mStartTime);
    }

    else if(num >= mEndTime)
    {
        mMachine->SetMachineFrame(mEndTime - mStartTime);
    }
}


