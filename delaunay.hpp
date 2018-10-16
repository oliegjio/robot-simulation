#pragma once

#include "point.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template <typename T>
struct triangle2 {
    std::vector<point2<T>*> vertices;
    std::vector<triangle2<T>*> triangles;
};

namespace delaunay {

    template <typename T>
    std::vector<triangle2<T>*> *triangulate(std::vector<point2<T>> &points);

}

enum side {
    left = 0,
    right = 1
};

template <typename T>
static side get_side(const point2<T> &start,
                            const point2<T> &end,
                            const point2<T> &point)
{
    T value = (point.x - start.x) * (end.y - start.y) -
        (point.y - start.y) * (end.x - start.x);
    return value <= 0 ? side::left : side::right;
}

template <typename T>
static typename std::list<T>::iterator next_iter(
    typename std::list<T>::iterator it,                                            const typename std::list<T>::iterator &begin,
    const typename std::list<T>::iterator &end)
{
    it++;
    if (it == end) {
        it = begin;
    }
    return it;
}

template <typename T>
static typename std::list<T>::iterator prev_iter(
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

template <typename T>
std::vector<triangle2<T>*> *delaunay::triangulate(
    std::vector<point2<T>> &points)
{
    if (points.size() < 3) return nullptr;
    std::sort(points.begin(), points.end());
    auto result = new std::vector<triangle2<T>*>;
    // std::list<> hull;

    // Get first triangle:
    auto first_triangle = new triangle2<T>;
    side side = get_side(points[0], points[1], points[2]);
    if (side == side::left) {
        first_triangle->vertices.push_back(&points[0]);
        first_triangle->vertices.push_back(&points[1]);
        first_triangle->vertices.push_back(&points[2]);
    } else {
        first_triangle->vertices.push_back(&points[0]);
        first_triangle->vertices.push_back(&points[1]);
        first_triangle->vertices.push_back(&points[2]);
    }
    result->push_back(first_triangle);

    return result;
}
