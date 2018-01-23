#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <vector>
#include <string>

std::vector<int> importInput(std::string const &fileName);
void displayInput(std::vector<int> &input);
void displayMemory(std::vector<std::vector<int> > &memoryAreas);
std::vector<int> reallocMemory(std::vector<int> memoryArea);
std::vector<std::vector<int> > getLoopMemoryArea(std::vector<int> memoryArea, std::vector<std::vector<int> > memoryAreas);

#endif // TOOLS_H_INCLUDED
