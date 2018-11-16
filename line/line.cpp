#include<GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glBegin(GL_LINES);
        glColor3f(0.0,1.0,0.0);
	glVertex2i(60,60);
	glVertex2i(20,20);
	glColor3f(0.0,0.0,1.0);
	glEnd();
	glFlush();
}
main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Line Plotting");
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(-100,100,-100,100,-10,10);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

