#pragma once
#include <string>
#include <vector>
#include <random>

struct Location
{
	std::string mName;
	double mLatitude;
	double mLongitude;
};

struct Population
{
	std::vector<std::vector<int>> mMembers;
};


std::vector<Location> ParseInputfile(std::string inputfile);
std::vector<double> getDifference(const std::vector<Location>& allLocations, std::vector<int> currentPath);
double sumDifference(std::vector<double> allDifference);
double getBackOriginDist(const std::vector<Location>& allLocations, std::vector<int> currentPath);
bool sortbysec(const std::pair<int,double> &a, const std::pair<int,double> &b);
double sumOfProb(const std::vector<double>& myProbability);
std::vector<double> divEachBy(const std::vector<double>& myProbability, const double& denominator);
std::vector<double> genProbVec(const std::vector<std::pair<int, double>>& myFitness, int popsize);
std::pair<double, double> genDoublePair(std::mt19937& randGen);
int getSelectedIndex(double target, std::vector<double>& myProbability);
std::pair<int, int> getSelectedParents(std::vector<double>& myProbability, std::mt19937& randGen);
std::vector<std::pair<int, int>> GenParentsVector(int popsize, std::vector<double>& myProbability, std::mt19937& randGen);
void printSelectedPairs(std::ofstream& ofile, const std::vector<std::pair<int, int>>& allParentsPairs);
int genCrossoverIndex(std::mt19937& randGen, int numLocation);
int genWhoGoFirst(std::mt19937& randGen);
std::vector<int> genNewCrossover(std::mt19937& randGen, int numLocation, const std::pair<int, int>& twoParents, Population myPop);
bool checkWhetherMutate(std::mt19937& randGen, int mutationchance);
std::vector<int> swapCrossover(std::mt19937& randGen, std::vector<int>& newCrossover);
Population genNewPopulation(const Population& myPop, const int& numLocation, const std::vector<std::pair<int, int>>& allParentsPairs, std::mt19937& randGen, const int& mutationchance);
void printGen(const Population& myPop, std::ofstream& ofile);
void printBestSol(Population& myPop, std::vector<std::pair<int, double> >& myNewFitness, std::ofstream& ofile, std::vector<Location>& allLocations);
