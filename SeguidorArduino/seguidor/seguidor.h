	
#ifndef SEGUIDOR_H_
#define SEGUIDOR_H_

#include "Arduino.h"

#define MderPos	6
#define MderNeg 9
#define MizqPos	5
#define MizqNeg 3
#define SIzquierdo	10
#define SCentral	11
#define SDerecho	12
#define Pot	A0


#define vStraightR 64  //25%
#define vStraightL 64  //25,7%
#define vSTurnR 30		//46.2% del 25%
#define vFTurnR 64		//25%
#define vFTurnL 64		//25%
#define vSTurnL 31		//48.8% del 25%
#define vSTurnMoreR 2	//3.79% de 25%
#define vFTurnMoreR 64	//25%
#define vFTurnMoreL 64	//25%
#define vSTurnMoreL 3	//4% de 26%
#define offR 3
#define offL 3
#define vAngleR 64
#define vAngleL 64

#define BBB 0
#define BBN 1
#define BNB 2
#define BNN 3
#define NBB 4
#define NBN 5
#define NNB 6
#define NNN 7

#define TR 0
#define TL 1
#define TMR 2
#define TML 3
#define AR 4
#define AL 5
#define KT 6

extern int fant;

int onRForward(int v);
int onRReverse(int v);
int onLForward(int v);
int onLReverse(int v);

int turnR(void);
int turnL(void);
int turnMoreR(void);
int turnMoreL(void);
int angleR(void);
int angleL(void);
int keepTrue(void);
int imLost(void);
int stall(int seg);
int sense(void);
void initEntrada();
float factorEscala();

#endif
