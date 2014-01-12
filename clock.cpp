#include <iostream>
#include <ctime>

using namespace std;

class Watch {
    unsigned int currentHours;
    unsigned int currentMinutes;
    unsigned int currentSeconds;
  
  public:
    Watch(unsigned int hours, unsigned int minutes, unsigned int seconds){
      this->currentHours = hours;
      this->currentMinutes = minutes;
      this->currentSeconds = seconds;
    }
  
    unsigned int getHours(){
      return this->currentHours;
    }
    
    void setHours(unsigned int a){
      this->currentHours = a;
    }
    
    unsigned int getMinutes(){
      return this->currentMinutes;
    }
    
    void setMinutes(unsigned int a){
      this->currentMinutes = a;
    }
    
    unsigned int getSeconds(){
      return this->currentSeconds;
    }
    
    void setSeconds(unsigned int a){
      this->currentSeconds = a;
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
    
    
};
  



int main(int argc, char* argv[]){
  time_t t = time(0);
  struct tm *timeNow = localtime(&t);
  Watch testWatch(timeNow->tm_hour, timeNow->tm_min, timeNow->tm_sec);
  
  
  
  return 0;
 }
