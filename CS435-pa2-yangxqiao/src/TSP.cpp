#include "TSP.h"
#include <iostream>
#include <random>
#include <numeric>
#include "TSP.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;

int genCrossoverIndex(std::mt19937& randGen, int numLocation)
{
    std::uniform_int_distribution<int> uid(1, numLocation-2);
    int crossIndex = uid(randGen);
    return crossIndex;
}


int genWhoGoFirst(std::mt19937& randGen)
{
    std::uniform_int_distribution<int> uid(0, 1);
    int whoGoFirst = uid(randGen);
    return whoGoFirst;
}


std::vector<int> genNewCrossover(std::mt19937& randGen, int numLocation, const std::pair<int, int>& twoParents, Population myPop)
{
    std::vector<int> newCrossover;
    int crossIndex = genCrossoverIndex(randGen, numLocation);
    int whoGoFirst = genWhoGoFirst(randGen);
    if(whoGoFirst == 1)
    {
        std::copy_n(myPop.mMembers[twoParents.first].begin(), crossIndex+1, std::back_inserter(newCrossover));
        std::copy_if(myPop.mMembers[twoParents.second].begin(), myPop.mMembers[twoParents.second].end(), back_inserter(newCrossover),[&newCrossover](const int& i) {
            return std::find(newCrossover.begin(), newCrossover.end(), i) == newCrossover.end();;
        });
    }
    else{
        std::copy_n(myPop.mMembers[twoParents.second].begin(), crossIndex+1, std::back_inserter(newCrossover));
        std::copy_if(myPop.mMembers[twoParents.first].begin(), myPop.mMembers[twoParents.first].end(), back_inserter(newCrossover),[&newCrossover](const int& i) {
            return std::find(newCrossover.begin(), newCrossover.end(), i) == newCrossover.end();;

        });
    }
    return newCrossover;
}


bool checkWhetherMutate(std::mt19937& randGen, int mutationchance)
{
    std::uniform_real_distribution<double> urd(0.0, 1.0);
    double mutant = urd(randGen);
    double mutatInFract = mutationchance/100.0;
    return mutant <= mutatInFract;
}


std::vector<int> swapCrossover(std::mt19937& randGen, std::vector<int>& newCrossover)
{
    std::uniform_int_distribution<int> uid(1, newCrossover.size()-1);
    int index1 = uid(randGen);
    int index2 = uid(randGen);
    std::swap(newCrossover[index1], newCrossover[index2]);
    return newCrossover;
}


Population genNewPopulation(const Population& myPop, const int& numLocation, const std::vector<std::pair<int, int>>& allParentsPairs, std::mt19937& randGen, const int& mutationchance)
{
    Population myNewPop;
    myNewPop.mMembers.resize(myPop.mMembers.size());
    int index = 0;
    std::generate(myNewPop.mMembers.begin(), myNewPop.mMembers.end(),[&randGen, &mutationchance, &allParentsPairs, &numLocation, &myPop, &index](){
        std::vector<int> newCrossOver = genNewCrossover(randGen, numLocation, allParentsPairs[index], myPop);
        index++;
        if(checkWhetherMutate(randGen, mutationchance))
        {
            newCrossOver = swapCrossover(randGen, newCrossOver);
        }
        return newCrossOver;
    });

    return myNewPop;
}


std::vector<Location> ParseInputfile(std::string inputfile)
{
    std::ifstream ifile(inputfile);
    if(ifile.fail())
    {
        cout << "Can't open the file" << endl;
    }

    std::string newline;
    std::vector<Location> allLocations;
    while(static_cast<bool>(std::getline(ifile, newline, '\n')))
    {
            if(!newline.empty())
            {
                std::stringstream ss(newline);
                std::string mName;
                std::string mLatitude;
                std::string mLongitude;
                std::getline(ss, mName, ',');
                std::getline(ss, mLatitude, ',');
                std::getline(ss, mLongitude, '\n');
                Location myLoc = {mName, std::stod(mLatitude), std::stod(mLongitude)};
                allLocations.emplace_back(myLoc);
            }
    }
    return allLocations;
}


double sumDifference(std::vector<double> allDifference){
    return std::accumulate(allDifference.begin(), allDifference.end(), 0.0, [](const double d1, const double d2)
    {
        return d1+d2;
    }
);}


std::vector<double> getDifference(const std::vector<Location>& allLocations, std::vector<int> currentPath)
{
    std::vector<double> differences;
    std::adjacent_difference(currentPath.begin(), currentPath.end(), std::back_inserter(differences),
                             [&allLocations](const int& loc1, const int& loc2)
                             {
                                 double lon2 = allLocations[loc2].mLongitude * 0.0174533;
                                 double lon1 = allLocations[loc1].mLongitude * 0.0174533;
                                 double lat1 = allLocations[loc1].mLatitude * 0.0174533;
                                 double lat2 = allLocations[loc2].mLatitude * 0.0174533;
                                 double dlon = lon2 - lon1;
                                 double dlat = lat2 - lat1;
                                 double a = pow(sin(dlat/2.0), 2.0) + cos(lat1) * cos(lat2) * pow(sin(dlon/2.0), 2.0);
                                 double c = 2.0 * atan2(sqrt(a), sqrt(1-a));
                                 return 3961.0 * c;
    });
    return differences;
}


double getBackOriginDist(const std::vector<Location>& allLocations, std::vector<int> currentPath)
{
    double lon2 = allLocations[currentPath.front()].mLongitude * 0.0174533;
    double lon1 = allLocations[currentPath.back()].mLongitude * 0.0174533;
    double lat1 = allLocations[currentPath.back()].mLatitude * 0.0174533;
    double lat2 = allLocations[currentPath.front()].mLatitude * 0.0174533;
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat/2.0), 2.0) + cos(lat1) * cos(lat2) * pow(sin(dlon/2.0), 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1-a));
    return 3961.0 * c;
}


bool sortbysec(const std::pair<int,double> &a,
              const std::pair<int,double> &b)
{
    return (a.second < b.second);
}


double sumOfProb(const std::vector<double>& myProbability)
{
    return std::accumulate(myProbability.begin(), myProbability.end(), 0.0, [](const double& a, const double& b)
                           {
        return a+b;
    });
}


std::vector<double> genProbVec(const std::vector<std::pair<int, double>>& myFitness, const int popsize)
{
    std::vector<double> myProbability(popsize);
    std::generate(myProbability.begin(), myProbability.end(), [&popsize](){
        return (1.0/popsize);
    });
    myProbability[myFitness[0].first] *= 6.0;
    myProbability[myFitness[1].first] *= 6.0;
    for(unsigned int i = 2; i < myFitness.size()/2; ++i)
    {
        myProbability[myFitness[i].first] *= 3.0;
    }

    return myProbability;
}


std::vector<double> divEachBy(const std::vector<double>& myProbability, const double& denominator)
{
    std::vector<double> result;
    std::transform(myProbability.begin(), myProbability.end(), std::back_inserter(result), [denominator](const double& a)
                   {
        return a/denominator;
    });
    return result;
}


std::pair<double, double> genDoublePair(std::mt19937& randGen)
{
    std::uniform_real_distribution<double> urd(0.0, 1.0);
    double firstP = urd(randGen);
    double secondP = urd(randGen);
    return {firstP, secondP};
}


int getSelectedIndex(double target, std::vector<double>& myProbability)
{
    double currentDouble = 0.0;
    unsigned int i;
    for(i = 0; i < myProbability.size(); ++i)
    {
        currentDouble += myProbability[i];
        if(currentDouble >= target)
        {
            return i;
        }
    }
    return i;
}


std::pair<int, int> getSelectedParents(std::vector<double>& myProbability, std::mt19937& randGen)
{
    std::pair<double, double> twoParents = genDoublePair(randGen);
    int firstPIndex = getSelectedIndex(twoParents.first, myProbability);
    int secondPIndex = getSelectedIndex(twoParents.second, myProbability);
    return {firstPIndex, secondPIndex};
}


std::vector<std::pair<int, int>> GenParentsVector(int popsize, std::vector<double>& myProbability, std::mt19937& randGen)
{
    std::vector<std::pair<int, int>> allParentsPair(popsize);
    for(int i = 0; i < popsize; ++i)
    {
        std::pair<int, int> oneParentPair = getSelectedParents(myProbability, randGen);
        allParentsPair[i] = oneParentPair;
    }
    return allParentsPair;
}


void printSelectedPairs(std::ofstream& ofile, const std::vector<std::pair<int, int>>& allParentsPairs)
{
    ofile << "SELECTED PAIRS:" << endl;
    for(unsigned int i = 0; i < allParentsPairs.size(); ++i)
    {
        ofile << "(" << allParentsPairs[i].first << "," << allParentsPairs[i].second << ")" << endl;
    }
}


void printGen(const Population& myPop, std::ofstream& ofile){
    for(unsigned int i = 0; i < myPop.mMembers.size(); ++i)
    {
        ofile << myPop.mMembers[i][0];
        for(unsigned int j = 1; j < myPop.mMembers[i].size(); ++j)
        {
           ofile << "," << myPop.mMembers[i][j];
        }
        ofile << endl;
    }
}


void printBestSol(Population& myPop, std::vector<std::pair<int, double> >& myNewFitness, std::ofstream& ofile, std::vector<Location>& allLocations)
{
    ofile << "SOLUTION: " << endl;
    int theBestSol = myNewFitness[0].first;
    std::vector<int> theBestArray = myPop.mMembers[theBestSol];
    for(unsigned int i = 0; i < theBestArray.size(); ++i)
    {
        ofile << allLocations[theBestArray[i]].mName << endl;
    }
    ofile << allLocations[0].mName << endl;
    ofile << "DISTANCE: " << myNewFitness[0].second << " miles";
}
