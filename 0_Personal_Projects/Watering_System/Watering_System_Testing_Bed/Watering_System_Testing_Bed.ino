int counter = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
  delay(2000);
}
/*
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
int Trig = 8;
int Echo = 9;
int Duration;
float Distance;

//LED
int led = 7;

void setup() {
  //Ultrasonic Sensor
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);


  //LED
  pinMode(led,OUTPUT);
}

void loop() {
  
  //Check temperature, humidity, and soil humidity once a minute.
  //completeWatering();

  if(counter == 1){
    checkWater();
  }

  delay(10000);//10sec
  counter++;
  
  if(counter >= 6){

    counter = 0;
  }

  checkWater();

  }

void checkWater(){
  //Check the water level in the bucket.
  digitalWrite(Trig,LOW);

  delayMicroseconds(1);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(11);

  digitalWrite(Trig,LOW);
  Duration = pulseIn(Echo,HIGH);
  
  if (Duration>0)
  {
    Distance = Duration/2;
    Distance = Distance*340*100/1000000; // ultrasonic speed is 340m/s = 34000cm/s = 0.034cm/us 
    
    if(Distance > 12){	 //This number should be (the height of your sensor to the bottom of the bucket) minus (the max height of water before its time to refill) in centimeters
      digitalWrite(led, HIGH);
    }else{

      digitalWrite(led, LOW);
    }
    
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
  delay(4400);
}
*/