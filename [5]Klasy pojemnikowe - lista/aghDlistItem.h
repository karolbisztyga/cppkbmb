#ifndef AGHDLISTITEM_H
#define AGHDLISTITEM_H

template<class T>
class aghDlistItem {

  private:
    aghDlistItem *next,*prev;
    T value;
  public:
    aghDlistItem(aghDlistItem<T>*,const T&);

    aghDlistItem<T> *getNext() const;
    aghDlistItem<T> *getPrev() const;

    void setNext(aghDlistItem<T>*);
    void setPrev(aghDlistItem<T>*);

    T& getValue();
    void setValue(const T&);

};

template<class T>
aghDlistItem<T>::aghDlistItem(aghDlistItem<T> *prev, const T &value) {
    this->next = NULL;
    this->prev = prev;
    this->value = value;
}

template<class T>
aghDlistItem<T>* aghDlistItem<T>::getNext() const {
    return this->next;
}

template<class T>
aghDlistItem<T>* aghDlistItem<T>::getPrev() const {
    return this->prev;
}

template<class T>
void aghDlistItem<T>::setNext(aghDlistItem<T> *next) {
    this->next = next;
}

template<class T>
void aghDlistItem<T>::setPrev(aghDlistItem<T> *prev) {
    this->prev = prev;
}

template<class T>
T& aghDlistItem<T>::getValue() {
    return this->value;
}


template<class T>
void aghDlistItem<T>::setValue(const T &value) {
    this->value = value;
}


#endif
