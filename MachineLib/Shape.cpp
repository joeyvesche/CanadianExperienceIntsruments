/**
 * @file Shape.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Shape.h"


/**
* Constructor
*/
Shape::Shape() : Component()
{
    mSink.SetComponent(this);
}

/**
* Draw our item
* @param graphics The graphics context to draw on
* \param x the x location to draw at
* \param y the y location to draw at
*/
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);
}

/** Handle updates for animation
* @param elapsed The time since the last update
*/
void Shape::Update(double elapsed)
{

}


/**
 * Destructor
 */
Shape::~Shape()
{
}

/** Override the SetRotation function to downstream rotations
* @param rotation the rotation to be set.
*/
void Shape::SetRotation(double rotation)
{
    Polygon::SetRotation(rotation);
}