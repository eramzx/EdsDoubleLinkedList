#include "edslist.h"
template <class T>
EdsList<T>::EdsList() {
	head = nullptr;
	tail = nullptr;
	list_size = 0;
}
template <class T>
EdsList<T>::~EdsList() {
	clear();
}
template <class T>
size_t EdsList<T>::size() const {
	return list_size;
}
template <class T>
bool EdsList<T>::empty() const {
	return list_size <= 0 ? true : false;
}
template <class T>
void EdsList<T>::push_front(const T& value) {
	node<T>* new_node = new node<T>;
	new_node->value = value;
	new_node->next = head;
	if (empty())
		tail = new_node;
	else
		tail->prev = new_node;
	head = new_node;
	list_size++;
}
template <class T>
void EdsList<T>::push_back(const T& value) {
	node<T>* new_node = new node<T>;
	new_node->value = value;
	new_node->prev = tail;
	if (empty())
		head = new_node;
	else
		tail->next = new_node;
	tail = new_node;
	list_size++;
}
template <class T>
void EdsList<T>::pop_front() {
	if (empty())
		throw std::underflow_error("Exception: pop_front()");
	node<T>* delete_node = head;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	else
		head->prev = nullptr;
	delete delete_node;
	list_size--;
}
template <class T>
void EdsList<T>::pop_back() { 
	if (empty())
		throw std::underflow_error("Exception: pop_back()");
	node<T>* delete_node = tail;
	tail = tail->prev;
	if (tail == nullptr)
		head = nullptr;
	else
		tail->next = nullptr;
	delete delete_node;
	list_size--;
}
template <class T>
void EdsList<T>::clear() {
	node<T>* delete_pointer;
	node<T>* traversal_ptr = head;
	while (traversal_ptr != nullptr) {
		delete_pointer = traversal_ptr;
		traversal_ptr = traversal_ptr->next;
		delete delete_pointer;
	}
	head = nullptr;
	tail = nullptr;
	list_size = 0;
}
template <class T>
void EdsList<T>::print() const {
	//special case testing
	if (empty()) { 
		std::cout << "Empty!" << std::endl;
		return;
	}
	if (size() == 1) {
		std::cout << head->value << std::endl;
		return;
	}//::end special case testing
	node<T>* traversal = head;
	std::cout << "Forward: ";
	while (traversal != nullptr) {
		std::cout << traversal->value << ' ';
		traversal = traversal->next;
	}
	std::cout << std::endl << "Reverse: ";
	traversal = tail;
	while (traversal != nullptr) {
		std::cout << traversal->value << ' ';
		traversal = traversal->prev;
	}
	std::cout << std::endl;
}
