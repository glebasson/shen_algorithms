#include <iostream>
#include <map>

int main(){
	std::string str;
	std::cin >> str;
	
	std::map<char, int> frequncy;
	for ( auto el : str ) {
		frequncy[el]++;
	}

	for ( auto &el : frequncy) {
		std::cout << el.first << ":" << el.second << std::endl;
	}
	
}