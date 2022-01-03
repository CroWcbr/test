#ifndef CUBE_RUBIK_HPP
# define CUBE_RUBIK_HPP

# include "init.hpp"
# include "Cell.hpp"
# include "Cube.hpp"

class Rubik
{
private:
	Cell * const	_cube	=	new Cell[6 * N * N + 1];
	Cell * const	_front	=	_cube + 0 * N * N;
	Cell * const	_left	=	_cube + 1 * N * N;
	Cell * const	_right	=	_cube + 2 * N * N;
	Cell * const	_back	=	_cube + 3 * N * N;
	Cell * const	_up		=	_cube + 4 * N * N;
	Cell * const	_down	=	_cube + 5 * N * N;
	double 			_rotate_y; 
	double 			_rotate_x;
	double 			_scale_z;
	int				_scale_count;	
	Cube			part_rubik[N][N][N];
	void	init_rubik();
//Rubic
public:
	void	draw();

//Rubik_simple
public:
	Rubik();
	~Rubik();
	double	getRotate_y( void) const;
	double	getRotate_x( void) const;
	double	getScale_z( void) const;	
	void	setRotate_y( double y );
	void	setRotate_x( double x );
	void	setScale_z( double z );
	void	print_rubik();

//Rubik_move
public:
	void	choose_move(std::string cmd);
private:
	void	x_clockwise(int index);
	void	x_counter_clockwise(int index);
	void	y_clockwise(int index);
	void	y_counter_clockwise(int index);
	void	z_clockwise(int index);
	void	z_counter_clockwise(int index);
	void	face_clockwise(Cell *face);
	void	move_F(Cell *face);
	void	move_R(Cell *face);
	void	move_L(Cell *face);
	void	move_U(Cell *face);
	void	move_D(Cell *face);
	void	move_B(Cell *face);
	void	face_counter_clockwise(Cell *face);
};

#endif
