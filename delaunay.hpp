#pragma once

#include "point.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <utility>

#include <GL/glut.h>

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
static side get_side(
    const point2<T> &start,
    const point2<T> &end,
    const point2<T> &point)
{
    T value = (point.x - start.x) * (end.y - start.y) -
        (point.y - start.y) * (end.x - start.x);
    return value <= 0 ? side::left : side::right;
}

template <typename T>
static typename std::list<T>::iterator next_iter(
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
void draw_triangles(const std::vector<triangle2<T>*> *triangles) {
    glBegin(GL_LINES);
    for (const auto &t : *triangles) {
        auto v = t->vertices;
        glVertex2f(v[0]->x, v[0]->y);
        glVertex2f(v[1]->x, v[1]->y);
        glVertex2f(v[1]->x, v[1]->y);
        glVertex2f(v[2]->x, v[2]->y);
        glVertex2f(v[2]->x, v[2]->y);
        glVertex2f(v[0]->x, v[0]->y);
    }
    glEnd();
}

template <typename T>
static bool operator==(
    const std::pair<point2<T>*, point2<T>*> &left,
    const std::pair<point2<T>*, point2<T>*> &right)
{
    if (left.first->x == right.first->x &&
        left.first->y == right.first->y &&
        left.second->x == right.second->x &&
        left.second->y == right.second->y)
    {
        return true;
    } else {
        return false;
    }
}

template <typename T>
std::vector<triangle2<T>*> *delaunay::triangulate(
    std::vector<point2<T>> &points)
{
    typedef std::pair<point2<T>*, point2<T>*> line2;

    if (points.size() < 3) return nullptr;

    std::sort(points.begin(), points.end());

    auto result = new std::vector<triangle2<T>*>;
    std::list<line2> hull;

    auto first_triangle = new triangle2<T>;
    if (get_side(points[0], points[1], points[2]) == side::left) {
        first_triangle->vertices.push_back(&points[0]);
        first_triangle->vertices.push_back(&points[1]);
        first_triangle->vertices.push_back(&points[2]);
        hull.push_back(line2(&points[0], &points[1]));
        hull.push_back(line2(&points[1], &points[2]));
        hull.push_back(line2(&points[2], &points[0]));
    } else {
        first_triangle->vertices.push_back(&points[1]);
        first_triangle->vertices.push_back(&points[0]);
        first_triangle->vertices.push_back(&points[2]);
        hull.push_back(line2(&points[1], &points[0]));
        hull.push_back(line2(&points[0], &points[2]));
        hull.push_back(line2(&points[2], &points[1]));
    }
    result->push_back(first_triangle);

    for (size_t i = 3; i < points.size(); i++) {
        auto it = hull.begin();
        while (true) {
            if (side::right == get_side(*it->first, *it->second, points[i])) {
                auto new_triangle = new triangle2<T>;
                new_triangle->vertices.push_back(it->first);
                new_triangle->vertices.push_back(&points[i]);
                new_triangle->vertices.push_back(it->second);
                result->push_back(new_triangle);

                auto top_line = line2(&points[i], it->second);
                auto bottom_line = line2(it->first, &points[i]);

                auto top_line_r = line2(it->second, &points[i]);
                auto bottom_line_r = line2(&points[i], it->first);

                it = prev_iter<line2>(it, hull.begin(), hull.end());
                if (*it == bottom_line_r)
                {
                    if ((it = hull.erase(it)) == hull.end()) {
                        it = hull.begin();
                    }
                } else {
                    it = next_iter<line2>(it, hull.begin(), hull.end());
                    it = hull.insert(it, bottom_line);
                    it = next_iter<line2>(it, hull.begin(), hull.end());
                }

                it = next_iter<line2>(it, hull.begin(), hull.end());
                if (*it == top_line_r)
                {
                    if ((it = hull.erase(it)) == hull.end()) {
                        it = hull.begin();
                    }
                    it = prev_iter<line2>(it, hull.begin(), hull.end());
                } else {
                    it = hull.insert(it, top_line);
                    it = prev_iter<line2>(it, hull.begin(), hull.end());
                }

                if ((it = hull.erase(it)) == hull.end()) {
                    it = hull.begin();
                }
            }
            it = next_iter<line2>(it, hull.begin(), hull.end());
            if (it == hull.begin()) {
                break;
            }
        }
    }

    return result;
}
