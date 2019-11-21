#include <algorithm>
#include <iostream>
#include <string>

struct el {
	int value;
	int currentmax;
	el* prev;
};

struct minstack {
	el* head=nullptr;

	void push(int q) {
		el* h = new el;
		h->value=q;
		h->prev = head;
		if (head==nullptr) {h->currentmax=q;}
		else {h->currentmax = std::max(head->currentmax, q);}
		head = h;
	}

	int getmax() {
		return(head->currentmax);
	}

	void pop() {
		head = head->prev;
	}
};

int main() {
	int n;
	std::cin >> n;
	std::string s;
	minstack stack;
	int tmp;
	for(int i=0; i<n; i++) {
		std::cin >> s;
		if(s == "max") std::cout << stack.getmax() << "\n"; 
		if(s == "push") {std::cin >> tmp; stack.push(tmp);}
		if(s =="pop") stack.pop();
	}
	return(0);
}