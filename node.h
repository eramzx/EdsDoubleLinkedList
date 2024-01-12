#ifndef NODE_H
#define NODE_H
template<class T>
class EdsList;

template <class T>
class node {
	friend class EdsList<T>;
	private:
		T value;
		node<T>* prev;
		node<T>* next;
	public:
		node(const T& = T(), node<T>* = nullptr, node<T>* = nullptr);
};
template <class T>
node<T>::node(const T& data, node<T>* left, node<T>* right) : value(data), prev(left), next(right) {};
#endif
