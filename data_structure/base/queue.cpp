#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct el {
	el* prev=nullptr;
	int endtime;
};


struct queue {
	el* head = nullptr;
	el* tail = nullptr;
	int len = 0;
	void push(int timestomp) {
		el *tmp = new el();
		tmp->endtime = timestomp;
		if (len == 0) {
			head = tmp;
			tail = head;
		}
		else {
			tail->prev = tmp;
			tail = tmp;
		}
		len++;
	}

	void pop() {
		head = head->prev;
		len--;
	}
};

void delcomplited(queue &q, int timestomp) {
	while (q.head != nullptr) {
		if (q.head->endtime <= timestomp) {
			// std::cout << q.head->endtime << "\n";
			q.pop();
		}
		else break;
		
	}
}

void printqueue(queue &q) {
	std::cout << "queue now: head->";
	el* tmp = q.head;
	while(tmp != nullptr) {
		std::cout << tmp->endtime << " ";
		tmp = tmp->prev;
	}
	std::cout << "<-tail" << "\n";
}

int main() {
	int n, bufsize;
	std::cin >> bufsize;
	std::cin >> n;
	int arrival, duration;
	queue qu;
	for (int i = 0; i < n; ++i) {
		// printqueue(qu);
		std::cin >> arrival;
		std::cin >> duration;
		delcomplited(qu, arrival);
		if(qu.len < bufsize) {
			if(qu.head == nullptr) {
				std::cout << arrival << "\n";
				qu.push(arrival + duration);
			} else {
				std::cout << qu.tail->endtime << "\n";
				qu.push(qu.tail->endtime + duration);
			}
		} else {std::cout << -1 << "\n";}
	}

	return(0);
}