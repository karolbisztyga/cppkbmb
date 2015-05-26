#ifndef AGHDLIST_H
#define AGHDLIST_H

template<class T>
class aghDList : public aghContainer<T> {
  public:
    virtual ~aghDList();
    aghDList();
    aghDList(const aghDList&);
    //aghDList(aghContainer<T>&);
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);
    aghDList<T>& operator=(aghDList<T> const& element);
    bool operator==(aghContainer<T> const& element);
    bool operator!=(aghContainer<T> const& element);

    aghDListItem<T>& getHead() const;
    void print();
  private:
    aghDListItem<T> *head;
};

template<class T>
aghDList<T>::aghDList() {
    this->head = NULL;
}

template<class T>
aghDList<T>::~aghDList() {
    delete this->head;
}

template<class T>
aghDListItem<T>& aghDList<T>::getHead() const {
    return *(this->head);
}

template<class T>
aghDList<T>::aghDList(const aghDList &list) {
    this->head = NULL;
    aghDListItem<T> *temp = &list.getHead();
    while( temp != NULL ) {
        this->append(temp->getValue());
        temp = temp->getNext();
    }
}

template<class T>
bool aghDList<T>::insert(int index, T const &t) {
    aghDListItem<T> *item = new aghDListItem<T>(NULL,t);
    if( this->head == NULL && index == 0 ) {
        this->head = item;
        return true;
    }
    int i=1;
    aghDListItem<T> *temp = this->head;
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
    delete item;
    return false;
}

template<class T>
T& aghDList<T>::at(int index) const {
    aghDListItem<T> *temp = this->head;
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
int aghDList<T>::size() const {
    aghDListItem<T> *temp = this->head;
    int size = 0;
    while( temp != NULL ) {
        ++size;
        temp = temp->getNext();
    }
    return size;
}

template<class T>
bool aghDList<T>::remove(int index) {
    aghDListItem<T> *temp = this->head;
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
            this->head = ( temp->getNext() != NULL ) ? temp->getNext() : NULL;
            delete temp;
            return true;
        }
        ++i;
        temp = temp->getNext();
    }
    return false;
}

template<class T>
aghDList<T>& aghDList<T>::operator=(aghDList<T> const& list) {
    if( aghDList<T>::operator!=(list) ) {
        this->clear();
        aghDListItem<T> *temp = &list.getHead();
        while( temp != NULL ) {
            this->append(temp->getValue());
            temp = temp->getNext();
        }
    }
}

template<class T>
bool aghDList<T>::operator==(aghContainer<T> const& element) {
    return this->aghContainer<T>::operator==(element);
}

template<class T>
bool aghDList<T>::operator!=(aghContainer<T> const& element) {
    return this->aghContainer<T>::operator!=(element);
}


template<class T>
void aghDList<T>::print() {
    aghDListItem<T> *temp = this->head;
    cout << "[ " ;
    while( temp != NULL ) {
        cout << temp->getValue() << " " ;
        temp = temp->getNext();
    }
    cout << "]\n" ;
}


#endif
