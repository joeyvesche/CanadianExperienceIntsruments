/**
 * @file Machine2Factory.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Machine2Factory.h"
#include "Machine.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "PegWheel.h"
#include "Lever.h"
#include "MachineSystemActual.h"
#include "Instrument.h"
#include "MachineInterpret.h"
#include "Winch.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/// The audio directory in resources
const std::wstring AudioDirectory = L"/audio";

using namespace std;

/**
 * Constructor
 * @param resourcesDir Resources directory for images
 * @param audioEngine Audio engine for instruments
 */
Machine2Factory::Machine2Factory(std::wstring resourcesDir, ma_engine* audioEngine) :
        mResourcesDir(resourcesDir), mAudioEngine(audioEngine)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
    mAudioDir = mResourcesDir + AudioDirectory;
}


/**
* Create a machine object
 * @return Object of type MachineSystemActual
*/
std::shared_ptr<MachineSystemActual> Machine2Factory::Create()
{
    shared_ptr<MachineSystemActual> machine = make_shared<MachineSystemActual>();
    machine->SetMachine(2);

    // The framework.
    auto base = make_shared<Shape>();
    int wid = 700;
    int hit = 600;
    base->Rectangle(150, 550, wid, hit);
    base->SetImage( mImagesDir + L"/mortier.png");
    machine->AddComponent(base);

    // The motor
    shared_ptr<Motor> motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(221, 500);
    motor->SetSpeed(0.5);
    machine->AddComponent(motor);

    // The pulley driven by the motor
    shared_ptr<Pulley> pulley1 = std::make_shared<Pulley>(30);
    pulley1->SetImage(mImagesDir + L"/pulley2.png");

    pulley1->SetPosition(221, 500 );
    pulley1->SetStart(249, 500);
    pulley1->SetBeltEnd(302, 449);

    // Connect motor as a source to the pulley as a sink
    motor->GetSource()->AddSink(pulley1->GetSink());



    // First peg wheel
    auto pegWheel1 = make_shared<PegWheel>(mImagesDir);
    pegWheel1->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel1->SetPosition(310, 449);

    machine->AddComponent(pegWheel1);
    machine->AddComponent(pulley1);

    // second peg wheel
    auto pegWheel2 = make_shared<PegWheel>(mImagesDir);
    pegWheel2->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel2->SetPosition(388, 449);

    machine->AddComponent(pegWheel2);

    // third peg wheel
    auto pegWheel3 = make_shared<PegWheel>(mImagesDir);
    pegWheel3->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel3->SetPosition(466, 449);

    machine->AddComponent(pegWheel3);

    // fourth peg wheel
    auto pegWheel4 = make_shared<PegWheel>(mImagesDir);
    pegWheel4->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel4->SetPosition(544, 449);

    machine->AddComponent(pegWheel4);

    // Last peg wheel
    auto pegWheel5 = make_shared<PegWheel>(mImagesDir);
    pegWheel5->SetImage(mImagesDir + L"/wood-wheel.png");
    pegWheel5->SetPosition(622, 449);

    machine->AddComponent(pegWheel5);




    // The Instruments
    auto kick = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
            mAudioDir + L"/kick.wav", mAudioEngine);
    kick->CenteredSquare(100);
    kick->SetPosition(278, 303);
    machine->AddComponent(kick);

    auto tom = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
            mAudioDir + L"/tom.wav",
            mAudioEngine);
    tom->CenteredSquare(60);
    tom->SetPosition(365, 303);
    machine->AddComponent(tom);

    auto snare = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
            mAudioDir + L"/snare.wav",
            mAudioEngine);
    snare->CenteredSquare(50);
    snare->SetPosition(445, 303);
    machine->AddComponent(snare);

    auto cowbell = std::make_shared<Instrument>(mImagesDir + L"/cowbell.png",
            mAudioDir + L"/cowbell.wav",
            mAudioEngine);
    cowbell->CenteredSquare(60);
    cowbell->SetPosition(525, 303);
    machine->AddComponent(cowbell);

    auto cymbal = std::make_shared<Instrument>(mImagesDir + L"/cymbal.png",
            mAudioDir + L"/cymbal.wav",
            mAudioEngine);
    cymbal->CenteredSquare(80);
    cymbal->SetPosition(603, 303);
    machine->AddComponent(cymbal);



    // second pulley
    auto pulley2 = std::make_shared<Pulley>(10);
    pulley2->SetImage(mImagesDir + L"/pulley1.png");
    pulley2->SetPosition(310, 449);
    pulley2->SetStart(318, 449);
    pulley2->SetBeltEnd(330, 530);
    machine->AddComponent(pulley2);
    pulley1->Drive(pulley2, false);
    // Connect pulley to peg wheel
    pulley2->GetSource()->AddSink(pegWheel1->GetSink());

    // third pulley
    auto pulley3 = std::make_shared<Pulley>(15);
    pulley3->SetImage(mImagesDir + L"/idler1.png");
    pulley3->SetPosition(343, 530);
    pulley3->SetStart(356, 530);
    pulley3->SetBeltEnd(375,449);
    machine->AddComponent(pulley3);
    pulley1->Drive(pulley3, true);

    // fourth pulley
    auto pulley4 = std::make_shared<Pulley>(15);
    pulley4->SetImage(mImagesDir + L"/pulley1.png");
    pulley4->SetPosition(388, 449);
    pulley4->SetStart(401,449);
    pulley4->SetBeltEnd(409,530);
    machine->AddComponent(pulley4);
    pulley1->Drive(pulley4, false);
    // Connect pulley to peg wheel
    pulley4->GetSource()->AddSink(pegWheel2->GetSink());

    // fifth pulley
    auto pulley5 = std::make_shared<Pulley>(15);
    pulley5->SetImage(mImagesDir + L"/idler1.png");
    pulley5->SetPosition(422, 530);
    pulley5->SetStart(435, 530);
    pulley5->SetBeltEnd(458, 449);
    machine->AddComponent(pulley5);
    pulley1->Drive(pulley5, true);

    // Sixth pulley
    auto pulley6 = std::make_shared<Pulley>(10);
    pulley6->SetImage(mImagesDir + L"/pulley1.png");
    pulley6->SetPosition(466, 449);
    pulley6->SetStart(474, 449);
    pulley6->SetBeltEnd(492, 530);
    machine->AddComponent(pulley6);
    pulley1->Drive(pulley6, false);
    // Connect pulley to peg wheel
    pulley6->GetSource()->AddSink(pegWheel3->GetSink());

    // Seventh pulley
    auto pulley7 = std::make_shared<Pulley>(15);
    pulley7->SetImage(mImagesDir + L"/idler1.png");
    pulley7->SetPosition(505, 530);
    pulley7->SetStart(518, 530);
    pulley7->SetBeltEnd(536, 449);
    machine->AddComponent(pulley7);
    pulley1->Drive(pulley7, true);

    // Eighth pulley
    auto pulley8 = std::make_shared<Pulley>(10);
    pulley8->SetImage(mImagesDir + L"/pulley1.png");
    pulley8->SetPosition(544, 449);
    pulley8->SetStart(552, 449);
    pulley8->SetBeltEnd(570, 530);
    machine->AddComponent(pulley8);
    pulley1->Drive(pulley8, false);
    // Connect pulley to peg wheel
    pulley8->GetSource()->AddSink(pegWheel4->GetSink());

    // Ninth pulley
    auto pulley9 = std::make_shared<Pulley>(15);
    pulley9->SetImage(mImagesDir + L"/idler1.png");
    pulley9->SetPosition(583, 530);
    pulley9->SetStart(596, 530);
    pulley9->SetBeltEnd(614, 449);
    machine->AddComponent(pulley9);
    pulley1->Drive(pulley9, true);

    // Tenth pulley
    auto pulley10 = std::make_shared<Pulley>(10);
    pulley10->SetImage(mImagesDir + L"/pulley1.png");
    pulley10->SetPosition(622, 449);
    pulley10->SetStart(614, 449);
    pulley10->SetBeltEnd(678, 385);
    machine->AddComponent(pulley10);
    pulley1->Drive(pulley10, false);
    // Connect pulley to peg wheel
    pulley10->GetSource()->AddSink(pegWheel5->GetSink());

    // Eleventh pulley
    auto pulley11 = std::make_shared<Pulley>(15);
    pulley11->SetImage(mImagesDir + L"/pulley3.png");
    pulley11->SetPosition(670, 197);
    machine->AddComponent(pulley11);
    pulley1->Drive(pulley11, true);

    // Twelveth pulley
    auto pulley12 = std::make_shared<Pulley>(10);
    pulley12->SetImage(mImagesDir + L"/pulley1.png");
    pulley12->SetPosition(670, 385);
    machine->AddComponent(pulley12);
    pulley1->Drive(pulley12, false);

    pulley12->SetStart(678, 385);
    pulley12->SetBeltEnd(683, 197);

    pulley11->SetStart(670, 189);
    pulley11->SetBeltEnd(600, 162);

    auto pulley13 = std::make_shared<Pulley>(20);
    pulley13->SetImage(mImagesDir + L"/pulley1.png");
    pulley13->SetPosition(600, 180);
    pulley13->SetStart(600, 162);
    pulley13->SetBeltEnd(220, 232);
    machine->AddComponent(pulley13);
    pulley1->Drive(pulley13, true);

    auto pulley14 = std::make_shared<Pulley>(20);
    pulley14->SetImage(mImagesDir + L"/pulley1.png");
    pulley14->SetPosition(220, 250);
    pulley14->SetStart(202, 250);
    pulley14->SetBeltEnd(193,500);
    machine->AddComponent(pulley14);
    pulley1->Drive(pulley14, true);



    pegWheel1->AddPeg(0.5);
    pegWheel1->AddPeg(0.7);

    pegWheel2->AddPeg(0.05);
    pegWheel2->AddPeg(0.20);
    pegWheel2->AddPeg(0.30);
    pegWheel2->AddPeg(0.80);

    pegWheel3->AddPeg(0.10);
    pegWheel3->AddPeg(0.45);
    pegWheel3->AddPeg(0.90);

    pegWheel4->AddPeg(0.25);
    pegWheel4->AddPeg(0.35);
    pegWheel4->AddPeg(0.45);
    pegWheel4->AddPeg(0.55);
    pegWheel4->AddPeg(0.65);

    pegWheel5->AddPeg(0.05);
    pegWheel5->AddPeg(0.25);



    // Right Lever mount
    auto lever1 = std::make_shared<Lever>(mImagesDir);
    lever1->SetPosition(622, 385);
    machine->AddComponent(lever1);
    pegWheel5->AddLever(lever1);

    // Second Lever mount
    auto lever2 = std::make_shared<Lever>(mImagesDir);
    lever2->SetPosition(544, 385);
    machine->AddComponent(lever2);
    pegWheel4->AddLever(lever2);

    // Third Lever mount
    auto lever3 = std::make_shared<Lever>(mImagesDir);
    lever3->SetPosition(466, 385);
    machine->AddComponent(lever3);
    pegWheel3->AddLever(lever3);

    // Fourth Lever mount
    auto lever4 = std::make_shared<Lever>(mImagesDir);
    lever4->SetPosition(388, 385);
    machine->AddComponent(lever4);
    pegWheel2->AddLever(lever4);

    // Fifth Lever mount
    auto lever5 = std::make_shared<Lever>(mImagesDir);
    lever5->SetPosition(310, 385);
    machine->AddComponent(lever5);
    pegWheel1->AddLever(lever5);

    /**
    auto winch = std::make_shared<Winch>(mImagesDir);
    winch->SetPosition(466, 220);
    winch->SetCableEnd(400, 400);
    machine->AddComponent(winch);
    pulley1->GetSource()->AddSink(winch->GetSink());
*/

    // First Drumstick
    auto stick1 = std::make_shared<Shape>();
    stick1->SetPosition(622, 385);
    stick1->Rectangle(-2,2,5,80);
    stick1->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick1);
    lever1->GetSource()->AddSink(stick1->GetSink());
    stick1->GetSink()->SetPhase(-0.012);
    lever1->SetStruckComponent(cymbal);

    // Second Drumstick
    auto stick2 = std::make_shared<Shape>();
    stick2->SetPosition(544, 385);
    stick2->Rectangle(-2,2,5,80);
    stick2->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick2);
    lever2->GetSource()->AddSink(stick2->GetSink());
    stick2->GetSink()->SetPhase(-0.012);
    lever2->SetStruckComponent(cowbell);

    // Third Drumstick
    auto stick3 = std::make_shared<Shape>();
    stick3->SetPosition(466, 385);
    stick3->Rectangle(-2,2,5,80);
    stick3->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick3);
    lever3->GetSource()->AddSink(stick3->GetSink());
    stick3->GetSink()->SetPhase(-0.012);
    lever3->SetStruckComponent(snare);

    // Fourth Drumstick
    auto stick4 = std::make_shared<Shape>();
    stick4->SetPosition(388, 385);
    stick4->Rectangle(-2,2,5,80);
    stick4->SetImage(mImagesDir + L"/drumstick.png");
    machine->AddComponent(stick4);
    lever4->GetSource()->AddSink(stick4->GetSink());
    stick4->GetSink()->SetPhase(-0.012);
    lever4->SetStruckComponent(tom);

    // Fifth Drumstick
    auto stick5 = std::make_shared<Shape>();
    stick5->SetPosition(310, 385);
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
    pulley11->GetSource()->AddSink(flag->GetSink());

    return machine;
}