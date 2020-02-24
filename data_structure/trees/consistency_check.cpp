#include <iostream>
#include <vector>

template <typename T>
void consistency_check(std::vector<T>& tree, int n, std::vector<T>& out) {
    if(tree[n*3 + 1] != -1)
        consistency_check(tree, tree[n*3 + 1], out);
    out.push_back(tree[n*3]);
    if(tree[n*3 + 2] != -1)
        consistency_check(tree, tree[n*3 + 2], out);
}

int main() {
    int n;
    std::cin >> n;
    if (n == 0) { std::cout << "CORRECT" << "\n"; return 0; }
    std::vector<long int> tree(n*3), out;
    for (int i=0; i<n*3; i+=3) {
        std::cin >> tree[i];
        std::cin >> tree[i+1];
        std::cin >> tree[i+2];
    }
    consistency_check(tree, 0, out);
    for(int i=1; i<n; ++i) {
        if (out[i] <= out[i-1]) {
            std::cout << "INCORRECT" << "\n";
            return(0);
        }
    }
    std::cout << "CORRECT" << "\n";
    return(0);
}