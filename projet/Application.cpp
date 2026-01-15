/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

//Constructeur
Application::Application(){}
//Destructeur
Application::~Application(){}  

//Initialisation des différentes instances de classe, avec association à une PIN; Via les constructeurs respectifs
void Application::init(void){
  vitesse= new SpeedSensor(A0); //Capteur de , Entrée analogique, doit se trouver sur A0
  distance=new DistanceSensor(D5); //Capteur de distance, Entrée
  buzzer=new Buzzer(D7); //Buzzer, Sortie 
  lights=new Lights(D8); //LEDs, Sortie
  tableaubord= new dashboard(); //Ecran LCD, communication via I2C donc pas de PIN associée
  temphum= new TempHumSensor(); //Capteur de Température et Humidité, communication via I2C donc pas de PIN associée
  Wire.begin(D2,D1); //Initialisation des PINs pour la communication via I2C
}

void Application::run(void){
  touch=digitalRead(D3);
  bouton=digitalRead(D6);

  //Vérifie si la vitesse limite est dépassée et déclenche l'alerte si c'est le cas
  if ((vitesse->read())>vitesse_limite){
    buzzer->beep(1000,200); //Activation du buzzer, 1kHz pendant 200ms : alerte sonore
    tableaubord->alert("Exces de Vitesse"); //Activation de l'alerte visuelle
  }

  //Vérifie si la distance minimale est franchie et déclenche l'alerte si c'est le cas
  else if ((distance->read())< minDistance){
     buzzer->beep(200,200); //200Hz pendant 200ms
     tableaubord->alert(distance->label()); //Activation de l'alerte visuelle :  affiche "Obstacle Proche"
  }

  //Fonctionnement normal
  else{
    buzzer->stop();
    if (bouton) lights->nextmode(); //Changement de mode d'allumage des LEDs quand le bouton est pressé
    if (touch) Mode=(Mode+1)%4; //Circulation dans les "pages" affichées par l'écran LCD, retour à 0 quand le mode3 (4ème) est dépassé

    //Différentes "pages" pouvant être affichées sur l'écran LCD
    switch (Mode){
      case 0: //Page d'affichage de la vitesse
      tableaubord->display(vitesse->label(),String(vitesse->read())+"km/h");
      break;
      case 1: //Page d'affichage de la température
      tableaubord->display(temphum->label(),String(temphum->Temperature())+" C");
      delay(20);
      break;
      case 2: //Page d'affichage de l'humidité
      tableaubord->display(temphum->label(),String(temphum->humidity())+" %");
      delay(20);
      break;
      case 3: //Page d'affichage de l'état des phares
      tableaubord->display("Phares",(lights->getmode())==0? "Off" : (lights->getmode())==1? "Code" : "Plein");
      break;
    }
  }
  delay(300);
}
