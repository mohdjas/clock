#include <iostream>
#include <pngwriter.h>
#include <ctime>

using namespace std;

class WatchInternals {
    unsigned int currentHours, currentMinutes, currentSeconds;
  
  public:
    WatchInternals(unsigned int hours, unsigned int minutes, unsigned int seconds){
      this->currentHours = hours;
      this->currentMinutes = minutes;
      this->currentSeconds = seconds;
    }
  
    unsigned int getHours(){
      return this->currentHours;
    }
    
    unsigned int getMinutes(){
      return this->currentMinutes;
    }
    
    unsigned int getSeconds(){
      return this->currentSeconds;
    }
    
    bool isAfterNoon(){
      return this->currentHours >= 12;
    }
    
    void tick(){
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
    
    void printTime(){
      cout << currentHours << ":" << currentMinutes << ":" << currentSeconds << endl;
    }
};
  
//pure virtual class to enforce functions that all watches must have
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

class WatchFace1 : public IWatchFace, public WatchInternals {
    pngwriter* watchCanvas;
    //all angles are in degrees
    int secondHandRadius, minuteHandRadius, hourHandRadius;
    int facePlateRadius;
    int canvasHeight, canvasWidth;
    int originX, originY;
  public:
    WatchFace1(unsigned int hours, unsigned int minutes, unsigned int seconds) : WatchInternals(hours, minutes, seconds){
      canvasHeight = canvasWidth = 300;
      this->watchCanvas = new pngwriter(canvasWidth, canvasHeight, 1.0, "WatchFace1");
      originX = canvasWidth/2;
      originY = canvasHeight/2;

      facePlateRadius = 100;
      
      secondHandRadius = 95;
      minuteHandRadius = 85;
      hourHandRadius = 60;
    }
    
    ~WatchFace1(){
      watchCanvas->close();
      delete watchCanvas;
    }
    
    void drawClock(){
      drawFacePlate();
      drawSecondsHand();
      drawMinutesHand();
      drawHoursHand();
    }
    
    void drawFacePlate(){
      watchCanvas->filledcircle(originX, originY, facePlateRadius, 0, 0, 0);
      watchCanvas->filledcircle(originX, originY, facePlateRadius-10, 50000, 50000, 50000);
    }
           
    void drawSecondsHand(){
      int x, y;
      double secondHandAngle = getSeconds()*6;
      x = originX + secondHandRadius*sin(rad(secondHandAngle));
      y = originY + secondHandRadius*cos(rad(secondHandAngle));
      watchCanvas->line(originX, originY, x, y, 65535, 0, 0);
    }
    
    void drawMinutesHand(){
      int x, y;
      double minuteHandAngle = getMinutes()*6 + getSeconds()*0.1;
      x = originX + minuteHandRadius*sin(rad(minuteHandAngle));
      y = originY + minuteHandRadius*cos(rad(minuteHandAngle));
      watchCanvas->line(originX, originY, x, y, 0, 65535, 0);
    }
    
    void drawHoursHand(){
      int x, y;
      //We do modulus 12 because we need angle from the 12 o'clock position.
      double hourHandAngle = (getHours()%12)*30 + getMinutes()*0.5;
      x = originX + hourHandRadius*sin(rad(hourHandAngle));
      y = originY + hourHandRadius*cos(rad(hourHandAngle));
      watchCanvas->line(originX, originY, x, y, 0, 0, 65535);
    }
    
    void displayAlarm(){
    }
    
    double rad(int angleInDegrees){
      return (double)((3.14159/180.0)*angleInDegrees);
    }

};

int main(int argc, char* argv[]){
  time_t t = time(0);
  struct tm *timeNow = localtime(&t);
  WatchFace1 testWatch(timeNow->tm_hour, timeNow->tm_min, timeNow->tm_sec);

  testWatch.printTime();
  testWatch.drawClock();
    
  return 0;
 }
