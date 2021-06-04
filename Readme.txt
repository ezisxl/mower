ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V9.5  09.04.2021
----------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card


Features of 9.5
---------------

V9.5 has Many Bug fixes so please upload all the code to each board again

- Fixed alarm functions using PCB clock and Arduino Clock Module
- New Alarm Menu (Green = Alarm is active)
- Fixed Go To Dock button when stop mow TFT button is pressed.
- Fixed TFT buttons remaining on screen when Exit Dock is selected.
- Error handling improvement and communication between TFT and Mower
	- Pause when wire tracking
	- Wire OFF Error doenst block mower from further communication
	- General screen updates are improved
- Improved compass home turning function
- Added new pins and touch calibration for newer TFT Touchscreenss (Seems like they changed the pins use setup 1 or 2 in Code)
- Auto wire ON/OFF function for PCB wire via NodeMCU Wifi board (Enter your WEMOSD1 blynk code into the NodeMCU code)
- Sonars activated before testing
- Sonars deactivated in the mowing loop if no signal is detected
- Mow the Line fixed in selecting from TFT menu.
- New TFT Menu Going Home.
- Expanded Settings options in WIFI Blynk App.



NodeMCU Board URL:
------------------
Use this URL to add the NodeMCU board 1.0 to the boards menu.

http://arduino.esp8266.com/stable/package_esp8266com_index.json

ESP32 Board URL:
------------------
Use this URL to add the ESP32 DOITDev1.0 board to the boards menu.
https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
