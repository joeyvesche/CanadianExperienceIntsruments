/**
 * @file Machine1Factory.h
 * @author Charles Owen
 *
 * Factory for creating Machine #1
 */

#ifndef CANADIANEXPERIENCE_MACHINE1FACTORY_H
#define CANADIANEXPERIENCE_MACHINE1FACTORY_H

#include <memory>
#include <string>

class Machine;
class MachineSystemActual;
struct ma_engine;

/**
 * Factory for creating Machine #1
 */
class Machine1Factory {
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    /// Path to the audio directory
    std::wstring mAudioDir;

    /// The miniaudio engine
    ma_engine* mAudioEngine;

public:
    Machine1Factory(std::wstring resourcesDir, ma_engine* audioEngine);

    std::shared_ptr<MachineSystemActual> Create();

};

#endif //CANADIANEXPERIENCE_MACHINE1FACTORY_H
