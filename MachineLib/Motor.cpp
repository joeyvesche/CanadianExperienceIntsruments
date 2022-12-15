/**
 * @file Motor.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Motor.h"

/// The size of the moving part
const int MotorSize = 30;

/// The base size of the motor.
const int BaseSize = 100;

/// Radius of a basic motor rotor in pixels
const double BasicRotorRadius = 15;

/**
 * Constructor
 * @param ImagesDirectory Image directory
 */
Motor::Motor(std::wstring ImagesDirectory) : mImagesDir(ImagesDirectory)
{

    // Sets the imaging and squaring of the components.
    mBase.CenteredSquare(BaseSize);
    CenteredSquare(MotorSize);
    mBase.SetImage(mImagesDir + L"/motor2.png");
    SetImage(mImagesDir + L"/shaft.png");
}

/**
 * Destructor
 */
Motor::~Motor()
{
}

/**
* Draw our motor
* @param graphics the graphics that will be used to draw
* @param x the x location to draw at
* @param y the y location to draw at
*/
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    wxPoint pos = GetPosition();
    mBase.DrawPolygon(graphics, pos.x + x, pos.y + y);

    Component::Draw(graphics, x, y);

}

/**
* Update the motor to spin
 * @param elapsed time that has passed
 */
 void Motor::Update(double elapsed)
 {
     auto rotation = GetRotation();
     rotation += elapsed * mSpeed;
     SetRotation(rotation);

     mSource.SetRotation(rotation);

 }