# SuperESP32World
Super Mario... on my ESP32?!

If you haven't guessed already this is a ESP32 version of Super Mario Bros/World. It is very hacky and probably not even going to reach past alpha status, but it's not going to stop me from trying.

## Roadmap
At the moment, I am trying to implement the basics before tackling anything big. This means reading input from controllers, ensuring video is displayed correctly, audio is working, etc.

## Why ESP32?
It's a very cheap Arduino-compatible development board with the following specs. I am using the Feather ESP32 version by Adafruit. Any ESP32 clone will do, be it a WeMos or some other manufacturer.

* 240 MHz dual core Tensilica LX6 microcontroller
* Integrated 520 KB SRAM, 4 MByte Flash (see below about that...)
* Integrated 802.11b/g/n HT40 Wi-Fi transceiver, baseband, stack and LWIP as well as dual mode Bluetooth (classic and BLE)
* On-board PCB antenna
* Ultra-low noise analog amplifier
* Hall sensor, 10x capacitive touch interface, 32 kHz crystal oscillator
* 3 x UARTs (one UART is used for bootloading/debug)
* 3 x SPI, 2 x I2C, 12 x ADC input channels, 2 x I2S Audio, 2 x DAC
* PWM/timer input/output available on every GPIO pin
* OpenOCD debug interface with 32 kB TRAX buffer
* SDIO master/slave 50 MHz
* SD-card interface support

The ESP32 runs a RTOS as well as our application code, so we have about half the memory to play with. If we were using WiFi or Bluetooth, then that memory usage increases and probably wouldn't be enough to run our project reliably. So those features are turned off in this application.

The flash is not truely user-accessible 4 MBytes. It's partitioned into a weird setup; some of it is reserved for the Boot ROM, then the application code (usually 1.25MB), then a OTA Update partition and other partitions including the SPIFFS storage partition. Unfortunately I have not figured out how to override this or if it's even possible to do so. Having 3MB for the application code and the rest for whatever would be nice, but seems sometimes we can't have all those luxuries...

Oh, and with the DACs, you can do some amazing stuff. How about rendering [realtime 3D models](http://bitluni.net/esp32-composite-video/), or RCA Composite [Video and Audio](http://bitluni.net/esp32-composite-audio/) ?

## Hardware Requirements
* An ESP32 Development Board
* USB Cable: For programming and serial debugging
* SNES/NES Controller(s): refer to bitluni's video on that subject [on his website](http://bitluni.net/gamepad/)
* Alligator clips: lazy method to connect the DAC outputs to the RCA Male pins
* RCA Cables: cheapo ones will do, just get the 3-pack, yellow/white/red

## Software Requirements
* A platform that can run PlatformIO, be it Windows, Mac or Linux
* C++ Editor of some sort (I personally use Eclipse or Notepad++ in a pinch)

### Note to Arduino IDE Users
You can probably get this to work if you do some tricks with the code files but I personally do not like the Arduino IDE since it feels rather clunky. While it might be good for the average person, it became a thorn in my backside rather quickly. Please follow the setup instructions to the best of your ability.

## Project Setup
1. Git clone this repository into a empty folder. For example, `/home/coburn/Dev` or `C:\Users\Coburn\Development`. It should end up cloning into SuperESP32World.
2. Uh I have to finish writing this

## Special Thanks
* Bitluni, who is [here](https://github.com/bitluni) and his website [here](http://bitluni.net). He is the one responsible for the ESP32 RCA Code, which I have included in my project. Please do go to his website and drop him a like or a one-off donation, without him I'd be stuck bashing my head against SPI Displays
* Adafruit (why not?)
* Expressif for the awesome development board

## FAQ
***To be written!***
