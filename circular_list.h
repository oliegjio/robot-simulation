#pragma once

#include <list>

template <typename T>
typename std::list<T>::iterator next_iter(
	typename std::list<T>::iterator it,
	const typename std::list<T>::iterator &begin,
	const typename std::list<T>::iterator &end)
{
	it++;
	if (it == end) {
		it = begin;
	}
	return it;
}

template <typename T>
typename std::list<T>::iterator prev_iter(
	typename std::list<T>::iterator it,
	const typename std::list<T>::iterator &begin,
	const typename std::list<T>::iterator &end)
{
	if (it == begin) {
		it = end;
	}
	it--;
	return it;
}