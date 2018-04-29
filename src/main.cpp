/* ====================================
 * Super ESP32 World - a ESP32 port of Super Mario from the Super Famicom/SNES
 * Written by SoftwareGuy (aka Coburn64)
 * Big thanks to bitluni for his RCA code, Retro Game Mechanics Explained for
 * many SNES related videos such as how the hardware runs, dots_tb for putting up
 * with my random brain picking and stupid annoying dumb questions (SADQ) and
 * anyone else I missed. You guys are awesome, and I'm grateful for that.
 * =====================================
 * This code is currently licensed under GPLv3. Don't be a dick and steal it.
 * If you improve it, submit a pull request with a description of what you did.
 * =====================================
 */

// Core essentials.
#include <soc/rtc.h>
#include <Arduino.h>

// Includes for input, audio and video.
#include <Graphics.h>
#include <Image.h>
#include <SimplePALOutput.h>

#include <GameControllers.h>
#include <AudioSystem.h>
#include <AudioOutput.h>

#include <Font.h>
#include <Sprites.h>

#include "core/variables.h"
#include "core/debugFont.h"
Font font(8, 8, debugFont::pixels);

// References to our things
GameControllers controllers;
Graphics graphics(VIDEO_XRES, VIDEO_YRES);
AudioSystem audioSystem(AUDIO_SAMPLING_RATE, AUDIO_BUFFER_SIZE);
AudioOutput audioOutput;
SimplePALOutput composite;

// Some definitions here to make compilers happy.
// Not needed in the Arduino IDE but probably PlatformIO
// will have a fit if it doesn't have some prototypes. Or
// whatever they are. ¯\_(ツ)_/¯

void setup();
void loop();
void companionCoreLoop(void *data);

// Setup is special. It is the beginning of everything as we... ah screw it
void setup() {
	Serial.begin(115200);
	Serial.println("\nHello from ESP32!");

	// Set the CPU to the highest possible frequency. Right now that's 240Mhz.
	rtc_clk_cpu_freq_set(RTC_CPU_FREQ_240M);

	// Initialize!
	// Composite Graphics
	Serial.println("Init: Composite");
	composite.init();
	Serial.println("Init: Graphics");
	graphics.init();

	// Set the font.
	Serial.println("Init: Font");
	graphics.setFont(font);
	graphics.setTextColor(graphics.rgb(255, 255, 255));

	// Audio
	Serial.println("Init: Audio Output");
	audioOutput.init(audioSystem); // @suppress("Invalid arguments")

	// Controllers
	Serial.println("Init: Controllers");
	controllers.init(CONTROLLER_LATCH, CONTROLLER_CLOCK);
	controllers.setController(0, GameControllers::SNES, CONTROLLER_DATA_PIN); //first controller

	Serial.println("Setup companion core...");
	// Tell Core 1 to work it's ass off and do the RCA driving.
	xTaskCreatePinnedToCore(companionCoreLoop, "rcaCore", 1024, NULL, 1, NULL, 0);

	Serial.println("-- READY --");
}

// Loop runs every tick, think of it running every frame in this sense.
// Could be core 0 or 1. not sure.
void loop() {
	// controllers.poll();

	graphics.begin(0);

	graphics.setCursor(8,8);
	graphics.print("BOOT OK\n");
	graphics.print("Free Heap: ");
	graphics.print(esp_get_free_heap_size());
	graphics.print("\nWhat's this? Graphics on my ESP32?!");
	graphics.end();
}

// This runs on the second core which we'll dedicate to pump out RCA video.
void companionCoreLoop(void *data)
{
  while (true)
  {
    composite.sendFrame(&graphics.frame);
  }
}
