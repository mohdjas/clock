#ifndef clock_h
#define clock_h

#include <iostream>
#include <ctime>
using namespace std;

class WatchInternals {
    struct tm *timeNow;
  public:
    WatchInternals();
    int getHours();
  	int getMinutes();
    int getSeconds();
    int getDay();
    int getMonth();
    int getYear();
    bool isAfterNoon();
    void tick();
    void printTime();
};
  
class IWatchFace {
  public:
    virtual ~IWatchFace() {}
    //TODO: change name to reflect that not all faces will be 'hands'   
    virtual void drawClock() = 0;
    virtual void drawSecondsHand() = 0;
    virtual void drawMinutesHand() = 0;
    virtual void drawHoursHand() = 0;
    //TODO: change name as it will not necessarily 'display' an alarm
    virtual void displayAlarm() = 0;    
};

#endif
