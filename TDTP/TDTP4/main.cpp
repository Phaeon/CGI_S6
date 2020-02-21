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

    glColor3f(0.75f, 0.0f, 1.0f);

    int v = glutGet(GLUT_ELAPSED_TIME)/11;
    glRotatef((GLfloat)v,0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,0.0f);
    glEnd();
    std::cout << glutGet(GLUT_ELAPSED_TIME) << std::endl;
    /*
    glPushMatrix();
	{
	    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
	    
		glutSolidCube(0.5);
	}
	glPopMatrix();
	*/

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