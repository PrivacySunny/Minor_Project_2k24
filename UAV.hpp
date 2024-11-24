
// Declaration of the UAV class.
//
// Updated Class UAV Line 11 to 29


#ifndef UAV_HPP
#define UAV_HPP


class UAV
{
public:
    int id;
    int loadCapacity;
    int maxDistance;
    double speed;
    int availableCapacity;

    // Constructor
    UAV(int id, int loadCapacity, int maxDistance, double speed);

    // Member functions
    int getId() const;
    int getAvailableCapacity() const;
    int getMaxDistance() const;
    void reduceCapacity(int amount);
    void resetCapacity();
};

// class UAV
// {
// public:
//     int id;
//     int loadCapacity;
//     int maxDistance;
//     double speed;

//     // // Constructor
//     // UAV(int id, int loadCapacity, int maxDistance, double speed)
//     //     : id(id), loadCapacity(loadCapacity), maxDistance(maxDistance), speed(speed) {}

//     UAV::UAV(int id, int loadCapacity, int maxDistance, double speed)
//         : id(id), loadCapacity(loadCapacity), maxDistance(maxDistance), speed(speed) {}
// };

// class UAV
// {
// private:
//     int id;                   // Unique identifier for the UAV
//     double loadCapacity;      // Maximum load capacity of the UAV
//     double availableCapacity; // Current available capacity
//     double maxDistance;       // Maximum distance the UAV can travel

// public:
//     UAV(int id, double loadCapacity, double maxDistance);

//     int getId() const;
//     double getAvailableCapacity() const;
//     double getMaxDistance() const;
//     void reduceCapacity(double amount);
//     void resetCapacity();
// };

#endif
