#include "line.h"

template <typename T>
line<T>::line(const point<T> &first, const point<T> &second)
	: first(first)
	, second(second) {}

template <typename T>
point<T> line<T>::getFirst() const {
	return first;
}

template <typename T>
point<T> line<T>::getSecond() const {
	return second;
}

template <typename T>
void line<T>::setFirst(const point<T> &first) {
	this->first = first;
}

template <typename T>
void line<T>::setSecond(const point<T> &second) {
	this->second = second;
}

template <typename T>
bool line<T>::operator==(const line<T> &other) {
	if (first == other.first && second == other.second) {
		return true;
	} else {
		return false;
	}
}

template class line<int>;
template class line<float>;