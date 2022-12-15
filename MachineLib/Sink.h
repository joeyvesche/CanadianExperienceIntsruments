/**
 * @file Sink.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SINK_H
#define CANADIANEXPERIENCE_SINK_H

class Component;
class Source;

/**
 * Class the represents the rotation sinks in the machine
 */
class Sink {
private:
    /// The component that is connected to the sink
    Component* mComponent = nullptr;

    /// A pointer to the driver that is driving the sink
    Source* mSource = nullptr;

    /// Speed multiplier of the rotation
    double mSpeed = 1;

    /// How much to adjust
    double mPhase = 0;

public:
    ~Sink();
    Sink();
    /// Copy constructor disabled
    Sink(const Sink&) = delete;
    /// Assignment operator disabled
    void operator=(const Sink&) = delete;

    void SetComponent(Component* component);
    void SetRotation(double rotation);

    Component* GetComponent() const;
    void SetDriver(Source* source);
    void SetPhase(double phase);

    /**
    * Sets the speed of how fast the sinks should be rotating.
    *
    * @param speed The new speed of the sink.
    */
    void SetSpeed(double speed) { mSpeed = speed; }


};

#endif //CANADIANEXPERIENCE_SINK_H
