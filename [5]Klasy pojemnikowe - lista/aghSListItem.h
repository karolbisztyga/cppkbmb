#ifndef AGHSLISTITEM_H
#define AGHSLISTITEM_H

template<class T>
class aghSlistItem {

  private:
    aghSlistItem *next;
    T value;
  public:
  	aghSlistItem(const T&);

    aghSlistItem *getNext() const;
    void setNext(aghSlistItem*);

    T& getValue();
    void setValue(const T&);
};

template<class T>
aghSlistItem<T>::aghSlistItem(const T &value) {//} : value(_value) {
    this->next = NULL;
    this->value = value;
}

template<class T>
aghSlistItem<T>* aghSlistItem<T>::getNext() const {
    return this->next;
}

template<class T>
void aghSlistItem<T>::setNext(aghSlistItem<T> *next) {
    this->next = next;
}

template<class T>
T& aghSlistItem<T>::getValue() {
    return this->value;
}

template<class T>
void aghSlistItem<T>::setValue(const T &value) {
    this->value = value;
}

#endif
