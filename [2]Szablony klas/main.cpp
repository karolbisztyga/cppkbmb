#include "aghInclude.h"

using namespace std;

int main() {

  AghMatrix<int> aghM1(4,2);
  AghMatrix<int> aghM2(2,4);
  int tab[] = {1,5,8,2,6,2,9,9};
  aghM1.setItems(2,2,3,4,6,7,0,9,1,2);
  aghM1.print();
  cout << " x " << endl;
  aghM2.setItems(tab);
  aghM2.print();

  cout << " = ";
  cout << endl;
  (aghM1*aghM2).print();

  cout << endl;
  return 0;
}
