/**
 * @file Shape.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "Sink.h"

/**
 * Class that represents all the shapes in the machine
 * derived from component
 */
class Shape : public Component{
private:
    Sink mSink; ///< The rotation sink for this component

public:
    Shape();

    /// Copy constructor disabled
    Shape(const Shape&) = delete;
    /// Assignment operator disabled
    void operator=(const Shape&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    virtual void Update(double elapsed) override;

    virtual ~Shape();

    virtual void SetRotation(double rotation) override;

    /**
    * Get the sink connected to shape.
    *
    * @return a pointer to the sink.
    */
    Sink* GetSink() { return &mSink; }

};

#endif //CANADIANEXPERIENCE_SHAPE_H
