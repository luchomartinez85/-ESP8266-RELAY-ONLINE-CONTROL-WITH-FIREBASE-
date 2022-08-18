/**********************************************************************************
 * TITULO: Código ESP8266 - FIREBASE
 * AUTOR: Jhimmy Astoraque Durán
 * DESCRIPCION: Este es el código de este episodio del canal que tambien es parte de la Serie Intermedia del esp8266
 * CANAL YOUTUBE: https://www.youtube.com/c/jadsatv
 * © 2020
 * *******************************************************************************/

#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"

// Credenciales wifi
const char *ssid = "COVID19"; // nombre de la red
const char *password = "seguridad";
//
//const char *ssid = "Fibertel WiFi732 2.4GHz"; // nombre de la red
//const char *password = "00431929220";

// Credenciales Proyecto Firebase
const char *FIREBASE_HOST = "https://rig-encender-default-rtdb.firebaseio.com/";
const char *FIREBASE_AUTH = "XUJVmLth672S0VKjCFoKJXwBN05NwBZj5CdVee3Z";

// Firebase Data object in the global scope
FirebaseData firebaseData;

const int relayPin01 = D1;
const int relayPin02 = D2;

int ENVIAR01 = 9;
int ENVIAR02 = 9;



void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(250);
  }
  
  Serial.print("\nConectado al Wi-Fi");
  Serial.println();
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  
  // String nodo1 = "Proyecto1";
  // String nodo2 = "Proyecto2";
   
    
 // Firebase.setInt(firebaseData,"NODO01", "RIG_01", 22);
 // Firebase.setInt(firebaseData, "NODO02","RIG_02", 33);

 //Firebase.setBool(firebaseData, nodo1 + "/RIG_01", false);
 
 //Firebase.setInt(firebaseData, nodo2 + "/RIG_02", 33);

 Firebase.setInt(firebaseData,"RIG_01", 11);
 Firebase.setInt(firebaseData,"RIG_02", 22);


   pinMode(relayPin01, OUTPUT);
   pinMode(relayPin02, OUTPUT);

   digitalWrite(relayPin01, HIGH);
   digitalWrite(relayPin02, HIGH);

}


void loop()

{


  Serial.println("-------------------------");
  Firebase.getInt(firebaseData, "/RIG_02");
  ENVIAR02 = firebaseData.intData();
  Serial.println("VALOR YA DECLARADO 02");
  Serial.println(ENVIAR02);
  Serial.println("-------------------------");

         
  if (ENVIAR02 == 1) {
    
 /*   Serial.println("02 --> Led Turned ON");
    Serial.println("esta leyendo: ");
    Serial.println(ENVIAR02);
    digitalWrite(relayPin02, LOW);
  */
 Serial.println("02 --> ENVIO DE PRENDIDO");
      digitalWrite(relayPin02, LOW); // turn on relay with voltage HIGH
      delay(200);              // pause
      digitalWrite(relayPin02, HIGH);  // turn off relay with voltage LOW
      delay(500);       
      Firebase.setInt(firebaseData,"RIG_02", 99);
  }
  
  else if (ENVIAR02 == 0) {
    /*
    Serial.println("02 --> Led Turned OFF");
    Serial.println("esta leyendo: ");
    Serial.println(ENVIAR02);
    digitalWrite(relayPin02, HIGH);
  */
  }

    else if (ENVIAR02 == 3) {
         Serial.println("02 --> ULTRA LARGO");
       digitalWrite(relayPin02, LOW); // turn on relay with voltage HIGH
      delay(9000);              // pause
      digitalWrite(relayPin02, HIGH);  // turn off relay with voltage LOW
      delay(500);
        Firebase.setInt(firebaseData,"RIG_02", 99);    
  }




  Serial.println("-------------------------");
  Firebase.getInt(firebaseData, "RIG_01");
  Serial.println(firebaseData.intData());
  ENVIAR01 = firebaseData.intData();
  Serial.println("VALOR YA DECLARADO 01");
  Serial.println(ENVIAR01);
  Serial.println("-------------------------");
 
         
  if (ENVIAR01 == 1) {

    
//    Serial.println("01 --> Led Turned ON");
//    Serial.println("esta leyendo ");
//    Serial.println(ENVIAR01);
//    digitalWrite(relayPin01, LOW);



      Serial.println("02 --> ENVIO DE PRENDIDO");
      digitalWrite(relayPin01, LOW); // turn on relay with voltage HIGH
      delay(200);              // pause
      digitalWrite(relayPin01, HIGH);  // turn off relay with voltage LOW
      delay(500);       
      Firebase.setInt(firebaseData,"RIG_01", 99);



    
  }
  else if (ENVIAR01 == 0) {
//    Serial.println("01 --> Led Turned OFF");
//    Serial.println("esta leyendo ");
//    Serial.println(ENVIAR01);
//    digitalWrite(relayPin01, HIGH);
  }
    else if (ENVIAR01 == 3) {
       Serial.println("01 --> ULTRA LARGO");
       digitalWrite(relayPin01, LOW); // turn on relay with voltage HIGH
      delay(9000);              // pause
      digitalWrite(relayPin01, HIGH);  // turn off relay with voltage LOW
      delay(500);
        Firebase.setInt(firebaseData,"RIG_01", 99);    
  }










} // End Loop
