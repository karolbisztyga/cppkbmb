#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

template<class T>
class aghContainer {
  private:
    
  public:

    void append(T const&);
    bool replace(int, T const&);
    void clear();
    bool isEmpty();
    int indexOf(T const& _value, int _from = 0) const;
    bool contains(T const& _value, int _from = 0) const;
    bool operator==(aghContainer<T> const&);
    bool operator!=(aghContainer<T> const&);
    T& operator[](int n) const;
    aghContainer<T>& operator+=(aghContainer<T> const&);
    aghContainer<T>& operator+=(T const&);
    aghContainer<T>& operator<<(T const&);
    aghContainer<T>& operator<<(aghContainer<T> const&);
    friend ostream& operator<<(ostream&, aghContainer<T> const&);
    aghContainer<T>& operator=(aghContainer<T> const&);


    virtual ~aghContainer();
    virtual bool insert(int, T const&) = 0;
    virtual T& at(int) const = 0;
    virtual int size() const = 0;
    virtual bool remove(int) = 0;

};

/// \brief constructor no params
///
///
template<class T>
aghContainer<T>::~aghContainer(){}

/// \brief appends the element to the container
///
/// \param t - element to be appended
///
/// \return void
template<class T>
void aghContainer<T>::append(T const &t) {
    this->insert(this->size(),t);
}

/// \brief replaces the element with given index
///
/// \param index - position of the element in it's container
/// \param t - element to be placed
///
/// \return void
template<class T>
bool aghContainer<T>::replace(int index, T const &t) {
    this->at(index) = t;
}

/// \brief clears the container
///
/// \return void
template<class T>
void aghContainer<T>::clear() {
    while( this->size() > 0 ) {
        this->remove(this->size()-1);
    }
}

/// \brief checks if the container contains any elements or not
///
/// \return bool:
/// \true - container is empty
/// \false - container isn't empty
template<class T>
bool aghContainer<T>::isEmpty() {
    return (this->size()==0);
}

/// \brief returns index of given element
///
/// \param _value - element to be searched in the container
/// \param _from - index to search from
///
/// \return void
template<class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const {
    for( int i=_from,s=this->size() ; i<s ; ++i ) {
        if( _value == this->at(i) ) {
            return i;
        }
    }
    return -1;
}

/// \brief pecifies if given element exists in the container
///
/// \param _value - element to be searched in the container
/// \param _from - index to search from
///
/// \return bool
/// \true - element is in the container
/// \false - element isn't in the container
template<class T>
bool aghContainer<T>::contains(T const& _value, int _from) const {
    return ( this->indexOf(_value,_from) != -1 );
}

/// \brief compares two containers
///
/// \param right - righthand container
///
/// \return bool
/// \true - equal
/// \false - not equal
template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right) {
    int size = this->size();
    if( size != right.size() ) {
        return false;
    }
    for( int i=0 ; i<size ; ++i ) {
        if( this->at(i) != right.at(i) ) {
            return false;
        }
    }
    return true;
}
/// \brief compares two containers
///
/// \param right - righthand container
///
/// \return bool
/// \true - not equal
/// \false - equal
template<class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right) {
    return !(*this == right );
}

/// \brief returns element with given index
///
/// \param n - index of an element
///
/// \return T& - adress of an element
template<class T>
T& aghContainer<T>::operator[](int n) const {
    return this->at(n);
}

/// \brief adds elements from given container to another one
///
/// \param right - container to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right) {
    for( int i=0,s=right.size() ; i<s ; ++i ) {
        this->append(right.at(i));
    }
    return *this;
}

/// \brief adds element to the container
///
/// \param right - element to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element) {
    this->append(element);
    return *this;
}

/// \brief adds element to the container
///
/// \param right - element to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element) {
    this->append(element);
    return *this;
}

/// \brief adds elements from given container to another one
///
/// \param right - container to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right) {
    *this+= right;
    return *this;
}

/// \brief assigment operator
///
/// \param c - container to be asigned
///
/// \return aghContainer<T>& - assigned container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator=(aghContainer<T> const& c) {
    if( this->operator!=(c) ) {
        this->clear();
        for( int i=0,l=c.size() ; i<l ; ++i ) {
            this->append(c.at(i));
        }
        return *this;
    }
}


#endif
