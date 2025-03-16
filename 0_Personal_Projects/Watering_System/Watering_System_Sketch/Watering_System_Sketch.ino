//Music
#define BEAT 300
#define PIN 10

#define DO 262
#define RE 294
#define MI 330
#define FA 349
#define SO 392
#define RA 440
#define SI 494
#define HDO 523

//----------------------

//Timer
int counter = 0;

//Ultrasonic Sensor
int trig = 8;
int echo = 9;
int duration;
float distance;

//LED
int led = 7;

//moisture sensor
int water_count = 0;

//relay
int relay = 2;

void setup() {
  //Used for testing
  Serial.begin(9600);


  //Ultrasonic Sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  //relay
  pinMode(relay, OUTPUT);
  pinMode(A1, INPUT);
}

void loop() {
  //Check water resevoir levels and soil humidity once a minute.

  if(counter == 1){
    checkWater();
    checkMoisture();
  }

  delay(10000);//10sec
  counter++;
  Serial.print("Counter is: ");
  Serial.println(counter);
  
  if(counter >= 6){

    counter = 0;
  }
}

void checkWater(){
  //Check the water level in the bucket.
  digitalWrite(trig, LOW);

  delayMicroseconds(1);
  digitalWrite(trig, HIGH);
  delayMicroseconds(11);

  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  
  if (duration>0)
  {
    distance = duration/2;
    distance = distance*340*100/1000000; // ultrasonic speed is 340m/s = 34000cm/s = 0.034cm/us 
    
    if(distance > 12){	 //This number should be (the height of your sensor to the bottom of the bucket) minus (the max height of water before its time to refill) in centimeters
      digitalWrite(led, HIGH);
    }else{

      digitalWrite(led, LOW);
    }
    
  }
}

//moisture sensor
void checkMoisture(){
  //Measure soil humidity
  int moisture = analogRead(A1);
  //For testing
  Serial.print("Moisture is:");
  Serial.println(analogRead(A1));

  if(moisture >= 700){
    digitalWrite(relay, LOW); //Our relay is "ACTIVE LOW" which means the relay triggers on a low signal
    delay(5000);
    digitalWrite(relay, HIGH);
    completeWatering();
  }
  else{
    digitalWrite(relay, HIGH);
  }
}

//Music
void completeWatering(){
  //Let them know that watering is complete.
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      tone(PIN,RE,BEAT); // D
      delay(BEAT) ;
      tone(PIN,MI,1200) ; // E
      delay(BEAT) ;
      delay(BEAT) ;
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; //  D
      delay(BEAT) ;
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      delay(BEAT) ;
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; // D
      delay(BEAT) ;
      tone(PIN,MI,BEAT) ; // E
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; // D
      delay(BEAT) ;
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      tone(PIN,RE,1200) ; // D
      delay(BEAT) ;
      delay(BEAT) ;
}
