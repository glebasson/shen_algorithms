#include <cassert>
#include <iostream>

class GCD final {
 public:
  static int naive(int &a, int &b) {
    int gcd=1;
    for(int i=2; i<=std::min(a, b); i++) {

      if((a % i == 0) && (b % i == 0)) {
        gcd = i;
      }
    }
    return(gcd);
  }

  static int euclid(const int &a, const int &b) {
    if (a%b == 0) {
      return b;
    }
    return euclid(b, a%b);
  }

 private:
  static int euclid_recurent(int &a, int &b) {
    if(a>=b) return(euclid(a,b));
    else return(euclid(b,a));
  }

};

int main(void) {
  int a, b;
  std::cin >> a >> b;
  std::cout << GCD::euclid(a, b) << std::endl;
  return 0;
}