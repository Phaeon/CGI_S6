// g++ main.cpp -lm -lGL -lglut
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>

void displayfunc(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-5.0f);          // move z units out from the screen.
    glRotatef(0.0f,1.0f,0.0f,0.0f);		// Rotate On The X Axis
    glRotatef(0.0f,0.0f,1.0f,0.0f);		// Rotate On The Y Axis

    glPushMatrix();
	{


		glutSolidSphere(0.5,100,10);
	

	}
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,10);
	glutCreateWindow("My Window");

	glutDisplayFunc(displayfunc);
	glutIdleFunc(displayfunc);
	//glutReshapeFunc();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
    
    gluPerspective(45.0f,(GLfloat)640/(GLfloat)480,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
    
    glMatrixMode(GL_MODELVIEW);


	glutMainLoop();

	return 1;
}