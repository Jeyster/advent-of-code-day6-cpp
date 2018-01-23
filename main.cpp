#include <iostream>
#include <algorithm>
#include "tools.h"

using namespace std;

int main()
{
    vector<int> input = importInput("input.txt");

    /* Vecteur de vecteur contenant le resultat après chaque itération*/
    vector<vector<int> > memoryAreas;
    memoryAreas.push_back(input);

    vector<vector<int> > loopArea;
    int reallocCounter(0);
    while(true)
    {
        vector<int> newMemoryArea = reallocMemory(memoryAreas.back());
        ++reallocCounter;

        loopArea = getLoopMemoryArea(newMemoryArea, memoryAreas);
        if(loopArea.size() == 0)
        {
            memoryAreas.push_back(newMemoryArea);
            //displayInput(newMemoryArea);
        }
        else
        {
            break;
        }
    }

    cout << "Nombre de reallocation avant boucle infini : " << reallocCounter << endl;
    cout << "Nombre de reallocation dans la boucle : " << loopArea.size() << endl;

    return 0;
}
