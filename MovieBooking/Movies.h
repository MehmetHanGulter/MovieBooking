using namespace std;
#pragma once
class Movies {
public:
    int* p;
	Movies() {
		size = 30;
		length = 0;
		p = new int[size];

	}
	Movies(int size) {
		this->size = size;
		p = new int[size];
		length = 0;
	}
    ~Movies() {
        delete[] p;
    };
	int getLength() {
		return length;
	}
	int setLength(int length) {
		this->length = length;
	}
	void append(int id)
	{
		p[length] = id;
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
            if (p[i] == id) {
                return i;
            }
        }
        return -1;
    }

private:
	int size;
	int length;
};