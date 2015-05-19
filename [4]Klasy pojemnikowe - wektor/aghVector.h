#ifndef AGHVECTOR_H
#define AGHVECTOR_H

template<class T>
class aghVector : public aghContainer<T> {

public:
    virtual ~aghVector();
    aghVector();
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);

    void print();
private:
	int length;
	T *items;
};

template<class T>
aghVector<T>::aghVector() {
	this->length = 0;
	this->items = new T[0];
}

template<class T>
aghVector<T>::~aghVector() {
	delete [] this->items;
}


template<class T>
bool aghVector<T>::insert(int index, T const &t) {
	if( index > this->length+1 ) {
		return false;
	}
	T *temp = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		temp[i] = this->items[i];
	}
	delete [] this->items;
	++this->length;
	this->items = new T[this->length];
	for( int i=0 ; i<index ; ++i ) {
		this->items[i] = temp[i];
	}
	this->items[index] = t;
	for( int i=index+1 ; i<this->length ; ++i ) {
		this->items[i] = temp[i+1];
	}
	delete [] temp;
	this->items[this->length-1] = t;
	return true;
}


template<class T>
T& aghVector<T>::at(int index) const {
	if( index >= this->length ) {
		throw aghException(0, "Index out of bound", __FILE__, __LINE__);
	}
	return this->items[index];
}


template<class T>
int aghVector<T>::size() const {
	return this->length;
}


template<class T>
bool aghVector<T>::remove(int index) {
	if( index >= this->length || index < 0 ) {
		return false;
	}
	T *temp = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		temp[i] = this->items[i];
	}
	delete [] this->items;
	this->items = new T[this->length-1];
	for( int i=0,c=0 ; i<this->length ; ++i ) {
		if( i != index ) {
			this->items[c++] = temp[i];
		}
	}
	--this->length;
	delete [] temp;
	return true;
}

template<class T>
void aghVector<T>::print() {
	for( int i=0 ; i<this->length ; ++i ) {
		cout << "["<< this->items[i] <<"]" ;
	}
	cout << endl;
}

#endif