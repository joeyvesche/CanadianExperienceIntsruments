/**
 * @file PegWheel.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Peg.h"
#include "PegWheel.h"
#include "Lever.h"

/// The image to use for the peg
const std::wstring PegImage = L"/peg.png";

/// Width to draw the peg image in pixels
const int PegWidth = 4;

/// Height to draw the peg image in pixels
const int PegHeight = 10;

/// The peg wheel radius
const double PegWheelRadius = 30;

/// Pi
const double PI = 3.1415926535897932384626433832795;
/// Pi * 2
const double PI2 = PI * 2;

/// Image for the fixed lever mounting point
const std::wstring LeverMountImage = L"/lever-mount.png";

/// Image for the moving lever itself
const std::wstring LeverImage = L"/lever.png";

/**
 * Constructor
 * @param ImagesDirectory Images directory
 */
 PegWheel::PegWheel(std::wstring ImagesDirectory): mImagesDir(ImagesDirectory)
{
     CenteredSquare(mRadius * 2);
     mSink.SetComponent(this);
}


/**
 * Destructor
 */
PegWheel::~PegWheel()
{
}

/**
 * Draw the item
 * @param graphics The graphics context to draw on
 * @param x the x location to draw at
 * @param y the y location to draw at
 */
void PegWheel::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    Component::Draw(graphics, x, y);

    for(auto peg : mPegs)
    {
        peg->Draw(graphics,GetPosition().x+  x, GetPosition().y + y, PegWheelRadius);
    }

}



/**
* Handle updates for the animation
 * @param elapsed The time since the last update
*/
void PegWheel::Update(double elapsed)
{

}

/**
* Override SetRotation to downstream rotations
 * @param rotation the rotation to be set
*/
void PegWheel::SetRotation(double rotation)
{
    Component::SetRotation(rotation);

    for(auto peg : mPegs)
    {
        peg->SetRotation(rotation);

    }

    for(auto levers : mLever)
    {
        levers->SetLever(false);
        for(auto peg : mPegs)
        {
            levers->MoveLever(peg);
        }
        levers->LeverReset();
    }

    mSource.SetRotation(rotation);
}

/**
* Adds the peg to the peg wheel
 * @param angle Angle to set the peg at
*/
void PegWheel::AddPeg(double angle)
{
    auto peg = std::make_shared<Peg>(mImagesDir, angle);
    mPegs.push_back(peg);

}

/**
 * Adds lever to machine to interact with peg
 * @param lever pointer to the lever
 */
void PegWheel::AddLever(std::shared_ptr<Lever> lever)
{
    mLever.push_back(lever);
}