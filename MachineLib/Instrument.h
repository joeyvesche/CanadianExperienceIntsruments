/**
 * @file Instrument.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_INSTRUMENT_H
#define CANADIANEXPERIENCE_INSTRUMENT_H

#include <miniaudio.h>
#include "Component.h"
#include "Sink.h"

/**
 * Class the represents the instruments in the machine
 * Makes the sounds when struck
 * Derived from component
 */
class Instrument : public Component {
private:
    /// The miniaudio sound
    ma_sound mSound;

public:
    Instrument(std::wstring resourcesDir, wxString audioDir, ma_engine* audioEngine);
    ~Instrument();

    /// Copy constructor disabled
    Instrument(const Instrument&) = delete;
    /// Assignment operator disabled
    void operator=(const Instrument&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    virtual void Update(double elapsed);
    void PlaySound();

};

#endif //CANADIANEXPERIENCE_INSTRUMENT_H
