/**
 * @file Lever.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "Source.h"
#include "Peg.h"
#include "Instrument.h"

/**
 * A class that represents the lever
 * derived from component
 */
class Lever : public Component{
private:
    /// A polygon of the base
    cse335::Polygon mLever;

    /// The images directory in resources
    std::wstring mImagesDir;
    /// Rotation source for lever
    Source mSource;
    /// The rotation of the wheel
    double mRotation;
    /// The instrument to play
    std::shared_ptr<Instrument> mInstrument = nullptr;
    /// True when peg is hit, false when not on peg
    bool mTemp = false;

public:
    Lever(std::wstring ImageDirectory);
    ~Lever();

    /// Copy constructor disabled
    Lever(const Lever&) = delete;
    /// Assignment operator disabled
    void operator=(const Lever&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    virtual void Update(double elapsed);
    void MoveLever(std::shared_ptr<Peg> peg);
    void SetRotation(double rotation);
    void LeverReset();

    /**
     * When the peg hits the lever
     * @param temp true when hit
     */
    void SetLever(bool temp) { mTemp = temp; }

    /**
     * Sets the instrument
     * @param instrument instrument to be set
     */
    void SetStruckComponent(std::shared_ptr<Instrument> instrument) { mInstrument = instrument; }

    /**
       * Get a pointer to the source object
       * @return pointer to Source object
       */
    Source* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_LEVER_H
