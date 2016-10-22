#include "controlPWM.h"
#include "Arduino.h"

controlPWM::controlPWM(unsigned int Positivo, unsigned int Negativo){
	vel=vStraight;
	Neg=Negativo;
	Pos=Positivo;
	analogWrite(Pos,vel);
	analogWrite(Neg,0);
}
void controlPWM::velocidad(int c, int sentido){
	if(sentido==FORWARD){
		analogWrite(Pos,constrain(vel+c,0,255));
		analogWrite(Neg,0);
	}
	else{
		analogWrite(Neg,constrain(vel+c,0,255));
		analogWrite(Pos,0);
	}
}

int controlPWM::velocidadActual(){
	return vel;
}

int imLost(){
	
}

int stall(int seg){
	delay(5000);
	return 0;
}

int sense(){
	int q=0;
	q |= (~digitalRead(SIzquierdo))<<2;
	q |= (~digitalRead(SCentral))<<1;
	q |= ~digitalRead(SDerecho);
	return q;
}

void initEntrada(){
	pinMode(SIzquierdo, INPUT);
	pinMode(SCentral, INPUT);
	pinMode(SDerecho, INPUT);
}

float factorEscala(){
	float t;
	return t=(90/25-1)/1023*analogRead(Pot)+1;
}
