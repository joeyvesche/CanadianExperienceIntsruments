/**
 * @file Winch.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_WINCH_H
#define CANADIANEXPERIENCE_WINCH_H

#include "Component.h"
#include "Sink.h"
#include "Source.h"
#include <vector>

/**
 * Class that represents the winch
 */
class Winch : public Component{
private:
    /// Where the belt is going to end
    std::vector<int> mBeltEnd = {0,0};
    /// Where the belt is going to start
    std::vector<int> mBeltStart = {0,0};
    /// The current length of the belt
    double mBeltLength = 0.0;
    /// Distance between the tangent and the end of the cable
    double mD = 0.0;

    Sink mSink; ///< The rotation sink for this component

    /// Rotation source for this component
    Source mSource;
    /// The radius of the winch
    int mRadius = 35;
    /// The images directory in resources
    std::wstring mImagesDir;

public:
    ///Copy constructor disabled
    Winch(const Winch&) = delete;
    /// Assignment operator disabled
    void operator=(const Winch&) = delete;

    Winch(std::wstring ImageDirectory);
    ~Winch();

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    virtual void SetRotation(double rotation);
    virtual void Update(double elapsed) override;
    virtual void SetCableEnd(int x, int y);
    int GetRadius();

    /**
   * Get the sink connected to shape.
   *
   * @return a pointer to the sink.
   */
    Sink* GetSink() { return &mSink; }


    /** Get a pointer to the source object
     *@return Pointer to CDriver object
     */
    Source* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_WINCH_H
