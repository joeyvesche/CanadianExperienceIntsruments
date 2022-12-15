/**
 * @file Machine2Factory.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINE2FACTORY_H

#include <memory>
#include <string>

class MachineSystemActual;
class Machine;
struct ma_engine;
/**
 * A class that represents our second machine
 */
class Machine2Factory {
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
    Machine2Factory(std::wstring resourcesDir, ma_engine* audioEngine);

    std::shared_ptr<MachineSystemActual> Create();

};

#endif //CANADIANEXPERIENCE_MACHINE2FACTORY_H
