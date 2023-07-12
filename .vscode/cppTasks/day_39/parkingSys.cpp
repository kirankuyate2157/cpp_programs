#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
private:
    int spots[3];

public:
    ParkingSystem(int big, int medium, int small)
    {
        spots[0] = big;
        spots[1] = medium;
        spots[2] = small;
    }

    bool addCar(int carType)
    {
        if (spots[carType - 1] > 0)
        {
            spots[carType - 1]--;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main()
{

    return 0;
}
/*
Input
    ["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
    [[ 1, 1, 0 ], [1], [2], [3], [1]] Output
        [null, true, true, false, false]

    Explanation
        ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
parkingSystem.addCar(3); // return false because there is no available slot for a small car
parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.

*/