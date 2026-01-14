#include "dashboard.h"

//Constructeur : Configuration de l'écran LCD, pas d'association de PIN car communication via I2C
dashboard::dashboard(){
  lcd.begin(16,2); //Dimensions de l'écran
  lcd.display(); //Allumage de l'écran LCD
  lcd.setRGB(0,255,0); //Fixe la couleur de l'écran LCD sur vert
}

//Fonction permettant le déclenchement des alertes et les affichages associés
void dashboard::alert(String msg){
  lcd.clear(); 
  lcd.setRGB(255,0,0); //Fixe la couleur de l'écran LCD sur rouge
  lcd.print(msg);
}

//Fonction permettant l'affichage des données en provenance des capteurs sur l'écran LCD
void dashboard::display(String title, String value){
  lcd.clear();
  lcd.setRGB(0,255,0); 
  lcd.setCursor(0,0); //Permet de commencer à écrire à gauche sur la première ligne de l'écran LCD
  lcd.print(title); 
  lcd.setCursor(0,1); //Permet de commncer à écrire à gauche sur la deuxième ligne de l'écran LCD
  lcd.print(value);
}
