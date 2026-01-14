#ifndef DASHBOARD_H_
#define DASHBOARD_H_

#include <Arduino.h>
#include <rgb_lcd.h>
using namespace std;
#include <Wire.h>

//Définition de la classe pour l'écran LCD
class dashboard{
  private:
  rgb_lcd lcd; //Création d'une instance de la classe associée à l'écran LCD
  
  public:
  //Constructeur
  dashboard();

  //Fontion permettant le déclenchement des alertes et les affichages associés
  void alert(String msg);

  //Fonction permettant l'affichage des données en provenance des capteurs sur l'écran LCD
  void display(String title, String value);

};


#endif
