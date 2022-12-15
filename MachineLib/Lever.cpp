/**
 * @file Lever.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Lever.h"

/// Image for the fixed lever mounting point
const std::wstring LeverMountImage = L"/lever-mount.png";

/// Image for the moving lever itself
const std::wstring LeverImage = L"/lever.png";

/// Height of the lever in pixels
const int LeverHeight = 58;

/// Width of the lever in pixels
const int LeverWidth = 28;

/// A peg is considered to be starting to touch
/// the lever when the angle reaches this value
const double PegStart = 0.02;

/// The peg releases the lever when the angle
/// reaches this value. This assumes the peg
/// is rotating in the negative direction.
const double PegEnd = -0.05;

/// The maximum rotation of the lever in turns
const double MaxRotation = 0.08;

/**
 * Constructor
 * @param ImageDirectory Image Directory
 */
Lever::Lever(std::wstring ImageDirectory) : mImagesDir(ImageDirectory)
{

    // Inherited Polygon object
    SetImage(mImagesDir + LeverMountImage);
    Rectangle(-LeverWidth/2, LeverHeight/2, LeverWidth, LeverHeight);

    // Composed Polygon object
    mLever.SetImage(mImagesDir + LeverImage);
    mLever.Rectangle(-LeverWidth/2, LeverHeight/2, LeverWidth, LeverHeight);

}

/**
 * Deconstructor
 */
 Lever::~Lever()
{
}

/**
 * Draw the lever/mount for the machine
 * @param graphics Context to draw on
 * @param x location x to draw at
 * @param y location y to draw at
 */
void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);
    mLever.DrawPolygon(graphics, GetPosition().x + x, GetPosition().y + y);


}

/**
 * Update the animation
 * @param elapsed time since last update
 */
void Lever::Update(double elapsed)
{

}

/**
 * Move the lever when the peg hits
 * @param peg The peg
 */
void Lever::MoveLever(std::shared_ptr<Peg> peg)
{
    // Add the current rotation of the peg and
    // the angle of the peg on the peg wheel.
    // This tells us where the peg is rotated, which
    // is the important part. The GetRotation is
    // for the pegwheel/peg combination.
    auto angle = peg->GetRotation() + peg->GetAngle();

    // Remove the turns and determine an angle in the
    // range -0.5 to 0.5. This code assumes turns, not
    // degrees or radians.
    angle -= GetRotation();
    int iAngle = (int)angle;
    angle -= iAngle;
    if(angle < -0.5)
    {
        angle += 1;
    }

    // Determine if the peg
    if(PegEnd <= angle && angle <= PegStart) {
        // This peg is in range
        double t = (angle-PegStart)/(PegEnd-PegStart);
        mTemp = true;

        mLever.SetRotation(t*MaxRotation);
        mSource.SetRotation(t*MaxRotation);

    }



}

/**
 * Sets the rotation of the lever
 * @param rotation how much to rotate
 */
void Lever::SetRotation(double rotation)
{
    mRotation = rotation;
    mLever.SetRotation(rotation);
}

/**
 * Reset the lever to original state and play sound
 */
void Lever::LeverReset()
{
    if (!mTemp) {
        if(mLever.GetRotation() != 0) {

            mInstrument->PlaySound();
        }

        mLever.SetRotation(0);
        mSource.SetRotation(0);
    }
}

