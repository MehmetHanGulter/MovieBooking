#pragma once
#include "Movies.h"
class MovieBookingSystem {
public:

    const static int numOfRow  = 30;
    const static int numOfColumn = 26;

	MovieBookingSystem() {
        
    }

    void addMovie(const long movieID, const int audienceRadius) {

        if (movie->isMovieIdUnique(movieID) && movie->isRadiusValid(audienceRadius)) {
           
            movie->append(movieID);
            cout << "\n" << "Movie at ";
            cout << "has been added.";
            cout << "\n";
            cout << "\n";
        }

        else {

            if (!movie->isMovieIdUnique(movieID)) {
                cout << "\n" << "Movie at " << "already exists.";

            }

            else {
                cout << "\n" << "Audience radius is not valid.";
            }
        }
    }
    void cancelMovie(const long movieID) {
        int index = movie->linearSearch(movieID);

        if (!movie->isMovieIdUnique(movieID)) {
       
            movie->deleteMovieByIndex(index);
            cout << "\n" << "Movie has been deleted";
        }
        
        else {
        
            cout << "\n" <<"Movie doesnt exist.";
        
        }
    }
    void showAllMovies() {

        for (int i = 0; i < movie->getLength(); i++) {
            cout << "\n" << movie->p[i];
         }
    }
    void showMovie(const long movieID) {

        if (!movie->isMovieIdUnique(movieID)) {

        }
        else {

            cout << "\n" << "Movie doesnt exist.";

        }
    }
    
   
private:
    Movies* movie = new Movies(20);

};
