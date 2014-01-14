#include "clock.h"

WatchInternals::WatchInternals(unsigned int hours, unsigned int minutes, unsigned int seconds){
  this->currentHours = hours;
  this->currentMinutes = minutes;
  this->currentSeconds = seconds;
}
  
unsigned int WatchInternals::getHours(){
  return this->currentHours;
}
    
unsigned int WatchInternals::getMinutes(){
  return this->currentMinutes;
}
    
unsigned int WatchInternals::getSeconds(){
  return this->currentSeconds;
}
    
bool WatchInternals::isAfterNoon(){
  return this->currentHours >= 12;
}
    
void WatchInternals::tick(){
  currentSeconds++;
  if (currentSeconds >= 60) {
    currentMinutes++;
    currentSeconds = 0;
  }
  if (currentMinutes >= 60) {
    currentHours++;
    currentMinutes = 0;
  }
  if (currentHours >= 24) {
    currentHours = 0;
  }
}
    
void WatchInternals::printTime(){
      cout << currentHours << ":" << currentMinutes << ":" << currentSeconds << endl;
}
