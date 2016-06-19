//
// Created by felixd on 6/18/16.
//

#include <cassert>
#include <cmath>
#include "point.h"

Point::Point(int num_dimensions, bool init_zeros)
        : cluster_(-1),
          dimensions_(num_dimensions) {
    if (init_zeros)
        for (int idx = 0; idx < dimensions_; ++idx)
            data_.push_back(0.0);
}

Point::Point(double x, double y, double z)
        : Point(3, false) {
    data_.clear();
    data_.push_back(x);
    data_.push_back(y);
    data_.push_back(z);
}

Point::Point(const std::vector<double> &data)
        : cluster_(-1) {

    dimensions_ = (int) data.size();
    data_.clear();

    for(const double &d : data) {
        data_.push_back(d);
    }
    // TODO: use copy/insert instead of element-wise copy.
}

// static
double Point::distance(const Point &p1, const Point &p2) {
    assert(p1.dimensions_ == p2.dimensions_);
    double dist = 0.0;

    for (int idx = 0; idx < p1.dimensions_; ++idx) {
        const double tmp = p1.data_[idx] - p2.data_[idx];
        dist += tmp * tmp;
    }
    return sqrt(dist);
}

void Point::add(const Point &point) {
    assert(dimensions_ == point.dimensions_);
    for (int idx = 0; idx < dimensions_; ++idx) {
        data_[idx] += point.data_[idx];
    }
}

std::ostream &operator<<(std::ostream &target, const Point &point) {
    target << "[";
    for (const double &d : point.data_) {
        target << d <<", ";
    }
    //target << "\b\b";
    target << "]";
    return target;
}
