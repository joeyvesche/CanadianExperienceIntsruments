/**
 * @file MachineSystemActual.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINESYSTEMACTUAL_H
#define CANADIANEXPERIENCE_MACHINESYSTEMACTUAL_H

#include <vector>
#include "Component.h"

/**
 * Class the represents each machine as a whole
 */
class MachineSystemActual {
private:
    int mX = 0;     ///< Machine X location
    int mY = 0;     ///< Machine Y location
    int mFrame = 0; ///< Current frame
    int mMachine = 1;  ///< Machine number

    /// the collection of compents for the machine
    std::vector<std::shared_ptr<Component> > mComponents;

public:

    MachineSystemActual();
    ~MachineSystemActual();
    void Update(double elapsed);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void SetMachineFrame(int frame);
    void AddComponent(std::shared_ptr<Component> component);

    /**
   * Set the machine number
   * @param machine An integer number. Each integer makes a different machine
   */
    void SetMachine(int machine) { mMachine = machine; }

    /**
    * Get the current machine number
    * @return Machine number
    */
    int GetMachine() const { return mMachine; }

    /**
    * Get the current frame
    * @return the current frame
    */
    int GetFrame() const { return mFrame; }

    /**
    * Set the frame
    * @param frame the frame to be set.
    */
    void SetFrame(int frame) { mFrame = frame; }

    /**
    * Set the location
    * @param pos the position to set
    */
    void SetLocation(wxPoint pos) { mX = pos.x; mY = pos.y; }

};

#endif //CANADIANEXPERIENCE_MACHINESYSTEMACTUAL_H
