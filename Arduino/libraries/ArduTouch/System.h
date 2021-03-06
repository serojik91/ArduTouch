/*
    Systems.h  

    Declarations for the Systems module

    ---------------------------------------------------------------------------
 
    Copyright (C) 2016, Cornfield Electronics, Inc.
 
    This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
    Unported License.
 
    To view a copy of this license, visit
    http://creativecommons.org/licenses/by-sa/3.0/
 
    Created by Bill Alessi & Mitch Altman.
 
   ---------------------------------------------------------------------------
*/

#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include "types.h"
#include "Audio.h"
#include "Synth.h"

#define LIBRARY_VERSION "0.86"

/* ------------------------------------------------------------------------- */

// declare the PCB REV of your board by uncommenting one of the lines below:

  #define PCB_REV_C                      
//#define PCB_REV_B                      
//#define PCB_REV_A                      

/* ------------------------------------------------------------------------- */

//#define MONITOR_CPU                    // monitor % CPU used rendering audio
//#define MONITOR_RAM                    // monitor free RAM 

#define RED_LED   0                    // red LED  #
#define BLUE_LED  1                    // blue LED #

#define LEFT_LED  0                    // left LED #
#define RIGHT_LED 1                    // right LED #

/* ------------------------      public vars      -------------------------- */

#ifdef MONITOR_CPU

extern byte  cpu;                      // % CPU used rendeing audio (parts per 256)

#endif

/* ----------------------     public functions     ------------------------- */

void ardutouch_info();                 // perform ongoing ardutouch tasks
void ardutouch_loop();                 // perform ongoing ardutouch tasks
void ardutouch_setup( Synth * );       // initialize ardutouch resources
void device_io();                      // manage device I/O

extern void onLED( byte );             // turn an LED on
extern void offLED( byte );            // turn an LED off
extern void blinkLED( byte );          // blink an LED 
extern byte getBlinkRate();            // return LED blink rate
extern void setBlinkRate( byte );      // set LED blink rate

extern void downOctave();              // lower keyboard by 1 octave 
extern byte getOctave();               // return keyboard's octave #
extern void setOctave( byte );         // set keyboard's octave #
extern void upOctave();                // raise keyboard by 1 octave 

extern void bufStats();                // prints audio buffer stats
extern int  freeRam();                 // returns space between heap & stack

/******************************************************************************
 *
 *                   Rand16 (Random 16-bit Number Generator)
 *
 ******************************************************************************/

class Rand16                           // 16-bit Linear FeedBack Shift Register
{
   public:

   Word output;                        // random 16-bit number

   void next();                        // generate next random value
   void reseed();                      // reseed the generator

} ;

#endif   // ifndef SYSTEM_H_INCLUDED
