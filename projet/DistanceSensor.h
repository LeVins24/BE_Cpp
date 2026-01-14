#ifndef DISTANCESENSOR_H_
#define DISTANCESENSOR_H_
#include "sensor.h"
#include <Arduino.h>

//Définition de la classe fille du capteur de distance
class DistanceSensor: public sensor{
  private:
  int signal; //Variable contenant le numéro de la PIN associée à la transmission des signaux TRIGGER(émetteur) et ECHO(récepteur), utilisée pour le constructeur

  public:
  //Constructeur
  DistanceSensor(int s);

  //Fonction qui renvoie la valeur de la distance vers l'avant, renvoie 0 si aucun obstacle ne se trouve dans les 5 mètres
  float read();

  //Affichage de "Obstacle Proche" sur l'écran LCD
  String label()const;

  //Surcharge de l'opérateur <
  bool operator < (float minDist);
};

#endif
