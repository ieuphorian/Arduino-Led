#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9

void setup() {
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  String receiveVal;     
  if(Serial.available() > 0){
    receiveVal = Serial.read();
    ColorChange(receiveVal);
    delay(200);
  }     
}

void ColorChange(String receivedVal){
  int r=0, g=0, b=0, colors[3], k = 0, t = 0;
  for (int i=0; i < receivedVal.length(); i++)
  { 
    if(receivedVal.charAt(i) == ';') 
    { 
      colors[t] = receivedVal.substring(k, i).toInt(); 
      k=(i+1); 
      t++; 
    }
  }
  r = colors[0];
  g = colors[1];
  b = colors[2];
  analogWrite(RED_LED, r);
  analogWrite(GREEN_LED, g);
  analogWrite(BLUE_LED, b);
}
