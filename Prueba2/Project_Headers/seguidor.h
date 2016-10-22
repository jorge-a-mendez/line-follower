#ifndef SEGUIDOR_H_
#define SEGUIDOR_H_


#define vStraightR 16384  //25%
#define vStraightL 48693  //25,7%
#define vSTurnR 7872		//46.2% del 26%
#define vFTurnR 48497		//26%
#define vFTurnL 17039		//26
#define vSTurnL 57221		//48.8% del 26%
#define vSTurnMoreR 645		//3.79% de 26%
#define vFTurnMoreR 48497	//26%
#define vFTurnMoreL 17039	//26%
#define vSTurnMoreL 64855	//4% de 26%
#define offR 645
#define offL 64855
#define vAngleR 16384
#define vAngleL 48693
#define SIzquierdo	(0x2&~PTBD)<<1
#define SCentral	(0x1&~PTBD)<<1
#define SDerecho	(0x4&~PTAD)>>2



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
int initEntrada(void);
float escalado(float x);

#endif
