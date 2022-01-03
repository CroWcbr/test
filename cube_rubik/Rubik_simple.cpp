#include "Rubik.hpp"

Rubik::Rubik()
{
	init_rubik();
}

Rubik::~Rubik()
{
}

double	Rubik::getRotate_y( void ) const
{
	return _rotate_y;
}

double	Rubik::getRotate_x( void ) const
{
	return _rotate_x;
}

double	Rubik::getScale_z( void ) const
{
	return _scale_z;
}

void	Rubik::setRotate_y( double y )
{
	_rotate_y += y;
}

void	Rubik::setRotate_x( double x )
{
	_rotate_x += x;
}

void	Rubik::setScale_z( double z )
{
	std::cout << "scale:\t" << _scale_count << "\tz\t" << z << std::endl;
	if ((_scale_count > - 10 && _scale_count < 5) || \
		(_scale_count > - 10 && z < 0) || \
		(_scale_count < 5 && z > 0))
	{	
		if (z > 0)
			_scale_count++;
		else
			_scale_count--;
		_scale_z += z;
	}
}

void	Rubik::print_rubik()
{
	for (int c = 0; c < N * 4; c++)
	{
		for (int r = 0; r < N * 4; r++)	
		{
			if ( c < N)
			{
				if (r < N)
					std::cout << " " << " ";		
				else if (r < N * 2)
					std::cout << (_up + c % N * N + r % N)->_colour << " ";
				else
					break ;
			}
			else if ( c < 2 * N)
			{
				if (r < N)
					std::cout << (_left + c % N * N + r % N)->_colour << " ";
				else if (r < 2 * N)
					std::cout << (_front + c % N * N + r % N)->_colour << " ";				
				else if (r < 3 * N)
					std::cout << (_right + c % N * N + r % N)->_colour << " ";
				else if (r < 4 * N)
					std::cout << (_back + c % N * N + r % N)->_colour << " ";							
			}
			else if ( c < 3 * N)
			{
				if (r < N)
					std::cout << " " << " ";		
				else if (r < N * 2)
					std::cout << (_down + c % N * N + r % N)->_colour << " ";
				else
					break ;
			}
			else if ( c < 4 * N)
			{
				if (r < N)
					std::cout << " " << " ";		
				else if (r < N * 2)
					std::cout << (_back + N * N - 1 - c % N * N - r % N)->_colour << " ";
				else
					break ;
			}
		}
		std::cout << std::endl;
	}
}