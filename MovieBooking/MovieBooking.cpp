
#include <iostream>
#include <string>
#include "MovieBookingSystem.h"
using namespace std;

int main()
{
	int* codes = new int[2];
	MovieBookingSystem movie;
	movie.addMovie(22, 0);
	movie.addMovie(23, 3);
	movie.showMovie(23);
	codes[0] = movie.makeReservation(23, 1, 'A');
	codes[1] = movie.makeReservation(23, 5, 'K');
	movie.showMovie(23);
	movie.showReservation(codes[0]);
	movie.showReservation(codes[1]);




	
	



}

