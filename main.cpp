#include <iostream>
#include <algorithm>
#include "tools.h"

using namespace std;

int main()
{
    vector<int> input = importInput("input.txt");
    displayInput(input);

    /* Vecteur de vecteur contenant le resultat après chaque itération*/
    vector<vector<int> > memoryAreas;
    memoryAreas.push_back(input);

    vector<int>::iterator itMax = max_element(input.begin(), input.end());
    cout << endl << "Max de l'input : " << *itMax << endl;
    //cout << "Iterator du max : " << itMax << endl;

    /*
    bool isInfiniteLoop(false);
    while(!isInfiniteLoop)
    {

    }
    */

    return 0;
}
