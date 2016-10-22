#include <stdio.h>
#include <stdlib.h>
#include "derivative.h" 
#include "timers.h"
byte ms;
int s;

int initTimer(){
	RTCSC=0x10;
	ms=0;
	s=0;
	return 0;
}

int resetTimer(){
	ms=0;
	s=0;
	return 0;
}

int updateTimer(){		//EC3883: agregar interrupciones de 1ms para llamar aca.
	asm{				//Si hace falta, agregar equivalente de 1us
		lda 	ms
		inca
		sta		ms
		cmp		1000
		bne		end
		upS:
			clra
			sta		ms
			lda		s
			inca
			sta		s
		end:
	}
	return 0;
}


