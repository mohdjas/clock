#include "skins.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Example1 Skin Class

Example1::Example1(unsigned int hours, unsigned int minutes, unsigned int seconds) : WatchInternals(hours, minutes, seconds){
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

Example2::Example2(unsigned int hours, unsigned int minutes, unsigned int seconds) : WatchInternals(hours, minutes, seconds){
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

