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

First of all, install [SilentPatch](https://github.com/CookiePLMonster/SilentPatchScarface).
It comes with the ultimate asi loader, which allows the game to load dinput8.dll from the game directory
(Normally it doesn't do this because it uses CoCreateInstance, which uses the class registry and loads dinput8.dll from system32).
Then simply put dinput8.dll into the game directory and TURN OFF vibration, it crashes the game for some reason
(and xdinput doesn't support it anyway).
