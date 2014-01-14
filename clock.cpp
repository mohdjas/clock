#include "clock.h"
#include "skins.h"

using namespace std;

int main(int argc, char* argv[]){
  time_t t = time(0);
  struct tm *timeNow = localtime(&t);
  Example2 testWatch2(timeNow->tm_hour, timeNow->tm_min, timeNow->tm_sec);
  
  testWatch2.drawClock();
    
  return 0;
 }
