#ifndef TEMPHUMSENSOR_H_
#define TEMPHUMSENSOR_H_
#include "sensor.h"
#include <Arduino.h>
#include <SHT31.h>
#include <Wire.h>

//Définition de la classe fille du capteur de température et d'humidité
class TempHumSensor: public sensor{
  private:
  SHT31 sht; //Création d'une instance de la classe associée au capteur de température (accès aux fonctions de la librairie SHT31)
  
  public:
  //Constructeur
  TempHumSensor();

  //Redéfinition de la fonction abstraite read() nécessaire
  float read();

  //Fonctions de récupération des données du capteur
  float Temperature();
  float humidity();

  //Affichage de "Temp&Humidity" sur l'écran LCD
  String label() const;
};

#endif
