#include <controlPWM.h>
#define Kp 27
#define Kd -19
#define Ki 0.0002
#define dt 50
#define TAM 25

int estadosAnteriores[TAM]={0};
int i=0,j=0;
int promedioParcial=0;
int muestras=0;
int QAnterior=0;
int q=0;
int error=0;
int errorAnterior=0;
int correccion=0;
int integral=0;
int derivativo=0;
const int estados[]={0,2,0,1,-2,0,-1,0};
controlPWM Derecho(MderPos,MderNeg,0);
controlPWM Izquierdo(MizqPos,MizqNeg,0);

void setup(){
  initEntrada();
  delay(5000);
  Izquierdo.changeVel(vStraightI);
  Derecho.changeVel(vStraightD);
}

void loop(){
   q = sense();
   if(q!=BBB){
     error = -estados[q];
     integral+=error;
     derivativo=(error-errorAnterior);
     correccion=  Kp*error + Kd*derivativo + Ki*integral;
     errorAnterior=error;
     Derecho.velocidad(correccion);
     Izquierdo.velocidad(-correccion);
     if(i==TAM) i=0;
     estadosAnteriores[i++]=error;
   }
   else{
      i=0;
      while(i<TAM){
        promedioParcial+=estadosAnteriores[i];
        estadosAnteriores[i++]=0;
      }
      while(q==0){
       if(promedioParcial<0){
         Derecho.velocidad(0,REVERSE);
         Izquierdo.velocidad(0);
         //Serial.println("Angulo Recto-Derecha");
       }
       else {
         Derecho.velocidad(0);
         Izquierdo.velocidad(0,REVERSE);
         //Serial.println("Angulo Recto-Izquierda");
       }
       q=sense();
      }
      i=0;
      promedioParcial=0;
      integral=0;
   }
   QAnterior=q;
   delayMicroseconds(dt);
}
