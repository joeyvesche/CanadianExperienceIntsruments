/**
 * @file Sink.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Sink.h"
#include "Component.h"
#include "Source.h"
#include "Polygon.h"


/**
* Constructor
*/
Sink::~Sink()
{
}

/**
 * Destructor
 */
Sink::Sink()
{
}

/**
* Sets the component that will be a sink.
*
* \param component A pointer to what component will be a sink.
*/
void Sink::SetComponent(Component* component)
{
    mComponent = component;
}

/**
* Uses speed to move each sink. This is called by driver to slow down gears.
*
* @param rotation the amount the sink should rotate with speed applied.
*/
void Sink::SetRotation(double rotation)
{
    if (mComponent != nullptr)
    {
        mComponent->SetRotation(rotation * mSpeed + mPhase);
    }
}

/**
* Getter for the component held by the sink.
*
* @return A pointer to the component, that is a sink.
*/
Component* Sink::GetComponent() const
{
    return mComponent;
}

/**
* Sets what will be driving the current sink.
*
* @param source a pointer to the source that will drive it.
*/
void Sink::SetDriver(Source* source)
{
    mSource = source;
}

/**
 * Sets the phase so everything is synced
 * @param phase amount to adjust
 */
void Sink::SetPhase(double phase)
{
    mPhase = phase;
    SetRotation(mPhase);

}