/**
 * @file Peg.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PEG_H
#define CANADIANEXPERIENCE_PEG_H

#include "Component.h"
#include "Sink.h"
#include "Source.h"

class PegWheel;
class Polygon;

/**
 * Class that represents the pegs of the pegwheel
 */
class Peg : public Component {
private:
    /// Polygon base for pegs
    cse335::Polygon mPolygon;

    /// The images directory in resources
    std::wstring mImagesDir;
    /// Angle for the peg to be set
    double mAngle = 0;

    /// Rotation sink for peg
    Sink mSink;
    /// Rotation source for peg
    Source mSource;
    /// The rotation of the wheel
    double mRotation = 0;

public:
    Peg(std::wstring ImageDirectory, double angle);
    ~Peg();

    /// Copy constructor deleted
    Peg(const Peg&) = delete;
    /// Assignment operator deleted
    void operator=(const Peg&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, double pegRadius);

    virtual void SetRotation(double rotation);

    virtual void Update(double elapsed) override;

    /**
     * Get a pointer to the source object
     * @return pointer to Source object
     */
    Source* GetSource() { return &mSource; }

    /**
     * Get the sink connected to the shape
     * @return a pointer to the sink
     */
    Sink* GetSink() { return &mSink; }

    /**
     * Gets the angle of the peg
     * @return double angle of peg
     */
    double GetAngle() { return mAngle; }

    /**
     * Gets the rotation of the peg
     * @return double rotation of the peg
     */
    double GetRotation() { return mRotation; }


};

#endif //CANADIANEXPERIENCE_PEG_H
