/* 
 * File:   TimeTracker.cpp
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#include "TimeTracker.h"

void TimeTracker::startTracking() {
    startTime = std::chrono::steady_clock::now();
}

void TimeTracker::stopTracking() {
    endTime = std::chrono::steady_clock::now();
}

double TimeTracker::getElapsedTime() const {
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    return static_cast<double>(duration.count());
}