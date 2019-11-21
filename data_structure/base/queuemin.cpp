#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
		if(head == nullptr) return(-1);
		return(head->currentmax);
	}

	void pop() {
		if(head != nullptr) head = head->prev;
	}
};

struct mindeque {
	minstack pushstack, popstack;

	void pushback(int q) {
		pushstack.push(q);
	}

	void popfront() {
		if(popstack.head == nullptr) {
			while(pushstack.head != nullptr) {
				int temp = pushstack.head->value;
				pushstack.pop();
				popstack.push(temp);
			}
		}
		popstack.pop();
	}

	int getmax() {
		return(std::max(pushstack.getmax(), popstack.getmax()));
	}
};

int main() {
	int n, m;
	std::cin >> n;
	std::vector<int> ar(n);
	int temp;
	for (int i = 0; i < n; ++i) {
		std::cin >> temp;
		ar[i] = temp;
	}
	std::cin >> m;
	mindeque deque;
	for (int i = 0; i < m; ++i) {
		deque.pushback(ar[i]);
	}
	std::cout << deque.getmax();
	for (int i = m; i < n; ++i) {
		deque.pushback(ar[i]);
		deque.popfront();
		std::cout << " " << deque.getmax();
	}
}