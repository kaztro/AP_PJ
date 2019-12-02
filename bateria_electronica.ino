/**ProyectoF 2016 **    https://youtu.be/V7R1cG3y84c
informacion de las librerias  https://github.com/TMRh20/TMRpcm
                              http://playground.arduino.cc/Main/CapacitiveSensor
*/
//líbrerias necesarias
#include <SD.h>  
#include <SPI.h>
#include <TMRpcm.h>  
#include <CapacitiveSensor.h>


#define pinSD 10     //define el pin para seleccionar la tarjeta SD

TMRpcm tmrpcm;   //Se crea un objeto de la librería TMRpcm

CapacitiveSensor   cs_14_2 = CapacitiveSensor(14,2); // define pines en arduino uno el 14 es A0.
CapacitiveSensor   cs_14_3 = CapacitiveSensor(14,3);
CapacitiveSensor   cs_14_4 = CapacitiveSensor(14,4);
CapacitiveSensor   cs_14_5 = CapacitiveSensor(14,5);
CapacitiveSensor   cs_14_6 = CapacitiveSensor(14,6);
CapacitiveSensor   cs_14_7 = CapacitiveSensor(14,7);
CapacitiveSensor   cs_14_8 = CapacitiveSensor(14,8);

int sense = 400;  // define sencibilidad a menor numero mas sencible
int tiempo = 100; // define tiempo maximo de reproduccion
int flag=0;
char* colection1[] = {"hhat.wav", "do.wav"};
char* colection2[] = {"plati2.wav", "re.wav"};
char* colection3[] = {"plati1.wav", "mi.wav"};
char* colection4[] = {"tambor1.wav", "fa.wav"};
char* colection5[] = {"tambor2.wav", "sol.wav"};
char* colection6[] = {"bombo1.wav", "la.wav"};
char* colectionCambio[] = {"go.wav", "si.wav"};

void setup(){
  tmrpcm.speakerPin = 9; // define el pin en el que está conectada la bocina
  Serial.begin(9600);    

  if (!SD.begin(pinSD)) {  // verifica la coneccion de la tarjeta sd:
    Serial.println("Fallo en la tarjeta SD");  //Aviso de que algo no anda bien 
    return;   //No hacer nada si no se pudo leer la tarjeta
  }
}

void loop(){  
   long valor1 =  cs_14_2.capacitiveSensor(20);
      long valor2 =  cs_14_3.capacitiveSensor(20);
      long valor3 =  cs_14_4.capacitiveSensor(20);
      long valor4 =  cs_14_5.capacitiveSensor(20);
      long valor5 =  cs_14_6.capacitiveSensor(20);
      long valor6 =  cs_14_7.capacitiveSensor(20);
      long valor7 =  cs_14_8.capacitiveSensor(20);
 
 if (valor1 > sense){
     // Serial.println("pad1");  //Imprime pad detectado
      tmrpcm.play(colection1[flag]);  // nombre de archivo a reproducir guardado en la sd.
      delay(tiempo);} 
 if (valor2 > sense){
      //Serial.println("pad2");  
    tmrpcm.play(colection2[flag]);    
      delay(tiempo);} 
 if (valor3 > sense){
      //Serial.println("pad3"); 
      tmrpcm.play(colection3[flag]);    
      delay(tiempo);} 
 if (valor4 > sense){
     // Serial.println("pad4");  
     tmrpcm.play(colection4[flag]);    
      delay(tiempo);}  
 if (valor5 > sense){
      Serial.println("pad5"); 
     tmrpcm.play(colection5[flag]);    
      delay(tiempo);} 
 if (valor6 > sense){
      Serial.println("pad6"); 
     tmrpcm.play(colection6[flag]);    
      delay(tiempo);} 
 if (valor7 > sense){
      //Serial.println("pad7");      
       flag++;
      if(flag>2){
        flag=0;
      };
     tmrpcm.play(colectionCambio[flag]);    
    delay(tiempo);      
      };
  }
 
  
  
