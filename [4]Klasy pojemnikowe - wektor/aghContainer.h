#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

template<class T>
class aghContainer {
  private:

  public:
//pure virtual
    virtual ~aghContainer() = 0;
    virtual bool insert(int, T const&) = 0;
    virtual T& at(int) const = 0;
    virtual int size() const = 0;
    virtual bool remove(int) = 0;
//others
    void append(T const&);
    bool replace(int, T const&);
    void clear();
    bool isEmpty();
    int indexOf(T const& _value, int _from = 0) const;
    bool contains(T const& _value, int _from = 0) const;
    bool operator==(aghContainer<T> const& right);
    bool operator!=(aghContainer<T> const& right);
    T& operator[](int n) const;
    aghContainer<T>& operator+=(aghContainer<T> const& right);
    aghContainer<T>& operator+=(T const& element);
    aghContainer<T>& operator<<(T const& element);
    aghContainer<T>& operator<<(aghContainer<T> const& right);
    friend ostream& operator<<(ostream&, aghContainer<T> const& right);

};

/// \brief appends the element to the container
///
/// \param t - element to be appended
///
/// \return void
template<class T>
void aghContainer<T>::append(T const &t) {

}

/// \brief replaces the element with given index
///
/// \param index - position of the element in it's container
/// \param t - element to be placed
///
/// \return void
template<class T>
bool aghContainer<T>::replace(int index, T const &t) {

}

/// \brief clears the container
///
/// \return void
template<class T>
void aghContainer<T>::clear() {

}

/// \brief checks if the container contains any elements or not
///
/// \return bool:
/// \true - container is empty
/// \false - container isn't empty
template<class T>
bool aghContainer<T>::isEmpty() {

}

/// \brief returns index of given element
///
/// \param _value - element to be searched in the container
/// \param _from - index to search from
///
/// \return void
template<class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const {

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
    
}

/// \brief returns element with given index
///
/// \param n - index of an element
///
/// \return T& - adress of an element
template<class T>
T& aghContainer<T>::operator[](int n) const {
    
}

/// \brief adds elements from given container to another one
///
/// \param right - container to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right) {
    
}

/// \brief adds element to the container
///
/// \param right - element to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element) {
    
}

/// \brief adds element to the container
///
/// \param right - element to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element) {
    
}

/// \brief adds elements from given container to another one
///
/// \param right - container to be added
///
/// \return aghContainer<T>& - summed container's reference
template<class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right) {

}

#endif
