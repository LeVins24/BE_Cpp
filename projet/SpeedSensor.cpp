#include "SpeedSensor.h"

//Constructeur : Configuration de la PIN pour le capteur de vitesse
SpeedSensor::SpeedSensor(int p){
  pin=p;
  pinMode(pin,INPUT);
}

//Fonction qui renvoie la valeur de la vitesse : relie la vitesse à la tension fournie de façon proportionelle (vitesse=0.1 x tension_capteur)
float SpeedSensor::read(){
  int Tension=analogRead(pin); //Lecture d'une tension analogique renvoyée par le potentiomètre
  return Tension*0.1;
}

//Affichage de "Vitesse" sur l'ecran LCD
String SpeedSensor::label() const{
  return "Vitesse";
}

//Surcharge de l'opérateur > pour qu'il compare la vitesse actuelle à la vitesse limite
bool SpeedSensor::operator>(float limit){
  return read()>limit;
}

