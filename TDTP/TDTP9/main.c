// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"


GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 
extern GLuint texture[];
GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
  //normal(0.0f,0.0f,1.0f)
  
  glBegin(GL_QUADS);
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    

    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,0.0f);
    
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(1.0f,-2.0f,0.0f);
    
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.0f,1.0f,0.0f);
    
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.0f,1.0f,0.0f);

  glEnd();


  //axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
