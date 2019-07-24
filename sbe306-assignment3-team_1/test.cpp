#include <math.h>
#include <GL/glut.h>
#include "glm.h"
#include "imageloader.h"
//#include <glut.h>

struct model {
	GLuint tex;
	GLuint dlist;
};

struct model g_models[16];
GLfloat angle=0.01;


void loadModel(struct model *m, char * name)
{
	char texture_path[256];

	//load object
	GLMmodel* pmodel = NULL;

	m->dlist = glGenLists(1);
	glNewList(m->dlist,GL_COMPILE);

	pmodel = glmReadOBJ(name);
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);

	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL |GLM_TEXTURE);

	glEndList();

	// load texture
	m->tex=0;
	if(pmodel->nummaterials>=2)
		if(strlen(pmodel->materials[1].dif_name)) {
			Image *texture_bmp=new Image();
			sprintf(texture_path, "data/%s", pmodel->materials[1].dif_name); 
			if(ImageLoad(texture_path, texture_bmp)) {
				glGenTextures(1,&m->tex);

				glBindTexture(GL_TEXTURE_2D,m->tex);

				glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,texture_bmp->sizeX,texture_bmp->sizeY,0,GL_RGB,GL_UNSIGNED_BYTE,texture_bmp->data);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
			} 

		delete texture_bmp;
	}

	glmDelete(pmodel);
}


void init(){
	glEnable(GL_TEXTURE_2D);

	GLfloat light_specular[] = {1.0,1.0,1.0,1.0};
	GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
	GLfloat light_ambient[] = {0.0,0.0,0.0,1.0};
	GLfloat light_position[] = { -2.0, 2.0, 2.0, 1.0 };
	GLfloat light_model[] = { 0.2, 0.2, 0.2, 1.0 };

	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION,light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_model);


	glClearColor (0.2, 0.2, 0.2, 1.0);
	glShadeModel (GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	//blending - antialiasing
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	//glEnable(GL_BLEND);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);
	glLineWidth(2.0);


	//fog
	glEnable(GL_FOG);
	GLfloat fogColor[4] = {0.2,0.2,0.2,1.0};
	GLint fogMode = GL_LINEAR;
	glFogi(GL_FOG_MODE,fogMode);
	glFogfv(GL_FOG_COLOR,fogColor);
	glFogf(GL_FOG_DENSITY,0.15);
	glHint(GL_FOG_HINT,GL_NICEST);
	glFogf(GL_FOG_START,50.0);
	glFogf(GL_FOG_END,100.0);


///////////////////////////////////////////////////////
	
	loadModel(&g_models[0], "data/saturn.obj");

	loadModel(&g_models[1], "data/moon.obj");


//	exit(0);
}

void display(){
    glRotatef(angle,0,1,0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	for(int i=0; i<2; i++) {
		glBindTexture(GL_TEXTURE_2D, g_models[i].tex);
		glCallList(g_models[i].dlist);
		glTranslatef(2.0f, 0.0f, 0.0f);
	}
	glPopMatrix();
		
	glutSwapBuffers();
}

void reshape(int w , int h){
	GLfloat aspectRatio = (GLfloat) w/h;
	glViewport( 0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0,(GLfloat) w/(GLfloat) h,1.0,40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,5,0,0,0,0,1,0);
}

void animate(void){
	 glutPostRedisplay();
}
void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
	  case 's':
		  glutIdleFunc(animate);
		  glutPostRedisplay();
		  break;
	  case 'd':
		  glutIdleFunc(NULL);
		  glutPostRedisplay();
		  break;
	  case 27:
		  exit(0);
		  break;
	  default:
		  break;
	}
}

int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DEPTH|GLUT_DOUBLE | GLUT_RGB );

	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init();

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

