using namespace std;
#include <string>

#pragma once
class Movies {
public:
	
	Movies() {
		col = 0;
		row = 0;
		p = new Movies[0];
		SEATS = NULL;
		this->size = 0;
		this->length = 0;
		this->id = 0;
	}
	Movies(int size, int length, int id) {
		col = 0;
		row = 0;
		this->size = size;
		this->length = length;
		this->id = id;
		p = new Movies[size];
		SEATS = NULL;
	}
	int getLength() {
		return length;
	}
	void setRow(int a) {
		this->row = a;
	}
	int getRow() {
		return row;
	}
	void append(long id, int radius)
	{
		p[length].id = id;
		p[length].radius = radius;
		if(radius == 0){
			p[length].whenToSpace = 10;
			p[length].row = 31;
			p[length].col = 27;
			p[length].initializeSeats();
		}
		if (radius == 1) {
			p[length].whenToSpace = 6;
			p[length].row = 16;
			p[length].col = 14;
			p[length].initializeSeats();
		}
		cout << p[length].id;	
		length++;
	}
	void deleteMovieByIndex(int index) {

		int i = index;
		while (i < length)
		{
			p[i] = p[i + 1];
			i++;
		}
		length--;

	}
	bool isMovieIdUnique(long movieId) {

		if (linearSearch(movieId) == -1) {
			return true;
		}
		else {
			return false;
		}

	}
	bool isRadiusValid(int audienceRadius) {
		if (audienceRadius >= 0 && audienceRadius <= 7) {
			return true;
		}
		else {
			return false;
		}
	}
	int linearSearch(long id) {
		for (int i = 0; i < length; i++) {
			if (p[i].id == id) {
				return i;
			}
		}
		return -1;
	}
	void displayAllMovies() {
		for (int i = 0; i < length; i++) {
			cout << "\n" << p[i].id;
		}
	}
	void initializeSeats() {
		
		SEATS = new string * [row];
		for (int i = 0; i < row; i++)
			SEATS[i] = new string[col];
	}
	
	void displayMovie(const long movieID) {

		int index = linearSearch(movieID);
		p[index].showTheatreRoom();
		

	}

	void res(const long movieID, const int row, const char col) {

		int index = linearSearch(movieID);
	
		if (!isMovieIdUnique(movieID) && !isReserved(movieID, row, col) && isAvaible(movieID, row, col)) {
			
			p[index].SEATS[((row-1)/(p[index].radius+1))+1][((int(col) - 65)/ (p[index].radius + 1)) + 1] = "O";

			}
		else {
			cout << "\n" << col << row << " seat is not avaible.";
		}

		
	}

	void decyrptResCode(const int resCode) {



	}

	void showReservation(const int resCode) {

	}

	bool isReserved(const long movieID, const int row, const char col) {

		int index = linearSearch(movieID);
		if (p[index].SEATS[row][int(col) - 64] == "X") {

			return false;
		}
		else {

			return true;
		}

	}

	bool isAvaible(const long movieID, const int row, const char col) {
		
		int index = linearSearch(movieID);

		if ((int(col)-65) % (p[index].radius + 1) == 0 && (row-1) % (p[index].radius + 1) == 0) {

			return true;

		}
		else {
			return false;
		}

	}

	void showTheatreRoom() {	
		cout << "\n";
		int i, j, k = 0;
		int alphabet = 65;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
			
				if (i == 0 && j == 0) {

					SEATS[i][j] = ' ';
				}
				else if (i == 0 && j > 0) {

					SEATS[i][j] = alphabet;
					alphabet = alphabet + radius + 1;
				}
				else if (i == 1 && j == 0) {
					SEATS[i][j] = "1";

				}

				else if (i > 1 && j == 0) {
					
					int res = (radius + 1) * i - radius;
					SEATS[i][j] = to_string(res);
				}

				else if (i > 0 && j > 0) {
					if (SEATS[i][j] != "O") {
						SEATS[i][j] = "X";
					}
				}

				if (i < whenToSpace || j>0) {
					cout << ' ' << SEATS[i][j];
				}

				else {

					cout << SEATS[i][j];
				}

				if (j == col-1) {

					cout << "\n";
				}

			}
		}

	}

private:
	Movies* p;
	string** SEATS;
	long id;
	int size;
	int length;
    int col;
	int row;
	int radius = 0;
	int whenToSpace = 10;
	int reservationCode = 0;
};