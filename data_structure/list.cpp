#include <iostream>
#include <vector>

// find max in moving window

template < typename T > 
struct node {
	node *prev=NULL;
	T data;
};

void updatemax(int val, std::pair<int, int> &el) {
	if( val > el.first ) {el.first=val; el.second=1;}
	else if ( val == el.first ) el.second++;
}

template < typename T > 
struct queue {

	node<T> *front = NULL;
	node<T> *back = NULL;
	int len=0;

	void push(const T& value) {
		node<T> *n = new node<T>;
		n->data = value;
		if (back) {
			back->prev = n;
		}
		back = n;
		if (len==0) front=back;
		len++;
	}

	T getfront() {
		return(front->data);
	}

	T getback() {
		return(back->data);
	}

	int size() {
		return(len);
	}

	T pop() {
		T temp = front->data;
		front = front->prev;
		return(temp);
	}

	std::pair<int, int> findmax() {
		std::pair<int, int> max;
		max.first = back->data;
		max.second = 1;

		for (node<int> *el = front; el->prev; el=el->prev) {
			updatemax(el->data, max);
		}
		return(max);
	}

};


int main() {
	// queue<int> q;
	// q.push(1);q.push(-100);q.push(6);q.push(0);q.push(-100);q.push(256);q.push(-100); 
	// std::pair<int, int> min = q.findmin();
	// std::cout << min.first << " " << min.second << std::endl;

	std::vector<int> v;
	int n, m;
	std::cin >> n;
	for (int i=0; i < n; i++) {int temp; std::cin >> temp; v.push_back(temp);}
	std::cin >> m;

	queue<int> q;
	for (int i=0; i < m; i++) {
		q.push(v[i]);
	}
	std::pair<int, int> max = q.findmax();
	std::cout << max.first << " ";

	for (int i=m; i < n; i++) {
		q.push(v[i]);
		if( q.getback() > max.first ) updatemax(q.getback(), max);
		if( q.getback() == max.first ) max.second++;

		int out = q.pop();
		if (out == max.first && max.second > 1) max.second--;
		if (out == max.first && max.second == 1) {
			max = q.findmax();
		}
		std::cout << max.first << " ";
	}
	std::cout << std::endl;
	return(0);
}