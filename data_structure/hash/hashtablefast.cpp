/** 
	Fast using builtin unordered_map
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#define MAX_LENGTH 15

// never do this
int m;

class MyHashFunction {
	private:
	int p = 1000000007;
	int x = 263;
	long int precalculated[MAX_LENGTH];

	public:
	MyHashFunction() {
		precalculated[0] = 1;
		for (int i=1; i < MAX_LENGTH; ++i) {
			precalculated[i] = precalculated[i-1] * x % p;
		}
	}

    size_t operator()(const std::string& s) const {
        long key = 0;
		for (int i=0; i < s.size(); ++i) {
			int adit = (int)s[i] * precalculated[i] % p;
			key = (key + adit) % p;
		}
		// std::cout << m << "\n";
		return key % m;
    } 
};

template <typename... Types>
class MyHashTable : public std::unordered_map<Types...> {
	typedef std::unordered_map<Types...> map;
	public:
	MyHashTable(int size) {
		map::rehash(size);
		map::reserve(100000);
	}
};

int main() {
	int n;
	std::cin >> m;
	MyHashTable<std::string, int, MyHashFunction> umap(m);
	std::cin >> n;
	std::string s;
	for (int i=0; i<n; ++i) {
		std::cin >> s;
		if (s == "add") {
			std::cin >> s;
			if(umap.find(s) == umap.end()) umap[s] = 1;
		} else if (s == "check") {
			std::cin >> s;
			int num = std::stoi(s);
			for (auto it = umap.begin(num); it != umap.end(num); ++it) std::cout << it->first << " ";
			std::cout << "\n";
		} else if (s == "find") {
			std::cin >> s;
			if(umap.find(s) != umap.end()) std::cout << "yes" << "\n";
			else std::cout << "no" << "\n";
		} else if (s == "del") {
			std::cin >> s;
			auto it = umap.find(s);
			if(it != umap.end()) umap.erase(it); 
		}
	}
	return(0);
}