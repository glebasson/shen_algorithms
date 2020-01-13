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

    int Union(int i, int j) {
        int i_id = find(i);
        int j_id = find(j);
        // std::cout << "i_id: "<< i_id << " ";
        // std::cout << "j_id: "<< j_id << "\n";
        if (i_id == j_id) return arr[i_id].el;
        if (arr[i_id].rank > arr[j_id].rank) {
            arr[j_id].parent = i_id;
            arr[i_id].el += arr[j_id].el;
            return arr[i_id].el;
        } else {
            arr[i_id].parent = j_id;
            if (arr[i_id].rank == arr[j_id].rank) ++arr[j_id].rank;
            arr[j_id].el += arr[i_id].el;
            return arr[j_id].el;
        }
    }

};

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    set<int> myset(n);
    int mmax = 0;
    for (int i = 0; i < n; ++i) {
        myset.makeset(i);
        int temp;
        std::cin >> temp;
        mmax = std::max(mmax, temp);
        myset.arr[i].el = temp;
    }

    for (int i = 0; i < m; ++i) {
        int src, dest;
        std::cin >> dest;
        std::cin >> src;
        mmax = std::max(mmax, myset.Union(dest-1, src-1));
        std::cout << mmax << "\n";
    }
    return(0);
}