template<class T>

class AghMatrix {
  private:
    T **matrix;
    int rows,cols;
  public:

  AghMatrix(int,int);

  void setItem(int r, int c, T value);
  void setItems(T *pt);
  void setItems(int r, int c,...);

};

template<class T>
AghMatrix<T>::AghMatrix(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  cout << "constructor!" ;
}

template<class T>
setItems(int r, int c,...) {
  /*va_list ap;
  va_start(ap, n);
  int max = va_arg(ap, int);
  for(int i = 2; i <= n; i++) {
      int a = va_arg(ap, int);
      if(a > max) max = a;
  }
  va_end(ap);*/
}
