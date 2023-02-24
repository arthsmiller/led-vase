void setup() {
  pinMode(2, OUTPUT); // red
  pinMode(3, OUTPUT); // green
  pinMode(4, OUTPUT); // blue
  pinMode(A0, INPUT); // potentiometer
}

void lampCtl(bool red, bool green, bool blue){
  // bools are flipped bc -> all colors off = white
  // at least for my waterboiler LED vase
  digitalWrite(2, !red);
  digitalWrite(3, !green);
  digitalWrite(4, !blue);
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

void party(){
  red();
  waitAndAbortIfChanged();
  white();
  waitAndAbortIfChanged();
  green();
  waitAndAbortIfChanged();
  yellow();
  waitAndAbortIfChanged();
  blue();
  waitAndAbortIfChanged();
  cyan();
  waitAndAbortIfChanged();
  magenta();
  waitAndAbortIfChanged();
}

void waitAndAbortIfChanged(){
  for(int i = 0 ; i < 20 ; ++i){
    delay(50);
    if(analogRead(A0) < 951){
      return;
  	}
  }
}

void loop() {
  int p = analogRead(A0);
  
  if(p > 951){
    party();
  }
  
  if(p > 876 && p < 950){
    white();
  }

  if(p > 751 && p < 875){
    yellow();
  }

  if(p > 626 && p < 750){
    cyan();
  }

  if(p > 501 && p < 625){
    magenta();
  }

  if(p > 376 && p < 500){
    blue();
  }

  if(p > 251 && p < 375){
    green();
  }

  if(p > 126 && p < 250){
    red();
  }

  if(p < 125){
    off();
  }

  delay(50);
}
