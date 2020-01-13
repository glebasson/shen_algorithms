#include <iostream>
#include <algorithm>

/**
 * Suplimentory structure for set
 */
template <class T>
struct cell {
    int rank = 0;
    int parent = 0;
    T el;
};

/**
 * Set data structure implementation.
 * Path compression enabled
 */
template <class T>
class set {
    public:
    cell<T> *arr = nullptr;
    set(int n) {
        arr = new cell<T>[n];
    }

    int find(int i) {
        if (i != arr[i].parent) {
            arr[i].parent = find(arr[i].parent); // path compression goes here
        }
        return arr[i].parent;
    }

    void makeset(int i) {
        arr[i].rank = 0;
        arr[i].parent = i;
    }

    void Union(int i, int j) {
        int i_id = find(i);
        int j_id = find(j);
        // std::cout << "i_id: "<< i_id << " ";
        // std::cout << "j_id: "<< j_id << "\n";
        if (i_id == j_id) return;
        if (arr[i_id].rank > arr[j_id].rank) {
            arr[j_id].parent = i_id;
        } else {
            arr[i_id].parent = j_id;
            if (arr[i_id].rank == arr[j_id].rank) ++arr[j_id].rank;
        }
    }

};

int main() {
    int n, e, d;
    std::cin >> n;
    std::cin >> e;
    std::cin >> d;
    set<int> myset(n);
    for (int i = 0; i < n; ++i) {
        myset.makeset(i);
    }

    for (int k = 0; k < e; ++k) {
        int i, j;
        std::cin >> i;
        std::cin >> j;
        myset.Union(i-1, j-1);
    }

    for (int k = 0; k < d; ++k) {
        int i, j;
        std::cin >> i;
        std::cin >> j;
        if (myset.find(i-1) == myset.find(j-1)) {
            std::cout << 0 << "\n";
            return(0);
        }
    }
    std::cout << 1 << "\n";
    return(0);
}