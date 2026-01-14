#ifndef SPEEDSENSOR_H_
#define SPEEDSENSOR_H_
#include "sensor.h"
#include <Arduino.h>

//Définition de la classe fille du capteur de vitesse, géré par le capteur d'angle rotatif (potentiomètre): la valeur de vitesse renvoyée est proportionnelle
//à la tension (comprise entre 0 et Vcc) fournie par le "capteur".
class SpeedSensor: public sensor{
  private:
  int pin; //Variable contenant le numéro de la PIN associée, utilisée pour le constructeur
  
  public:
  //Constructeur
  SpeedSensor(int p);

  //Fonction qui renvoie la valeur de la vitesse : relie l'angle à la vitesse de façon proportionelle (vitesse=0.1 x angle)
  float read();

  //Affichage de "Vitesse" sur l'ecran LCD
  String label() const;

  //Surcharge de l'opérateur >
  bool operator > (float limit);
};

#endif
