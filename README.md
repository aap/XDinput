# XDinput

XInput to DInput translator. THIS IS ALPHA WARE.

Code is based on https://github.com/elishacloud/DirectX-Wrappers.

Since some games don't support XInput and the XInput to DInput mapping from windows is
totally useless, another solution is needed.
XInput plus works in principle but it did not work with Scarface The World is Yours
and since it isn't open source, I had to write my own.

I only tested it with Scarface The World is Yours and only on one machine,
I expect problems with other games or other machines, but at least you have
source code to fix it.

Also vibration isn't supported yet.

# Downloads

Binary files are in the [bin](bin) directory.
The verbose dll will print some stuff that might be helpful if things don't work.

# How to get Scarface to load this

The game will *not* load a custom dinput8.dll by itself because it uses
CoCreateInstance, which uses the class registry and loads dinput8.dll from system32.
To make it load a custom dinput8.dll you need to do some hackery:
Get [this](bin/scarface_dinput.zip) and make the game load it,
then it should work.
