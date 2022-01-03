#include "Rubik.hpp"

void	Rubik::init_rubik()
{
	_rotate_y = 20; 
	_rotate_x = 20;
	_scale_z = -2.5;
	_scale_count = 0;
	_cube[6 * N * N]._colour = -1;
	for (int col = 0; col < 6; col++)
		for (int c = 0; c < N; c++)
			for (int r = 0; r < N; r++)
			{
				_cube[col * N * N + c * N + r]._colour = col;
			}
//std::cout << "in Rubik first\taddr\t"<< &_cube[0] << "\t" << _cube << std::endl;			
//std::cout << "in Rubik last\taddr\t"<< &_cube[N * N * 6] << "\t" << _cube + N * N * 6 + 1 << std::endl;
//	for (int z = 0; z < N * N * 6 + 1; z++)
//		std::cout <<  z << "\t" << &_cube[z] << "\t" << _cube[z]._colour << std::endl;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			for (int z = 0; z < N; z++)
			{
				part_rubik[x][y][z].initColor(x, y, z, _cube);
//				part_rubik[x][y][z].print_addr(x, y, z);
			}
}

void	Rubik::draw()
{
//std::cout << "in Rubik first\taddr\t"<< &_cube[0] << "\t" << _cube << std::endl;			
//std::cout << "in Rubik last\taddr\t"<< &_cube[N * N * 6] << "\t" << _cube + N * N * 6 << std::endl;

	// for (int z = 0; z < N * N; z++)
	// 	std::cout <<  &_cube[z] << " " << _cube[z]._colour << "\t";
	// std::cout << std::endl;
	// for (int z = 0; z < N; z++)
	// 	for (int y = 0; y < N; y++)
	// 		for (int x = 0; x < N; x++)
	// 			CR[z][y][x].print_addr(z, y, x);

	glPushMatrix();
		glColor3f(0.25, 0.25, 0.25);
		glutSolidCube(SIDE_RUBIK * N * 0.85);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-SIDE_RUBIK * N / 2, \
				-SIDE_RUBIK * N / 2, \
				SIDE_RUBIK * N / 2);
	for (int z = 0; z < N; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				part_rubik[x][y][z].draw(float(x) * SIDE_RUBIK, \
								float(y) * SIDE_RUBIK, \
								float(z) * SIDE_RUBIK);
	glPopMatrix();
}
