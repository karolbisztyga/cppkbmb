#include "aghInclude.h"

using namespace std;

int main() {

  AghMatrix<int> aghM1(2,3);
  AghMatrix<int> aghM2(3,3);
  aghM1.setItems(2,2,-2,-3,1,-1,4,0);
  aghM1.print();
  cout << " x " << endl;
  int tab[] = {-2,-1,2,3,0,1,2,2,-1};
  aghM2.setItems(tab);
  aghM2.print();

  cout << " = ";
  cout << endl;
  (aghM1*aghM2).print();

  cout << endl;
  return 0;
}
