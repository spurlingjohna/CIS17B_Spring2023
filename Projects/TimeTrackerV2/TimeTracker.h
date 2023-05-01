/* 
 * File:   TimeTracker.h
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

/* 
 * File:   TimeTracker.h
 * Author: andrewspurling
 *
 * Created on April 30, 2023, 1:09 PM
 */

#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#pragma once
#include <chrono>

using namespace std;

class TimeTracker {
public:
    void startTracking();
    void stopTracking();
    double getElapsedTime() const;

private:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
};

#endif /* TIMETRACKER_H */

