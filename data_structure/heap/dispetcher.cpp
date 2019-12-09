#include <iostream>
#include <vector>
#include <queue>

// pair(endtime, procnumber)

int main() {
	int n, m;
	std::cin >> n;
	std::cin >> m;
	typedef std::pair<long int, long int> p;
	auto cmp = [](p left, p right) {
		if (left.first == right.first) {
			return left.second > right.second;
		}
		return left.first > right.first; 
	};
	std::priority_queue<p, std::vector<p>, decltype(cmp)> heap(cmp);
	int temp;
	int k = std::min(n, m);
	for (int i = 0; i < k; ++i)
	{
		std::cin >> temp;
		heap.push(p(temp, i));
		std::cout << i << " " << 0 << "\n";
	}
	for (int i = n; i < m; ++i)
	{
		std::cin >> temp;
		p t = heap.top();
		std::cout << t.second << " " << t.first << "\n";
		heap.pop();
		heap.push(p(t.first + temp, t.second));
		
	}
	return(0);
}
