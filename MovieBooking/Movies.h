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
	~Movies() {
		delete[] p;

		for (int i = 0; i < row; i++) {
			delete[] SEATS[i];
		}
		delete[] SEATS;
	}

	void append(long id, int radius)
	{
		p[length].id = id;
		p[length].radius = radius;

		switch (radius)
		{
		case 0:
			p[length].whenToSpace = 10;
			p[length].row = 31;
			p[length].col = 27;
			p[length].initializeSeats();
			break;
		case 1:
			p[length].whenToSpace = 6;
			p[length].row = 16;
			p[length].col = 14;
			p[length].initializeSeats();
			break;
		case 2:
			p[length].whenToSpace = 4;
			p[length].row = 11;
			p[length].col = 10;
			p[length].initializeSeats();
			break;
		case 3:
			p[length].whenToSpace = 4;
			p[length].row = 9;
			p[length].col = 8;
			p[length].initializeSeats();
			break;
		case 4:
			p[length].whenToSpace = 3;
			p[length].row = 7;
			p[length].col = 7;
			p[length].initializeSeats();
			break;
		case 5:
			p[length].whenToSpace = 3;
			p[length].row = 6;
			p[length].col = 6;
			p[length].initializeSeats();
			break;
		case 6:
			p[length].whenToSpace = 3;
			p[length].row = 6;
			p[length].col = 5;
			p[length].initializeSeats();
			break;
		case 7:
			p[length].whenToSpace = 3;
			p[length].row = 5;
			p[length].col = 5;
			p[length].initializeSeats();
			break;
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

	int res(const long movieID, const int row, const char col) {

		int index = linearSearch(movieID);
	
		if (!isMovieIdUnique(movieID) && !isReserved(movieID, row, col) && isAvaible(movieID, row, col) && isInFormat(row,col)) {          
			
			p[index].SEATS[((row-1)/(p[index].radius+1))+1][((int(col) - 65) / (p[index].radius + 1)) + 1] = "O";

			int rowa = row; // 1 basamak
			int cola = int(col); // 2 basamak 20
			int indeksRes = index; //1 basamak

			int code = cola * 100 + rowa * 10 + indeksRes;
			return code;

			}
		else {
			cout << "\n" << col << row << " seat is not avaible.";
			return -1;
		}

		

	}

	void showReservation(const int resCode) {

		
		int resCol = resCode / 100;
		int resRow = (resCode / 10) % 10;
		int index = resCode % 10;
		if (isReserved(p[index].id, resRow, resCol) && resCode!=-1) {
			cout << "seat: " << char(resCol) << resRow << " in movie at " << p[index].id << "\n";
		}
		else {
			cout << "unvalid reservation code.";
		}

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

	bool isInFormat(const int row, const char col) {

		if (row > -1 && row < 31 && int(col)>64 && int(col) < 91) {
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

	void asd() {
		
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
	int whenToSpace = 0;
	int reservationCode = 0;
};