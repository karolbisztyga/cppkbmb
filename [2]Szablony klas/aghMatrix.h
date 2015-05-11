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

  void print();

};

template<class T>
AghMatrix<T>::AghMatrix(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->matrix = new T*[this->rows];
  for( int i=0 ; i<this->rows ; ++i ) {
    this->matrix[i] = new T[this->cols];
  }
}

template<class T>
void AghMatrix<T>::setItems(T *pt) {
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      this->matrix[i][j] = *pt;
      ++pt;
    }
  }
}
  
template<class T>
void AghMatrix<T>::setItems(int r, int c,...) {
  va_list ap;
  va_start(ap, c);
  int counter=0;
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      this->matrix[i][j] = va_arg(ap,T);
    }
  }
  va_end(ap);
}

template<class T>
void AghMatrix<T>::print() {
  T *pt = &this->matrix[0][0];
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      cout << "[" << this->matrix[i][j] << "]";
      ++pt;
    }
    cout << endl;
  }
}