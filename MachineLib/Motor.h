/**
 * @file Motor.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "Source.h"

class Polygon;

/**
 * Class the represents the motor and its driving factor
 */
class Motor : public Component{
private:
    /// The speed the motor will rotate at
    double mSpeed = 1.0;
    /// A polygon of the base
    cse335::Polygon mBase;
    /// Rotation source
    Source mSource;
    /// The images directory in resources
    std::wstring mImagesDir;

public:
    Motor(std::wstring ImagesDirectory);
    virtual ~Motor();

    /// Copy constructor disabled
    Motor(const Motor&) = delete;
    /// Assignment operator disabled
    void operator=(const Motor&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    virtual void Update(double elapsed) override;

    /**
    * Set the speed of the motor
    * @param speed the speed we will set the motor as.
    */
    void SetSpeed(double speed) { mSpeed = speed; }

    /** Get a pointer to the source object
    * @return Pointer to CDriver object
    */
    Source* GetSource() { return &mSource; }

    /**
     * Gets the motors x position
     * @return double x position
     */
    double GetX() { return GetPosition().x; }

    /**
     * Gets the motors y position
     * @return double y position
     */
    double GetY() { return GetPosition().y; }


};

#endif //CANADIANEXPERIENCE_MOTOR_H
