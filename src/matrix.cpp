#include "../include/matrix.h"
#include <string>

template <class T>
matrix<T>::matrix() {}

template <class T>
matrix<T>::matrix(unsigned int x, unsigned int y){
	resize(x,y);
}

template <class T>
matrix<T>::matrix(matrix& matrix){
	*this = matrix;
}

template <class T>
void matrix<T>::resize(unsigned int x, unsigned int y){
	m.resize(x, vector<T>(y));
}

template <class T>
vector<T> & matrix<T>::operator[](unsigned int i) {
	return m[i];
}

template <class T>
matrix<T>& matrix<T>::operator=(const matrix& matrix){
	m = matrix.m;
	return (*this);
}

//

template class matrix <int>;
template class matrix <double>;
template class matrix <float>;
template class matrix <char>;
template class matrix <string>;
template class matrix <bool>;
