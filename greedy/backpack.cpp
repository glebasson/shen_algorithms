#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator> 
#include <iomanip>

// Problem: just casual continius backpack problem
// input max W, c_i, w_i
// maximaize sum c_i * wi_i, with respect of sum w_i <= W

using P = std::pair<int,double>;

double maximize_backpack(std::vector<P> v, int &maxweight) {
  int weight = 0;
  double value = 0;
  for (auto &el : v) {
    if ( (weight + el.second) <= maxweight) {
      value += el.first;
      weight += el.second;
    } else {
      value += el.first/el.second * (maxweight - weight);
      break;
    }
  }
  return value;
}

int main(void) {
  int n, w;
  std::cin >> n;
  std::cin >> w;

  std::vector<std::pair<int,double>> cw(n);
  int tmp;
  for ( auto &el : cw ) {
    std::cin >> el.first;
    std::cin >> el.second;
  }

  std::sort(cw.begin(), cw.end(), [](P &left, P &right){
    return (left.first)/left.second > (right.first)/right.second;
  });

  double max = maximize_backpack(std::move(cw), w);
  std::cout << std::fixed << std::setprecision(3) << max << std::endl; 

}