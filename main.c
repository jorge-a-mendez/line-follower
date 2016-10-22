#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "motor.h"
#include "timers.h"
#include "seguidor.h"




void main(void) {
  EnableInterrupts;
  /* include your code here */

  SOPT1=0x42;
  PWMInit();
  initTimer();
  

  for(;;) {
    keepTrue();
  }
}
