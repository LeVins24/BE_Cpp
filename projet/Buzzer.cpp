#include "Buzzer.h"

//Constructeur : Configuration de la PIN pour le Buzzer
Buzzer::Buzzer(int p){
  pin=p;
  pinMode(pin,OUTPUT);
}

//Fonction d'activation du buzzer
void Buzzer::beep(int freq,int duration){
  tone(pin,freq,duration);
}

//Fonction d'arrêt du buzzer
void Buzzer::stop(){
  noTone(pin);
}


