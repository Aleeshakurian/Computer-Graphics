#include<GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(50,50);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(20,20);
	glColor3f(0.0,0.0,0.0);
	glEnd();
	glFlush();
}
main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Point Plotting");
	glClearColor(0.5,0.0,0.5,0.0);
	glOrtho(-100,100,-100,100,-10,10);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
