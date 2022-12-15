/**
 * @file Machine.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Machine.h"
#include "MachineStandin.h"

using namespace std;

Machine::Machine()
{
    mStandin = make_shared<MachineStandin>();
}

void Machine::SetLocation(int x, int y)
{
    mStandin->SetLocation(wxPoint(x, y));
}

void Machine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mStandin->DrawMachine(graphics);
}

void Machine::SetMachineFrame(int frame)
{
    mStandin->SetMachineFrame(frame);
}

void Machine::SetMachineNumber(int seed)
{
    mStandin->SetMachine(seed);
}

int Machine::GetMachineNumber()
{
    return mStandin->GetMachine();
}

