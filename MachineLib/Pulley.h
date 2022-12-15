/**
 * @file Pulley.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PULLEY_H
#define CANADIANEXPERIENCE_PULLEY_H

#include "Component.h"
#include "Sink.h"
#include "Source.h"
#include <vector>

/**
 * Class that represents the pulley and belts
 */
class Pulley : public Component {
private:
    /// Where the belt is going to end
     std::vector<int> mBeltEnd = {0,0};
    /// Where the belt is going to start
    std::vector<int> mBeltStart = {0,0};
    /// The current length of the belt
    double mBeltLength = 0.0;
    /// Distance between the tangent and the end of the cable
    double mD = 0.0;

    /// Rotation sink
    Sink mSink;
    /// Rotation source
    Source mSource;
    /// The radius of the Pulley
    int mRadius;

    /// The amount the pulley should adjust to
    double mAdjustment = 0.0;

public:
    /// Copy constructor disbaled
    Pulley(const Pulley&) = delete;
    /// Assignment operator disabled
    void operator=(const Pulley&) = delete;

    Pulley(int radius);
    ~Pulley();

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    virtual void SetRotation(double rotation);
    virtual void SetBeltEnd(int x, int y);
    virtual void Update(double elapsed) override;
    int GetRadius();
    void Drive(std::shared_ptr<Pulley> pulley, bool sign);
    void SetStart(int x, int y);

    /**
     * Get the sink connected to shape
     * @return a pointer to the sink
     */
     Sink* GetSink() { return &mSink; }

     /**
      * Get the source to the object
      * @return Pointer to driver object
      */
      Source* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_PULLEY_H
