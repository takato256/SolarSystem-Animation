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
	// ‘¾—z
	glColor3d(1.0, 0.8, 0.0);	// ‘¾—z‚ÌF
	glutWireSphere(0.7, 20, 16);

	// …¯
	glPushMatrix();
		glRotated((double)year*1.6, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(0.4*2, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(0.6, 0.5, 0.4); // …¯‚ÌF
		glutWireSphere(0.04, 10, 8);	// …¯‚Ì‘å‚«‚³
	glPopMatrix();

	// ‹à¯
	glPushMatrix();
		glRotated((double)year*1.2, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(0.7*2, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(1.0, 0.7, 0.2); // ‹à¯‚ÌF
		glutWireSphere(0.08, 10, 8);    // ‹à¯‚Ì‘å‚«‚³
	glPopMatrix();

	// ’n‹…
	glPushMatrix();
		glRotated((double)year, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(1.0*2, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(0.0, 0.0, 1.0);
		glColor3d(0.0, 0.4, 0.8); // ’n‹…‚ÌF
		glutWireSphere(0.1, 10, 8);    // ’n‹…‚Ì‘å‚«‚³
	glPopMatrix();

	// ‰Î¯
	glPushMatrix();
		glRotated((double)year*0.8, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(1.5*1.5, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(1.0, 0.0, 0.0);
		glColor3d(0.7, 0.3, 0.2); // ‰Î¯‚ÌF
		glutWireSphere(0.05, 10, 8);    // ‰Î¯‚Ì‘å‚«‚³
	glPopMatrix();

	// –Ø¯
	glPushMatrix();
		glRotated((double)year*0.4, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(5.2*0.6, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(0.8, 0.5, 0.2); // –Ø¯‚ÌF
		glutWireSphere(1.12/4, 10, 8);    /* planet */
	glPopMatrix();

	// “y¯
	glPushMatrix();
		// “y¯‚Ì‹…‘Ì
		glRotated((double)year * 0.3, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(9.5*0.4, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(0.9, 0.8, 0.6); // “y¯‚ÌF
		glutWireSphere(0.94 / 4, 10, 8);    // “y¯‚Ì‘å‚«‚³
		// “y¯‚Ì—Ö
		glColor3d(0.7, 0.7, 0.7); // —Ö‚ÌF
		
	glPopMatrix();

	// “V‰¤¯
	glPushMatrix();
		glRotated((double)year * 0.2, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(19.1 * 0.22, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(0.5, 0.7, 0.9); // “V‰¤¯‚ÌF
		glutWireSphere(0.39 / 3, 10, 8);    // “V‰¤¯‚Ì‘å‚«‚³
	glPopMatrix();

	// ŠC‰¤¯
	glPushMatrix();
		glRotated((double)year * 0.18, 0.0, 1.0, 0.0); // Œö“]‘¬“x y²’†S
		glTranslated(30 * 0.15, 0.0, 0.0);	// Œö“]”¼Œa x²’†S
		glRotated((double)day, 0.0, 1.0, 0.0);	// ©“]
		glColor3d(0.3, 0.5, 1.0); // ŠC‰¤¯‚ÌF
		glutWireSphere(0.38 / 3, 10, 8);    // ŠC‰¤¯‚Ì‘å‚«‚³
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
	gluLookAt(0.0, 7.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
