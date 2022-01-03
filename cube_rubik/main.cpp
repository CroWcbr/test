#include "init.hpp"
#include "Rubik.hpp"

Rubik rubik;

void renderScene()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(0, 0, rubik.getScale_z());
		glRotatef( rubik.getRotate_x(), 1.0, 0.0, 0.0 );
		glRotatef( rubik.getRotate_y(), 0.0, 1.0, 0.0 );
		rubik.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void reshapeScene(int w, int h)
{
	if (h == 0)
		h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(60, w / h, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void specialKeys( int key, int x, int y ) 
{
	if (key == GLUT_KEY_RIGHT)
		rubik.setRotate_y( 5 );
	else if (key == GLUT_KEY_LEFT)
		rubik.setRotate_y( -5 );
	else if (key == GLUT_KEY_UP)
		rubik.setRotate_x( 5 );
	else if (key == GLUT_KEY_DOWN)
		rubik.setRotate_x( -5 );
	else if (key == GLUT_KEY_HOME)
		rubik.setScale_z( -0.1 );
	else if (key == GLUT_KEY_END)
		rubik.setScale_z( 0.1 );
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{

	if (key == 27)
		exit(0);
	std::string cmd[] {"F", "R", "L", "U", "D", "B"};
//	std::string cmd_hatch[] {"F'", "R'", "L'", "U'", "D'", "B'"};
	if (key >= '1' && key <= '6')
	{
		rubik.choose_move(cmd[key - '0' - 1]);
		std::cout << std::endl;
		rubik.print_rubik();		
	}	
}

void init_cubik()
{
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(1, 1);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Cube-Rubik");
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(orLEFT, orRIGHT, orBOTTOM, orTOP, orNEAR, orFAR);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init_cubik();

	rubik.print_rubik();
	
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);
	glutIdleFunc(renderScene);
	
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keys);

	glutMainLoop();
	return 0;
}
