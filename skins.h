#ifndef skins_h
#define skins_h

#include "clock.h"
#include <pngwriter.h>

class Example1 : public IWatchFace, public WatchInternals {
    pngwriter* watchCanvas;
    int secondHandRadius, minuteHandRadius, hourHandRadius;
    int facePlateRadius;
    int canvasHeight, canvasWidth;
    int originX, originY;
  public:
    Example1(unsigned int, unsigned int, unsigned int);
    ~Example1();
    void drawClock();
    void drawFacePlate();
    void drawSecondsHand();
    void drawMinutesHand();
    void drawHoursHand();
    void displayAlarm();
    double rad(int);
};

class Example2 : public IWatchFace, public WatchInternals {
    pngwriter* watchCanvas;
    float secondHandRatio, minuteHandRatio, hourHandRatio;
    int facePlateRadius;
    int canvasHeight, canvasWidth;
    int originX, originY;
  public:
    Example2(unsigned int, unsigned int, unsigned int);
    ~Example2();
    void drawClock();
    void drawFacePlate();
    void drawSecondsHand();
    void drawMinutesHand();
    void drawHoursHand();
    void displayAlarm();
    double rad(int);
};

#endif
