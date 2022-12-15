/**
 * @file Component.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include <string>
#include "Polygon.h"

/**
 * A class that represents components
 * derived from polygon
 */
class Component : public cse335::Polygon{
private:
    /// the offset of the component
    wxPoint mOffSet;

    /// Point representing the position
    wxPoint mPosition = wxPoint(0, 0);

public:
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Handles updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) = 0;

    /// Copy constructor disabled
    Component(const Component&) = delete;
    /// Assignment operator disabled
    void operator=(const Component&) = delete;

    /** Set the componets position
	 * @param x The new component position
     * @param y The new component position*/
    virtual void SetPosition(int x, int y);

    /** Get the componets position
     * \returns The componets position*/
    wxPoint GetPosition() const { return mPosition; }

    virtual ~Component();

    Component();


};

#endif //CANADIANEXPERIENCE_COMPONENT_H
