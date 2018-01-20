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

void setup()
{
  for (int i = 0; i < NUM_BUTTONS; i++){
    pinMode(greenPin+i, OUTPUT);      // sets the digital pin 13 as output
    pinMode(bluePin+i, OUTPUT);      // sets the digital pin 13 as output
    pinMode(redPin+i, OUTPUT);      // sets the digital pin 13 as output
    pinMode(inPin+i, INPUT_PULLUP);        // sets the digital pin 7 as input
  }
  Serial.begin(9600);
 }

void loop()
{
  for (int i = 0; i < NUM_BUTTONS; i++){
 
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
}

