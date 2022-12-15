/**
 * @file Winch.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Winch.h"

/**
 * Constructor
 * @param ImageDirectory Images Directory
 */
Winch::Winch(std::wstring ImageDirectory) : mImagesDir(ImageDirectory)
{

    CenteredSquare(mRadius * 2);
    SetImage(mImagesDir + L"/winch.png");

    mSink.SetComponent(this);

}

/**
 * Destructor
 */
Winch::~Winch()
{
}

/**
* Draw our winch and the string
* \param graphics The graphics context to draw on
* \param x the x location to draw at
* \param y the y location to draw at
*/
void Winch::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
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
    double b = theta - phi + M_PI / 2.0;

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

    graphics->StrokeLine(int(tangent[0] + x) - 4, int(tangent[1] + y), int(x + drawPoint[0]), int(y + drawPoint[1]));

   // graphics->StrokeLine(mBeltStart[0], mBeltStart[1], int(drawPoint[0]), int(drawPoint[1]));

    Component::Draw(graphics, x, y);

}

/** Handle updates for animation
* @param elapsed The time since the last update
*/
void Winch::Update(double elapsed)
{
}

/**
* Gets the radius of the trap
* @return The radius.
*/
int Winch::GetRadius()
{
    return mRadius;
}

/** Override the SetRotation function to downstream rotations
* @param rotation the rotation to be set.
*/
void Winch::SetRotation(double rotation)
{

    // Change the rope to the dependence of rotation depends on circle circumfrance and rotation amount.
    mBeltLength -= abs((GetRotation()-rotation)*GetRadius()*2*M_PI);
    Polygon::SetRotation(rotation);
    mSource.SetRotation(rotation);

}

/**
* Set the endpoint of our cable.
* @param x The x spot of the endpoint
* @param y The y spot of the endpoint
*/
void Winch::SetCableEnd(int x, int y)
{
    mBeltEnd[0] = x;
    mBeltEnd[1] = y;

    mBeltLength = 0.0;

}