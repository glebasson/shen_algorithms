/** 
	This implementation of hash table works slow because
	new take too long time in c++ (one el memory allocation)
*/
#include <algorithm>
#include <iostream>
#include <string>

template<typename T>
struct el {
	el *next = nullptr;
	T content;
};

template<typename T>
class onewaylist {
	public:
	el<T> *begin = nullptr;
	// onewaylist(T init) {
	// 	begin = new el<T>;
	// 	begin->content = init;
	// }

	void addnew(T newel) {
		el<T> *old = begin;
		begin = new el<T>;
		begin->content = newel;
		begin->next = old;
	}

	el<T>* find (T element) {
		el<T>* iter = begin;
		while (iter->next) {
			if(iter->content == element) return iter;
		}
		return nullptr;
	}

	void del(T element) {
		el<T>* iter = begin;
		el<T>* prev = nullptr;
		while (iter->next) {
			if(iter->content == element) {
				prev->next = iter->next;
				delete iter;
				return;
			}
			prev = iter;
		}
	}

};

template<class T>
class hashtable {
	private:
	int hashfunction() {

	}
	public:
	onewaylist<T>* arr = nullptr;

	hashtable(int m) {
		arr = new onewaylist<T>[m];
	}

	void 

	void addstr(T newel) {
		onewaylist<T> l = arr[hashfunction(newel)];
		if(!l.find(newel))
			l.addnew(newel);
	}

	void delstr(T newel) {
		arr[hashfunction(newel)].del(newel);
	}

	std::string findstr(T newel) {
		if(arr[hashfunction(newel)].find(newel)) return("yes");
		return("no");
	}

};

int main() {
	std::string mystr("hi man");
	std::cout << mystr[0] << "\n";
}