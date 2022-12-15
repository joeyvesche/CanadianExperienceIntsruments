/**
 * @file DrawableMachine.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_DRAWABLEMACHINE_H
#define CANADIANEXPERIENCE_DRAWABLEMACHINE_H
#include "Drawable.h"
#include "AnimChannel.h"
#include "Timeline.h"

struct ma_engine;
class MachineSystem;

/**
 * Class that adapts our machine to CanadianExperience
 */
class DrawableMachine : public Drawable{
private:
    /// pointer to the machine
    std::shared_ptr<MachineSystem> mMachine = nullptr;

    /// The resources directory
    std::wstring mResourcesDir;

    /// The miniaudio engine
    ma_engine* mAudioEngine;

    /// The timeline we are adding to
    Timeline* mTimeline = nullptr;

    /// Time to start the machine at
    double mStartTime = 0.0;

    /// TIme to end the machine at
    double mEndTime = 0.0;

    /// Which machine to select
    int mMachineNum = 1;

public:
    /// virtual destructor
    virtual ~DrawableMachine();
    /// Default constructor disabled
    DrawableMachine() = delete;
    /// Copy constructor disabled
    DrawableMachine(const DrawableMachine&) = delete;
    /// Assignment operator disabled
    void operator=(const DrawableMachine&) = delete;

    DrawableMachine(std::wstring name, int machineNum, const std::wstring resourceDir, ma_engine *engine);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    virtual bool HitTest(wxPoint position) override;

    void SetKeyFrame(int num);
    void SetPosition(wxPoint position);
    virtual void SetDialog(wxFrame* mainframe) override;

    virtual void SetMachineNum(int num) override;

    /**
     * Set the start time of the machine
     * @param time Time to start
     */
    virtual void SetStartTime(double time) override { mStartTime = time; };

    /**
     * Set the end time of the machine
     * @param time Time to end
     */
    virtual void SetEndTime(double time) override { mEndTime = time; }

    /**
     * Get the machine number
     * @return int machine number
     */
    int GetMachineNum() { return mMachineNum; }

    /**
     * Get the start time of the machine
     * @return start time of the machine
     */
    double GetStartTime() { return mStartTime; }

    /**
     * Get the end time of the machine
     * @return end time of the machine
     */
    double GetEndTime() { return mEndTime; }
};

#endif //CANADIANEXPERIENCE_DRAWABLEMACHINE_H
