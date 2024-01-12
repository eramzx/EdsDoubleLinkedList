#ifndef EDSLIST_H
#define EDSLIST_H
#include <iostream>
#include "node.h"
template <class T>
class EdsList {
	private:
		node<T>* head;
		node<T>* tail;
		size_t list_size;
	public:
		EdsList();
		~EdsList();
		void push_front(const T&);
		void push_back(const T&);
		void pop_front();
		void pop_back();
		size_t size() const;
		bool empty() const;
		void clear();
		void print() const;
};
template class EdsList<char>;
template class EdsList<float>;
#endif
