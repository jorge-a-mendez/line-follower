#include <seguidor.h>

int q=0;

void setup(){
  initEntrada();
}

void loop(){
  q=sense();
  if(q==BBB){
    if( fant==TR || fant==TMR || fant==AR){
      angleR();
    }
    else if(fant==TL || fant==TML || fant==AL){
      angleL();
    }
  }
  else if(q==BBN){
	//if(fant!=TL && fant!=TML ){
		turnMoreR();
	//}
	//else turnMoreL();
  }
  else if(q==BNB){
    keepTrue();				   
  }
  else if(q==BNN){
	//if(fant!=TML){
		turnR();
	//}
	//else turnMoreL();
  }
  else if(q==NBB){
	//if(fant!=TR && fant!=TMR){
		turnMoreL();
	//}
	//else turnMoreR();
  }
  else if(q==NBN){
	if( fant==TR || fant==TMR || fant==AR){
		angleR();
	}
	else if(fant==TL || fant==TML || fant==AL){
		angleL();
	}
  }
  else if(q==NNB){
    //if(fant!=TMR){
		turnL();
	//}
	//else turnMoreR();
  }
  else if(q==NNN){
    keepTrue();
  }

//endLoop:;  

}

