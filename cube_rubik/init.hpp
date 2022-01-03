#ifndef INIT_HPP
# define INIT_HPP

# include <iostream>
# include <GL/glut.h>
# include <string.h>

# define	N			3
# define	WIDTH		800
# define	HEIGHT		800

//glOrtho
# define	orLEFT		-1
# define	orRIGHT		1
# define	orBOTTOM	-1
# define	orTOP		1
# define	orNEAR		-2
# define	orFAR		1

//side of glOrtho
# define	SIDE_RUBIK	1.0/N
# define	SIDE_CUBE	0.95/N

//colour for rubik
# define	BLUE		0.0,0.0,1.0
# define	WHITE		1.0,1.0,1.0
# define	RED			1.0,0.0,0.0
# define	GREEN		0.0,1.0,0.0
# define	YELLOW		1.0,1.0,0.0
# define	ORANGE		1.0,0.5,0.0
# define	BLACK		0.0,0.0,0.0
# define	GREY		0.5,0.5,0.5

#endif
