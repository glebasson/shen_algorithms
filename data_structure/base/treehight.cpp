#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct tree {
	std::vector<tree*> children;
	tree* parent = nullptr;

	int height(){
		if(children.size()) {
			int max=0;
			for (int i = 0; i < children.size(); ++i) {
				max = std::max(max, children[i]->height());
			}
			return(max + 1);
		}
		else {
			return(1);
		}
	}
};

int main() {
	int n;
	std::cin >> n;
	std::vector<tree> treearray(n);
	int ind, root;
	for (int i = 0; i < n; ++i) {
		std::cin >> ind;
		if(ind == -1){root = i;}
		else {
			treearray[i].parent = &treearray[ind];
			treearray[ind].children.push_back(&treearray[i]);
		}
	}
	std::cout << treearray[root].height() << "\n";
	return(0);
}