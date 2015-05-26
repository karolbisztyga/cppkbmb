#ifndef AGHDLISTITEM_H
#define AGHDLISTITEM_H

template<class T>
class aghDListItem {

  private:
    aghDListItem *next,*prev;
    T value;
  public:
    aghDListItem(aghDListItem<T>*,const T&);

    aghDListItem<T> *getNext() const;
    aghDListItem<T> *getPrev() const;

    void setNext(aghDListItem<T>*);
    void setPrev(aghDListItem<T>*);

    T& getValue();
    void setValue(const T&);

};

template<class T>
aghDListItem<T>::aghDListItem(aghDListItem<T> *prev, const T &value) {
    this->next = NULL;
    this->prev = prev;
    this->value = value;
}

template<class T>
aghDListItem<T>* aghDListItem<T>::getNext() const {
    return this->next;
}

template<class T>
aghDListItem<T>* aghDListItem<T>::getPrev() const {
    return this->prev;
}

template<class T>
void aghDListItem<T>::setNext(aghDListItem<T> *next) {
    this->next = next;
}

template<class T>
void aghDListItem<T>::setPrev(aghDListItem<T> *prev) {
    this->prev = prev;
}

template<class T>
T& aghDListItem<T>::getValue() {
    return this->value;
}


template<class T>
void aghDListItem<T>::setValue(const T &value) {
    this->value = value;
}


#endif
