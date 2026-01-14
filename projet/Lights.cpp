#include "Lights.h"

//Constructeur : Configuration de la PIN pour les 10 LEDs (toute la bande),
Lights::Lights(int pin): phare(10,pin) {
  phare.begin();
  phare.show(); //Allume les LEDs
}

//Fonction faisant correspondre l'allumage des LEDs avec le mode sélectionné
void Lights::update(){
  phare.clear(); //mode 0 : LEDs éteintes

  //Paramétrage de la bande de LEDs
  //mode 1 : 6 LEDs centrales allumés, intensité normale
  if (mode==1){
    for (int i=2;i<=7;i++){
      phare.setBrightness(10); //Intensité lumineuse : entre 0 et 255. Nécessité de diminuer pour ne pas consommer trop de courant
      phare.setPixelColor(i,phare.Color(255,255,255)); //Fixe la couleur des LEDs sur blanc
    }
  }
  //mode 2 : toutes les LEDs allumées, intensté plus forte
  else if (mode==2){
    for (int i=0;i<10;i++){
      phare.setBrightness(40); 
      phare.setPixelColor(i,phare.Color(255,255,255));
    }
  }
  phare.show(); //Allume les LEDs
}

//Fonction permettant de passer au mode d'allumage suivant
void Lights::nextmode(){
  mode=(mode+1)%3;
  update();
}

//Fonction qui renvoie l'intitulé du mode actuel d'allumage des LEDs
int Lights::getmode() const{
  return mode;
}
