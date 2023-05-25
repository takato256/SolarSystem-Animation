/* p4-MovingPlanet.c
 * Animation for a solar system ( see p3-planet.c ) using by glutTimerFunc().
 */
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

int 	year = 0, day = 0;
int 	samplingTime = 50;

void myKeyboard(unsigned char key, int x, int y)
{
	if ( key == 27) exit (0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);

	glutWireSphere(1.0, 20, 16);	// ëæóz

	// êÖêØ
	glPushMatrix();
		glRotated((double)year*0.241/5, 0.0, 1.0, 0.0); // åˆì] yé≤íÜêS
		glTranslated(0.3871/4, 0.0, 0.0);	// åˆì]îºåa xé≤íÜêS
		glRotated((double)day, 0.0, 1.0, 0.0);	// é©ì]
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// ã‡êØ
	glPushMatrix();
		glRotated((double)year*0.615/5, 0.0, 1.0, 0.0);
		glTranslated(0.7233/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// ínãÖ
	glPushMatrix();
		glRotated((double)year/5, 0.0, 1.0, 0.0);
		glTranslated(1.0/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// âŒêØ
	glPushMatrix();
		glRotated((double)year*1.881/5, 0.0, 1.0, 0.0);
		glTranslated(1.5237/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// ñÿêØ
	glPushMatrix();
		glRotated((double)year*11.862/5, 0.0, 1.0, 0.0);
		glTranslated(5.2030/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// ìyêØ
	glPushMatrix();
		glRotated((double)year*29.459/5, 0.0, 1.0, 0.0);
		glTranslated(9.5388/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// ìVâ§êØ
	glPushMatrix();
		glRotated((double)year*84.023/5, 0.0, 1.0, 0.0);
		glTranslated(19.1914/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();

	// äCâ§êØ
	glPushMatrix();
		glRotated((double)year*164.772/5, 0.0, 1.0, 0.0);
		glTranslated(30.0611/4, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet */
	glPopMatrix();



	glutSwapBuffers();
}

void myInit(char *progname)
{
	int width = 1000, height = 1000;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(progname);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (double)width / (double)height, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void myTimer(int value)
{
	if (value==1)
	{
		glutTimerFunc(samplingTime,myTimer,1);
		year = (year+1);
		day  = (day+5);
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myInit(argv[0]);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(samplingTime, myTimer, 1);
	glutDisplayFunc(myDisplay); 
	glutMainLoop();
	return 0;
}
