int pins[6][6] =
{
  {7, 31, 22, A0, A10},
  {6, 33, 24, A1, A11},
  {5, 35, 26, A2, A12},
  {4, 37, 28, A3, A13},
  {3, 39, 30, A4, A14},
  {2, 41, 32, A5, A15},
};

int getPin(int x, int y) {
  return pins[y][x];
}

void A_chord() {
  digitalWrite(getPin(3, 2), HIGH);
  digitalWrite(getPin(3, 3), HIGH);
  digitalWrite(getPin(3, 4), HIGH);
}

void B_chord() {
  digitalWrite(getPin(3, 1), HIGH);
  digitalWrite(getPin(1, 2), HIGH);
  digitalWrite(getPin(1, 3), HIGH);
  digitalWrite(getPin(1, 4), HIGH);
  digitalWrite(getPin(3, 5), HIGH);
}

void C_chord() {
  digitalWrite(getPin(2, 1), HIGH);
  digitalWrite(getPin(3, 2), HIGH);
  digitalWrite(getPin(4, 4), HIGH);
 
}

void D_chord() {
  digitalWrite(getPin(3, 3), HIGH);
  digitalWrite(getPin(2, 4), HIGH);
  digitalWrite(getPin(3, 5), HIGH);
  
}

void E_chord() {
  digitalWrite(getPin(3, 1), HIGH);
  digitalWrite(getPin(3, 2), HIGH);
  digitalWrite(getPin(4, 3), HIGH);
  
}
void F_chord() {
  digitalWrite(getPin(4, 0), HIGH);
  digitalWrite(getPin(4, 4), HIGH);
  digitalWrite(getPin(4, 5), HIGH);
  digitalWrite(getPin(4, 3), HIGH);
  digitalWrite(getPin(3, 1), HIGH);
  digitalWrite(getPin(3, 2), HIGH);
  
}


void G_chord() {
  digitalWrite(getPin(2, 0), HIGH);
  digitalWrite(getPin(3, 1), HIGH);
  digitalWrite(getPin(2, 4), HIGH);
  digitalWrite(getPin(2, 5), HIGH);
}

void A_minor_chord() {
  digitalWrite(getPin(4, 4), HIGH);
  digitalWrite(getPin(3, 3), HIGH);
  digitalWrite(getPin(3, 2), HIGH);
}

void B_minor_chord() {
  digitalWrite(getPin(3, 1), HIGH);
  digitalWrite(getPin(1, 2), HIGH);
  digitalWrite(getPin(1, 3), HIGH);
  digitalWrite(getPin(2, 4), HIGH);
  digitalWrite(getPin(3, 5), HIGH);
}
void D_minor_chord() {
  digitalWrite(getPin(2, 4), HIGH);
  digitalWrite(getPin(3, 3), HIGH);
  digitalWrite(getPin(4, 5), HIGH);

}

void E_minor_chord() {
  digitalWrite(getPin(3, 1), HIGH);
  digitalWrite(getPin(3, 2), HIGH);

}

void F_minor_chord() {
  digitalWrite(getPin(4, 0), HIGH);
  digitalWrite(getPin(2, 1), HIGH);
  digitalWrite(getPin(2, 2), HIGH);
  digitalWrite(getPin(4, 3), HIGH);
  digitalWrite(getPin(4, 4), HIGH);
  digitalWrite(getPin(4, 5), HIGH);
  
}


void switchOff() {
  for (int x = 0; x < 6; x++) {
    for (int y = 0; y < 6; y++) {
      digitalWrite(getPin(x, y), LOW);
    }
  }
}

void checkWorking() {
  for (int x = 0; x < 6; x++) {
    for (int y = 0; y < 6; y++) {
      digitalWrite(getPin(x, y), HIGH);
      delay(50);
      digitalWrite(getPin(x, y), LOW);
    }
  }
}

void setup() {
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 6; y++) {
      pinMode(getPin(x, y), OUTPUT);
    }
  }
  switchOff();
  checkWorking();

  Serial.begin(9600);
  
}

void loop(){
  if(Serial.available()) {
    String input = Serial.readString();
    if( input == "A" ){
       A_chord();
       delay(2000);
       switchOff();
    }
     else if( input == "B" ){
       B_chord();
       delay(2000);
       switchOff();
    }
    else if( input == "C" ){
       C_chord();
       delay(2000);
       switchOff();
    }
    else if( input == "D" ){
       D_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "E" ){
       E_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "F" ){
       F_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "G" ){
       G_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "Am" ){
       A_minor_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "Bm" ){
       B_minor_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "Dm" ){
       D_minor_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "Em" ){
       E_minor_chord();
       delay(2000);
       switchOff();
    }

    else if( input == "Fm" ){
       F_minor_chord();
       delay(2000);
       switchOff();
    }
  //int input = Serial.parseInt();
  }
  for(int i = 0; i < 8; i++){
     A_minor_chord();
  delay(1000);
  switchOff();
 F_chord();
  delay(1000);
  switchOff();
 C_chord();
  delay(1000);
  switchOff();
 G_chord();
  delay(1000);
  switchOff();
  }
// A_minor_chord();
//  delay(5000);
//  switchOff();
// B_minor_chord();
//  delay(5000);
//  switchOff();
// D_minor_chord();
//  delay(5000);
//  switchOff();
// E_minor_chord();
//  delay(5000);
//  switchOff();
// F_minor_chord();
//  delay(5000);
//  switchOff();
 

}
