#include <stdio.h>
#include <stdlib.h>
#include "derivative.h"
#include "motor.h"
#include "seguidor.h"

//TPM cuenta hasta 65536
int PWMInit(){
	TPM3SC=0x8;		//selecciona bus clock sin divisor
	TPM3MOD=0xFFFF;
	TPM3C0SC=0x28;	//selecciona ch1 como PWM edge aligned
	TPM2SC=0x8;
	TPM2MOD=0xFFFF;
	TPM2C1SC=0x28;
	PTBDD|=0x8;  //
	PTBPE|=0x8;  //
	PTBD|=0x8;   //inicializacion de PTB3 como 1
	//duty cycle se selecciona on TPM1C1V
	return 0;
}

int onR(word v){
	float aux=(float)v;
	aux *= escalado(26);	//EC3883: escala entre 25% y porcentaje leido de potenciometro
	v=(word)aux;
	// EC3883: agregar if(v>0) ... y poner otro TPM a cero
	//else prender otro TPM y poner este a cero
	TPM3C0V=v; 		//revisar cual es ch0 y cual es ch1
	return 0;
}

int onL(word v){
	float aux;
	aux = (float)(65535-v);
	aux *= escalado(26);	//EC3883: escala entre 25% y porcentaje leido de potenciometro
	v = (word)(65535-aux);
	// EC3883: agregar if(v>0) ... y poner otro TPM a cero
	//else prender otro TPM y poner este a cero
	TPM2C1V=v;		//Lo que habia era TPM3C1V=v
	return 0;
}
