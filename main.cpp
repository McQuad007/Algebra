#include "polinomy.h"
int main(){

  polinomy a, b, c;
  a.getMonomy(1,"u",-0.5);
  a.getMonomy(2,"x",3);
  a.integ("u");
  a.print();
  return 0;

}
