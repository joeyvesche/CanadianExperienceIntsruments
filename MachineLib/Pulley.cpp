/**
 * @file Pulley.cpp
 * @author joeyv
 */
#include "pch.h"
#include "Pulley.h"

/// PI
const double PI = 3.1415;

/**
 * constructor
 * @param radius Radius of the pulley
 */
Pulley::Pulley(int radius) : Component()
{

    mRadius = radius;
    CenteredSquare(mRadius * 2);
    mSink.SetComponent(this);
}

/**
* Deconstructor
*/
Pulley::~Pulley()
{
}

/**
* Draw the Pulley/Belt
 * @param graphics the graphics context to draw on
 * @param x the x location to draw at
 * @param y the y location to draw at
*/
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    wxPen pen(*wxBLACK,2);
    graphics->SetPen(pen);
    auto pos = GetPosition();

    // Belt difference
    double xDifference = (double)mBeltEnd[0] - (double)pos.x;
    double yDifference = (double)mBeltEnd[1] - (double)pos.y;

    // use formula
    double theta = atan2(yDifference, xDifference);

    double distance = sqrt((double)(xDifference * xDifference) + (yDifference * yDifference));
    double phi = asin(double(mRadius) / distance);
    double b = theta - phi + PI / 2.0;

    std::vector<double> tangent;
    tangent.push_back(double(mRadius * cos(b)));
    tangent.push_back(double(-mRadius) * sin(b));

    std::vector<int> point1;
    point1.push_back(pos.x);
    point1.push_back(pos.y);

    tangent[0] = tangent[0] + point1[0];
    tangent[1] = tangent[1] + point1[1];

    // Draw partial line
    // how far to belt end
    mD = sqrt(((mBeltEnd[1] - tangent[1]) * (mBeltEnd[1] - tangent[1])) + ((mBeltEnd[0] - tangent[0]) * (mBeltEnd[0] - tangent[0])));

    if(int(mBeltLength) == 0)
    {
        mBeltLength = mD;
    }

    // what % of line is outstanding
    double t = mBeltLength / mD;

    // draw that much
    auto f = t;

    std::vector<double> drawPoint;
    drawPoint.push_back(tangent[0] + (mBeltEnd[0] - tangent[0]) * t);
    drawPoint.push_back(tangent[1] + (mBeltEnd[1] - tangent[1]) * t);


    graphics->StrokeLine(mBeltStart[0], mBeltStart[1], int(drawPoint[0]), int(drawPoint[1]));

    Component::Draw(graphics, x, y);
}

/**
* Gets the radius
 * @return the Radius of the pulley
*/
int Pulley::GetRadius()
{
    return mRadius;
}

/**
* Override to downstream rotations
 * @param rotation how much to rotate
*/
void Pulley::SetRotation(double rotation)
{
    Polygon::SetRotation(rotation);
    mSource.SetRotation(rotation);

}

/**
* Set the endpoint of the belt
 * @param x The x spot of the endpoint
 * @param y The y spot of the endpoint
*/
void Pulley::SetBeltEnd(int x, int y)
{
    mBeltEnd[0] = x;
    mBeltEnd[1] = y;

    mBeltLength = 0.0;
}

/**
 * Set the startpoint of the belt
 * @param x The x location of the startpoint
 * @param y The y location of the startpoint
 */
void Pulley::SetStart(int x, int y)
{
    mBeltStart[0] = x;
    mBeltStart[1] = y;

}

/**
* Handle updates for animation
 * @param elapsed The time since the last update
*/
void Pulley::Update(double elapsed)
{
}

/**
* Tells the pulley what pulley it will drive
 * @param pulley the pulley that the calling pulley will drive
 * @param sign which way the pulley will rotate
*/
void Pulley::Drive(std::shared_ptr<Pulley> pulley, bool sign)
{
    int val;
    // counterclockwise
    if (sign)
    {
        val = 1;
    }
    // clockwise
    else
    {
        val = -1;
    }

    mSource.AddSink(pulley->GetSink());
    pulley->GetSink()->SetSpeed((mRadius / pulley->mRadius) * val);
}