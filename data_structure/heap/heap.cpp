// there was heap implementation
// #include <random>
// #include <algorithm>
// #include <iterator>
// #include <iostream>
// #include <functional>
// #include <unordered_map>

// // use standart libs for generating random vector

// int main() {
// 	// First create an instance of an engine.
//     std::random_device rnd_device;
//     // Specify the engine and distribution.
//     std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
//     std::uniform_int_distribution<int> dist {1, 52};

//     auto gen = [&dist, &mersenne_engine](){
//                    return dist(mersenne_engine);
//                };

//     // here goes problem solving
//     int n = 1000;
//     std::vector<int> vec(n);
//     std::generate(std::begin(vec), std::end(vec), gen);

//     int min = vec[0];
//     int max = vec[0];
//     int sum = 0;
//     std::unordered_map<int, int> dict;

//     for(auto &el: vec) {
//     	if (el < min) min = el;
//     	if (el > max) max = el;
//     	sum += el;
//     	if (dict.find(el) == std::end(dict)) {
//     		dict[el] = 1;
//     	} else {
//     		++dict[el];
//     	}
//     }



//     std::cout << "min: " << min << "\n";
//     std::cout << "max: " << max << "\n";
//     std::cout << "mean: " << float(sum/n) << "\n";

//     min = (*dict.begin()).second;
//     int least;
//     max = (*dict.begin()).second;
//     int most;
//     for (auto &el: dict) {
// 	    if (el.second < min) {min = el.second; least = el.first;}
//     	if (el.second > max) {max = el.second; most = el.first;}
// 	}
// 	std::cout << "least: " << least << " encountered " << min << " times" << "\n";
//     std::cout << "most: " << most << " encountered " << max << " times" << "\n";

// 	return(0);
// }
