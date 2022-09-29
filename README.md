# Willaston-station-node-Address-3 

This is my node for the Willaston station mimic panel

The mimic panel can be seen in this youtube channel video  https://youtu.be/dvoi87_vEuU 

It is running on a Arduino Mega which is connected to JMRI using a 6 meter usb cable and it is setup as a CMRI node address 10

The sketch will be getting a few changes in the next weeks as I add some more funtions to it.

The code started off from the basic idea shown in Robs little wicket series and because I am using a usb lead I do not need to include the import Auto485 library which will free up pin 2 as well on the Arduino. This was a spill over from Rob seeing Autohomers video on using CMRI. I do also have  an RS485 bus on the layout but again I am using a different module which uses an extra chip on the board to control the trigering for the RX and TX lines so again I can remove the library and just use serial begin to start the bus communication.

More details to follow
