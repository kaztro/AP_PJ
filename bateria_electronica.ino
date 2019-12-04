//líbrerias necesarias
#include <SD.h>  
#include <SPI.h>
#include <TMRpcm.h>  
#include <CapacitiveSensor.h>


#define pinSD 10     

TMRpcm tmrpcm;   

CapacitiveSensor   cs_14_2 = CapacitiveSensor(14,2); 
CapacitiveSensor   cs_14_3 = CapacitiveSensor(14,3);
CapacitiveSensor   cs_14_4 = CapacitiveSensor(14,4);
CapacitiveSensor   cs_14_5 = CapacitiveSensor(14,5);
CapacitiveSensor   cs_14_6 = CapacitiveSensor(14,6);
CapacitiveSensor   cs_14_7 = CapacitiveSensor(14,7);
CapacitiveSensor   cs_14_8 = CapacitiveSensor(14,8);

int sense = 400;  
int tiempo = 100; 
int flag=0;
char* colection1[] = {"hhat.wav", "do.wav"};
char* colection2[] = {"plati2.wav", "re.wav"};
char* colection3[] = {"plati1.wav", "mi.wav"};
char* colection4[] = {"tambor1.wav", "fa.wav"};
char* colection5[] = {"tambor2.wav", "sol.wav"};
char* colection6[] = {"bombo1.wav", "la.wav"};
char* colectionCambio[] = {"go.wav", "si.wav"};

void setup(){
  tmrpcm.speakerPin = 9; 
  Serial.begin(9600);    

  if (!SD.begin(pinSD)) {  
    Serial.println("Fallo en la tarjeta SD");   
    return;   
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
      tmrpcm.play(colection1[flag]);  
      delay(tiempo);} 
 if (valor2 > sense){  
    tmrpcm.play(colection2[flag]);    
      delay(tiempo);} 
 if (valor3 > sense){ 
      tmrpcm.play(colection3[flag]);    
      delay(tiempo);} 
 if (valor4 > sense){  
     tmrpcm.play(colection4[flag]);    
      delay(tiempo);}  
 if (valor5 > sense){ 
     tmrpcm.play(colection5[flag]);    
      delay(tiempo);} 
 if (valor6 > sense){ 
     tmrpcm.play(colection6[flag]);    
      delay(tiempo);} 
 if (valor7 > sense){      
       flag++;
      if(flag>2){
        flag=0;
      };
     tmrpcm.play(colectionCambio[flag]);    
    delay(tiempo);      
      };
  }
 
  
  
