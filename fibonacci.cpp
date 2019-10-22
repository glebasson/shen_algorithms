#include <cassert>
#include <iostream>

class Fibonacci final {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
    int v0, v1=1, v2=0;
    for(int i=1; i<n; i++){
        v0=v1;
        v1=(v2+v1)%10;
        v2=v0;
    }
    return(v1);
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}