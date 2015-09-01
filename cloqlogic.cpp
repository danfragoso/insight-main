#include <virtuabotixRTC.h>
//6 CLK, 7 DAT, 8 RST
virtuabotixRTC myRTC(6, 7, 8);

int sh;
int sm;
int s;
int st;

void setup() {

Serial.begin(9600);

}

void loop() {

  myRTC.updateTime();

  sh = ( myRTC.hours * 3600);
  sm = (myRTC.minutes * 60);
   s = (myRTC.seconds);

   st = (sh + sm + s);

   Serial.print(st);

delay( 1000);

}
