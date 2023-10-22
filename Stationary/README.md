# QR watch face
A textual watchface

![Screenshot](./stationary_screen.png)


## Origin
I saw the original Stationary watchface (https://github.com/BraininaBowl/Stationary-Text-for-Watchy), I liked it a lot, but wanted it in French. It was also a good project to start fiddling with Watchy.  
But English and French don't work the same, so I ended up almost rewriting the whole thing.

## Features
Display the time and the date in text form. Nothing more, nothing less.

I made time display as close as possible to good French, while keeping the numbers (it say "quinze" and not "et quart", to go with the 24h format). But if you find errors, please report them.

## How to use/install
I used PlatformIO.  
You can use `pio run -t upload` to compile and upload the project to your Watchy.

If you don't use PlatformIO, look at the `platformio.ini` to have a list of libs necessary for compilation.
