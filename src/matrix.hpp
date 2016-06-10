#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

static unsigned long tam = 0;

template <class T>
class matrix {

private:
	vector< vector <T> > m;
public:
	matrix(){}
	
	matrix(unsigned int x, unsigned int y) { resize(x, y); } // Builds a matrix with the provided size
	
	matrix(const matrix & matrix){ *this = matrix; }
	
	void resize(unsigned int x, unsigned int y){ m.resize(x, vector<T>(y)); }
	
	vector<T> & operator[] (unsigned int i){ return m[i]; } // Set or get a value of the matrix
	
	matrix & operator=(const matrix & matrix) {	m = matrix.m; return (*this);}
	
	unsigned long size(){ return m.size(); }
	
	unsigned long colSize(){ return (m.empty() ? 0 : m[0].size()); } // Returns number of columns

	vector<typename vector<T>::iterator> begin() {
		tam = colSize();

		vector<typename vector<T>::iterator> v;

		for (int i = 0; i < size(); i++)
			v.push_back(m[i].begin());

		return v;
	}

	typename vector<T>::iterator end(){ return m[size() - 1].end(); }

	class iterator {
	private:
		vector<typename vector<T>::iterator> it;
		int posF = 0, posC = 0;
		bool end = false;
	public:
		iterator(){}
		explicit iterator(const vector<typename vector<T>::iterator>& iterator){ it = iterator; }
		explicit iterator(const iterator& iterator){ it = iterator.it; }
		
		iterator& operator=(const vector<typename vector<T>::iterator>& iterator) {
			it = iterator;
			return *this;
		}

		iterator& operator=(const iterator& iterator) {
			it = iterator.it;
			return *this;
		}

		T & operator*(){ return *(it[posF] + posC); }
		
		void operator++() {
			if ((posC + 1) < tam)
				posC++;
			else if (unsigned(posF + 1) < it.size())
				posF++, posC = 0;
			else
				end = true;
		}

		bool operator==(const vector<typename vector<T>::iterator>& iterator){ return (it == iterator); }
		bool operator!=(const vector<typename vector<T>::iterator>& iterator){ return (it != iterator); }
		bool operator!=(const typename vector<T>::iterator& iterator){ return !end; }
	};
};

#endif
