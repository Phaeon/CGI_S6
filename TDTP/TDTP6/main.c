// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

// 0 : avant, 1 : arriere, 2 : droit, 3 : gauche, 4 : dessus, 5 : dessous
static int faces[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}};
static int sommets[][3] = {{0, 3, 5}, {0, 2, 5}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {1, 3, 4}, {1, 2, 4}};

typedef struct {
  GLfloat coords[8][3];
} cube;

cube creerCubeStruct(GLfloat taille) {
  cube out; 
  for(int i=0;i<8;i++){
    switch(sommets[i][0]){
      case 0:
        out.coords[i][0]=0;
      break;
      case 1:
        out.coords[i][0]=taille;
      break;
    }
    switch(sommets[i][1]){
      case 2:
        out.coords[i][1]=taille;
      break;
      case 3:
        out.coords[i][1]=0;
      break;
    }
    switch(sommets[i][2]){
      case 4:
        out.coords[i][2]=taille;
      break;
      case 5:
        out.coords[i][2]=0;
      break;
    }
  }
  return out;
}

GLvoid drawCube(cube c) {
  glBegin(GL_QUADS);
  for(int i=0;i<6;i++){
    glColor3f(0.4f,(float)i/6.0, 1-(float)i/6);
    glVertex3f(c.coords[faces[i][0]][0],c.coords[faces[i][0]][1],c.coords[faces[i][0]][2]);
    glVertex3f(c.coords[faces[i][1]][0],c.coords[faces[i][1]][1],c.coords[faces[i][1]][2]);
    glVertex3f(c.coords[faces[i][2]][0],c.coords[faces[i][2]][1],c.coords[faces[i][2]][2]);
    glVertex3f(c.coords[faces[i][3]][0],c.coords[faces[i][3]][1],c.coords[faces[i][3]][2]);
  }
  glEnd();
}

GLvoid Modelisation()
{
  VM_init();

  drawCube(creerCubeStruct(0.5f));

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
