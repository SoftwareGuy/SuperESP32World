// This file is part of Super ESP32 World.
// Variables for the project.

// Controllers
const int CONTROLLER_LATCH = 16;
const int CONTROLLER_CLOCK = 17;
const int CONTROLLER_DATA_PIN = 18;

const int AUDIO_SAMPLING_RATE = 16000;
const int AUDIO_BUFFER_SIZE = 2048;

// Video
//PAL MAX, half: 324x268 full: 648x536
//NTSC MAX, half: 324x224 full: 648x448
const int VIDEO_XRES = 320;
const int VIDEO_YRES = 240;
