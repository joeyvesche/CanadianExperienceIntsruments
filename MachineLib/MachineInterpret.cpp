/**
 * @file MachineInterpret.cpp
 * @author joeyv
 */

#include "pch.h"
#include "MachineInterpret.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"


/// A constant of the framerate of the machine
const int FrameRate = 30;


/**
 * Constructor
 * @param resourcesDir Resoruces directory for the images
 * @param audioEngine Audio engine for instruments
 */
MachineInterpret::MachineInterpret(std::wstring resourcesDir, ma_engine* audioEngine) : mResourcesDir(resourcesDir), mAudioEngine(audioEngine)
{
    SetMachineNumber(1);
}

/**
* Set the location of our machine
* @param x and int of our x location machine will be set at
* @param y and int of our y location machine will be set at
*/
void MachineInterpret::SetLocation(int x, int y)
{
    mMachine->SetLocation(wxPoint(x, y));
}

/**
* Draw our machine
* @param graphics the graphics that will be used to draw
*/
void MachineInterpret::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->Draw(graphics);
}

/**
* This class handles the updating and reseting of the frames
* @param frame the frame we should be at, calling update
*/
void MachineInterpret::SetMachineFrame(int frame)
{
    if (frame < mMachine->GetFrame())
    {
        mMachine->SetFrame(0);
    }

    while (mMachine->GetFrame() < frame) {
        mMachine->SetFrame(mMachine->GetFrame() + 1);
        mMachine->Update(1.0 / FrameRate);
    }

}

/**
* Set the machine number
* @param machine An integer number. Each integer makes a different machine
*/
void MachineInterpret::SetMachineNumber(int machine)
{

    if (machine == 1)
    {
        Machine1Factory factory(mResourcesDir, mAudioEngine);
        mMachine = factory.Create();
    }
    else
    {
        Machine2Factory factory(mResourcesDir, mAudioEngine);
        mMachine = factory.Create();
    }
    mMachine->SetMachine(machine);
}

/**
* Get the current machine number
* @return Machine number
*/
int MachineInterpret::GetMachineNumber()
{
    return mMachine->GetMachine();
}
