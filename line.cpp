#include "line.h"

template <typename T>
line2<T>::line2(const point2<T> &first, const point2<T> &second) {
	this->first = first;
	this->second = second;
}

template <typename T>
point2<T> line2<T>::getFirst() const {
	return first;
}

template <typename T>
point2<T> line2<T>::getSecond() const {
	return second;
}

template <typename T>
void line2<T>::setFirst(const point2<T> &first) {
	this->first = first;
}

template <typename T>
void line2<T>::setSecond(const point2<T> &second) {
	this->second = second;
}

template <typename T>
bool line2<T>::operator==(const line2<T> &other) {
	if (first == other.first && second == other.second) {
		return true;
	} else {
		return false;
	}
}