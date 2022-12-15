/**
 * @file Machine.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINE_H
#define CANADIANEXPERIENCE_MACHINE_H

#include <vector>

class MachineStandin;

/**
 * Class that represents a Machine
 */
class Machine {
private:

    /// Stand-in machine class to draw graphics
    std::shared_ptr<MachineStandin> mStandin;

public:
    /// Constructor
    Machine();

    /// Destructor
    virtual ~Machine() {}

    /// Copy constructor disabled
    Machine(const Machine &) = delete;

    /// Assignment operator disabled
    void operator=(const Machine &) = delete;

    /**
    * Set the position for the root of the machine
    * @param x X location (pixels)
    * @param y Y location (pixels)
    */
    virtual void SetLocation(int x, int y);

    /**
    * Draw the machine at the currently specified location
    * @param graphics GDI+ Graphics object
    */
    virtual void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    virtual void SetMachineFrame(int frame);

    /**
    * Set the machine number
    * @param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine);

    /**
     * Get the current machine number
     * @return Machine number integer
     */
    virtual int GetMachineNumber();

};

#endif //CANADIANEXPERIENCE_MACHINE_H
