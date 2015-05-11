#include "aghInclude.h"

using namespace std;
/*
int max(int n, ...) {
  va_list ap;
  va_start(ap, n);
  int max = va_arg(ap, int);
  for(int i = 2; i <= n; i++) {
      int a = va_arg(ap, int);
      if(a > max) max = a;
  }
  va_end(ap);
  return max;
}
*/
int main() {

  AghMatrix<int> aghM(2,2);
  cout << max(5,1,2,3,4,5) << " " ;
  cout << "Siema..." ;

  cout << endl;
  return 0;
}
