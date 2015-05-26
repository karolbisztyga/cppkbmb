#ifndef AGHSLIST_H
#define AGHSLIST_H

template<class T>
class aghSlist : public aghContainer<T> {
  public:
    virtual ~aghSlist();
    aghSlist();
    aghSlist(const aghSlist&);
    //aghSlist(aghContainer<T>&);
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);
    aghSlist<T>& operator=(aghSlist<T> const& element);
    bool operator==(aghContainer<T> const& element);
    bool operator!=(aghContainer<T> const& element);

    aghSlistItem<T>& getHead() const;
    void print();
  private:
    aghSlistItem<T> *head;
};

template<class T>
aghSlist<T>::~aghSlist() {
    aghSlistItem<T> *temp = this->head;
    while( temp != NULL ) {
        aghSlistItem<T> *prev = temp;
        temp = temp->getNext();
        delete prev;
    }
}

template<class T>
aghSlist<T>::aghSlist() {
    this->head = NULL;
}

template<class T>
aghSlistItem<T>& aghSlist<T>::getHead() const {
    return *(this->head);
}

template<class T>
aghSlist<T>::aghSlist(const aghSlist &list) {
    this->head = NULL;
    aghSlistItem<T> *temp = &list.getHead();
    while( temp != NULL ) {
        this->append(temp->getValue());
        temp = temp->getNext();
    }
}
/*
template<class T>
aghSlist<T>::aghSlist(aghContainer<T> &container) {
    
}
*/
template<class T>
bool aghSlist<T>::insert(int index, T const &t) {
    aghSlistItem<T> *item = new aghSlistItem<T>(t);
    if( this->head == NULL && index == 0 ) {
        this->head = item ;
        return true;
    }
    int i=1;
    aghSlistItem<T> *temp = this->head;
    while( temp != NULL ) {
        if( i == index ) {
            if( temp->getNext() != NULL ) {
                item->setNext(temp->getNext());
            }
            temp->setNext(item);
            return true;
        }
        ++i;
        temp = temp->getNext();
    }
    return false;
}

template<class T>
T& aghSlist<T>::at(int index) const {
    int i=0;
    aghSlistItem<T> *temp = this->head;
    while( i++ < index ) {
        temp = temp->getNext();
        if( temp == NULL ) {
            throw aghException(0, "Index out of bound", __FILE__, __LINE__);
        }
    }
    return temp->getValue();
}

template<class T>
int aghSlist<T>::size() const {
    int size = 0;
    aghSlistItem<T> *temp = this->head;
    while( temp != NULL ) {
        ++size;
        temp = temp->getNext();
    }
    return size;
}

template<class T>
bool aghSlist<T>::remove(int index) {
    if( index == 0 ) {
        if( this->head == NULL ) {
            return false;
        }
        aghSlistItem<T> *it = ( this->head->getNext() != NULL ) ? this->head->getNext() : NULL ;
        this->head = it;
    }
    aghSlistItem<T> *temp = this->head;
    int i=1;
    while( temp != NULL ) {
        if( i == index ) {
            aghSlistItem<T> *it = ( temp->getNext()->getNext() != NULL ) ? 
                temp->getNext()->getNext() : NULL ;
            temp->setNext(it);
            return true;
        }
        ++i;
        temp = temp->getNext();
    }
    return false;
}

template<class T>
aghSlist<T>& aghSlist<T>::operator=(aghSlist<T> const& list) {
    if( aghSlist<T>::operator!=(list) ) {
        this->clear();
        aghSlistItem<T> *temp = &list.getHead();
        while( temp != NULL ) {
            this->append(temp->getValue());
            temp = temp->getNext();
        }
        return *this;
    }
}

template<class T>
bool aghSlist<T>::operator==(aghContainer<T> const& element) {
    return this->aghContainer<T>::operator==(element);
}

template<class T>
bool aghSlist<T>::operator!=(aghContainer<T> const& element) {
    return this->aghContainer<T>::operator!=(element);
}


template<class T>
void aghSlist<T>::print() {
    aghSlistItem<T> *temp = this->head;
    cout << "[ " ;
    while( temp != NULL ) {
        cout << temp->getValue() << " " ;
        temp = temp->getNext();
    }
    cout << "]\n";
}

#endif
