#include <GL/glut.h>
#include <math.h>
//#include "glm.h"
//#include "imageloader.h"


static int shoulder = 0, shoulder2 = 0, relbow = 0, lelbow = 0 , fingerBase = 0, fingerUp = 0, rhip = 0, rhip2 = 0, rknee = 0, lknee = 0, lhip = 0, lhip2 = 0 ;
double eye[] = { 0, 0, -20 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };


void init(void)
{
    glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
}

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}

void Left()
{
	double ax[] = { 0, 1, 0 };  
	rotatePoint(ax,(double) 5/180*3.14,eye);
}

void Right()
{
	double ax[] = { 0, 1, 0 };  
	rotatePoint(ax,(double)-5/180*3.14,eye);
}

void Up()
{
	double ax[] = { 1, 0, 0 };  
	rotatePoint(ax,(double)5/180*3.14,eye);
}

void Down()
{
	double ax[] = { 1, 0, 0 };  
	rotatePoint(ax,(double)-5/180*3.14,eye);
}

void moveForward()
{
	eye[2]=eye[2]+1;
	gluLookAt(eye[0],eye[1],eye[2],center[0],center[1],center[2],up[0],up[1],up[2]);
}

void moveBack()
{
	eye[2]=eye[2]-1;
	gluLookAt(eye[0],eye[1],eye[2],center[0],center[1],center[2],up[0],up[1],up[2]);
}

void draw_head_trunk(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
   	glPushMatrix();
	glTranslatef(0,4,0);
	glScalef(1,1.5,1);
	glutWireSphere(1,10,10);
	glPopMatrix();
	//glPushMatrix();             why ???
	glScalef(1.5,2,1);
	//glTranslatef(0,1,0);
	glutWireCube(2.5);
	
	
}

void draw_right_arm(void)
{
	// Draw from shoulder
	glPushMatrix();
	glTranslatef(-1.5,1,0);
	glRotatef(shoulder,0,0,1);
	glTranslatef(-1,0,0);
	glPushMatrix();
	glScalef(1.5,0.3,1);
	glutWireCube(1);
	glPopMatrix();
	
	// Draw from elbow
	glTranslatef(-0.75,0,0);
	glRotatef(relbow,0,0,1);
	glTranslatef(-0.75,0,0);
	glPushMatrix();
	glScalef(1.5,0.3,1);
	glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	
	//draw finger 1.1
	glTranslatef(-0.65,0.1,-0.1);
	glRotatef(fingerBase,0,0,1);
	glTranslatef(-0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 1.2
	glTranslatef(-0.2,0,0);
	glRotatef(fingerUp,0,0,1);
	glTranslatef(-0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 2.1
	glPopMatrix();
	glTranslatef(-0.65,0.1,0.05);
	glRotatef(fingerBase,0,0,1);
	glTranslatef(-0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 2.2
	glTranslatef(-0.2,0,0);
	glRotatef(fingerUp,0,0,1);
	glTranslatef(-0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();
	
	//draw finger 3.1
	glPopMatrix();
	glTranslatef(-0.65,0.1,0.2);
	glRotatef(fingerBase,0,0,1);
	glTranslatef(-0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 3.2
	glTranslatef(-0.2,0,0);
	glRotatef(fingerUp,0,0,1);
	glTranslatef(-0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 4.1
	glPopMatrix();
	glTranslatef(-0.65,0.1,0.35);
	glRotatef(fingerBase,0,0,1);
	glTranslatef(-0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 4.2
	glTranslatef(-0.2,0,0);
	glRotatef(fingerUp,0,0,1);
	glTranslatef(-0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 5.1
	glPopMatrix();
	glTranslatef(-0.65,-0.1,0.35);
	glRotatef(-fingerBase,0,0,1);
	glTranslatef(-0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 5.2
	glTranslatef(-0.2,0,0);
	glRotatef(-fingerUp,0,0,1);
	glTranslatef(-0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();


	glPopMatrix();
	
}


void draw_left_arm(void)
{
	//draw from shoulder
	glPushMatrix();
	glTranslatef(1.5,1,0);
	glRotatef(shoulder2,0,0,1);
	glTranslatef(1,0,0);
	glPushMatrix();
	glScalef(1.5,0.3,1);
	glutWireCube(1);
	glPopMatrix();

	//draw from elbow
	glTranslatef(0.75,0,0);
	glRotatef(lelbow,0,0,1);
	glTranslatef(0.75,0,0);
	glPushMatrix();
	glScalef(1.5,0.3,1);
	glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	
	//draw finger 1.1
	glTranslatef(0.65,0.1,-0.1);
	glRotatef(-fingerBase,0,0,1);
	glTranslatef(0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 1.2
	glTranslatef(0.2,0,0);
	glRotatef(-fingerUp,0,0,1);
	glTranslatef(0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 2.1
	glPopMatrix();
	glTranslatef(0.65,0.1,0.05);
	glRotatef(-fingerBase,0,0,1);
	glTranslatef(0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 2.2
	glTranslatef(0.2,0,0);
	glRotatef(-fingerUp,0,0,1);
	glTranslatef(0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 3.1
	glPopMatrix();
	glTranslatef(0.65,0.1,0.2);
	glRotatef(-fingerBase,0,0,1);
	glTranslatef(0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 3.2
	glTranslatef(0.2,0,0);
	glRotatef(-fingerUp,0,0,1);
	glTranslatef(0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 4.1
	glPopMatrix();
	glTranslatef(0.65,0.1,0.35);
	glRotatef(-fingerBase,0,0,1);
	glTranslatef(0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 4.2
	glTranslatef(0.2,0,0);
	glRotatef(-fingerUp,0,0,1);
	glTranslatef(0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	//draw finger 5.1
	glPopMatrix();
	glTranslatef(0.65,-0.1,0.35);
	glRotatef(fingerBase,0,0,1);
	glTranslatef(0.25,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(1);
	glPopMatrix();
	//draw finger 5.2
	glTranslatef(0.2,0,0);
	glRotatef(fingerUp,0,0,1);
	glTranslatef(0.1,0,0);
	glPushMatrix();
	glScalef(0.3,0.1,0.1);
	glutWireCube(0.8);
	glPopMatrix();

	glPopMatrix();
}

void draw_righ_leg(void)
{
	glPushMatrix();
	glTranslatef(1,-1,0);
	glRotatef(rhip,1,0,0);
	glTranslatef(0,-1,0);
	glPushMatrix();
	glScalef(0.5,1.5,1);
	glutWireCube(1);
	glPopMatrix();
	
	glTranslatef(0,-0.75,0);
	glRotatef(rknee,1,0,0);
	glTranslatef(0,-0.75,0);
	glPushMatrix();
	glScalef(0.5,1.5,1);
	glutWireCube(1);
	glPopMatrix();

	glTranslatef(0,-1,0); 
	glPushMatrix();
	glScalef(1,0.5,2.5);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

}

void draw_left_leg(void)
{
	glPushMatrix();
	glTranslatef(-1,-1,0);
	glRotatef(lhip,1,0,0);
	glTranslatef(0,-1,0);
	glPushMatrix();
	glScalef(0.5,1.5,1);
	glutWireCube(1);
	glPopMatrix();
	
	glTranslatef(0,-0.75,0);
	glRotatef(lknee,1,0,0);
	glTranslatef(0,-0.75,0);
	glPushMatrix();
	glScalef(0.5,1.5,1);
	glutWireCube(1);
	glPopMatrix();

	glTranslatef(0,-1,0); 
	glPushMatrix();
	glScalef(1,0.5,2.5);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT );
   	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	draw_head_trunk();
	draw_righ_leg();
	draw_left_leg();		
	draw_right_arm();
	draw_left_arm();

	glutSwapBuffers();
	//floor
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
        //glBindTexture(GL_TEXTURE_2D, _textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      glBegin(GL_QUADS);
       
		glNormal3f(0.0,-1.0,0.0);
		glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5,-0.25,2);
        glTexCoord2f(5.0f,  0.0f);
        glVertex3f(0.5,-0.25,2);
        glTexCoord2f(5.0f,  20.0f);							
        glVertex3f(0.5,-0.25,-2);
        glTexCoord2f(0.0f, 20.0f);
        glVertex3f(-0.5,-0.25,-2);
        glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

    glPushMatrix();
    	glTranslatef(0.0, 0.015, -1.6);
    	//glRotatef(VRot,0,1,0);
    	
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: Left(); break;
	case GLUT_KEY_RIGHT: Right(); break;
	case GLUT_KEY_UP:    Up(); break;
	case GLUT_KEY_DOWN:  Down(); break;
	}

	glutPostRedisplay();
}

/* I tried to limit my angles in switch case using  this function 
but it does not work properly as it does not diffrentiate between different cases, I do not know why
int limit (int angle, int max , char sign){
	if (sign == '+'){
		if (angle+5 == 0) {angle = (angle + 5) % max; glutPostRedisplay();}
		if ( (angle + 5) % max == 0){ return 0;}
		angle = (angle + 5) % max ;
		glutPostRedisplay();
		return 0;}
	else if (sign == '-'){
		if (angle-5 == 0) {angle = (angle - 5) % max; glutPostRedisplay();}
		if ( (angle - 5) % -max == 0){ return 0;}
		angle = (angle - 5) % max ;
		glutPostRedisplay();
		return 0;}
	return 0 ;
}
*/

void goTimer (int value ){
	if (value == 0)
    {
        shoulder = (shoulder + 1) ;
		shoulder2 = (shoulder2 + 1) ;
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 0);
		if ((shoulder2 + 1) > 100) {
			glutTimerFunc(0, goTimer, 1);
		}
    }
    else if (value == 1)
    {
        shoulder = (shoulder - 1);
		shoulder2 = (shoulder2 - 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 1);
		if ((shoulder2 - 1) < -100 ) {
			glutTimerFunc(0, goTimer, 0);
		}
    }
	else if (value == 2)
    {
        lhip = (lhip - 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 2);
		if ((lhip - 1) < -100 ) {
			glutTimerFunc(0, goTimer, 5);
		}
    }
	else if (value == 3)
    {
        lknee = (lknee - 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 3);
		if ((lknee - 1) < -120 ) {
			glutTimerFunc(0, goTimer, 4);
		}
    }
	else if (value == 4)
    {
        lknee = (lknee + 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 4);
		if ((lknee + 1) > 0 ) {
			glutTimerFunc(0, goTimer, 3);
		}
    }
	else if (value == 5)
    {
        lhip = (lhip + 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 5);
		if ((lhip + 1) > 100 ) {
			glutTimerFunc(0,goTimer,2);
		}
    }
}

void ta4gee3 (void){
	goTimer(0) ;
}

void tamareen_elsba7(void){
	goTimer(2) ;	
	goTimer(3) ;
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1' :
		ta4gee3();
		break ;
	case '2' :
		tamareen_elsba7();
		break ;
	case 's':
		if (shoulder+5 == 0) {shoulder = (shoulder + 5) % 100; glutPostRedisplay();}
		if ( (shoulder + 5) % 100 == 0){ break;}
		shoulder = (shoulder + 5) % 100 ;
		glutPostRedisplay();
		break;
	case 'S':
		if (shoulder-5 == 0) {shoulder = (shoulder - 5) % 100; glutPostRedisplay();}
		if ( (shoulder - 5 ) % -100 == 0){ break;}
		shoulder = (shoulder - 5) % 100 ;
		glutPostRedisplay();
		break;
	case 'a':
		if (shoulder2+5 == 0) {shoulder2 = (shoulder2 + 5) % 100; glutPostRedisplay();}
		if ( (shoulder2 + 5) % 100 == 0){ break;}
		shoulder2 = (shoulder2 + 5) % 100 ;
		glutPostRedisplay();
		break;
	case 'A':
		if (shoulder2-5 == 0) {shoulder2 = (shoulder2 - 5) % 100; glutPostRedisplay();}
		if ( (shoulder2 - 5 ) % -100 == 0){ break;}
		shoulder2 = (shoulder2 - 5) % 100 ;
		glutPostRedisplay();
		break;
	case 'd':
		if (relbow+5 == 0) {relbow = (relbow + 5) % 160; glutPostRedisplay();}
		if ( (relbow + 5 ) % 160 == 0){ break;}
		relbow = (relbow + 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'D':
		if (relbow-5 == 0) {relbow = (relbow - 5) % 160; glutPostRedisplay();}
		if ( (relbow - 5 ) % 160 == 0){ break;}
		relbow = (relbow - 5) % 160 ;
		glutPostRedisplay();
		break;
		case 'c':
		if (lelbow+5 == 0) {lelbow = (lelbow + 5) % 160; glutPostRedisplay();}
		if ( (lelbow + 5 ) % 160 == 0){ break;}
		lelbow = (lelbow + 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'C':
		if (lelbow-5 == 0) {lelbow = (lelbow - 5) % 160; glutPostRedisplay();}
		if ( (lelbow - 5 ) % 160 == 0){ break;}
		lelbow = (lelbow - 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'z':
		if ( (fingerBase + 5 ) % 90 == 0){ break;}
		fingerBase = (fingerBase + 5) % 90 ;
		glutPostRedisplay();
		break;
	case 'Z':
		if (fingerBase == 0) {break; glutPostRedisplay();}
		if ( (fingerBase - 5 ) % 90 == 0){ break;}
		fingerBase = (fingerBase - 5) % 90 ;
		glutPostRedisplay();
		break;
	case 'x':
		if ( (fingerUp + 5 ) % 90 == 0){ break;}
		fingerUp = (fingerUp + 5) % 90 ;
		glutPostRedisplay();
		break;
	case 'X':
		if (fingerUp == 0) {break; glutPostRedisplay();}
		if ( (fingerUp - 5 ) % 90 == 0){ break;}
		fingerUp = (fingerUp - 5) % 90 ;
		glutPostRedisplay();
		break;
	case 'q':
		if (rhip+5 == 0) {rhip = (rhip + 5) % 160; glutPostRedisplay();}
		if ( (rhip + 5 ) % 160 == 0){ break;}
		rhip = (rhip + 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'Q':
		if (rhip-5 == 0) {rhip = (rhip - 5) % 160; glutPostRedisplay();}
		if ( (rhip - 5 ) % 160 == 0){ break;}
		rhip = (rhip - 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'w':
		if (rknee +5 > 0){break;}
		if (rknee+5 == 0) {rknee = (rknee + 5) % 160; glutPostRedisplay();}
		if ( (rknee + 5 ) % 160 == 0){ break;}
		rknee = (rknee + 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'W':
		if (rknee-5 == 0) {rknee = (rknee - 5) % 160; glutPostRedisplay();}
		if ( (rknee - 5 ) % 160 == 0){ break;}
		rknee = (rknee - 5) % 160 ;
		glutPostRedisplay();
		break;
	/*case 'e':
		rhip2 = (rhip2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		rhip2 = (rhip2 - 5) % 360;
		glutPostRedisplay();
		break;*/
	case 'r':
		if (lhip+5 == 0) {lhip = (lhip + 5) % 160; glutPostRedisplay();}
		if ( (lhip + 5 ) % 160 == 0){ break;}
		lhip = (lhip + 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'R':
		if (lhip-5 == 0) {lhip = (lhip - 5) % 160; glutPostRedisplay();}
		if ( (lhip - 5 ) % 160 == 0){ break;}
		lhip = (lhip - 5) % 160 ;
		glutPostRedisplay();
		break;
	case 't':
		if (lknee +5 > 0){break;}
		if (lknee+5 == 0) {lknee = (lknee + 5) % 160; glutPostRedisplay();}
		if ( (lknee + 5 ) % 160 == 0){ break;}
		lknee = (lknee + 5) % 160 ;
		glutPostRedisplay();
		break;
	case 'T':
		if (lknee-5 == 0) {lknee = (lknee - 5) % 160; glutPostRedisplay();}
		if ( (lknee - 5 ) % 160 == 0){ break;}
		lknee = (lknee - 5) % 160 ;
		glutPostRedisplay();
		break;
	/*case 'y':
		lhip2 = (lhip2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		lhip2 = (lhip2 - 5) % 360;
		glutPostRedisplay();
		break;*/

	case 'F':
		moveForward(); 
		glutPostRedisplay(); 
		break;
	case 'B':
		moveBack(); 
		glutPostRedisplay(); 
		break;

	default:
		break;
	}
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("body");
	init();
	glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}







