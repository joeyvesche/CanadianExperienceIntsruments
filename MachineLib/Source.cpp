/**
 * @file Source.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Source.h"
#include "Sink.h"

/**
* Constructor
*/
Source::Source()
{
}

/**
 * Destructor
 */
Source::~Source()
{
}

/**
* Add a sink to our vector of sinks.
* @param sink a sink that will be added to our vector
*/
void Source::AddSink(Sink* sink)
{
    mSinks.push_back(sink);
    sink->SetDriver(this);
}

/** SetRotation function to downstream rotations
* @param rotation the rotation to be set.
*/
void Source::SetRotation(double rotation)
{
    for (auto item : mSinks)
    {
        item->SetRotation(rotation);
    }
}