#include <iostream>
#include <vector>

template<typename T>
void in_order(std::vector<T>& tree, int n) {
    in_order(tree, tree[n*3 + 1]);
    std::cout << tree[n*3] << " ";
    in_order(tree, tree[n*3 + 2]);
}

template<typename T>
void pre_order(std::vector<T>& tree, int n) {
    std::cout << tree[n*3] << " ";
    pre_order(tree, tree[n*3 + 1]);
    pre_order(tree, tree[n*3 + 2]);
}

template<typename T>
void post_order(std::vector<T>& tree, int n) {
    post_order(tree, tree[n*3 + 1]);
    post_order(tree, tree[n*3 + 2]);
    std::cout << tree[n*3] << " ";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> tree(n*3);
    for (int i=0; i<n; ++i) {
        std::cin >> tree[i];
        std::cin >> tree[i+1];
        std::cin >> tree[i+2];
    }
    in_order(tree, 0);
    std::cout << "\n";
    // pre_order(tree, 0);
    // std::cout << "\n";
    // post_order(tree, 0);
    // std::cout << "\n";
}