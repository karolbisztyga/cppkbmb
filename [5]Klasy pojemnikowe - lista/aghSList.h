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
    aghSList<T>& operator=(aghContainer<T> const& element);
    bool operator==(aghContainer<T> const& element);
    bool operator!=(aghContainer<T> const& element);
  private:
    int length;
    T *items;
};



#endif
