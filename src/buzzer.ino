/*
* The calculation of the tones is made following the
* the mathematical operation
* 
*          timeHigh = period / 2 = 1 / (2 * toneFrequency)
*
* where the different tones are described as in the table:
*
* Note       Frequency period       timeHigh
* c              261 Hz                     3830       1915
* d              294 Hz                     3400       1700
* e              329 Hz                     3038       1519
* f              349 Hz                     2864       1432
* g              392 Hz                     2550       1275
* a              440 Hz                     2272       1136
* b              493 Hz                     2028       1014
* c              523 Hz                     1912       956
*
*/ 

#include "Speaker.h"

Speaker speakerOne = {9, 15, 300, {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4}, {'ccggaag ffeeddc '}};

void playTone(Speaker *aSpeaker, int tone, int duration)
{
   for (long i = 0; i < duration; i += tone * 2)
    {
        digitalWrite(aSpeaker->speakerPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(aSpeaker->speakerPin, LOW);
        delayMicroseconds(tone);
    }
}

void playNote(Speaker *aSpeaker, int c){
    char names[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
    int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
    
    for (int i = 0; i < 8; i++)
    {
        if (names[i] == *aSpeaker->notes)
        {
            playTone(aSpeaker, tones[i], *aSpeaker->beats);
        }
    }
}

void setup(Speaker *aSpeaker)
{
    pinMode(aSpeaker->speakerPin, OUTPUT);
}

void loop()
{
    for (int i = 0; i < speakerOne.length; i++)
    {
        if (speakerOne.notes[i] == ' ')
        {
            delay(speakerOne.beats[i] * speakerOne.tempo);
        } else {
            playNote(speakerOne.notes[i], speakerOne.beats[i] * speakerOne.tempo);
        }
    }
}