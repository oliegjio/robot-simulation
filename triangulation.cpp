#include "triangulation.h"

#include <algorithm>
#include <vector>

#include "circular_list.h"

template <typename T>
side triangulation<T>::get_side(
	const line<T> &line,
	const point<T> &point)
{
	T value = (point.getX() - line.getFirst().getX()) *
		(line.getSecond().getY() - line.getFirst().getY()) -
		(point.getY() - line.getFirst().getY()) *
		(line.getSecond().getX() - line.getFirst().getX());
	return value <= 0 ? side::left : side::right;
}

template <typename T>
line_shape<T> *triangulation<T>::triangulate(const point_shape<T> &shape)
{
	if (shape.size() < 3) return nullptr;

	auto points = shape.get_points();

	std::sort(points.begin(), points.end());

	auto lines = new std::vector<line<T>>;
	std::list<line<T>> hull;

	if (get_side(line<T>(points[0], points[1]), points[2]) == side::left) {
		hull.push_back(line<T>(points[0], points[1]));
		hull.push_back(line<T>(points[1], points[2]));
		hull.push_back(line<T>(points[2], points[0]));
	}
	else {
		hull.push_back(line<T>(points[1], points[0]));
		hull.push_back(line<T>(points[0], points[2]));
		hull.push_back(line<T>(points[2], points[1]));
	}
	lines->push_back(line<T>(points[0], points[1]));
	lines->push_back(line<T>(points[1], points[2]));
	lines->push_back(line<T>(points[2], points[0]));

	for (size_t i = 3; i < points.size(); i++) {
		auto it = hull.begin();
		while (true) {
			if (side::right == get_side(*it, points[i])) {
				lines->push_back(line<T>(it->getFirst(), points[i]));
				lines->push_back(line<T>(points[i], it->getSecond()));

				auto top_line = line<T>(points[i], it->getSecond());
				auto bottom_line = line<T>(it->getFirst(), points[i]);

				auto top_line_r = line<T>(it->getSecond(), points[i]);
				auto bottom_line_r = line<T>(points[i], it->getFirst());

				it = prev_iter<line<T>>(it, hull.begin(), hull.end());
				if (*it == bottom_line_r)
				{
					if ((it = hull.erase(it)) == hull.end()) {
						it = hull.begin();
					}
				}
				else {
					it = next_iter<line<T>>(it, hull.begin(), hull.end());
					it = hull.insert(it, bottom_line);
					it = next_iter<line<T>>(it, hull.begin(), hull.end());
				}

				it = next_iter<line<T>>(it, hull.begin(), hull.end());
				if (*it == top_line_r)
				{
					if ((it = hull.erase(it)) == hull.end()) {
						it = hull.begin();
					}
					it = prev_iter<line<T>>(it, hull.begin(), hull.end());
				}
				else {
					it = hull.insert(it, top_line);
					it = prev_iter<line<T>>(it, hull.begin(), hull.end());
				}

				if ((it = hull.erase(it)) == hull.end()) {
					it = hull.begin();
				}
			}
			it = next_iter<line<T>>(it, hull.begin(), hull.end());
			if (it == hull.begin()) {
				break;
			}
		}
	}

	return new line_shape<T>(*lines);
}

template class triangulation<int>;
template class triangulation<float>;