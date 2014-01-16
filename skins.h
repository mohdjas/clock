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
    Example1();
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
    Example2();
    ~Example2();
    void drawClock();
    void drawFacePlate();
    void drawSecondsHand();
    void drawMinutesHand();
    void drawHoursHand();
    void displayAlarm();
    double rad(int);
};

class Example3 : public IWatchFace, public WatchInternals {
		pngwriter* watchCanvas;
		int secondRadius, minuteRadius, hourRadius, daysRadius, monthRadius, yearRadius;
    int facePlateRadius;
    int canvasHeight, canvasWidth;
    int originX, originY;
    int hoursCentreX, hoursCentreY, minutesCentreX, minutesCentreY;
    int daysCentreX, daysCentreY, monthCentreX, monthCentreY;
    int yearCentreX, yearCentreY;
	public:
		Example3();
		~Example3();
		void drawClock();
		void drawFacePlate();
		void drawSecondsHand();
		void drawMinutesHand();
		void drawHoursHand();
		void drawDaysHand();
		int getDaysInMonth();
		bool isLeapYear();
		void drawMonthsHand();
		void displayAlarm();
		
		double rad(int);
};

#endif
