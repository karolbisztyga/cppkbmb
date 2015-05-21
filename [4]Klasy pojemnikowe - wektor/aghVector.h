#ifndef AGHVECTOR_H
#define AGHVECTOR_H

template<class T>
class aghVector : public aghContainer<T> {

public:
    virtual ~aghVector();
    aghVector();
    aghVector(const aghVector&);
    aghVector(aghContainer<T>&);
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);

	aghVector<T>& operator=(aghVector<T> const& element);
	aghVector<T>& operator=(aghContainer<T> const& element);
	bool operator==(aghContainer<T> const& element);
	bool operator!=(aghContainer<T> const& element);

    void print();
private:
	int length;
	T *items;
};
/*
template<class T>
aghVector<T>& aghVector<T>::operator+=(T const& element) {
	cout << "\nherer\n" ;
	aghContainer<T>::operator+=(element);
	return *this;
}
*/
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
aghVector<T>::aghVector(const aghVector<T> &v) {
	this->length = v.size();
	this->items = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		this->items[i] = v[i];
	}
}

template<class T>
aghVector<T>::aghVector(aghContainer<T> &c) {
	this->length = c.size();
	this->items = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		this->items[i] = c.at(i);
	}
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
		this->items[i] = temp[i-1];
	}
	delete [] temp;
	return true;
}


template<>
bool aghVector<int>::insert(int index, int const &t) {
	if( index > this->length+1 ) {
		return false;
	}
	int *temp = new int[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		temp[i] = this->items[i];
	}
	delete [] this->items;
	++this->length;
	this->items = new int[this->length];
	for( int i=0 ; i<index ; ++i ) {
		this->items[i] = temp[i];
	}
	this->items[index] = t;
	for( int i=index+1 ; i<this->length ; ++i ) {
		this->items[i] = temp[i-1];
	}
	delete [] temp;
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

template<class T>
aghVector<T>& aghVector<T>::operator=(aghVector<T> const& element) {
	/*this->length = element.size();
	delete [] this->items;
	this-> items = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		this->items[i] = element.at(i);
	}
	return *this;*/
	if( this->operator!=(element) ) {
		this->aghContainer<T>::operator=(element);
	}
}

template<class T>
aghVector<T>& aghVector<T>::operator=(aghContainer<T> const& element) {
	if( this->operator!=(element) ) {
		/*this->length = element.size();
		delete [] this->items;
		this-> items = new T[this->length];
		for( int i=0 ; i<this->length ; ++i ) {
			this->items[i] = element.at(i);
		}
		return *this;*/
		this->aghContainer<T>::operator=(element);
	}
}
/* */

template<class T>
bool aghVector<T>::operator==(aghContainer<T> const& element) {
	return this->aghContainer<T>::operator==(element);
}

template<class T>
bool aghVector<T>::operator!=(aghContainer<T> const& element) {
	return this->aghContainer<T>::operator!=(element);
}

#endif