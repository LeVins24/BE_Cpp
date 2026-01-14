/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "sensor.h"
#include "SpeedSensor.h"
#include "TempHumSensor.h"
#include "DistanceSensor.h"
#include "Buzzer.h"
#include "Lights.h"
#include "dashboard.h"
#include <Wire.h>
using namespace std;

/**
  * @class Application
  * @brief Classe Application 
*/
class Application {
private:
//Définition d'un pointeur sur une instance de chaque classe, permettant d'initialiser ces instances dans Application.init()
DistanceSensor *distance;
Buzzer *buzzer;
Lights *lights;
dashboard *tableaubord;
SpeedSensor *vitesse;
TempHumSensor *temphum;

//Définition de variables et constantes nécessaires au bon fonctionnement.
const float vitesse_limite=90.0; //Vitesse limite de déclenchement de l'alerte "Excès de Vitesse"
const float minDistance=20.0; //Distance minimale vers l'avant de déclenchement de l'alerte "Obstacle Proche"
int Mode=0; //Variable qui mémorise le numéro de la "page" affichée sur l'écran LCD (Vitesse, Température, Humidité, Phares)

//Booléens permettant de réagir à l'appui sur le capteur de toucher ou sur le bouton poussoir
bool touch;
bool bouton;

public:
  /**
     * @fn Application();
     * @brief Constructeur par defaut
    */
  Application();
  /**
     * @fn Application();
     * @brief Destructeur
    */
  ~Application();
  /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
  void init(void);
  /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
  void run(void);
};
#endif