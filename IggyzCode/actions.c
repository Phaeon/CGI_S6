#include "actions.h"

extern GLfloat xrot;   
extern GLfloat yrot; 
extern blend;
extern light;

const GLfloat rotstep = 3.0f;

GLfloat clamp_high = 0.0f;
GLfloat clamp_low = -90.0f;

extern GLfloat srot;
extern GLfloat drot;
extern GLfloat frot;
extern GLfloat grot;

void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

    if(srot>clamp_high) srot=clamp_high;
    if(drot>clamp_high) drot=clamp_high;
    if(frot>clamp_high) frot=clamp_high;
    if(grot>clamp_high) grot=clamp_high;

    if(srot<clamp_low) srot=clamp_low;
    if(drot<clamp_low) drot=clamp_low;
    if(frot<clamp_low) frot=clamp_low;
    if(grot<clamp_low) grot=clamp_low;

    switch (key) {    
    case ESCAPE: 
	exit(1);                   	
	break; 
    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;
    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;

    case TOUCHE_MIN_A:
    case TOUCHE_MAJ_A:
      srot-=rotstep;
      drot-=rotstep;
      frot-=rotstep;
      grot-=rotstep;
      break;

    case TOUCHE_MIN_Z:
    case TOUCHE_MAJ_Z:
      srot+=rotstep;
      drot+=rotstep;
      frot+=rotstep;
      grot+=rotstep;
      break;

    case TOUCHE_MIN_S:
    case TOUCHE_MAJ_S:
      srot+=rotstep;
      break;

    case TOUCHE_MIN_D:
    case TOUCHE_MAJ_D:
      drot+=rotstep;
      break;

    case TOUCHE_MIN_F:
    case TOUCHE_MAJ_F:
      frot+=rotstep;
      break;

    case TOUCHE_MIN_G:
    case TOUCHE_MAJ_G:
      grot+=rotstep;
      break;

    case TOUCHE_MIN_E:
    case TOUCHE_MAJ_E:
      srot-=rotstep;
      break;

    case TOUCHE_MIN_R:
    case TOUCHE_MAJ_R:
      drot-=rotstep;
      break;

    case TOUCHE_MIN_T:
    case TOUCHE_MAJ_T:
      frot-=rotstep;
      break;

    case TOUCHE_MIN_Y:
    case TOUCHE_MAJ_Y:
      grot-=rotstep;
      break;

    }
}

