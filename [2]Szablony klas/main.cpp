#include "aghInclude.h"

using namespace std;

int main() {

  AghMatrix<int> aghM(3,2);
  int tab[] = {1,5,8,2,6,2};
  aghM.setItems(2,2,3,4,6,7,0,1);
  aghM.print();
  cout << endl;
  aghM.setItems(tab);
  aghM.print();

  cout << endl;
  return 0;
}
