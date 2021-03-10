using namespace std;
#include <string>
#include <time.h>

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
			p[length].avaibleSeats = 780;
			p[length].initializeSeats();
			break;
		case 1:
			p[length].whenToSpace = 6;
			p[length].row = 16;
			p[length].col = 14;
			p[length].avaibleSeats = 195;
			p[length].initializeSeats();
			break;
		case 2:
			p[length].whenToSpace = 4;
			p[length].row = 11;
			p[length].col = 10;
			p[length].avaibleSeats = 90;
			p[length].initializeSeats();
			break;
		case 3:
			p[length].whenToSpace = 4;
			p[length].row = 9;
			p[length].col = 8;
			p[length].avaibleSeats = 56;
			p[length].initializeSeats();
			break;
		case 4:
			p[length].whenToSpace = 3;
			p[length].row = 7;
			p[length].col = 7;
			p[length].avaibleSeats = 36;
			p[length].initializeSeats();
			break;
		case 5:
			p[length].whenToSpace = 3;
			p[length].row = 6;
			p[length].col = 6;
			p[length].avaibleSeats = 25;
			p[length].initializeSeats();
			break;
		case 6:
			p[length].whenToSpace = 3;
			p[length].row = 6;
			p[length].col = 5;
			p[length].avaibleSeats = 20;
			p[length].initializeSeats();
			break;
		case 7:
			p[length].whenToSpace = 3;
			p[length].row = 5;
			p[length].col = 5;
			p[length].avaibleSeats = 16;
			p[length].initializeSeats();
			break;
		}

		printDate(id);
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
		if (length>0) {
			cout << "Movies on Show: ";
			for (int i = 0; i < length; i++) {
				cout << "\nMovie at: ";
				printDate(p[i].id);
				cout << " (" << "avaible seats :" << p[i].avaibleSeats << ")";
			}
		}
		else {
			cout << "No movies on show.";
		}
	}
	
	void initializeSeats() {
		
		SEATS = new string * [row];
		for (int i = 0; i < row; i++)
			SEATS[i] = new string[col];


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

			}
		}

	}
	
	void displayMovie(const long movieID) {

		int index = linearSearch(movieID);
		cout << "\nMovie at: ";
		printDate(movieID);
		cout << " (" << "avaible seats :" << p[index].avaibleSeats << ")";
		showTheatreRoom(movieID);
		

	}

	int res(const long movieID, const int row, const char col) {

		int index = linearSearch(movieID);
	
		if (!isMovieIdUnique(movieID) && !isReserved(movieID, row, col) && p[index].isAvaible(row, col) && isInFormat(row,col)) {
			
			p[index].SEATS[((row-1)/(p[index].radius+1))+1][((int(col) - 65) / (p[index].radius + 1)) + 1] = "O";

			cout << "\n" << "RESERVATION MADE ON " << col << row << " at ";
			printDate(p[index].id);

			int rowa = row; // 1 basamak
			int cola = int(col); // 2 basamak 20
			int indeksRes = index; //1 basamak
			int code = cola * 100 + rowa * 10 + indeksRes;
			p[index].avaibleSeats--;
			return code;

			}
		else if(!p[index].isAvaible(row, col)) {
			cout << "\n" << col << row << " seat is not occupiable.";
			return -1;
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
		if (isReserved(p[index].id ,resRow, resCol)) {
			cout << "\nseat: " << char(resCol) << resRow << " in movie at ";
			printDate(p[index].id);
			cout << "\n";
		}
		else {
			cout << "\nunvalid reservation code.";
		}

	}

	void cancelReservations(const int numRes, const int* resCode) {


		for (int i = 0; i < numRes; i++)
		{
			if (resCode[i] > 0) {
				int resCol = resCode[i] / 100;
				int resRow = (resCode[i] / 10) % 10;
				int index = resCode[i] % 10;
				if (isReserved(p[index].id, resRow, resCol)) {

					p[index].SEATS[((resRow - 1) / (p[index].radius + 1)) + 1][((int(resCol) - 65) / (p[index].radius + 1)) + 1] = "X";
					cout << "\nSeat: " << char(resCol) << resRow << " in movie at ";
					printDate(p[index].id);
					cout << "has been canceled.\n";
					p[index].avaibleSeats++;
				}
				else {
					cout << "\nunvalid reservation code.";
				}
			}
			else {
				cout << "\nunvalid reservation code.";
			}
		}

	}

	bool isReserved(const long movieID, const int row, const char col) {

		int index = linearSearch(movieID);

		if (p[index].SEATS[((row - 1) / (p[index].radius + 1)) + 1][((int(col) - 65) / (p[index].radius + 1)) + 1] == "X") {
			
			return false;
		}
		else {
		
			return true;
		}

	}

	bool isAvaible(const int row, const char col) {
		

		if ((int(col)-65) % (radius + 1) == 0 && (row-1) % (radius + 1) == 0) {

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

	void showTheatreRoom(const long movieID) {
		cout << "\n";
		int index = linearSearch(movieID);
		int i, j, k = 0;
		int alphabet = 65;
		for (i = 0; i < p[index].row; i++)
		{
			for (j = 0; j < p[index].col; j++)
			{
			
				if (i < p[index].whenToSpace || j>0) {
					cout << ' ' << p[index].SEATS[i][j];
				}

				else {

					cout << p[index].SEATS[i][j];
				}

				if (j == p[index].col-1) {

					cout << "\n";
				}

			}
		}

	}

	void printDate(const long id) {
		time_t asd = id;
		char str[26];
		ctime_s(str, sizeof str, &asd);
		cout << str;
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
	int avaibleSeats = 0;
};