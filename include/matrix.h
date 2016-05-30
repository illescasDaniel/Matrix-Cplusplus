#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

template <class T>
class matrix {

private:
	vector< vector <T> > m;
public:
	matrix();

	// Main constructor, builds a matrix using the size specified (X row x Y columns)
	matrix(unsigned int x, unsigned int y);

	// Copy constructor
	matrix(const matrix & matrix);

	// Resize a matrix providing its new size
	void resize(unsigned int x, unsigned int y);

	// Set or get a value of the matrix using the square brackets
	vector<T> & operator[] (unsigned int i);

	// Clone a matrix
	matrix & operator=(const matrix & matrix);
};

#endif
