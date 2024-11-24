// Updated Resource Structure

#ifndef RESOURCE_HPP
#define RESOURCE_HPP
//
#include <string>


struct Resource
{
    std::string type;
    int amount;
    int unfulfilledAmount;
    int priority;

    Resource() : type(""), amount(0), unfulfilledAmount(0), priority(0) {}
};

// class Resource
// {
// public:
//     std::string type;         // Type of resource (e.g., medicine, food, weapons)
//     double unfulfilledAmount; // Amount needed but not yet fulfilled

//     Resource(std::string type, double unfulfilledAmount) : type(type), unfulfilledAmount(unfulfilledAmount) {}
// };

#endif
