//
// Created by redpanda on 7/19/2025.
//

#include "Copyright.h"

namespace Support {
    Copyright::Copyright(std::string publisher, unsigned int year, std::string month) :
        publisher(std::move(publisher)), year(year), month(std::move(month)) { }

    std::string Copyright::getPublisher() const {
        return publisher;
    }

    unsigned int Copyright::getYear() const {
        return year;
    }

    std::string Copyright::getMonth() const {
        return month;
    }

    std::string Copyright::toString() const {
        return std::format("(C){0} {1} {2}", publisher, std::to_string(year), month);
    }

} // Support
