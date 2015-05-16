#ifndef AGHMATRIX_H
#define AGHMATRIX_H

template<class T>

class aghMatrix {
  private:
    T **matrix;
    int rows,cols;

    char addChars(char,char);
    char multipleChars(char,char);
    void setSize(int,int);
    char* multipleWords(char*,char*);
    char* addLetter(char*,char);
  public:
    char* addWords(char*,char*);

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
  aghMatrix<T> operator=(aghMatrix<T>);

//other methods
  void print();

};


/*-----------------------------------------------------------------------------------------------*/

/*          CONSTRUCTORS/DESTRUCTORS          */

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

/*          SETTERS/GETTERS                   */

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

/*          OPERATORS                         */

template<class T>
aghMatrix<T> aghMatrix<T>::operator*(aghMatrix &m) {
  if( this->cols != m.getRows() ) {
    throw aghException(0, "Matrixes don't match", __FILE__, __LINE__);
  }
  aghMatrix result(this->rows,m.getCols());
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0,endj=m.getCols() ; j<endj ; ++j ) {
      T t[this->cols];
      for( int k=0 ; k<this->cols ; ++k ) {
        t[k] = this->matrix[i][k]*m.getItem(k,j) ;
      }
      T addT = t[0];
      for( int l=1 ; l<this->cols ; ++l ) {
        addT = addT+t[l];
      }
      result.setItem(i,j,addT);
    }
  }
  return result;
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

template<class T>
T aghMatrix<T>::operator()(int r, int c) {
  if( r > this->rows || c > this->cols ) {
    throw aghException(0, "Index out of range", __FILE__, __LINE__);
  }
  return this->matrix[r][c];
}

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
aghMatrix<T> aghMatrix<T>::operator=(aghMatrix<T> m) {
  if( this->rows != m.getRows() || this->cols != m.getCols() ) {
    this->setSize(m.getRows(),m.getCols());
  }
  aghMatrix<T> result(this->rows,this->cols);
  if( this->cols == m.getCols() && this->rows == m.getRows() ) {
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        result.setItem(i,j,m.getItem(i,j));
        this->matrix[i][j] = m.getItem(i,j);
      }
    }
  }
  return result;
}

/*          SPECIALIZED                      */

template<>
aghMatrix<char> aghMatrix<char>::operator*(aghMatrix &m) {
  if( this->cols != m.getRows() ) {
    throw aghException(0, "Matrixes don't match", __FILE__, __LINE__);
  }
  aghMatrix result(this->rows,m.getCols());
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0,endj=m.getCols() ; j<endj ; ++j ) {
      char c = 'a';
      for( int k=0 ; k<this->cols ; ++k ) {
        c = this->addChars(c,this->multipleChars(this->matrix[i][k],m.getItem(k,j)));
      }
      result.setItem(i,j,c);
    }
  }
  return result;
}

template<>
aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> &m) {
  if( this->cols != m.getRows() ) {
    throw aghException(0, "Matrixes don't match", __FILE__, __LINE__);
  }
  aghMatrix<char*> result(this->rows,m.getCols());
  for( int i=0 ; i<this->rows ; ++i ) {
    for( int j=0,endj=m.getCols() ; j<endj ; ++j ) {
      char* c = new char[0];
      for( int k=0 ; k<this->cols ; ++k ) {
        c = this->addWords(c,this->multipleWords(this->matrix[i][k],m.getItem(k,j)));
      }
      result.setItem(i,j,c);
    }
  }
  return result;
}

template<>
void aghMatrix<char>::setItems(int r, int c,...) {
  if( this->rows = 0 || this->cols == 0 ) {
    this->setSize(r,c);
  }
  va_list ap;
  va_start(ap, c);
  for( int i=0 ; i<r ; ++i ) {
    for( int j=0 ; j<c ; ++j ) {
      this->matrix[i][j] = (char)va_arg(ap,int);
    }
  }
  va_end(ap);
}

template<>
aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> &m) {
  if( this->rows == m.getRows() && this->cols == m.getCols() ) {
    aghMatrix<char> result(this->rows,this->cols);
    for( short i=0 ; i<this->rows ; ++i ) {
      for( short j=0 ; j<this->cols ; ++j ) {
        char x = this->addChars(this->matrix[i][j],m.getItem(i,j));
        //cout << "\n "<< this->matrix[i][j] << "+" << m.getItem(i,j) << "=" << x <<" \n" ;
        result.setItem(i,j,x);
      }
    }
    return result;
  }
}

template<>
char* aghMatrix<char*>::operator()(int r, int c) {
  char *item = this->getItem(r,c);
  int len=0;
  while( item[len]!='\0' ) {
    ++len;
  }
  char *result = new char[len];
  for( int i=0 ; i<len ; ++i ) {
    result[i] = item[i];
  }
  return result;
}

template<>
aghMatrix<char*> aghMatrix<char*>::operator=(aghMatrix<char*> m) {
  if( this->rows != m.getRows() || this->cols != m.getCols() ) {
    this->setSize(m.getRows(),m.getCols());
  }
  aghMatrix<char*> result(this->rows,this->cols);
  if( this->cols == m.getCols() && this->rows == m.getRows() ) {
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        int counter = 0;
        char *item = m.getItem(i,j);
        while( item[counter]!='\0' ) {
          ++counter;
        }
        char *itemToAdd = new char[counter];
        for( int i=0 ; i<counter ; ++i ) {
          itemToAdd[i] = item[i];
        }
        result.setItem(i,j,itemToAdd);
        this->matrix[i][j] = itemToAdd;
      }
    }
  }
  return result;
}

template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*> &m) {
  if( this->cols != m.getCols() || this->rows != m.getRows() ) {
    return false;
  }
  for (int i = 0; i < this->rows; ++i) {
    for (int j = 0; j < this->cols; ++j) {
      int counter = 0;
      while( this->matrix[i][j][counter]!='\0' ) {
        if( this->matrix[i][j][counter] != m.getItem(i,j)[counter] ) {
          return false;
        }
        ++counter;
      }
    }
  }
  return true;
}


template<>
aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> &m) {
  if( this->rows != m.getRows() || this->cols != m.getCols() ) {
    throw aghException(0, "Matrixes don't match", __FILE__, __LINE__);
  }
  aghMatrix<char*> result(this->rows,this->cols);
  for( short i=0 ; i<this->rows ; ++i ) {
    for( short j=0 ; j<this->cols ; ++j ) {
      result.setItem(i,j,this->addWords(this->matrix[i][j],m.getItem(i,j)));
    }
  }
  return result;
}

/*          OTHER METHODS                     */

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
char aghMatrix<T>::addChars(char a, char b) {
  return (char)((((int)a-97)+((int)b-97))%26 + 97);
}

template<class T>
char aghMatrix<T>::multipleChars(char a,char b) {
  return (char)((((int)a-97)*((int)b-97))%26 + 97);
}

template<class T>
char* aghMatrix<T>::addWords(char *a,char *b) {
  char *result = new char[0];
  int aLen = 0;
  while( a[aLen]!='\0' ) {
    bool add = true;
    int i=0;
    while( result[i]!='\0' ) {
      if( result[i]==a[aLen] ) {
        add = false;
        break;
      }
      ++i;
    }
    if( add ) {
      result = this->addLetter(result,a[aLen]);
    }
    ++aLen;
  }
  int bLen = 0;
  while( b[bLen]!='\0' ) {
    bool add = true;
    int i=0;
    while( result[i]!='\0' ) {
      if( result[i]==b[bLen] ) {
        add = false;
        break;
      }
      ++i;
    }
    if( add ) {
      result = this->addLetter(result,b[bLen]);
    }
    ++bLen;
  }
  return result;
}

template<class T>
char* aghMatrix<T>::multipleWords(char *a,char *b) {
  char *result = new char[0];
  int aCounter = 0;
  while( a[aCounter]!='\0' ) {
    int bCounter = 0;
    while( b[bCounter]!='\0' ) {
      if( a[aCounter] == b[bCounter] ) {
        int resultCounter = 0;
        bool add = true;
        while( result[resultCounter]!='\0' ) {
          if( result[resultCounter]==a[aCounter] ) {
            add = false;
            break;
          }
          ++resultCounter;
        }
        if( add ) {
          result = this->addLetter(result,a[aCounter]);
        }
      }
      ++bCounter;
    }
    ++aCounter;
  }
  return result;
}

template<class T>
char* aghMatrix<T>::addLetter(char *word,char letter) {
  int len = 0;
  while( word[len]!='\0' ) {
    ++len;
  }
  char *result = new char[len+1];
  for( int i=0 ; i<len ; ++i ) {
    result[i] = word[i];
  }
  result[len] = letter;
  return result;
}

#endif