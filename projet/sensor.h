#ifndef SENSOR_H_
#define SENSOR_H_
#include <Arduino.h>

//Définition de la classe mère "capteurs" qui gère les différents capteurs : de vitesse, de température et humidité et de distance.
class sensor {
  public:
  //Constructeur
  sensor();

  //Fonction pour lire les valeurs mesurées par les capteurs (utilisée seulement pour vitesse et distance)
  virtual float read()=0;

  //Fonction qui permet l'affichage du nom du capteur sur l'écran LCD
  virtual String label() const=0;

  //Destructeur
  ~sensor();
};

#endif