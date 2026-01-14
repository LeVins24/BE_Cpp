#ifndef BUZZER_H_
#define BUZZER_H_
#include <Arduino.h>

//Définition de la classe pour le buzzer
class Buzzer{
  private:
  int pin; //Variable contenant le numéro de PIN associé, utilisée pour le constructeur

  public:
  //Constructeur
  Buzzer(int p);

  //Fonction d'activation du buzzer
  void beep(int freq,int duration);

  //Fonction d'arrêt du buzzer
  void stop();
};

#endif



