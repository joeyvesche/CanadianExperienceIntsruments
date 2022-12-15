/**
 * @file Instrument.cpp
 * @author joeyv
 */

#include "pch.h"
#include "Instrument.h"


/**
 * Constructor
 * @param imageDir Images directory
 * @param audioDir Audio directory
 * @param audioEngine audio engine, what plays the sounds
 */
 Instrument::Instrument(std::wstring imageDir, wxString audioDir, ma_engine* audioEngine)

 {
     SetImage(imageDir);

     auto result = ma_sound_init_from_file(audioEngine, audioDir, 0, NULL, NULL, &mSound);
     if (result != MA_SUCCESS)
     {
         wxString msg;
         msg.Printf(L"Unable to load audio file %s - %d", audioDir, result);
         wxMessageBox( msg, wxT("miniaudio failure"), wxICON_ERROR);
     }

 }

/**
 * Destructor
 */
Instrument::~Instrument()
{
    if(ma_sound_is_playing(&mSound))
    {
        ma_sound_stop(&mSound);
    }

    ma_sound_uninit(&mSound);
}

/**
 * Draw the lever/mount for the machine
 * @param graphics Context to draw on
 * @param x location x to draw at
 * @param y location y to draw at
 */
void Instrument::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);

}

/**
* Handle updates for animation
 * @param elapsed The time since the last update
*/
void Instrument::Update(double elapsed)
{

}

/**
 * Plays the sound
 */
void Instrument::PlaySound()
{
    // If the sound is already playing, stop it first
    if(ma_sound_is_playing(&mSound))
    {
        ma_sound_stop(&mSound);
    }

    // Always rewind to the beginning before playing
    ma_sound_seek_to_pcm_frame(&mSound, 0);

    // And play the sound!
    ma_sound_start(&mSound);
}