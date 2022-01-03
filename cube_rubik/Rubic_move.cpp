#include "Rubik.hpp"

void	Rubik::x_clockwise(int index)
{
	int	tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = _front[i * N + index]._colour;
		_front[i * N + index]._colour = _down[i * N + index]._colour;
		_down[i * N + index]._colour = _back[N * N - 1 - i * N - index]._colour;
		_back[N * N - 1 - i * N - index]._colour = _up[i * N + index]._colour;
		_up[i * N + index]._colour = tmp;
	}
}

void	Rubik::x_counter_clockwise(int index)
{
	int	tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = _front[i * N + index]._colour;
		_front[i * N + index]._colour = _up[i * N + index]._colour;
		_up[i * N + index]._colour = _back[N * N - 1 - i * N - index]._colour;
		_back[N * N - 1 - i * N - index]._colour = _down[i * N + index]._colour;
		_down[i * N + index]._colour = tmp;
	}
}

void	Rubik::y_clockwise(int index)
{
	int	tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = _front[i + index * N]._colour;
		_front[i + index * N]._colour = _right[i + index * N]._colour;
		_right[i + index * N]._colour = _back[i + index * N]._colour;
		_back[i + index * N]._colour = _left[i + index * N]._colour;
		_left[i + index * N]._colour = tmp;
	}
}

void	Rubik::y_counter_clockwise(int index)
{
	int	tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = _front[i + index * N]._colour;
		_front[i + index * N]._colour = _left[i + index * N]._colour;
		_left[i + index * N]._colour = _back[i + index * N]._colour;
		_back[i + index * N]._colour = _right[i + index * N]._colour;
		_right[i + index * N]._colour = tmp;
	}
}

void	Rubik::z_clockwise(int index)
{
	int	tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = _up[N * N - N + i - N * index]._colour;

		_up[N * N - N + i - N * index]._colour = _left[N * N - 1 - i * N  - index]._colour;
		_left[N * N - 1 - i * N  - index]._colour = _down[N - 1 - i + N * index]._colour;
		_down[N - 1 - i + N * index]._colour = _right[i * N + index]._colour;
		_right[i * N + index]._colour = tmp;
	}
}

void	Rubik::z_counter_clockwise(int index) 
{
	int	tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = _up[N * N - N + i - N * index]._colour;

		_up[N * N - N + i - N * index]._colour = _right[i * N + index]._colour;
		_right[i * N + index]._colour = _down[N - 1 - i + N * index]._colour;
		_down[N - 1 - i + N * index]._colour = _left[N * N - 1 - i * N  - index]._colour;
		_left[N * N - 1 - i * N  - index]._colour = tmp;
	}
}

void	Rubik::face_clockwise(Cell *face) 
{
	int tmp[N * N];
	for (int i = 0; i < N * N; i++)
		tmp[i] = face[i]._colour;
 	for (int c = 0; c < N; c++)
		for (int r = 0; r < N; r++)
	 		face[c * N + r]._colour = tmp[N * N - N + c - r * N];
}

void	Rubik::face_counter_clockwise(Cell *face) 
{
	int tmp[N * N];
	for (int i = 0; i < N * N; i++)
		tmp[i] = face[i]._colour;
 	for (int c = 0; c < N; c++)
		for (int r = 0; r < N; r++)
	 		face[c * N + r]._colour = tmp[N - 1 - c + N * r];
}

void	Rubik::move_F(Cell *face)
{
		z_clockwise(0);
		face_clockwise(face);
}

void	Rubik::move_R(Cell *face)
{
		x_clockwise(N - 1);
		face_clockwise(face);
}

void	Rubik::move_L(Cell *face)
{
		x_counter_clockwise(0);
		face_clockwise(face);
}

void	Rubik::move_U(Cell *face)
{
		y_clockwise(0);
		face_clockwise(face);
}

void	Rubik::move_D(Cell *face)
{
		y_counter_clockwise(N - 1);
		face_clockwise(face);
}

void	Rubik::move_B(Cell *face)
{
		z_counter_clockwise(N - 1);
		face_clockwise(face);
}

void	Rubik::choose_move(std::string cmd)
{
	if (cmd == "F")
		move_F(_front);
	else if (cmd == "R")
		move_R(_right);
	else if (cmd == "L")
		move_L(_left);
	else if (cmd == "U")
		move_U(_up);	
	else if (cmd == "D")
		move_D(_down);	
	else if (cmd == "B")
		move_B(_back);
}
