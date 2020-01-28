/** 
	Telephone numbers book
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>


int main() {
    std::vector<std::string> arr(10000000);
	int n;
	std::cin >> n;
	std::string s;
	for (int i=0; i<n; ++i) {
		std::cin >> s;
		if (s == "add") {
			std::cin >> s;
            int num = std::stoi(s);
            std::cin >> s;
			arr[num] = s;
		} else if (s == "find") {
			std::cin >> s;
            int num = std::stoi(s);
			if(!arr[num].empty()) std::cout << arr[num] << "\n";
			else std::cout << "not found" << "\n";
		} else if (s == "del") {
			std::cin >> s;
            int num = std::stoi(s);
			if(!arr[num].empty()) arr[num].clear();
		}
	}
	return(0);
}