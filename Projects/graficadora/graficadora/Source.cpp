#include<GL/glut.h>


void mostrar(void) {
	//no muestra nada
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	//glutWireTorus(0.25, 0.75, 28, 28);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(.60);
	glutSwapBuffers();	
}
void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
int main(int argc, char **argv) {
	int win1;

	//Inicializacion de GLUT 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA |GLUT_DEPTH| GLUT_DOUBLE);

	//Ventana 
	glutInitWindowSize(500,500);
	glutInitWindowPosition(150, 50);
	win1 = glutCreateWindow("GRAFICADORA XYZ");
	glutDisplayFunc(mostrar);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}