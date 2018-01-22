#include <iostream>
#include <fstream>
#include <sstream>
#include "tools.h"

using namespace std;

vector<int> importInput(string fileName)
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

void displayInput(vector<int> input)
{
    vector<int>::iterator itInput;
    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        cout << *itInput << endl;
    }
}
