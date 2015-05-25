#ifndef AGHDLIST_H
#define AGHDLIST_H

template<class T>
class aghDList : public aghContainer<T> {
  public:
    virtual ~aghDList();
    aghDList();
    aghDList(const aghDList&);
    aghDList(aghContainer<T>&);
    bool insert(int, T const&);
    T& at(int) const;
    int size() const;
    bool remove(int);
    aghDList<T>& operator=(aghDList<T> const& element);
    aghDList<T>& operator=(aghContainer<T> const& element);
    bool operator==(aghContainer<T> const& element);
    bool operator!=(aghContainer<T> const& element);
  private:
    int length;
    T *items;
};

#endif
