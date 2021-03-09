#pragma once
#include "Movies.h"
class MovieBookingSystem {
public:

    const static int numOfRow  = 30;
    const static int numOfColumn = 26;
  

    void addMovie(const long movieID, const int audienceRadius) {

        if (movie->isMovieIdUnique(movieID) && movie->isRadiusValid(audienceRadius)) {

            movie->append(movieID, audienceRadius);
            cout << "\n" << "Movie at ";
            cout << "has been added.";
            cout << "\n";
            cout << "\n";
        }

        else {

            if (!(movie->isMovieIdUnique(movieID))) {
                cout << "\n" << "Movie at " << "already exists.";

            }

            else {
                cout << "\n" << "Audience radius is not valid.";
            }
        }
    }
    void cancelMovie(const long movieID) {
        int index = movie->linearSearch(movieID);

        if (!(movie->isMovieIdUnique(movieID))) {

            movie->deleteMovieByIndex(index);
            cout << "\n" << "Movie has been deleted";
        }

        else {

            cout << "\n" << "Movie doesnt exist.";

        }
    }
    void showAllMovies() {
         movie->displayAllMovies();

     
    } 
    void showMovie(const long movieID) {

        if (!(movie->isMovieIdUnique(movieID))) {
            movie->displayMovie(movieID);
        }
        else {

            cout << "\n" << "Movie doesnt exist.";

        }
    }
    int makeReservation(const long movieID, const int row, const char col) {

        return movie->res(movieID,row, col);
    }
    void showReservation(const int resCode) {

        movie->showReservation(resCode);

    }
    void cancelReservations(const int numRes, const int* resCode) {
        movie->cancelReservations(numRes, resCode);
    }
private:
    Movies *movie = new Movies(10,0,0);

};
