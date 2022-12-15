/**
 * @file Component.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Component.h"

/**
 * Draw the item
 * @param graphics The graphics context to draw on
 * @param x the x location to draw at
 * @param y the y location to draw at
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Polygon::DrawPolygon(graphics, mPosition.x + x, mPosition.y + y);
}

/**
* Deconstructor
*/
Component::~Component()
{

}

/// Constructor
Component::Component()
{

}

void Component::SetPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}