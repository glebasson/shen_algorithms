#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	int i = 0;
	int sum = 0;
	while (sum < n) {
		if (n - sum > 2*(i+1)) {
			v.push_back(++i);
			sum += i;
		} else {
			v.push_back(n-sum);
			sum += n-sum;
		}
	}

	std::cout << v.size() << std::endl;
	for (auto &el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}