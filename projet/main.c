// gcc main.c actions.c axes.c init.c lumiere.c switch_move.c switch_blend.c  switch_light.c VM_init.c ppm.c -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <stdio.h>
#include <math.h>

extern GLuint texture[];

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLfloat wiggle_acc = 0.0f;
GLfloat wiggle = 0.0f;
GLfloat wiggle2 = 0.0f;

GLuint move = 0;
const GLfloat MAXspeed = 4.0f;
GLfloat force_z=100.0f;
GLfloat speed;
const GLfloat acc=2.0f;
const GLfloat drag=0.4f;

void makeFish();
void makeFishBowl();

GLvoid Modelisation()
{
  //printf("force_z:%f\nspeed=:%f",force_z,speed);
  VM_init();
  if(force_z>0.0f)
    force_z-=drag;
  if(force_z<100.0f)
    force_z+=acc*move;
  if(force_z<0.0f) force_z=0.0f;
  if(force_z>100.0f) force_z=100.0f;
  //printf("force_z: %f\n",force_z);

  speed=MAXspeed*force_z/100.0f;
  wiggle_acc+=speed/100.0f;
  wiggle = sin(wiggle_acc);
  wiggle2= sin(wiggle_acc*2);

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
  makeFish();
  
  //axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}

void makeFish(){
glPushMatrix();
//glPopMatrix();

  glColor3f(0.0f,0.0f,0.0f); //eyes
  glPushMatrix();
    glTranslatef(0.0f, 0.1f, -0.8f);

    glPushMatrix();
      glTranslatef(-0.2f, 0.0f,0.0f);
      glutSolidSphere(0.08f,10,10);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0.2f, 0.0f,0.0f);
      glutSolidSphere(0.08f,10,10);
    glPopMatrix();
  glPopMatrix();

  glColor3f(0.0f,1.0f,0.4f); //body
  glPushMatrix();
    glScalef( 0.4f, 0.4f, 1.0f);
    glutSolidSphere(1,10,10);
  glPopMatrix();

  glPushMatrix();
    glRotatef(wiggle*4.0f,0.0f,1.0f,0.0f);
    glTranslatef(0.f,0.f,1.0f);
    glPushMatrix();
      glScalef( 0.2f, 0.2f, 0.5f);
      glutSolidSphere(1,10,10);
    glPopMatrix();

    glRotatef(wiggle*1.0f,0.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
    glBindTexture(GL_TEXTURE_2D,texture[0]);
      glTexCoord2f(0.0f,0.0f);
      glVertex3f(0.0f,-0.2f,0.0f);
      glTexCoord2f(1.0f,0.0f);
      glVertex3f(0.0f,-0.5f,0.8f);
      glTexCoord2f(1.0f,1.0f);
      glVertex3f(0.0f,0.4f,0.6f);
      glTexCoord2f(0.0f,1.0f);
      glVertex3f(0.0f,0.2f,0.0f);
    glEnd();
  glPopMatrix();  

  glPushMatrix();
    glTranslatef(0.0f,0.1f,0.0f);
    glBegin(GL_QUADS);
      glBindTexture(GL_TEXTURE_2D,texture[0]);
      glTexCoord2f(0.0f,0.0f);
      glVertex3f(0.0f,0.2f,0.0f);
      glTexCoord2f(1.0f,0.0f);
      glVertex3f(0.0f,0.4f,0.6f);
      glTexCoord2f(1.0f,1.0f);
      glVertex3f(0.0f,-0.5f,0.8f);
      glTexCoord2f(0.0f,1.0f);
      glVertex3f(0.0f,-0.2f,0.0f);
    glEnd();

    glTranslatef(0.0f,0.0f,-0.4f);

    glPushMatrix();
      glTranslatef(0.2f,0.0f,0.0f);
      glRotatef(20.0f,0.0f,0.0f,1.0f);
      glRotatef(30.0f+wiggle*2.0f,0.0f,1.0f,0.0f);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);
        glVertex3f(0.0f,0.1f,0.0f);
        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.0f,0.2f,0.6f);
        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.0f,-0.3f,0.8f);
        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.0f,-0.1f,0.0f);
      glEnd();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.2f,0.0f,0.0f);
      glRotatef(-20.0f,0.0f,0.0f,1.0f);
      glRotatef(-30.0f-wiggle*2.0f,0.0f,1.0f,0.0f);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);
        glVertex3f(0.0f,0.1f,0.0f);
        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.0f,0.2f,0.6f);
        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.0f,-0.3f,0.8f);
        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.0f,-0.1f,0.0f);
      glEnd();
    glPopMatrix();

  glPopMatrix();

  glTranslatef(0.f,-0.2f,-0.2f);
  glColor3f(1.0f,1.0f,1.0f); //puffer
  glPushMatrix();
    glScalef( 0.4f, 0.4f, 0.8f);
    glutSolidSphere(1,10,10);
  glPopMatrix();

glPopMatrix();}

void makeFishBowl(){
glPushMatrix();
  
  glScalef(50.0f,50.0f,50.0f);
  glColor3f(0,0,1);
  glutSolidSphere(1,10,10);
  glTranslatef(0,-1,0);
  glColor3f(1,0.8f,0.2f);
  glutSolidCube(1);

glPopMatrix();}