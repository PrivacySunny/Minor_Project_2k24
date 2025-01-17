
// Updated Code

#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits
#include "UAV.hpp"
#include "Outpost.hpp"
#include "ResourceAllocator.hpp"
#include "Resource.hpp"

int main()
{
    std::vector<UAV> uavs = {
        UAV(1, 500, 150, 2.5),
        UAV(2, 300, 100, 1.8),
        UAV(3, 700, 200, 3.0),
        UAV(4, 1000, 250, 4.0)};

    std::vector<Outpost> outposts;
    int numOutposts;

    std::cout << "Enter the number of outposts: ";
    while (!(std::cin >> numOutposts) || numOutposts <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a positive integer for the number of outposts: ";
    }

    for (int i = 0; i < numOutposts; ++i)
    {
        double distance;
        int urgency;

        std::cout << "Enter distance of outpost " << (i + 1) << " from base station (in km): ";
        while (!(std::cin >> distance) || distance <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a positive value for distance: ";
        }

        std::cout << "Enter urgency of the requirement for outpost " << (i + 1) << ": ";
        while (!(std::cin >> urgency) || urgency <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a positive integer for urgency: ";
        }

        Outpost outpost(i + 1, distance, urgency);
        int numResources;

        std::cout << "Enter the number of resource types needed for outpost " << (i + 1) << ": ";
        while (!(std::cin >> numResources) || numResources < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a non-negative integer for resource types: ";
        }

        for (int j = 0; j < numResources; ++j)
        {
            Resource res;
            std::cin.ignore(); // Clear buffer before reading strings
            std::cout << "Enter resource type (medicine/food/weapons): ";
            std::getline(std::cin, res.type);

            std::cout << "Enter amount of " << res.type << ": ";
            while (!(std::cin >> res.amount) || res.amount <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a positive integer for amount: ";
            }
            res.unfulfilledAmount = res.amount;

            if (res.type == "medicine")
                res.priority = 1;
            else if (res.type == "food")
                res.priority = 2;
            else if (res.type == "weapons")
                res.priority = 3;
            else
            {
                std::cerr << "Invalid resource type! Please enter medicine, food, or weapons.\n";
                return -1; // Exit or handle error
            }

            outpost.addResource(res);
        }

        outposts.push_back(outpost);
    }

    ResourceAllocator allocator(uavs, outposts);
    allocator.allocateResources();

    return 0;
}



// 1. Code with hardcoded input ------------------------->

// // Contains the main logic and program flow.

// #include <iostream>
// #include <vector>
// #include "UAV.hpp"
// #include "Outpost.hpp"
// #include "ResourceAllocator.hpp"
// #include "Resource.hpp"

// int main()
// {
//     // Define some UAVs with id, load capacity, and max distance
//     std::vector<UAV> uavs = {
//         UAV(1, 500, 100), // UAV 1: 500 units capacity, 100 km range
//         UAV(2, 300, 80),
//         UAV(3, 500, 120)   // UAV 2: 300 units capacity, 80 km range
//     };

//     // Define some outposts
//     std::vector<Outpost> outposts;

//     // Example input (replace this with user input or external input as needed)
//     Outpost outpost1(1, 30, 2);
//     outpost1.addResource(Resource("medicine", 300));
//     outpost1.addResource(Resource("food", 200));

//     Outpost outpost2(2, 50, 1);
//     outpost2.addResource(Resource("weapons", 400));

//     Outpost outpost3(3, 50, 3);
//     outpost3.addResource(Resource("medicine", 500));
//     outpost3.addResource(Resource("food", 400));

//     outposts.push_back(outpost1);
//     outposts.push_back(outpost2);
//     outposts.push_back(outpost3);

//     // Create resource allocator and allocate resources
//     ResourceAllocator allocator(uavs, outposts);
//     allocator.allocateResources();

//     return 0;
// }

// 2nd Code with user input with some error ----------------------->

// #include <iostream>
// #include <vector>
// #include "UAV.hpp"
// #include "Outpost.hpp"
// #include "ResourceAllocator.hpp"
// #include "Resource.hpp"

// int main()
// {
//     std::vector<UAV> uavs = {
//         UAV(1, 500, 150, 2.5),
//         UAV(2, 300, 100, 1.8),
//         UAV(3, 700, 200, 3.0),
//         UAV(4, 1000, 250, 4.0)};

//     std::vector<Outpost> outposts;
//     int numOutposts;

//     std::cout << "Enter the number of outposts: ";
//     std::cin >> numOutposts;

//     for (int i = 0; i < numOutposts; ++i)
//     {
//         double distance;
//         int urgency;

//         std::cout << "Enter distance of outpost " << (i + 1) << " from base station (in km): ";
//         std::cin >> distance;

//         std::cout << "Enter urgency of the requirement for outpost " << (i + 1) << ": ";
//         std::cin >> urgency;

//         Outpost outpost(i + 1, distance, urgency);
//         int numResources;
//         std::cout << "Enter the number of resource types needed for outpost " << (i + 1) << ": ";
//         std::cin >> numResources;

//         for (int j = 0; j < numResources; ++j)
//         {
//             Resource res;
//             std::cout << "Enter resource type (medicine/food/weapons): ";
//             std::cin >> res.type;
//             std::cout << "Enter amount of " << res.type << ": ";
//             std::cin >> res.amount;
//             res.unfulfilledAmount = res.amount;

//             if (res.type == "medicine")
//                 res.priority = 1;
//             else if (res.type == "food")
//                 res.priority = 2;
//             else if (res.type == "weapons")
//                 res.priority = 3;

//             outpost.addResource(res);
//         }

//         outposts.push_back(outpost);
//     }

//     // Create ResourceAllocator and allocate resources
//     ResourceAllocator allocator(uavs, outposts);
//     allocator.allocateResources();

//     return 0;
// }
