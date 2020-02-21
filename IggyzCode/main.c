// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  glPushMatrix();
  {
  	GLdouble m[16] = {	1,	0,	0,	0,
            						0,	1,	0,	0,
            						0,	0,	1,	0,
            						0,	0,	0,	2
            					};
  	GLdouble n[16] = {	2,	0,	0,	0,
            						0,	2,	0,	0,
            						0,	0,	2,	0,
            						0,	0,	0,	1
            					};
  	GLdouble o[16] = {	4,	0,	0,	0,
  						0,	3,	0,	0,
  						0,	0,	2,	0,
  						0,	0,	0,	1
  					};
  	glMultMatrixd(m);
  	//glMultMatrixd(n);

    glutSolidCube(0.5);
  }
  glPopMatrix();


  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
