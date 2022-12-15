/**
 * @file Machine1Factory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "Machine1Factory.h"
#include "Machine.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "PegWheel.h"
#include "Lever.h"
#include "MachineSystemActual.h"
#include "Instrument.h"
#include "MachineInterpret.h"

using namespace std;

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/// The audio directory in resources
const std::wstring AudioDirectory = L"/audio";

/**
 * Constructor
 * @param resourcesDir Image resource directory
 * @param audioEngine Audio engine for instruments
 */
Machine1Factory::Machine1Factory(std::wstring resourcesDir, ma_engine* audioEngine) :
        mResourcesDir(resourcesDir), mAudioEngine(audioEngine)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
    mAudioDir = mResourcesDir + AudioDirectory;
}

/**
 * Create a machine
* @return object of type Machine
*/
std::shared_ptr<MachineSystemActual> Machine1Factory::Create()
{
    // The machine itself
    shared_ptr<MachineSystemActual> machine = make_shared<MachineSystemActual>();

    // The framework.
    auto base = make_shared<Shape>();
    int wid = 543;
    int hit = 366;
    base->Rectangle(150, 550, wid, hit);
    base->SetImage( mImagesDir + L"/framework.png");
    machine->AddComponent(base);

    // The motor
    shared_ptr<Motor> motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(201, 452);
    motor->SetSpeed(-0.2);
    machine->AddComponent(motor);

    // The pulley driven by the motor
    shared_ptr<Pulley> pulley1 = std::make_shared<Pulley>(30);
    pulley1->SetImage(mImagesDir + L"/pulley2.png");

    pulley1->SetPosition(201, 452 );
    pulley1->SetStart(201, 482);
    pulley1->SetBeltEnd(254, 527);

    // Connect motor as a source to the pulley as a sink
    motor->GetSource()->AddSink(pulley1->GetSink());

    // Two more pulleys
    auto pulley2t = std::make_shared<Pulley>(20);
    pulley2t->SetImage(mImagesDir + L"/pulley1.png");
    pulley2t->SetPosition(270, 517);
    pulley2t->SetStart(270, 535);
    pulley2t->SetBeltEnd(614,535);
    machine->AddComponent(pulley2t);

    // First peg wheel
    auto pegWheel1 = make_shared<PegWheel>(mImagesDir);
    pegWheel1->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel1->SetPosition(622, 385);

    machine->AddComponent(pegWheel1);

    auto kick = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
            mAudioDir + L"/kick.wav", mAudioEngine);
    kick->CenteredSquare(100);
    kick->SetPosition(278, 239);
    machine->AddComponent(kick);

    auto tom = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
            mAudioDir + L"/tom.wav",
            mAudioEngine);
    tom->CenteredSquare(60);
    tom->SetPosition(365, 244);
    machine->AddComponent(tom);

    auto snare = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
            mAudioDir + L"/snare.wav",
            mAudioEngine);
    snare->CenteredSquare(50);
    snare->SetPosition(445, 244);
    machine->AddComponent(snare);

    auto cowbell = std::make_shared<Instrument>(mImagesDir + L"/cowbell.png",
            mAudioDir + L"/cowbell.wav",
            mAudioEngine);
    cowbell->CenteredSquare(60);
    cowbell->SetPosition(525, 234);
    machine->AddComponent(cowbell);

    auto cymbal = std::make_shared<Instrument>(mImagesDir + L"/cymbal.png",
            mAudioDir + L"/cymbal.wav",
            mAudioEngine);
    cymbal->CenteredSquare(80);
    cymbal->SetPosition(603, 224);
    machine->AddComponent(cymbal);

    // Bottom right pulley
    auto pulley3t = std::make_shared<Pulley>(20);
    pulley3t->SetImage(mImagesDir + L"/pulley1.png");
    pulley3t->SetPosition(622, 517);
    machine->AddComponent(pulley3t);

    machine->AddComponent(pulley1);
    pulley3t->SetStart(640,517);
    pulley3t->SetBeltEnd(638,385);

    pulley1->Drive(pulley2t, true);
    pulley1->Drive(pulley3t, true);

    // fourth pulley
    auto pulley4 = std::make_shared<Pulley>(10);
    pulley4->SetImage(mImagesDir + L"/idler1.png");
    pulley4->SetPosition(670, 385);
    pulley4->SetStart(679,385);
    pulley4->SetBeltEnd(680, 197);
    machine->AddComponent(pulley4);

    // fifth pulley
    auto pulley5 = std::make_shared<Pulley>(15);
    pulley5->SetImage(mImagesDir + L"/pulley3.png");
    pulley5->SetPosition(670, 197);
    pulley5->SetStart(657,197);
    pulley5->SetBeltEnd(662, 350);
    machine->AddComponent(pulley5);

    // sixth pulley to move belt over
    auto pulley6 = std::make_shared<Pulley>(10);
    pulley6->SetImage(mImagesDir + L"/idler1.png");
    pulley6->SetPosition(653, 350);
    pulley6->SetStart(653,359);
    pulley6->SetBeltEnd(622,368);
    machine->AddComponent(pulley6);

    // Seventh pulley
    auto pulley7 = std::make_shared<Pulley>(20);
    pulley7->SetImage(mImagesDir + L"/pulley1.png");
    pulley7->SetPosition(622, 385);
    pulley7->SetStart(622, 403);
    pulley7->SetBeltEnd(670,390);
    machine->AddComponent(pulley7);

    // Wheel on pulley
    auto pulley7w = std::make_shared<Pulley>(15);
    pulley7w->SetImage(mImagesDir + L"/pulley3.png");
    pulley7w->SetPosition(622, 385);
    pulley7w->SetStart(607,385);
    pulley7w->SetBeltEnd(595, 466);
    machine->AddComponent(pulley7w);

    pulley1->Drive(pulley7w, true);
    pulley1->Drive(pulley7, true);
    pulley7->GetSource()->AddSink(pulley7w->GetSink());
    pulley7w->Drive(pulley4, true);
    pulley7w->Drive(pulley6, false);
    pulley7w->Drive(pulley5, true);

    // Connect pulley to peg wheel
    pulley7w->GetSource()->AddSink(pegWheel1->GetSink());

    // second peg wheel
    auto pegWheel2 = make_shared<PegWheel>(mImagesDir);
    pegWheel2->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel2->SetPosition(544, 385);

    machine->AddComponent(pegWheel2);

    // third peg wheel
    auto pegWheel3 = make_shared<PegWheel>(mImagesDir);
    pegWheel3->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel3->SetPosition(466, 385);

    machine->AddComponent(pegWheel3);

    // fourth peg wheel
    auto pegWheel4 = make_shared<PegWheel>(mImagesDir);
    pegWheel4->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel4->SetPosition(388, 385);

    machine->AddComponent(pegWheel4);

    // Last peg wheel
    auto pegWheel5 = make_shared<PegWheel>(mImagesDir);
    pegWheel5->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel5->SetPosition(310,385);

    machine->AddComponent(pegWheel5);

    // Eighth pulley
    auto pulley8 = std::make_shared<Pulley>(15);
    pulley8->SetImage(mImagesDir + L"/idler1.png");
    pulley8->SetPosition(583, 466);
    pulley8->SetStart(570,466);
    pulley8->SetBeltEnd(551,385);
    machine->AddComponent(pulley8);
    pulley1->Drive(pulley8, false);

    // Ninth pulley
    auto pulley9 = std::make_shared<Pulley>(10);
    pulley9->SetImage(mImagesDir + L"/pulley1.png");
    pulley9->SetPosition(544, 385);
    pulley9->SetStart(536,385);
    pulley9->SetBeltEnd(518,466);
    machine->AddComponent(pulley9);
    pulley1->Drive(pulley9, true);
    // Connect pulley to peg wheel
    pulley9->GetSource()->AddSink(pegWheel2->GetSink());

    // Tenth pulley
    auto pulley10 = std::make_shared<Pulley>(15);
    pulley10->SetImage(mImagesDir + L"/idler1.png");
    pulley10->SetPosition(505, 466);
    pulley10->SetStart(492,466);
    pulley10->SetBeltEnd(486,385);
    machine->AddComponent(pulley10);
    pulley1->Drive(pulley10, false);

    // Eleventh pulley
    auto pulley11 = std::make_shared<Pulley>(20);
    pulley11->SetImage(mImagesDir + L"/pulley1.png");
    pulley11->SetPosition(466, 385);
    pulley11->SetStart(448,385);
    pulley11->SetBeltEnd(435, 466);
    machine->AddComponent(pulley11);
    pulley1->Drive(pulley11, true);
    // Connect pulley to peg wheel
    pulley11->GetSource()->AddSink(pegWheel3->GetSink());

    // Twelveth pulley
    auto pulley12 = std::make_shared<Pulley>(15);
    pulley12->SetImage(mImagesDir + L"/idler1.png");
    pulley12->SetPosition(422, 466);
    pulley12->SetStart(410,466);
    pulley12->SetBeltEnd(406,385);
    machine->AddComponent(pulley12);
    pulley1->Drive(pulley12, false);


    // Thirteenth pulley
    auto pulley13 = std::make_shared<Pulley>(20);
    pulley13->SetImage(mImagesDir + L"/pulley1.png");
    pulley13->SetPosition(388, 385);
    pulley13->SetStart(370,385);
    pulley13->SetBeltEnd(356,466);
    machine->AddComponent(pulley13);
    pulley1->Drive(pulley13, true);
    // Connect pulley to peg wheel
    pulley13->GetSource()->AddSink(pegWheel4->GetSink());

    // Fourteenth pulley
    auto pulley14 = std::make_shared<Pulley>(15);
    pulley14->SetImage(mImagesDir + L"/idler1.png");
    pulley14->SetPosition(343, 466);
    pulley14->SetStart(329,466);
    pulley14->SetBeltEnd(320, 385);
    machine->AddComponent(pulley14);
    pulley1->Drive(pulley14, false);

    // Last pulley
    auto pulley15 = std::make_shared<Pulley>(10);
    pulley15->SetImage(mImagesDir + L"/pulley1.png");
    pulley15->SetPosition(310, 385);
    pulley15->SetStart(302,379);
    pulley15->SetBeltEnd(199, 424);
    machine->AddComponent(pulley15);
    pulley1->Drive(pulley15, true);
    // Connect pulley to peg wheel
    pulley15->GetSource()->AddSink(pegWheel5->GetSink());

    pegWheel1->AddPeg(0.5);
    pegWheel2->AddPeg(0.05);
    pegWheel2->AddPeg(0.30);
    pegWheel2->AddPeg(0.55);
    pegWheel2->AddPeg(0.80);

    pegWheel3->AddPeg(0.15);
    pegWheel3->AddPeg(0.40);
    pegWheel3->AddPeg(0.65);
    pegWheel3->AddPeg(0.90);

    double temp = 0;
    for(int i=0;i<8;i++)
    {
        pegWheel4->AddPeg(0.05 + temp);
        temp+=1.0/8;
    }

    pegWheel5->AddPeg(0.05);
    pegWheel5->AddPeg(0.55);


    // Right Lever mount
    auto lever1 = std::make_shared<Lever>(mImagesDir);
    lever1->SetPosition(622, 321);
    machine->AddComponent(lever1);
    pegWheel1->AddLever(lever1);

    // Second Lever mount
    auto lever2 = std::make_shared<Lever>(mImagesDir);
    lever2->SetPosition(544, 321);
    machine->AddComponent(lever2);
    pegWheel2->AddLever(lever2);

    // Third Lever mount
    auto lever3 = std::make_shared<Lever>(mImagesDir);
    lever3->SetPosition(466, 321);
    machine->AddComponent(lever3);
    pegWheel3->AddLever(lever3);

    // Fourth Lever mount
    auto lever4 = std::make_shared<Lever>(mImagesDir);
    lever4->SetPosition(388, 321);
    machine->AddComponent(lever4);
    pegWheel4->AddLever(lever4);

    // Fifth Lever mount
    auto lever5 = std::make_shared<Lever>(mImagesDir);
    lever5->SetPosition(310, 321);
    machine->AddComponent(lever5);
    pegWheel5->AddLever(lever5);

    // First Drumstick
    auto stick1 = std::make_shared<Shape>();
    stick1->SetPosition(622, 321);
    stick1->Rectangle(-2,2,5,80);
    stick1->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick1);
    lever1->GetSource()->AddSink(stick1->GetSink());
    stick1->GetSink()->SetPhase(-0.012);
    lever1->SetStruckComponent(cymbal);

    // Second Drumstick
    auto stick2 = std::make_shared<Shape>();
    stick2->SetPosition(544, 321);
    stick2->Rectangle(-2,2,5,80);
    stick2->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick2);
    lever2->GetSource()->AddSink(stick2->GetSink());
    stick2->GetSink()->SetPhase(-0.012);
    lever2->SetStruckComponent(cowbell);

    // Third Drumstick
    auto stick3 = std::make_shared<Shape>();
    stick3->SetPosition(466, 321);
    stick3->Rectangle(-2,2,5,80);
    stick3->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick3);
    lever3->GetSource()->AddSink(stick3->GetSink());
    stick3->GetSink()->SetPhase(-0.012);
    lever3->SetStruckComponent(snare);

    // Fourth Drumstick
    auto stick4 = std::make_shared<Shape>();
    stick4->SetPosition(388, 321);
    stick4->Rectangle(-2,2,5,80);
    stick4->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick4);
    lever4->GetSource()->AddSink(stick4->GetSink());
    stick4->GetSink()->SetPhase(-0.012);
    lever4->SetStruckComponent(tom);

    // Fifth Drumstick
    auto stick5 = std::make_shared<Shape>();
    stick5->SetPosition(310, 321);
    stick5->Rectangle(-2,2,5,80);
    stick5->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick5);
    lever5->GetSource()->AddSink(stick5->GetSink());
    stick5->GetSink()->SetPhase(-0.012);
    lever5->SetStruckComponent(kick);

    // The rotating flag
    auto flag = std::make_shared<Shape>();
    flag->SetImage(mImagesDir + L"/msu-flag.png");
    flag->Rectangle(0, 0, 28, 60);
    flag->SetPosition(670, 197);
    machine->AddComponent(flag);
    pulley5->GetSource()->AddSink(flag->GetSink());

    return machine;
}