#include "skins.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Example1 Skin Class

Example1::Example1() : WatchInternals(){
	canvasHeight = canvasWidth = 3000;
	this->watchCanvas = new pngwriter(canvasWidth, canvasHeight, 1.0, "Example1.png");
	originX = canvasWidth/2;
	originY = canvasHeight/2;
	facePlateRadius = 0.48*canvasHeight;
	secondHandRadius = 0.95*facePlateRadius;
	minuteHandRadius = 0.90*secondHandRadius;
	hourHandRadius = 0.60*secondHandRadius;
}
    
Example1::~Example1(){
	watchCanvas->close();
	delete watchCanvas;
}
    
void Example1::drawClock(){
	drawFacePlate();
	drawSecondsHand();
	drawMinutesHand();
	drawHoursHand();
}
    
void Example1::drawFacePlate(){
	watchCanvas->filledcircle(originX, originY, facePlateRadius, 0, 0, 0);
	watchCanvas->filledcircle(originX, originY, 0.98*facePlateRadius, 50000, 50000, 50000);
}

void Example1::drawSecondsHand(){
	int x, y;
	double secondHandAngle = getSeconds()*6;
	x = originX + secondHandRadius*sin(rad(secondHandAngle));
	y = originY + secondHandRadius*cos(rad(secondHandAngle));
	watchCanvas->line(originX, originY, x, y, 65535, 0, 0);
}
    
void Example1::drawMinutesHand(){
	int x, y;
	double minuteHandAngle = getMinutes()*6 + getSeconds()*0.1;
	x = originX + minuteHandRadius*sin(rad(minuteHandAngle));
	y = originY + minuteHandRadius*cos(rad(minuteHandAngle));
	watchCanvas->line(originX, originY, x, y, 0, 65535, 0);
}
    
void Example1::drawHoursHand(){
	int x, y;
	//We do modulus 12 because we need angle from the 12 o'clock position.
	double hourHandAngle = (getHours()%12)*30 + getMinutes()*0.5;
	x = originX + hourHandRadius*sin(rad(hourHandAngle));
	y = originY + hourHandRadius*cos(rad(hourHandAngle));
	watchCanvas->line(originX, originY, x, y, 0, 0, 65535);
}
    
void Example1::displayAlarm(){
}
    
double Example1::rad(int angleInDegrees){
	return (double)((3.14159/180.0)*angleInDegrees);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Example2 Skin Class

Example2::Example2() : WatchInternals(){
	canvasHeight = canvasWidth = 1500;
	this->watchCanvas = new pngwriter(canvasWidth, canvasHeight, 0.9, "Example2.png");
	originX = canvasWidth/2;
	originY = canvasHeight/2;
	facePlateRadius = 0.48*canvasHeight;
	secondHandRatio = 1.0 - 0.025;
	minuteHandRatio = 1.0 - 0.25;
	hourHandRatio = 1.0 - 0.90;
}
    
Example2::~Example2(){
	watchCanvas->close();
	delete watchCanvas;
}
    
void Example2::drawClock(){
  drawFacePlate();
  drawHoursHand();
  drawMinutesHand();
  drawSecondsHand();    
}
    
void Example2::drawFacePlate(){
  watchCanvas->filledcircle(originX, originY, 1.02*facePlateRadius, 0.5, 0.5, 0.5);
  watchCanvas->filledcircle(originX, originY, facePlateRadius, 50000, 50000, 50000);
}
 
void Example2::drawSecondsHand(){
  int x, y;
  double secondHandAngle = getSeconds()*6;
  x = originX + secondHandRatio*facePlateRadius*sin(rad(secondHandAngle));
  y = originY + secondHandRatio*facePlateRadius*cos(rad(secondHandAngle));
  watchCanvas->filledcircle(x, y, (1.0-secondHandRatio)*facePlateRadius, 0.45, 0.45, 1.0);
}
    
void Example2::drawMinutesHand(){
  int x, y;
  double minuteHandAngle = getMinutes()*6 + getSeconds()*0.1;
  x = originX + minuteHandRatio*facePlateRadius*sin(rad(minuteHandAngle));
  y = originY + minuteHandRatio*facePlateRadius*cos(rad(minuteHandAngle));
  watchCanvas->filledcircle(x, y, (1.0-minuteHandRatio)*facePlateRadius, 1.0, 0.4, 0.4);
}
    
void Example2::drawHoursHand(){
  int x, y;
  //We do modulus 12 because we need angle from the 12 o'clock position.
  double hourHandAngle = (getHours()%12)*30 + getMinutes()*0.5;
  x = originX + hourHandRatio*facePlateRadius*sin(rad(hourHandAngle));
  y = originY + hourHandRatio*facePlateRadius*cos(rad(hourHandAngle));
  watchCanvas->filledcircle(x, y, (1.0-hourHandRatio)*facePlateRadius, 0.0, 0.8, 0.8);
}
    
void Example2::displayAlarm(){
}
    
double Example2::rad(int angleInDegrees){
  return (double)((3.14159/180.0)*angleInDegrees);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Example3 Skin Class

Example3::Example3() : WatchInternals(){
	canvasHeight = canvasWidth = 3000;
	this->watchCanvas = new pngwriter(canvasWidth, canvasHeight, 0.9, "Example3.png");
	originX = canvasWidth/2;
	originY = canvasHeight/2;
	yearCentreX = originX;
	yearCentreY = originY;
	facePlateRadius = 0.48*canvasHeight;
	yearRadius = facePlateRadius;
	monthRadius = 0.75*yearRadius;
	daysRadius = 0.45*monthRadius;
  hourRadius = 0.40*daysRadius;
	minuteRadius = 0.40*hourRadius;
	secondRadius = (1.0/16)*minuteRadius;
}
    
Example3::~Example3(){
	watchCanvas->close();
	delete watchCanvas;
}
    
void Example3::drawClock(){
  drawFacePlate(); //Doubles as the year indicator as well
  drawMonthsHand();
  drawDaysHand();
  drawHoursHand();
  drawMinutesHand();
  drawSecondsHand();
}
    
void Example3::drawFacePlate(){
  watchCanvas->filledcircle(originX, originY, facePlateRadius, 0.75, 0.75, 0.75);
}
 
void Example3::drawSecondsHand(){
  int x, y;
  double secondHandAngle = getSeconds()*6;
  x = minutesCentreX + (minuteRadius-secondRadius)*sin(rad(secondHandAngle));
  y = minutesCentreY + (minuteRadius-secondRadius)*cos(rad(secondHandAngle));
  watchCanvas->filledcircle(x, y, secondRadius, 0.2, 0.2, 0.2);
}
    
void Example3::drawMinutesHand(){
  double minuteHandAngle = getMinutes()*6 + getSeconds()*0.1;
  minutesCentreX = hoursCentreX + (hourRadius-minuteRadius)*sin(rad(minuteHandAngle));
  minutesCentreY = hoursCentreY + (hourRadius-minuteRadius)*cos(rad(minuteHandAngle));
  watchCanvas->filledcircle(minutesCentreX, minutesCentreY, minuteRadius, 0.3, 0.3, 0.3);
}
    
void Example3::drawHoursHand(){
  //We do modulus 12 because we need angle from the 12 o'clock position.
  double hourHandAngle = (getHours())*15 + getMinutes()*0.25;
  hoursCentreX = daysCentreX + (daysRadius-hourRadius)*sin(rad(hourHandAngle));
  hoursCentreY = daysCentreY + (daysRadius-hourRadius)*cos(rad(hourHandAngle));
  watchCanvas->filledcircle(hoursCentreX, hoursCentreY, hourRadius, 0.4, 0.4, 0.4);
}

void Example3::drawDaysHand(){
  double dayHandAngle = getDay()*(360.0/getDaysInMonth());
  daysCentreX = monthCentreX + (monthRadius-daysRadius)*sin(rad(dayHandAngle));
  daysCentreY = monthCentreY + (monthRadius-daysRadius)*cos(rad(dayHandAngle));
  watchCanvas->filledcircle(daysCentreX, daysCentreY, daysRadius, 0.5, 0.5, 0.5);
}

int Example3::getDaysInMonth(){
  int month = getMonth() + 1;
  switch(month){
    case 1: case 3: case 5:
    case 7: case 8: case 10:
    case 12: return 31; break;
    
    case 4: case 6: case 9:
    case 11: return 30; break;
    
    case 2: return isLeapYear() ? 29 : 28; break;
  }
}

bool Example3::isLeapYear(){
  return getYear()%4 == 0;
}

void Example3::drawMonthsHand(){
  double monthHandAngle = getMonth()*(360.0/12) + getDay()*(30.0/getDaysInMonth());
  monthCentreX = yearCentreX + (yearRadius-monthRadius)*sin(rad(monthHandAngle));
  monthCentreY = yearCentreY + (yearRadius-monthRadius)*cos(rad(monthHandAngle));
  watchCanvas->filledcircle(monthCentreX, monthCentreY, monthRadius, 0.6, 0.6, 0.6);
}
    
void Example3::displayAlarm(){
}
    
double Example3::rad(int angleInDegrees){
  return (double)((3.14159/180.0)*angleInDegrees);
}


