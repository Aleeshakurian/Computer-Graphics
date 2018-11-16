#include<stdio.h>
#include<GL/glut.h>
void circle_plotting(float xx,float yy);
float r,xc,yc,x,y,p;
void circle_algorithm()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glPointSize(4.0);
	x=0;
	y=r;
	p=1-r;
	glBegin(GL_POINTS);
	circle_plotting(x,y);
	while(x<=y)
	{
		if(p<0)
		{
			x=x+1;
			p=p+(2*x)+1;
		}
		else
		{
			x=x+1;
			y=y-1;
			p=p+(2*(x-y))+1;
		}
		circle_plotting(x,y);
	}
	glEnd();
	glFlush();
}


void circle_plotting(float xx,float yy)
{
	glVertex2f(xc+xx,yc+yy);
	glVertex2f(xc-xx,yc-yy);
	glVertex2f(xc-xx,yc+yy);
	glVertex2f(xc+xx,yc-yy);
	glVertex2f(xc+yy,yc+xx);
	glVertex2f(xc-yy,yc+xx);
	glVertex2f(xc+yy,yc-xx);
	glVertex2f(xc-yy,yc-xx);
}
main(int argc,char **argv)
{
	printf("Enter radious :");
	scanf("%f",&r);
	printf("Enter center point xc and yc: ");
	scanf("%f%f",&xc,&yc);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow(" circle_Drawing");
	glClearColor(1.0,1.0,0.0,0.0);
	glOrtho(-100,100,-100,100,-10,10);
	glutDisplayFunc(circle_algorithm);
	glutMainLoop();
	return 0;
}
