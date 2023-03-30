#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <utility>
#include <vector>
#include <set>

int population(std::vector<std::pair<int, int>>& values) {
    std::map<int, int> data;
    for (auto value : values) {
        if (data.count(value.first) == 0)
            data[value.first] = 0;
        if (data.count(value.second) == 0)
            data[value.second] = 0;

        data[value.first]++;
        data[value.second]--;
    }
    int max = 0;
    int current = 0;
    int year = 0;
    for (auto [key, value] : data) {
        current += value;
        if (current > max) {
            max = current;
            year = key;
        }
    }
    return max;
}

using point = std::pair<uint64_t, uint64_t>;
double distance(point p1, point p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double min_distance(std::vector<point> points) {
    std::sort(points.begin(), points.end(), [](point a, point b) { return a.first < b.first; });
    double res = std::numeric_limits<double>::max();

    auto comarator = [](point a, point b) { return a.second < b.second; };
    std::set<point, decltype(comarator)> box;

    box.insert(points[0]);

    int left = 0;

    for (int i = 1; i < points.size(); i++) {
        while (left < points.size() && points[i].first - res > points[left].first)
            box.erase(points[left++]);

        point lower_point = std::make_pair(points[i].first - res, points[i].second - res);
        auto it = box.lower_bound(lower_point);

        for (; it != box.end() && points[i].second + res > it->second; it++)
            res = std::min(res, distance(points[i], *it));

        box.insert(points[i]);
    }
    return res;
}