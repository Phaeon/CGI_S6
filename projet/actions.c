#include "actions.h"
#include <stdio.h>

extern GLfloat xrot;   
extern GLfloat yrot; 
extern blend;
extern light;

extern move;

extern GLfloat force_z;
extern GLfloat acc;
extern GLfloat drag;

void touche_pressee(unsigned char key, int x, int y) 
{
    //usleep(10);  

    switch (key) {    
    case ESCAPE: 
	exit(1);                   	
	break; 

    case ESPACE:
        move = switch_move(move);
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;

    case TOUCHE_MIN_E: 
    case TOUCHE_MAJ_E: 
      light = switch_light(light);
      break;
    }
}

