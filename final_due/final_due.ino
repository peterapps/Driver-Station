#include "HID.h"
#include "Joystick.h"

#define NUM_BUTTONS 10
#define TIME_TO_CHANGE_COLOR 1500

int redPin = 22;   // LED connected to digital pin 13
int greenPin = 32;   // LED connected to digital pin 13
int bluePin = 42;   // LED connected to digital pin 13
int inPin = 2;     // pushbutton connected to digital pin 7
bool values[NUM_BUTTONS];       // variable to store the read value
bool previous[NUM_BUTTONS];
long millis_held[NUM_BUTTONS];
unsigned long firstTime[NUM_BUTTONS];

union bytestoint
{
   int value;
   byte bytes[4] = {0,0,0,0};
};

byte data[10];
bytestoint sliders[4];
bytestoint knobs[2];

void setup()
{
  for (int i = 0; i < NUM_BUTTONS; i++){
    pinMode(greenPin+i, OUTPUT);      // sets the digital pin 13 as output
    pinMode(bluePin+i, OUTPUT);      // sets the digital pin 13 as output
    pinMode(redPin+i, OUTPUT);      // sets the digital pin 13 as output
    pinMode(inPin+i, INPUT_PULLUP);        // sets the digital pin 7 as input
  }
  Serial2.begin(9600);
  
  Joystick.clearState();
}

void loop()
{
  Joystick.clearState();

/*  for (int i = 0; i < NUM_BUTTONS; i++){
 
    values[i] = digitalRead(inPin+i);     // read the input pin

    if (values[i] == 0 && previous[i] == 1 && (millis() - firstTime[i]) > 200) {//IF IT IS TURNED ON
      firstTime[i] = millis();
    }

    millis_held[i] = (millis() - firstTime[i]);

    if(values[i] == false && millis_held[i] > TIME_TO_CHANGE_COLOR){
      digitalWrite(redPin+i,HIGH);
      digitalWrite(greenPin+i,HIGH);
      digitalWrite(bluePin+i, LOW);    
    }
    else if(values[i] == false ){
      digitalWrite(redPin+i,HIGH);
      digitalWrite(greenPin+i,LOW);
      digitalWrite(bluePin+i, HIGH);    
    }
    else{
      digitalWrite(redPin+i,LOW);
      digitalWrite(greenPin+i,HIGH);
      digitalWrite(bluePin+i, HIGH);    
    }
    
    previous[i] = values[i];
   }

   int q=0;
*/
/*  if (Serial2.available()) {
    delay(20);
    while(Serial2.available() && q<10) {
      data[q++] = Serial2.read();
//      Serial.println(i);
    }
  }

  if(q>0) {
    for (int i =0; i < 4; i++){
      sliders[i].bytes[0] = data[i];
      sliders[i].bytes[1] = (data[4] >> (i*2)) & 3;    
    }
    
    for(int w = 0; w < q; w++){
      Serial.print(data[w]);
      Serial.print('\t');
    }
    Serial.print('\n');
  }

  Joystick.state.x.axis = analogRead(0)-sliders[0].value;
  Joystick.state.y.axis = sliders[1].value-analogRead(1);
*/
  Joystick.state.buttons.b00 = 1;
  Joystick.state.buttons.b01 = !values[1];
  Joystick.state.buttons.b02 = !values[2];
  Joystick.state.buttons.b03 = !values[3];
  Joystick.state.buttons.b04 = !values[4];
  Joystick.state.buttons.b05 = !values[5];
  Joystick.state.buttons.b06 = !values[6];
  Joystick.state.buttons.b07 = !values[7];
  Joystick.state.buttons.b08 = !values[8];
  Joystick.state.buttons.b09 = !values[9];
  Joystick.state.buttons.b10 = !values[0];

}

