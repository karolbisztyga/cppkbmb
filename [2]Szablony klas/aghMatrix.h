template<class T>

class aghMatrix {
  private:
    T **matrix;
    int rows,cols;


    char addChars(char,char);
    void setSize(int,int);
  public:

//constructors/destructors
  aghMatrix();
  aghMatrix(const aghMatrix<T>&);
  aghMatrix(int,int);
  ~aghMatrix();

//getters/setters
  int getRows() const{return this->rows;};
  int getCols() const{return this->cols;};

  T getItem(int r,int c) const{return this->matrix[r][c];};
  void setItem(int, int, T);
  void setItems(T *pt);
  void setItems(int,int,...);

//operators
  aghMatrix operator*(aghMatrix<T>&);
  T operator()(int, int);

  aghMatrix<T> operator+(aghMatrix<T>&);
  bool operator==(aghMatrix<T>&);
  bool operator!=(aghMatrix<T>&);
  void operator=(aghMatrix<T>&);

//specialized functions
  //aghMatrix<char> operator+(aghMatrix<char>&);

//other methods
  void print();

};

template<class T>
aghMatrix<T>::aghMatrix() {
  this->rows = 0;
  this->cols = 0;
}

template<class T>
aghMatrix<T>::~aghMatrix() {
  this->rows=0;
  this->cols=0;
  /*for( int i=0 ; i<this->rows ; ++i ) {
    delete [] this->matrix[i];
  }
  delete [] this->matrix;*/
}

template<class T>
aghMatrix<T>::aghMatrix(const aghMatrix<T> &m) {
  this->setSize(m.getRows(),m.getCols());
  if( this->cols == m.getCols() && this->rows == m.getRows() ) {
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        this->matrix[i][j] = m.getItem(i,j);
      }
    }
  }
}

template<class T>
aghMatrix<T>::aghMatrix(int rows, int cols) {
  this->setSize(rows,cols);
}

template<class T>
void aghMatrix<T>::setSize(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->matrix = new T*[this->rows];
  for( int i=0 ; i<this->rows ; ++i ) {
    this->matrix[i] = new T[this->cols];
  }
}

template<class T>
void aghMatrix<T>::setItem(int r, int c, T value) {
  this->matrix[r][c] = (T)value;
}

template<class T>
void aghMatrix<T>::setItems(T *pt) {
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      this->matrix[i][j] = *pt;
      ++pt;
    }
  }
}
  
template<class T>
void aghMatrix<T>::setItems(int r, int c,...) {
  if( this->rows = 0 || this->cols == 0 ) {
    this->setSize(r,c);
  }
  va_list ap;
  va_start(ap, c);
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      this->matrix[i][j] = va_arg(ap,T);
    }
  }
  va_end(ap);
}

template<class T>
void aghMatrix<T>::print() {
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      cout << "[" << this->matrix[i][j] << "]";
    }
    cout << endl;
  }
}

template<class T>
aghMatrix<T> aghMatrix<T>::operator*(aghMatrix &m) {
  if( this->cols != m.getRows() ) {
    throw aghException(0, "Matrixes don't match", __FILE__, __LINE__);
  }
  aghMatrix result(this->rows,m.getCols());
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0,endj=m.getCols() ; j<endj ; ++j ) {
      T t=0;
      for( int k=0 ; k<this->cols ; ++k ) {
        t += this->matrix[i][k]*m.getItem(k,j) ;
        //c = c.add(Complex(this->matrix[i][k]).mul(m.get(k,j)));
        //cout << "mul: [" << i << "," << k << "] * [" << k << "," << j << "]\n" ;
      }
      result.setItem(i,j,t);
    }
  }
  return result;
}

template<class T>
T aghMatrix<T>::operator()(int r, int c) {
  if( r > this->rows || c > this->cols ) {
    throw aghException(0, "Index out of range", __FILE__, __LINE__);
  }
  return this->matrix[r][c];
}

template<class T>
char aghMatrix<T>::addChars(char a, char b) {
  //cout << a << "," << (((int)a-97)+((int)b-97)) << endl;
  //return (char)(((int)a-97+(int)b-97)%26);
}

template<>
void aghMatrix<char>::setItems(int r, int c,...) {
  va_list ap;
  va_start(ap, c);
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0 ; j<this->cols ; ++j ) {
      this->matrix[i][j] = (char)va_arg(ap,int);
    }
  }
  va_end(ap);
}

template<class T>
aghMatrix<T> aghMatrix<T>::operator+(aghMatrix<T> &m) {  
  if( this->cols != m.getCols() || this->rows != m.getRows() ) {
    throw aghException(0, "Matrixes don't match", __FILE__, __LINE__);
  }
  aghMatrix result(this->rows, m.getCols());
  for (int i = 0; i < this->rows; ++i) {
    for (int j = 0; j < this->cols; ++j) {
      result.setItem(i,j,this->matrix[i][j] + m.getItem(i,j));
    }
  }
  return result;
}
/*
template<>
aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> &m) {
  if( this->rows == m.getRows() && this->cols == m.getCols() ) {
    aghMatrix<char> result(this->rows,this->cols);
    for( short i=0 ; i<this->rows ; ++i ) {
      for( short j=0 ; j<this->cols ; ++j ) {
        char x = this->addChars(this->matrix[i][j],m.getItem(i,j));
        result.setItem(i,j,x);
      }
    }
    return result;
  }
}*/

template<class T>
bool aghMatrix<T>::operator==(aghMatrix &m) {
  if( this->cols != m.getCols() || this->rows != m.getRows() ) {
    return false;
  }
  for (int i = 0; i < this->rows; ++i) {
    for (int j = 0; j < this->cols; ++j) {
      if(this->matrix[i][j] != m.getItem(i,j)) {
        return false;
      }
    }
  }
  return true;
}

template<class T>
bool aghMatrix<T>::operator!=(aghMatrix &m) {
  if( this->cols != m.getCols() || this->rows != m.getRows() ) {
    return true;
  }
  for (int i = 0; i < this->rows; ++i) {
    for (int j = 0; j < this->cols; ++j) {
      if(this->matrix[i][j] != m.getItem(i,j)) {
        return true;
      }
    }
  }
  return false;
}

template<class T>
void aghMatrix<T>::operator=(aghMatrix<T> &m) {
  if( this->rows != m.getRows() || this->cols != m.getCols() ) {
    this->setSize(m.getRows(),m.getCols());
  }
  if( this->cols == m.getCols() && this->rows == m.getRows() ) {
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        this->matrix[i][j] = m.getItem(i,j);
      }
    }
  }
}
