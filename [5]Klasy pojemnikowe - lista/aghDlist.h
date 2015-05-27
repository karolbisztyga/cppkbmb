#ifndef AGHDLIST_H
#define AGHDLIST_H

template<class T>
class aghDlist : public aghContainer<T> {
  public:
    virtual ~aghDlist();
    aghDlist();
    aghDlist(const aghDlist&);
    aghDlist(aghContainer<T>&);
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);
    aghDlist<T>& operator=(aghDlist<T> const& element);
    aghDlist<T>& operator=(aghContainer<T> const& element);
    bool operator==(aghContainer<T> const& element);
    bool operator!=(aghContainer<T> const& element);

    aghDlistItem<T>& getHead() const;
    void print();
  private:
    aghDlistItem<T> *head;
};

template<class T>
aghDlist<T>::aghDlist() {
    this->head = NULL;
}

template<class T>
aghDlist<T>::~aghDlist() {
    this->clear();
}

template<class T>
aghDlistItem<T>& aghDlist<T>::getHead() const {
    return *(this->head);
}

template<class T>
aghDlist<T>::aghDlist(aghContainer<T> &container) {
    aghDlist<int> *pt = static_cast<aghDlist<int>*>(&container);
    this->head = NULL;
    aghDlistItem<T> *temp = &pt->getHead();
    while( temp != NULL ) {
        this->append(temp->getValue());
        temp = temp->getNext();
    }
}

template<class T>
aghDlist<T>::aghDlist(const aghDlist &list) {
    this->head = NULL;
    aghDlistItem<T> *temp = &list.getHead();
    while( temp != NULL ) {
        this->append(temp->getValue());
        temp = temp->getNext();
    }
}

template<class T>
bool aghDlist<T>::insert(int index, T const &t) {
    aghDlistItem<T> *item = new aghDlistItem<T>(NULL,t);
    if( index == 0 ) {
        if( this->head != NULL ) {
            this->head->setPrev(item);
            item->setNext(this->head);
        }
        this->head = item;
        return true;
    }
    int i=1;
    aghDlistItem<T> *temp = this->head;
    while( temp != NULL ) {
        if( i == index ) {
            if( temp->getNext() != NULL ) {
                item->setNext(temp->getNext());
                temp->getNext()->setPrev(item);
            }
            temp->setNext(item);
            item->setPrev(temp);
            return true;
        }
        ++i;
        temp = temp->getNext();
    }
    return false;
}

template<class T>
T& aghDlist<T>::at(int index) const {
    aghDlistItem<T> *temp = this->head;
    int i=0;
    while( temp != NULL ) {
        if( i == index ) {
            return temp->getValue();
        }
        ++i;
        temp = temp->getNext();
    }
    throw aghException(0, "Index out of bound", __FILE__, __LINE__);
}

template<class T>
int aghDlist<T>::size() const {
    aghDlistItem<T> *temp = this->head;
    int size = 0;
    while( temp != NULL ) {
        ++size;
        temp = temp->getNext();
    }
    return size;
}

template<class T>
bool aghDlist<T>::remove(int index) {
    aghDlistItem<T> *temp = this->head;
    int i=0;
    while( temp != NULL ) {
        if( i == index ) {
            if( temp != this->head ) {
                temp->getPrev()->setNext(NULL);
            }
            if( temp->getNext() != NULL ) {
                if( temp != this->head ) {
                    temp->getNext()->setPrev(temp->getPrev());
                    temp->getPrev()->setNext(temp->getNext());
                }
            }
            if( temp == this->head ) {
                this->head = ( temp->getNext() != NULL ) ? temp->getNext() : NULL;
            }
            delete temp;
            return true;
        }
        ++i;
        temp = temp->getNext();
    }
    return false;
}

template<class T>
aghDlist<T>& aghDlist<T>::operator=(aghDlist<T> const& list) {
    if( aghDlist<T>::operator!=(list) ) {
        this->clear();
        aghDlistItem<T> *temp = &list.getHead();
        while( temp != NULL ) {
            this->append(temp->getValue());
            temp = temp->getNext();
        }
    }
}

template<class T>
aghDlist<T>& aghDlist<T>::operator=(aghContainer<T> const& element) {
    if( this->operator!=(element) ) {
        this->aghContainer<T>::operator=(element);
    }
}

template<class T>
bool aghDlist<T>::operator==(aghContainer<T> const& element) {
    return this->aghContainer<T>::operator==(element);
}

template<class T>
bool aghDlist<T>::operator!=(aghContainer<T> const& element) {
    return this->aghContainer<T>::operator!=(element);
}


template<class T>
void aghDlist<T>::print() {
    aghDlistItem<T> *temp = this->head;
    cout << "[ " ;
    while( temp != NULL ) {
        cout << temp->getValue() << " " ;
        temp = temp->getNext();
    }
    cout << "]\n" ;
}


#endif
