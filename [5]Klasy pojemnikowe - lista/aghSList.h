#ifndef AGHSLIST_H
#define AGHSLIST_H

template<class T>
class aghSList : public aghContainer<T> {
  public:
    virtual ~aghSList();
    aghSList();
    aghSList(const aghSList&);
    aghSList(aghContainer<T>&);
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);
    aghSList<T>& operator=(aghSList<T> const& element);
    bool operator==(aghContainer<T> const& element);
    bool operator!=(aghContainer<T> const& element);

    aghSListItem<T>& getHead() const;
    void print();
  private:
    aghSListItem<T> *head;
};

template<class T>
aghSList<T>::~aghSList() {
    delete this->head;
}

template<class T>
aghSList<T>::aghSList() {
    this->head = NULL;
}

template<class T>
aghSListItem<T>& aghSList<T>::getHead() const {
    return this->head;
}

template<class T>
aghSList<T>::aghSList(const aghSList &list) {
    aghSListItem<T> *temp = list.getHead();
    while( temp != NULL ) {
        this->append(*temp);
        temp = temp->getNext();
    }
}
/*
template<class T>
aghSList<T>::aghSList(aghContainer<T> &container) {
    
}
*/
template<class T>
bool aghSList<T>::insert(int index, T const &t) {
    aghSListItem<T> *item = new aghSListItem<T>(t);
    if( this->head == NULL && index == 0 ) {
        this->head = item ;
        return true;
    }
    int i=1;
    aghSListItem<T> *temp = this->head;
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
T& aghSList<T>::at(int index) const {
    int i=0;
    aghSListItem<T> *temp = this->head;
    while( i++ < index ) {
        temp = temp->getNext();
        if( temp == NULL ) {
            throw aghException(0, "Index out of bound", __FILE__, __LINE__);
        }
    }
    return temp->getValue();
}

template<class T>
int aghSList<T>::size() const {
    int size = 0;
    aghSListItem<T> *temp = this->head;
    while( temp != NULL ) {
        ++size;
        temp = temp->getNext();
    }
    return size;
}

template<class T>
bool aghSList<T>::remove(int index) {
    if( index == 0 ) {
        aghSListItem<T> *it = ( this->head->getNext() != NULL ) ? this->head->getNext() : NULL ;
        this->head = it;
    }
    aghSListItem<T> *temp = this->head;
    int i=0;
    while( temp != NULL ) {
        if( i+1 == index ) {
            aghSListItem<T> *it = ( temp->getNext()->getNext() != NULL ) ? 
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
aghSList<T>& aghSList<T>::operator=(aghSList<T> const& element) {
    
}

template<class T>
bool aghSList<T>::operator==(aghContainer<T> const& element) {
    
}

template<class T>
bool aghSList<T>::operator!=(aghContainer<T> const& element) {
    
}


template<class T>
void aghSList<T>::print() {
    aghSListItem<T> *temp = this->head;
    cout << "[ " ;
    while( temp != NULL ) {
        cout << temp->getValue() << " " ;
        temp = temp->getNext();
    }
    cout << "]";
}

#endif
