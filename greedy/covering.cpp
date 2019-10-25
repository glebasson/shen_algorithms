#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator> 

using Segment = std::pair<int, int>;

std::vector<int> get_covering_set(std::vector<Segment> segments) {
  std::vector<int> cover_set;
  int most_right = segments[0].second;
  cover_set.push_back(most_right);
  for ( auto &s : segments) {
    if (s.first > most_right) {
      most_right = s.second;
      cover_set.push_back(most_right);
    } 
  }
  return(cover_set);
}

int main(){
  int n;
  std::cin >> n;
  std::vector<Segment> segments(n);
  for (auto &s : segments) {
    std::cin >> s.first;
    std::cin >> s.second; 
  }

  std::sort(segments.begin(), segments.end(), [](Segment &left, Segment &right) {
    return left.second < right.second;
  });

  auto points = get_covering_set(std::move(segments));
  std::cout << points.size() << std::endl;
  for (auto point:points) {
    std::cout << point << " ";
  }
  std::cout << std::endl;
}