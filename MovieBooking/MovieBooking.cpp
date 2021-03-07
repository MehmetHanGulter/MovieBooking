
#include <iostream>
#include <string>
#include "MovieBookingSystem.h"
using namespace std;

int main()
{
	MovieBookingSystem movie;
	movie.addMovie(123, 1);
	movie.addMovie(124, 1);
	movie.addMovie(125313, 1);
	movie.addMovie(126, 1);
	movie.cancelMovie(125313);
	movie.addMovie(44,3);
	movie.showAllMovies();





	


}

