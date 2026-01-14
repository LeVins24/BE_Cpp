#include "TempHumSensor.h"

//Constructeur ; pas d'association de PIN car communication via I2C
TempHumSensor::TempHumSensor(){
}

//Redéfinition de la fonction abstraite read() nécessaire
float TempHumSensor::read(){return 0;} //Inutilisée, on ne peut pas renvoyer deux éléments différents en même temps dans une seule fonction

//Fonction qui renvoie la valeur de la température de l'environnement
float TempHumSensor::Temperature(){
  sht.requestData(); //Lancement d'une mesure
  sht.readData(); //Récupération des données brutes mesurées (rawTemp et RawHum)
  float T=sht.getTemperature(); //Recalcul de la valeur réelle de température (175.0*(rawTemp/65535.0)-45.0)
  return T;
}
//Fonction qui renvoie la valeur de l'humidité de l'environnement
float TempHumSensor::humidity(){
  sht.requestData();
  sht.readData();
  float H= sht.getHumidity(); //Recalcul de la valeur réelle d'humidité (100.0*(rawHum/65535.0)
  return H;
}

//Affichage de "Temp&Humidity" sur l'ecran LCD
String TempHumSensor::label() const{
  return "Temp&Humidity";
}

