// gcc hand.c actions.c axes.c init.c lumiere.c switch_blend.c  switch_light.c VM_init.c -lm -lGL -lGLU -lglut -o my_hand

#include "init.h"
#include "axes.h"
#include "VM_init.h"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLfloat srot = 0.0f;
GLfloat drot = 0.0f;
GLfloat frot = 0.0f;
GLfloat grot = 0.0f;

void drawFingerBit(GLfloat len){
glPushMatrix();

  glScalef(.5f,.5f,len);
  glutSolidCube(1);  

glPopMatrix();
}

void knuckle(GLfloat rot){
  glTranslatef(0.0f,0.25f,0.0f);
    glRotatef(rot,1.0f,0.0f,0.0f);
  glTranslatef(0.0f,-0.25f,0.0f);
}

void drawFinger(GLfloat rot, GLfloat scale){
glPushMatrix();

  knuckle(rot);

  glTranslatef(0.0f,0.0f,0.5f*scale);
  drawFingerBit(1.0f*scale);

  glTranslatef(0.0f,0.0f,0.5f*scale);

  knuckle(rot);

  GLfloat scale1=0.75f*scale;
  glTranslatef(0.0f,0.0f,0.5f*scale1);
  drawFingerBit(1.0f*scale1);

  glTranslatef(0.0f,0.0f,0.5f*scale1);

  knuckle(rot);

  GLfloat scale2=0.60f*scale;
  glTranslatef(0.0f,0.0f,0.5f*scale2);
  drawFingerBit(1.0f*scale2);

glPopMatrix();
}

void drawThumb(GLfloat rot, GLfloat scale){
glPushMatrix();

  knuckle(rot);

  glTranslatef(0.0f,0.0f,0.5f*scale);
  drawFingerBit(1.0f*scale);

  glTranslatef(0.0f,0.0f,0.5f*scale);

  knuckle(rot);

  GLfloat scale1=1.1f*scale;
  glTranslatef(0.0f,0.0f,0.5f*scale1);
  drawFingerBit(1.0f*scale1);

glPopMatrix();
}

GLvoid Modelisation()
{
  VM_init();

  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
  glColor3f(.8f,.5f,.4f);

  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glDisable(GL_BLEND);              // Turn Blending Off
  glEnable(GL_DEPTH_TEST); 
  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
glPushMatrix();
  GLfloat scale=1.0f;
  glScalef(scale,scale,scale);
  glRotatef(180.f,0.0f,1.0f,0.0f);
  
  glPushMatrix();
    glScalef(2.0f,.5f,2.0f);
    glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0f,0.0f,1.0f);
    drawFinger(drot,1.0f);

    glPushMatrix();
      glTranslatef(-.7f,0.0f,0.0f);
      drawFinger(srot,.8f);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(.7f,0.0f,0.0f);
      drawFinger(frot,.9f);
    glPopMatrix();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0f,0.0f,-1.0f);
    glRotatef(40.0f,0.0f,1.0f,0.0f);
    glRotatef(-grot/10.0f,-0.2f,0.1f,0.1f);
    glTranslatef(0.0f,0.1f,1.2f);
    glScalef(1.0f,.5f,1.6f);
    glutSolidCube(1);

    glPushMatrix();
      glTranslatef(0.0f,0.0f,0.3f);
      drawThumb(grot,.5f);
    glPopMatrix();
  glPopMatrix();


glPushMatrix();
  glTranslatef(0.0f,0.4f,0.0f);
  axes();
glPopMatrix();

glPopMatrix();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
