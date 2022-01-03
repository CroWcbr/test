#include "Cube.hpp"

Cube::Cube()
{
}

Cube::~Cube()
{
}

void Cube::initColor(int x, int y, int z, Cell * const _cube)
{
//	std::cout <<  "in Cube\taddr\t"<< &_cube[0] << "\t" << _cube << std::endl;
//	std::cout <<  "in Cube\taddr\t"<< &_cube[N * N * 6 + 1] << "\t" << &_cube[N * N * 6 + 1] << std::endl;	
	_colour[0] = _colour[1]= _colour[2] = _colour[3] = _colour[4] = _colour[5] = &_cube[6 * N * N];
	if (z == 0)
		_colour[0] = &_cube[N * N - N - N * y + x + 0 * N * N];		//front
	if (z == N - 1)	
		_colour[3] = &_cube[N * N - 1 - y * N - x + 3 * N * N];		//back
	if (x == 0)
		_colour[1] = &_cube[N * N - 1 - z - y * N + 1 * N * N];		//left
	if (x == N - 1)
		_colour[2] = &_cube[N * N - 1 - x - y * N + z + 2 * N * N];	//right
	if (y == 0)
		_colour[4] = &_cube[N * z + x + 5 * N * N];					//up
	if (y == N - 1)
		_colour[5] = &_cube[N * N - N - z * N + x + 4 * N * N];		//down
}

void Cube::draw(float x, float y, float z)
{
	glPushMatrix();
		glTranslated(x, y, -z);
		draw();
	glPopMatrix();
}

void Cube::draw_colour(int i)
{
	switch (i)
	{
		case 0: // front
			return (glColor3f(RED));
		case 1:	// left
			return (glColor3f(GREEN));
		case 2:	// right
			return (glColor3f(BLUE));
		case 3:	// back
			return (glColor3f(ORANGE));
		case 4:	// up
			return (glColor3f(WHITE));
		case 5:	// down
			return (glColor3f(YELLOW));
		default:// not seen
			return (glColor3f(GREY));
	}
}

void Cube::print_addr(int x, int y, int z)
{
	std::cout << "x\t" << x << "\ty\t" << y << "\tz\t" << z 
			<< "\taddr0\t" << *(_colour + 0) << " - " <<  (*(_colour + 0))->_colour 
			<< "\taddr1\t" << *(_colour + 1) << " - " <<  (*(_colour + 1))->_colour 
			<< "\taddr2\t" << *(_colour + 2) << " - " <<  (*(_colour + 2))->_colour 	
			<< "\taddr3\t" << *(_colour + 3) << " - " <<  (*(_colour + 3))->_colour
			<< "\taddr4\t" << *(_colour + 4) << " - " <<  (*(_colour + 4))->_colour	
			<< "\taddr5\t" << *(_colour + 5) << " - " <<  (*(_colour + 5))->_colour
			<< std::endl;
}

void	Cube::draw()
{
	glBegin(GL_QUADS);
	// front
		draw_colour((*(_colour + 0))->_colour);
		glVertex3f(0, 0, 0);
		glVertex3f(SIDE_CUBE, 0, 0);   
		glVertex3f(SIDE_CUBE, SIDE_CUBE, 0);  
		glVertex3f(0, SIDE_CUBE, 0);
	// left
		draw_colour((*(_colour + 1))->_colour);
		glVertex3f(0, 0, 0);
		glVertex3f(0, SIDE_CUBE, 0);
		glVertex3f(0, SIDE_CUBE, -SIDE_CUBE);
		glVertex3f(0, 0, -SIDE_CUBE);
	// right
		draw_colour((*(_colour + 2))->_colour);
		glVertex3f(SIDE_CUBE, 0, 0);   
		glVertex3f(SIDE_CUBE, SIDE_CUBE, 0);    
		glVertex3f(SIDE_CUBE, SIDE_CUBE, -SIDE_CUBE);   
		glVertex3f(SIDE_CUBE, 0, -SIDE_CUBE);
	// back
		draw_colour((*(_colour + 3))->_colour);
		glVertex3f(0, 0, -SIDE_CUBE);
		glVertex3f(0, SIDE_CUBE, -SIDE_CUBE);          
		glVertex3f(SIDE_CUBE, SIDE_CUBE, -SIDE_CUBE);          
		glVertex3f(SIDE_CUBE, 0, -SIDE_CUBE);   
	// up
		draw_colour((*(_colour + 5))->_colour);
		glVertex3f(0, SIDE_CUBE, 0);   
		glVertex3f(0, SIDE_CUBE, -SIDE_CUBE);      
		glVertex3f(SIDE_CUBE, SIDE_CUBE, -SIDE_CUBE);         
		glVertex3f(SIDE_CUBE, SIDE_CUBE, 0);       
	// down
		draw_colour((*(_colour + 4))->_colour);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -SIDE_CUBE);
		glVertex3f(SIDE_CUBE, 0, -SIDE_CUBE);   
		glVertex3f(SIDE_CUBE, 0, 0);
	glEnd();
}

// void	Cube::draw()
// {
// 	float a = _size;
// 	float arr[]={-a,-a,a,	a,-a,a,		a,a,a, 		-a,a,a,
// 				a,-a,-a,	-a,-a,-a,	-a,a,-a, 	a,a,-a,
// 				-a,-a,-a,	-a,-a,a,	-a,a,a,		-a,a,-a,
// 				a,-a,a,		a,-a,-a,	a,a,-a, 	a,a,a,
// 				-a,-a,a,	a,-a,a,		a,-a,-a, 	-a,-a,-a,
// 				-a,a,a,		a,a,a,		a,a,-a,		-a,a,-a};
// 	float col[]={
// 				1,0,0,		1,0,0,		1,0,0,		1,0,0,
// 				0,0,1,		0,0,1,		0,0,1, 		0,0,1,
// 				1,1,0,		1,1,0,		1,1,0,		1,1,0,
// 				0,1,1,		0,1,1,		0,1,1, 		0,1,1,
// 				1,0,1,		1,0,1,		1,0,1, 		1,0,1,
// 				1,0.5,0.5,	1,0.5,0.5,	1,0.5,0.5,	1,0.5,0.5};
// 	glVertexPointer(3,GL_FLOAT, 0, &arr);
// 	glEnableClientState(GL_VERTEX_ARRAY);
// 		glColorPointer(3, GL_FLOAT, 0, &col);
// 	glEnableClientState(GL_COLOR_ARRAY);
// 		glDrawArrays(GL_QUADS,0,24);
// 	glDisableClientState(GL_COLOR_ARRAY);
// 	glDisableClientState(GL_VERTEX_ARRAY);
// }
