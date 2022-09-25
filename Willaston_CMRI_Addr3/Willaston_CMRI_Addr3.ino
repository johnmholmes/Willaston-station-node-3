// Willaston Station has 2 tracks in use platform 1 and a siding this will be used to 
// control the routes only at the momment but has had the signals added to the code
// it is served by T10 turnout in jmri thrown platform 1 closed siding
// platform 1 has 2 sensors S** platform enterance S** platform end
// siding has 2 sensors S88 siding entrance S** siding end
// approaching the station turnout a sensor s**
// this station has 10 routes avaiable to it
// pins available to use
// pins 0 , 1 & 2 are used to control the crmi bus leaving 18 possible devices
// pin 3 route IO34 willaston 1 to peel 1
// pin 4 route IO35 willaston 1 to peel 2
// pin 5 route IO32 willaston 1 to dock city 1
// pin 6 route IO33 willaston 1 to dock city 2
// pin 7 route IO31 willaston 1 to upper level
// pin 8 willaston platform 1 signal green led
// pin 9 willaston platform 1 signal red led
// pin 10 willaston siding signal green led 
// pin 11 willaston siding signal red led
// pin 12 willaston approach platform 1 signal green led
// pin 13 willaston approach platform 1 signal red led
// pin a0 route IO40 willaston 2 to peel 1
// pin a1 route IO41 willaston 2 to peel 2
// pin a2 route IO38 willaston to dock city 1
// pin a3 route IO39 willaston to dock city 2
// pin a4 route IO37 willaston to upper level
// pin a5 willaston approach siding signal green led
// pin a6 willaston approach siding signal red led
// pin a7 not in use

#include <CMRI.h>
#include <Auto485.h>

#define CMRI_ADDR 3
//willaston platform 1 routes
#define IO34 3    // siwtch 1
#define IO35 4    // switch 2
#define IO32 5    // switch 3
#define IO33 6    // switch 4
#define IO31 7    // switch 5
//willaston siding routes
#define IO40 A0    // siwtch 6
#define IO41 A1    // switch 7
#define IO38 A2    // switch 8
#define IO39 A3    // switch 9
#define IO37 A4    // switch 10

//signals led setup
#define P1_GREEN 8    //P1 GREEN LED
#define P1_RED 9      //P1 RED LED
#define SIDE_GREEN 10 //SIDING GREEN LED
#define SIDE_RED 11   //SIDING RED LED
#define P1A_GREEN 12  //P1 APPROACH GREEN LED
#define P1A_RED 13    //P1 APPRACH RED LED
#define SIDEA_GREEN A5   //P1 APPROACH GREEN LED
#define SIDEA_RED A6    //P1 APPRACH RED LED

#define DE_PIN 2     // used for interupt

Auto485 bus(DE_PIN); // Arduino pin 2 -> MAX485 DE and RE pins
CMRI cmri(CMRI_ADDR, 24, 48, bus); // defaults to a SMINI with address 0. SMINI = 24 inputs, 48 outputs

void setup() {
pinMode (P1_GREEN, OUTPUT);
pinMode (P1_RED, OUTPUT);
pinMode (SIDE_GREEN, OUTPUT);
pinMode (SIDE_RED, OUTPUT);
pinMode (P1A_GREEN, OUTPUT);
pinMode (P1A_RED, OUTPUT);
pinMode (SIDEA_GREEN, OUTPUT);
pinMode (SIDE_RED, OUTPUT);

//willaston platform 1 routes
pinMode (IO34, INPUT_PULLUP);// peel 1
pinMode (IO35, INPUT_PULLUP);// peel 2
pinMode (IO32, INPUT_PULLUP);// dock city 1
pinMode (IO33, INPUT_PULLUP);// dock city 2
pinMode (IO31, INPUT_PULLUP);// upper level
// willaston siding routes
pinMode (IO40, INPUT_PULLUP);// peel 1
pinMode (IO41, INPUT_PULLUP);// peel 2
pinMode (IO38, INPUT_PULLUP);// dock city 1
pinMode (IO39, INPUT_PULLUP);// dock city 2
pinMode (IO37, INPUT_PULLUP);// upper level

bus.begin(19200);
}

void loop() {

cmri.process();
digitalWrite (P1_GREEN, cmri.get_bit(0));    //jmri address 3001
digitalWrite (P1_RED, cmri.get_bit(1));      //jmri address 3002
digitalWrite (SIDE_GREEN, cmri.get_bit(2));  //jmri address 3003
digitalWrite (SIDE_RED, cmri.get_bit(3));    //jmri address 3004
digitalWrite (P1A_GREEN, cmri.get_bit(4));   //jmri address 3005
digitalWrite (P1A_RED, cmri.get_bit(5));     //jmri address 3006
digitalWrite (SIDEA_GREEN, cmri.get_bit(6)); //jmri address 3007
digitalWrite (SIDEA_RED, cmri.get_bit(7));   //jmri address 3008

//willaston 1
cmri.set_bit(0, !digitalRead(3)); //jmri 3001
cmri.set_bit(1, !digitalRead(4)); //jmri 3002
cmri.set_bit(2, !digitalRead(5)); //jmri 3003
cmri.set_bit(3, !digitalRead(6)); //jmri 3004
cmri.set_bit(4, !digitalRead(7)); //jmri 3005
//willaston siding
cmri.set_bit(5, !digitalRead(A0)); //jmri 3006
cmri.set_bit(6, !digitalRead(A1)); //jmri 3007
cmri.set_bit(7, !digitalRead(A2)); //jmri 3008
cmri.set_bit(8, !digitalRead(A3)); //jmri 3009
cmri.set_bit(9, !digitalRead(A4)); //jmri 3010

}
