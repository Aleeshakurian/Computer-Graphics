#include<GL/glut.h>
void boundfill(float,float,float[],float[]);
float fill[3]={0.0,0.0,1.0},old[3]={0.0,1.0,0.0};
void display()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(old);
	glBegin(GL_LINE_LOOP);
	glVertex2i(100,150);
	glVertex2i(400,150);
	glVertex2i(400,350);
	glVertex2i(100,350);
	glEnd();
	boundfill(200.5,160.3,fill,old);
	glFlush();
}
void boundfill(float x,float y,float fill[3],float old[3])
{
	float pix[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pix);
	if((!(pix[0]==old[0]&&pix[1]==old[1]&&pix[2]==old[2]))&&(!(pix[0]==fill[0]&&pix[1]==fill[1]&&pix[2]==fill[2])))
	{
		glBegin(GL_POINTS);
		glColor3fv(fill);
		glVertex2f(x,y);
		glEnd();
		glFlush();
		boundfill(x-1,y,fill,old);
		boundfill(x+1,y,fill,old);
		boundfill(x,y+1,fill,old);
		boundfill(x,y-1,fill,old);
	}
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Boundary_Fill");
	glutDisplayFunc(display);
	glOrtho(0.0,640.0,0.0,480.0,1.0,-1.0);
	glutMainLoop();
	return 0;
}
