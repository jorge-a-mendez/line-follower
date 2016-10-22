#include <stdio.h>
#include <stdlib.h>
#include "derivative.h"
#include "motor.h"
#include "timers.h"
#include "seguidor.h"


extern int fant;
int turnR(){
	if (fant!=0) resetTimer();
	onR(vSTurnR);
	onL(vFTurnR);
	fant=0;
	return 0;
}

int turnL(){
	if (fant!=1) resetTimer();
	onR(vFTurnL);
	onL(vSTurnL);
	fant=1;
	return 0;
}

int turnMoreR(){
	//resetTimer();
	onR(vSTurnMoreR);
	onL(vFTurnMoreR);
	fant=2;
	return 0;
}

int turnMoreL(){
	//resetTimer();
	onR(vFTurnMoreL);
	onL(vSTurnMoreL);
	fant=3;
	return 0;
}

int angleR(){
	onR(offR);
	onL(vAngleR);
	fant=4;
	//hay que saber que tiempo tarda en compensar
	//para hacer la llamada a esta funcion y saber
	//que caso interesa para saber que volvio a la
	//pista
	return 0;
}

int angleL(){
	onL(offL);
	onR(vAngleL);
	fant=5;
	return 0;
}

int keepTrue(){			//EC3883: estos seran los valores iniciales. 
	onR(vStraightR);	//luego de esto se usa el PID y suma o resta
	onL(vStraightL);	//directamente a "vd" con las constantes
	fant=6;				//kp, ki y kd
	return 0;
}

int imLost(){
	
}

int stall(int seg){
	extern int s;
	initTimer();		//hacer timer de segundos
	while(s!=seg);
	return 0;
}

int sense(){
	int q;
	q=SIzquierdo | SCentral | SDerecho;
	return q;//('q' es porque en digitales 'q' eran los estados)
}
	
int initEntrada(){
	PTBDD &= 0xFC;
	//PTBPE &= 0xFE;
	PTADD &= 0xFB;
	//Potenciometro
	ADCSC1 = 0;
	ADCSC2 = 0;
	ADCCFG = 0; //8 bits, bus clock
	APCTL1 = 1; //PTA0 disabled as i/o pin
	return 0;
}

float escalado(float x){
	float t;
	ADCSC1=0;
	while(!ADCSC1);
	t=ADCR;	
	t *=(90/x-1);
	t /=255;		//EC3883: se puede escalar a un valor fijo de 50%
	t++;
	return t;
}


