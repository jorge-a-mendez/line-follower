#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "motor.h"
#include "timers.h"
#include "seguidor.h"



int fant;


void main(void) {
	int q;
	EnableInterrupts;
  /* include your code here */

  
  SOPT1=0x42;
  PWMInit();
  initTimer();
  initEntrada();
  
  for(;;) {
	  q=sense();
	  if(q==0){
		  if( fant==0 || fant==2 || fant==4){
			  angleR();
		  }
		  else 
			  if(fant==1 || fant==3 || fant==5){
				  angleL();
			  }
	  }
	  else 
		  if(q==1){
			  turnMoreR();
		  }
		  else 
			  if(q==2){
				  keepTrue();				   
			  }
			  else 
				  if(q==3){
					  turnR();
				  }
				  else
					  if(q==4){
						  turnMoreL();
					  }
					  else
						  if(q==5){
							  continue;
						  }
						  else
							  if(q==6){
								  turnL();
							  }
							  else
								  if(q==7){
									  keepTrue();
								  }
  }
}
