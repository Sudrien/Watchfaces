# QR watch face
A watch face displaying the time in a QR Code

![Screenshot](./qr_watchface_screen.png)


## Origin
A watch loving friend was annoying with his love of weird time displays : binary, decimal, in reverse…  
So I wanted to annoy him back with a watchface which would display the time (and date) as a QR code.

## Features
Display the time and the date in a QR code. You can either decode it in your head (I tried, without success), or use a code scanner to see the time and date.

But if you are like me, you like to cheat, so you can press down (bottom right button) to switch on or off the display of the time and date string, in tiny font above the QR code.

## How to use/install
I used PlatformIO.  
You can use `pio run -t upload` to compile and upload the project to your Watchy.

If you don't use PlatformIO, look at the `platformio.ini` to have a list of libs necessary for compilation.
