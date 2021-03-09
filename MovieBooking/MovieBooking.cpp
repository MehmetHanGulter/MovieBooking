
#include <iostream>
#include <string>
#include "MovieBookingSystem.h"
using namespace std;

int main()
{
	MovieBookingSystem movie;
	movie.addMovie(22, 0);
	movie.addMovie(23, 1);
	movie.showMovie(23);
	movie.makeReservation(23, 1, 'A');
	movie.makeReservation(23, 11, 'K');

	movie.showMovie(23);
	



	
	



}

