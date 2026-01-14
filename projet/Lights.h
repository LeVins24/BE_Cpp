#ifndef LIGHTS_H_
#define LIGHTS_H_
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Lights{
  private:
  Adafruit_NeoPixel phare; //Création d'une instance de la classe associée au LEDs (accès aux fonctions de la librairie Adafruit_Nepixel)
  int mode=0; //Variable qui mémorise le mode d'allumage des LEDs
  
  public:
  //Constructeur
  Lights(int pin);

  //Fonction faisant correspondre l'allumage des LEDs avec le mode sélectionné
  void update();

  //Fonction permettant de passer au mode d'allumage suivant
  void nextmode();

  //Fonction qui renvoie l'intitulé du mode actuel d'allumage des LEDs
  int getmode() const;

};

#endif