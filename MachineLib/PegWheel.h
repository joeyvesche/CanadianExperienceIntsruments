/**
 * @file PegWheel.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PEGWHEEL_H
#define CANADIANEXPERIENCE_PEGWHEEL_H

#include "Component.h"
#include "Source.h"
#include "Sink.h"

class Peg;
class Lever;

/**
 * Class that represents the Pegwheel and pegs
 * Derived from component
 */
class PegWheel : public Component {
private:
    /// The radius of the wheel
    int mRadius = 30;
    /// Rotation source for peg
    Source mSource;
    /// Rotation sink for peg
    Sink mSink;
    /// Vector of peg wheels
    std::vector<std::shared_ptr<Peg>> mPegs;
    /// The images directory in resources
    std::wstring mImagesDir;
    /// Vector of levers
    std::vector<std::shared_ptr<Lever>> mLever;

public:
    PegWheel(std::wstring ImagesDirectory);
    ~PegWheel();

    /// Copy constructor deleted
    PegWheel(const PegWheel&) = delete;
    /// Assignment operator deleted
    void operator=(const PegWheel&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
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

      void AddPeg(double angle);
      void AddLever(std::shared_ptr<Lever>);


};

#endif //CANADIANEXPERIENCE_PEGWHEEL_H
