#include "seguidor.h"
#include "Arduino.h"

int fant=0;

int turnR(){
	onRForward(vSTurnR);
	onLForward(vFTurnR);
	fant=TR;
	return 0;
}

int turnL(){
	onRForward(vFTurnL);
	onLForward(vSTurnL);
	fant=TL;
	return 0;
}

int turnMoreR(){
	onRForward(vSTurnMoreR);
	onLForward(vFTurnMoreR);
	fant=TMR;
	return 0;
}

int turnMoreL(){
	onRForward(vFTurnMoreL);
	onLForward(vSTurnMoreL);
	fant=TML;
	return 0;
}

int angleR(){
	onRReverse(vAngleR);
	onLForward(vAngleR);
	fant=AR;
	return 0;
}

int angleL(){
	onRForward(vAngleL);
	onLReverse(vAngleL);
	fant=AL;
	return 0;
}

int keepTrue(){
	onRForward(vStraightR);
	onLForward(vStraightL);
	fant=AR;
	return 0;
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
	
int onRForward(int v){
	analogWrite(MderPos,v);		
	analogWrite(MderNeg,0);
	return 0;
}

int onLForward(int v){
	analogWrite(MizqPos,v);	
	analogWrite(MizqNeg,0);
	return 0;
}

int onRReverse(int v){
	analogWrite(MderPos,0);		
	analogWrite(MderNeg,v);
	return 0;
}

int onLReverse(int v){
	analogWrite(MizqPos,0);	
	analogWrite(MizqNeg,v);
	return 0;
}
