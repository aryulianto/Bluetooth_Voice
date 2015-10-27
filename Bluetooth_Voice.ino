#include <SoftwareSerial.h>  				// Mengisltal Software Serial Port
#define RxD 11						// Set RX berada pada Pin 11
#define TxD 10						// Set TX berada pada pin 10 
#define DEBUG_ENABLED  1
#define RELAY1 13					// Mendefinisikan LED berada pada pin 13
SoftwareSerial blueToothSerial(RxD,TxD);	 
String voice;
void setup() {	
  Serial.begin(9600);					// Menghubungkan Laptop dengan Arduino
pinMode(RELAY1, OUTPUT);			        // Set LED menjadi Output
 blueToothSerial.begin(9600); 			        // Menghubungkan Laptop dengan Bluetooth
}
 
void loop() {
 while (blueToothSerial.available()) {  		// Mengecek Apakah ada masukan
 delay(50);						// Jeda 0.5 detik
 char charBTSerial = blueToothSerial.read();	        // Membaca Masukan
    if (charBTSerial == '#') 
	break; 						// Berhenti
      	voice += charBTSerial; 
  }  
if (voice.length() > 0) {				// Jika serial lebih dari 0
    Serial.println(voice); 			        // Menampilkan Suara
    if(voice == "*on") digitalWrite(RELAY1,0);	
    Serial.println("Light ON");                // Jika suara “nyalakan lampu, maka LED akan menyala
    if(voice == "*ok") digitalWrite(RELAY1,1);  
    Serial.println("Light OFF");                // Jika suara “matikan lampu, maka LED akan mati
    voice="";
  }
}

