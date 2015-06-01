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

private:
	int length;
	T *items;
};

/// \brief constructor no params
///
///
template<class T>
aghVector<T>::aghVector() {
	this->length = 0;
	this->items = new T[0];
}

/// \brief destructor
///
///
template<class T>
aghVector<T>::~aghVector() {
	delete [] this->items;
}

/// \brief constructor copy
///
/// \param v - vector to be copied
template<class T>
aghVector<T>::aghVector(const aghVector<T> &v) {
	this->length = v.size();
	this->items = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		this->items[i] = v[i];
	}
}

/// \brief constructor copy
///
/// \param c - container to eb copied
template<class T>
aghVector<T>::aghVector(aghContainer<T> &c) {
	this->length = c.size();
	this->items = new T[this->length];
	for( int i=0 ; i<this->length ; ++i ) {
		this->items[i] = c.at(i);
	}
}

/// \brief inserts element in vector
///
/// \param index - where is the element meant to be
/// \param t - element to be added
///
/// \return bool
///		true - inserting successful
///		false - inserting unsuccessful
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

/// \brief returns vector's element on given index
///
/// \param index - index of an element
///
/// \return T& - element's reference
template<class T>
T& aghVector<T>::at(int index) const {
	if( index >= this->length ) {
		throw aghException(0, "Index out of bound", __FILE__, __LINE__);
	}
	return this->items[index];
}

/// \brief returns vector's size
///
///
/// \return int - size of the vector
template<class T>
int aghVector<T>::size() const {
	return this->length;
}

/// \brief removes element from vector
///
/// \param index - index of an element
///
/// \return bool
///		true - element existed and has been removed
///		false - there wasn't such element
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

/// \brief assigment operator
///
/// \param aghVector - vector to be copied
///
/// \return aghVector<T>& - vector's reference
template<class T>
aghVector<T>& aghVector<T>::operator=(aghVector<T> const& element) {
	if( this->operator!=(element) ) {
		this->aghContainer<T>::operator=(element);
	}
}

/// \brief assigment operator
///
/// \param aghVector - container to be copied
///
/// \return aghVector<T>& - vector's reference
template<class T>
aghVector<T>& aghVector<T>::operator=(aghContainer<T> const& element) {
	if( this->operator!=(element) ) {
		this->aghContainer<T>::operator=(element);
	}
}

/// \brief comparing operator
///
/// \param aghContainer - vector to be compared
///
/// \return bool
///		true - containers are the same
///		false - containers are different
template<class T>
bool aghVector<T>::operator==(aghContainer<T> const& element) {
	return this->aghContainer<T>::operator==(element);
}

/// \brief comparing operator
///
/// \param aghContainer - vector to be compared
///
/// \return bool
///		true - containers are different
///		false - containers are the same
template<class T>
bool aghVector<T>::operator!=(aghContainer<T> const& element) {
	return this->aghContainer<T>::operator!=(element);
}

#endif
