#include "DistanceSensor.h"
//Constructeur : Configuration de la PIN pour le capteur de distance
DistanceSensor::DistanceSensor(int s){
  signal=s;
}

//Fonction qui renvoie la valeur de la distance vers l'avant, renvoie 0 si aucun obstacle ne se trouve dans les 5 mètres
//Fonctionnement : le capteur en mode émetteur émet un onde qui va rebondir sur l'obstacle puis être récupérée par le capteur en mode récepteur
//Le capteur renvoie le temps écoulé entre le début de l'émission et la fin de la réception de l'onde, qu'il faut reconvertir en distance
float DistanceSensor::read(){
  pinMode(signal,OUTPUT); //Configuration de la PIN en Sortie (capteur en mode émetteur)
  digitalWrite(signal,LOW); //Permet de stabiliser avant d'envoyer le signal (avec le delay)
  delayMicroseconds(2);
  digitalWrite(signal,HIGH); //Emission d'une onde pendant 10us
  delayMicroseconds(10);
  digitalWrite(signal,LOW); //Fin de l'émission
  pinMode(signal,INPUT_PULLUP); //Configuration de la PIN en Entrée (capteur en mode récepteur), en PULLUP pour éviter que la PIN soit flottante.
  long duration=pulseIn(signal,HIGH,30000); //Fonction permettant la mesure du temps de voyage de l'onde
  return duration*0.034/2; //Conversion du temps de voyage aller-retour (donc division par 2) en une distance en cm (vitesse du son : 0,034cm/us)
}

//Affichage de "Obstacle Proche" sur l'écran LCD
String DistanceSensor::label() const{
  return "Obstacle Proche";
}

//Surcharge de l'opérateur < pour qu'il compare la distance libre actuelle à la distance minimale
bool DistanceSensor::operator<(float minDist){
  return read()<minDist;
}
