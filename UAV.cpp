
// Updated UAV.hpp File with some error handling --------------------->

#include "UAV.hpp"

// Constructor
UAV::UAV(int id, int loadCapacity, int maxDistance, double speed)
    : id(id), loadCapacity(loadCapacity), maxDistance(maxDistance), speed(speed), availableCapacity(loadCapacity) {}

// Get UAV ID
int UAV::getId() const
{
    return id;
}

// Get available capacity
int UAV::getAvailableCapacity() const
{
    return availableCapacity;
}

// Get max distance
int UAV::getMaxDistance() const
{
    return maxDistance;
}

// Reduce capacity
void UAV::reduceCapacity(int amount)
{
    availableCapacity -= amount;
    if (availableCapacity < 0)
        availableCapacity = 0;
}

// Reset capacity
void UAV::resetCapacity()
{
    availableCapacity = loadCapacity;
}



// // Definition of the UAV class.
// //
// #include "UAV.hpp"

// UAV::UAV(int id, double loadCapacity, double maxDistance)
//     : id(id), loadCapacity(loadCapacity), availableCapacity(loadCapacity), maxDistance(maxDistance) {}

// int UAV::getId() const
// {
//     return id;
// }

// double UAV::getAvailableCapacity() const
// {
//     return availableCapacity;
// }

// double UAV::getMaxDistance() const
// {
//     return maxDistance;
// }

// void UAV::reduceCapacity(double amount)
// {
//     availableCapacity -= amount;
// }

// void UAV::resetCapacity()
// {
//     availableCapacity = loadCapacity; // Reset capacity to maximum load
// }
