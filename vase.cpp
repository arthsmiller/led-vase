//#include <JeeLib.h>

int redIO = 2;
int greenIO = 3;
int blueIO = 4;

void setup() {
  pinMode(redIO, OUTPUT); // red
  pinMode(greenIO, OUTPUT); // green
  pinMode(blueIO, OUTPUT); // blue
  pinMode(A0, INPUT); // potentiometer
}

void lampCtl(bool red, bool green, bool blue){
  // bools are flipped bc -> all colors off = white
  // at least for my waterboiler LED vase
  digitalWrite(redIO, !red);
  digitalWrite(greenIO, !green);
  digitalWrite(blueIO, !blue);
  //Serial.begin(9600);
}

void red(){
  lampCtl(1, 0, 0);
}
void green(){
  lampCtl(0, 1, 0);
}
void blue(){
  lampCtl(0, 0, 1);
}
void yellow(){
  lampCtl(1, 1, 0);
}
void cyan(){
  lampCtl(0, 1, 1);
}
void magenta(){
  lampCtl(1, 0, 1);
}
void white(){
  lampCtl(1, 1, 1);
}
void off(){
  lampCtl(0, 0, 0);
}

void party(int iterations, int pMin, int pMax){
  red();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }

  white();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }  

  green();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }  

  yellow();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }  
  
  blue();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }  
  
  cyan();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }  
  
  magenta();
  if(waitAndAbortIfChanged(iterations, pMin, pMax)){
    return;
  }
}

int waitAndAbortIfChanged(int iterations, int pMin, int pMax){
  int pW = 0;
  for(int i = 0 ; i < iterations ; ++i){
    delay(50);
    pW = analogRead(A0);
    if(pW < pMin && pW > pMax){
      return 1;
  	}
  }
  return 0;
}

void loop() {
  int p = analogRead(A0);
  //Serial.println(p);
  
  if(p > 901){
    party(100, 901, 1000);
  }

  if(p > 801 && p < 900){
    party(20, 801, 900);
  }

  if(p > 701 && p < 800){
    party(5, 701, 800);
  }

  if(p > 601 && p < 700){
    yellow();
  }

  if(p > 501 && p < 600){
    cyan();
  }

  if(p > 401 && p < 500){
    magenta();
  }

  if(p > 301 && p < 400){
    blue();
  }

  if(p > 201 && p < 300){
    green();
  }

  if(p > 101 && p < 200){
    red();
  }

  if(p > 21 && p < 100){
    white();
  }

  if(p < 20){
    off();
  }

  //Sleepy::loseSomeTime(100);
}
