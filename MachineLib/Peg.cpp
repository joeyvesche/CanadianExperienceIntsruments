/**
 * @file Peg.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Peg.h"

/// The peg wheel radius
const double PegWheelRadius = 30;
/// Width to draw the peg image in pixels
const int PegWidth = 4;

/// Height to draw the peg image in pixels
const int PegHeight = 10;

/// The image to use for the peg
const std::wstring PegImage = L"/peg.png";

/**
 * Constructor
 * @param ImageDirectory Image directory
 * @param angle Angle for the pegs to be set
 */
Peg::Peg(std::wstring ImageDirectory, double angle) : mImagesDir(ImageDirectory)
{
    mAngle = angle;
    mPolygon.BottomCenteredRectangle(PegWidth, PegHeight);
    mPolygon.SetImage(mImagesDir + PegImage);
    mSink.SetComponent(this);
}

/**
 * Destructor
 */
Peg::~Peg()
{

}

/**
 * Draws the pegs
 * @param graphics graphics context to draw on
 * @param x x location to draw at
 * @param y y location to draw at
 * @param pegRadius the Pegs radius
 */
void Peg::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, double pegRadius)
{
    graphics->PushState();
    graphics->Translate(x,  y);
    graphics->Rotate((mRotation + mAngle) * M_PI * 2);
    mPolygon.DrawPolygon(graphics, 0, -PegWheelRadius);
    graphics->PopState();
}

/**
 * Sets the rotation of the pegs
 * @param rotation how much to rotate
 */
void Peg::SetRotation(double rotation)
{
    mRotation = rotation;
}

/**
* Handle updates for the animation
 * @param elapsed The time since the last update
*/
void Peg::Update(double elapsed)
{

}