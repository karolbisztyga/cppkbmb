#include "aghInclude.h"

using namespace std;

int main() {

  AghMatrix<int> aghM(4,2);
  int tab[] = {1,5,8,2,6,2,9,9};
  aghM.setItems(2,2,3,4,6,7,0,9,1,2);
  aghM.print();
  cout << endl;
  aghM.setItems(tab);
  aghM.print();

  cout << endl;
  return 0;
}
