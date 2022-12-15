/**
 * @file MachineInterpret.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEINTERPRET_H
#define CANADIANEXPERIENCE_MACHINEINTERPRET_H

#include "MachineSystem.h"
#include "MachineSystemActual.h"
struct ma_engine;

/**
 * Class the represents a machine derived from MachineSystem
 */
class MachineInterpret : public MachineSystem {
private:
    /// Stores the actual machine/parts
    std::shared_ptr<MachineSystemActual> mMachine;

    /// The resources directory
    std::wstring mResourcesDir;

    /// The miniaudio engine
    ma_engine* mAudioEngine;

public:
    /// Constructor
    MachineInterpret(std::wstring resourcesDir, ma_engine* audioEngine);
    /// Destructor
    virtual ~MachineInterpret() {}

    /// Copy constructor disabled
    MachineInterpret(const MachineInterpret&) = delete;
    /// Assignment operator disabled
    void operator=(const  MachineInterpret&) = delete;

    virtual void SetLocation(int x, int y);

    virtual void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);

    virtual void SetMachineFrame(int frame);

    virtual void SetMachineNumber(int machine);

    virtual int GetMachineNumber();


};

#endif //CANADIANEXPERIENCE_MACHINEINTERPRET_H
