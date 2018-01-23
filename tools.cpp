#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "tools.h"

using namespace std;

vector<int> importInput(string const &fileName)
{
    ifstream myStream(fileName);
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        exit(0);
    }

    int number;
    vector<int> input;
    while(myStream >> number)
    {
        input.push_back(number);
    }

    return input;
}

void displayInput(vector<int> &input)
{
    vector<int>::iterator itInput;
    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        cout << *itInput << " ";
    }
    cout << endl;
}

void displayMemory(vector<vector<int> > &memoryAreas)
{
    vector<int>::iterator itArea;
    vector<vector<int> >::iterator itAreas;
    for(itAreas = memoryAreas.begin(); itAreas != memoryAreas.end(); ++itAreas)
    {
        for(itArea = itAreas->begin(); itArea != itAreas->end(); ++itArea)
        {
            cout << *itArea << " ";
        }
        cout << endl;
    }
}

vector<int> reallocMemory(vector<int> memoryArea)
{
    vector<int>::iterator itMax = max_element(memoryArea.begin(), memoryArea.end());
    int memoryBankToRedistribute = *itMax;
    *itMax = 0;
    vector<int>::iterator itArea;

    for(itArea = itMax + 1; (itArea != memoryArea.end()) && (memoryBankToRedistribute > 0); ++itArea)
    {
        ++*itArea;
        --memoryBankToRedistribute;
    }

    while(memoryBankToRedistribute > 0)
    {
        for(itArea = memoryArea.begin(); (itArea != memoryArea.end()) && (memoryBankToRedistribute > 0); ++itArea)
        {
            ++*itArea;
            --memoryBankToRedistribute;
        }
    }

    return memoryArea;
}

vector<vector<int> > getLoopMemoryArea(vector<int> memoryArea, vector<vector<int> > memoryAreas)
{
    vector<vector<int> > loopAreas;
    vector<vector<int> >::iterator itAreas;
    for(itAreas = memoryAreas.begin(); itAreas != memoryAreas.end(); ++itAreas)
    {
        if(*itAreas == memoryArea)
        {
            return vector<vector<int> >(itAreas, memoryAreas.end());
        }
    }

    return loopAreas;
}
