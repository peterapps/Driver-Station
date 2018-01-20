union bytestoint
{
   int value;
   byte bytes[4] = {0,0,0,0};
};

byte data[10];
bytestoint sliders[4];
bytestoint knobs[2];

void setup() {
  Serial2.begin(9600);
  Serial.begin(9600);
}

void loop() {

  int q=0;

  if (Serial2.available()) {
    delay(20);
    while(Serial2.available() && q<10) {
      data[q++] = Serial2.read();
    }
  }

  if(q>0) {
    for (int i =0; i < 4; i++){
      sliders[i].bytes[0] = data[i];
      sliders[i].bytes[1] = (data[4] >> (i*2)) & 3;    
      Serial.print(sliders[i].value);
      Serial.print('\t');      
    }
    Serial.print('\n');
    
/*    for(int w = 0; w < q; w++){
      Serial.print(data[w]);
      Serial.print('\t');
    }
    Serial.print('\n');*/
  }
  
  /*  Serial2.readBytesUntil('d', data, 3);
  for(int i = 0; i < 2;i++){
    Serial.print(data[i]);
    Serial.print("\t");
  }
  Serial.print("\n");*/

}
