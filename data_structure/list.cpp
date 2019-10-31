#include <iostream>

// implementation of stack and solved problem of brackets
template <typename T>
struct node {
	T value;
	int num;
	node *prev;
};

template <typename T>
struct stack {
	node<T> *head = NULL;
	int length = 0;
	void push(const int &value) {
		node<T> *el = new node<T>;
		(*el).value = value;
		(*el).prev = head;
		head = el;
		length++;
	}

	int pop() {
		int a = head->value;
		head = head->prev;
		length--;
		return(a);
	}

	int top() {
		return(head->value);
	}

	int size() {
		return(length);
	}
};

int main() {
	stack<int> st;
	int count = 0;
	char c;
	while (std::cin >> c) {
		if (c == '[' || c == '{' || c == '(') {
			st.push(c);
			st.head->num = count;
		}
		else if (c == ']' || c == '}' || c == ')') {
			if (st.head == NULL){
				std::cout << count << std::endl;
				return(0);
			}
			int top = st.top();
			if ((top == '[' && c == ']') || \
				(top == '{' && c == '}') || \
				(top == '(' && c == ')')) {
				st.pop();
			} else {
				std::cout << count << std::endl;
				return(0);
			}
		}
	}
	if (st.size()) {
		while(st.size() > 1) {
			st.pop();
		}
		std::cout << st.head->num << std::endl;
		return(0);
	}
	std::cout << "Success" << std::endl;

	return(0);
}

