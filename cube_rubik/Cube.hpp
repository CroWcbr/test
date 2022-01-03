#ifndef CUBE_HPP
# define CUBE_HPP

# include "init.hpp"
# include "Cell.hpp"

class Cube
{
private:
	Cell *_colour[6];
	void draw();
	void draw_colour(int i);
public:
	Cube();
	~Cube();

void initColor(int i, int j, int k, Cell * const _cube);

	void draw(float x, float y, float z);

void print_addr(int z, int y, int x);
};

#endif
