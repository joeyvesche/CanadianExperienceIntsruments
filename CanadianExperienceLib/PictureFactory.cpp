/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "DrawableMachine.h"

using namespace std;

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @param audioEngine The audio engine to use in this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir, ma_engine* audioEngine)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    shared_ptr<Picture> picture = make_shared<Picture>();

    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background
    );

    // Create the first machine
    auto machineRoot = make_shared<Actor>(L"machine root1");
    auto machine1 = make_shared<DrawableMachine>(L"machine1", 1, resourcesDir, audioEngine);
    picture->SetMachine1(machine1);

    machine1->SetStartTime(0);
    machine1->SetEndTime(450);

    machineRoot->AddDrawable(machine1);
    machineRoot->SetRoot(machine1);
    picture->AddActor(machineRoot);

    // Create the first machine
    auto machineRoot2 = make_shared<Actor>(L"machine root2");
    auto machine2 = make_shared<DrawableMachine>(L"machine2", 2, resourcesDir, audioEngine);
    machine2->SetMachineNum(2);

    machine2->SetStartTime(450);
    machine2->SetEndTime(900);

    picture->SetMachine2(machine2);
    machineRoot2->SetPosition(wxPoint(600, 100));
    machineRoot2->AddDrawable(machine2);
    machineRoot2->SetRoot(machine2);
    picture->AddActor(machineRoot2);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    return picture;
}

