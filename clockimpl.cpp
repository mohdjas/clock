#include "clock.h"

WatchInternals::WatchInternals(){
  time_t t = time(0);
  timeNow = localtime(&t);
}
  
int WatchInternals::getHours(){
  return timeNow->tm_hour;
}
    
int WatchInternals::getMinutes(){
  return timeNow->tm_min;
}
    
int WatchInternals::getSeconds(){
  return timeNow->tm_sec;
}

int WatchInternals::getDay(){
  return timeNow->tm_mday - 1;
}

int WatchInternals::getMonth(){
  return timeNow->tm_mon;
}

int WatchInternals::getYear(){
  return timeNow->tm_year+1900; //since tm_year stores years since 1900
}
    
bool WatchInternals::isAfterNoon(){
  return getHours() >= 12;
}

void WatchInternals::tick(){
  time_t t = time(0);
  timeNow = localtime(&t);
}
    
void WatchInternals::printTime(){
      cout << getHours() << ":" << getMinutes() << ":" << getSeconds() << endl;
}
