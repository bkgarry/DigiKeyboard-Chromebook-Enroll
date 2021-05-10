This code was designed to enroll a chromebook running Chrome OS 74 but can be customized to enroll chromebooks running other versions.  We will go over some of the code below and how it can be customized depending on which version of Chrome OS is being used.
- Line 1 imports the DigiKeyboard Library which is required to run the code.
- Lines 2-3 define keys that the library doesn’t already include
- Lines 5-9 are the most important variables where you setup your wireless and authentication info.
- Line 11 is the setup method.  Everything in setup will run once.
- Line 83 If you want anything to repeat then it must go in the loop method.

The pressKey function (line 87) is where you can specify which key is pressed and how many times it is pressed.  For example, if you say pressKey(KEY_TAB, 4); Then the Tab key will be pressed 4 times.  There is a 50 millisecond delay before the key is pressed and a delay after the key is pressed to make sure that the keystrokes don’t overlap.  The delay after a key is pressed is the keyWait variable on line 9.  This would be the best place to change a value in order to troubleshoot any problems the code may be having.  Just set it to something like 1000 to slow down the time between keystrokes so you can actually watch what is happening.

The wait function is where you can specify how long to wait in seconds before continuing to the next section.  This is to allow time for a page to fully load, a connection to the wireless to made, or an authentication to happen.

Lines 78-79 Turn on the LED on the board to show that the program is finished (which can also be seen when the chromebook is enrolled).

Please note that on a UK Layout chromebook, you may have to use " instead of @ in your email address to get it to enter the correct keystroke.
