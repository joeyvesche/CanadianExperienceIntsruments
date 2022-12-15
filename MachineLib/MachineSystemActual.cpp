/**
 * @file MachineSystemActual.cpp
 * @author joeyv
 */

#include "pch.h"
#include "MachineSystemActual.h"

/** Handle updates for animation
 * \param elapsed The time since the last update
 */
void MachineSystemActual::Update(double elapsed)
{
    for (auto item : mComponents)
    {
        item->Update(elapsed);
    }
}

/**
 * Draw our draw function that draws each component
 * \param graphics The graphics context to draw on
 */
void MachineSystemActual::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto item : mComponents)
    {
        item->Draw(graphics, mX, mY);

    }
}

/**
* Add each the component to our machine
* @param component the component to be added to our machine.
*/
void MachineSystemActual::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
}

/**
 * Sets the frame on the machine
 * @param frame fame to be set
 */
void MachineSystemActual::SetMachineFrame(int frame)
{

}


/**
 * Constructor
 */
MachineSystemActual::MachineSystemActual()
{

}


/**
 * Destructor
 */
MachineSystemActual::~MachineSystemActual()
{
}