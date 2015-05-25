#ifndef AGHSLISTITEM_H
#define AGHSLISTITEM_H

template<class T>
class aghSListItem {

  private:
    aghSListItem *next;
    T value;
  public:
  	aghSListItem(const T&);

    aghSListItem *getNext() const;
    void setNext(aghSListItem*);

    T& getValue();
    void setValue(const T&);
};

template<class T>
aghSListItem<T>::aghSListItem(const T &value) {//} : value(_value) {
    this->next = NULL;
    this->value = value;
}

template<class T>
aghSListItem<T>* aghSListItem<T>::getNext() const {
    return this->next;
}

template<class T>
void aghSListItem<T>::setNext(aghSListItem<T> *next) {
    this->next = next;
}

template<class T>
T& aghSListItem<T>::getValue() {
    return this->value;
}

template<class T>
void aghSListItem<T>::setValue(const T &value) {
    this->value = value;
}

#endif
