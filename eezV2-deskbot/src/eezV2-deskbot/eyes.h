#ifndef EYES_H
#define EYES_H

#include <U8g2lib.h>
#include <Servo.h>

class robotEyes{

  public: 
    robotEyes(U8G2 &display, int ldrPin, int touchPin, int buzzerPin, int micPin, int servoPin);
    void update();
    void draw();
    void begin(); 
  
  private:
    U8G2 &u8g2;
    int currentState; 
    
    // Blink variables
    bool isAutoBlinking; 
    unsigned long lastBlinkCheckTime;
    unsigned long blinkStartTime; 

    // Hardware pins
    int touchPin; 
    int ldrPin; 
    int buzzerPin;
    int micPin;

    // Servo variables
    Servo neckServo; 
    int servoPin;
    int currentServoAngle;
    unsigned long lastServoMoveTime;
    
    // Startle scenario variables
    enum StartleState {
      STARTLE_NONE,       
      STARTLE_SHOCK1,     
      STARTLE_BLINK,      
      STARTLE_SHOCK2,     
      STARTLE_LOOK_LEFT,  
      STARTLE_LOOK_RIGHT  
    };
    StartleState currentStartleState; 
    unsigned long startleStepStartTime;
    int micBaseLevel;

    // Startle sound variables
    int startleSoundStep;
    unsigned long lastStartleSoundTime;
    
    // Light sensor / Sleep variables
    bool isScaredOfDark;    
    bool isSleepyFromDark;  
    bool wasInLight;        
    unsigned long timeEnteredDark;

    // Idle variables
    int idleState; 
    unsigned long lastIdleChangeTime; 
    
    // Touch / Angry variables
    bool isAngryFromTouch;    
    unsigned long touchStartTime; 
    bool wasTouched;          

    // Sound variables
    int soundState;             
    unsigned long lastSoundTime;  
    
    // Constants
    enum {
      STATE_NORMAL = 0,
      STATE_BLINK = 1,
      STATE_LOOK_RIGHT = 2,
      STATE_LOOK_LEFT = 3,
      STATE_HAPPY = 4,
      STATE_SLEEPY = 5,
      STATE_SAD = 6,
      STATE_ANGRY = 7,
      STATE_SCARED = 8,
      
      BLINK_INTERVAL = 2000, 
      BLINK_DURATION = 100,  
      DARKNESS_THRESHOLD = 150,
      DARK_SLEEP_TIME = 5000,
      
      // Normal sound config
      SOUND_BEEP_DURATION = 100, 
      SOUND_PAUSE_DURATION = 50, 
      SOUND_INTERVAL = 5000,
      
      // Happy sound config
      HAPPY_SOUND_BEEP_DURATION = 80, 
      HAPPY_SOUND_PAUSE_DURATION = 40,
      HAPPY_SOUND_INTERVAL = 1000,
      
      IDLE_LOOK_INTERVAL = 3000, 
      ANGRY_TOUCH_DURATION = 4000, 
      
      // Angry sound config
      ANGRY_SOUND_BEEP_DURATION = 50, 
      ANGRY_SOUND_PAUSE_DURATION = 50,
      ANGRY_SOUND_INTERVAL = 500,

      // Servo Angles (Center 0)
      ANGLE_CENTER = 0,   
      ANGLE_LEFT = 45,    
      ANGLE_RIGHT = 0,    
      
      // Mic settings
      MIC_THRESHOLD = 100,       
      
      // Animation timings
      TIME_SHOCK1 = 600,   
      TIME_BLINK = 150,    
      TIME_SHOCK2 = 600,   
      TIME_LOOK = 800,     
      
      // Startle sound config
      FREQ_DU = 300,       
      FREQ_DIT = 600,      
      TIME_DU = 150,       
      TIME_DIT = 80,       
      TIME_PAUSE_S = 50,   
      TIME_PAUSE_L = 250   
    };

    void normal();
    void angry();
    void sad();
    void scared();
    void blink();
    void happy();
    void lookLeft();
    void lookRight();
    void sleepy();
    void suprised(); 
};

#endif