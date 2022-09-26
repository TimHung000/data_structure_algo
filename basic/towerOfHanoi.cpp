#include <iostream>

const int TOWER1 = 1;
const int TOWER2 = 2;
const int TOWER3 = 3;

void towerOfHanoi(int sourceTower,int auxillaryTower, int destinationTower, int disks)
{
    if(!disks) return;
    towerOfHanoi(sourceTower, destinationTower, auxillaryTower, disks - 1);
    std::cout << "move disk" << disks << " from Tower" << sourceTower << " to Tower" << destinationTower << "\n";
    towerOfHanoi(auxillaryTower, sourceTower, destinationTower, disks - 1);
}

int main()
{
    const int disks = 64;
    towerOfHanoi(TOWER1, TOWER2, TOWER3, disks);
    return 0;
}
