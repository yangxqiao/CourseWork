#include "SrcMain.h"
#include <iostream>
#include <random>
#include <numeric>
#include "TSP.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iterator>

using std::cout;
using std::endl;

void ProcessCommandArgs(int argc, const char* argv[])
{
    std::string inputfile = argv[1];
    std::ofstream ofile("log.txt");
    int popsize = std::stoi(argv[2]);
    int generations = std::stoi(argv[3]);
    int mutationchance = std::stoi(argv[4]);
    int seed = std::stoi(argv[5]);
    std::mt19937 randGen(seed);

    // Part 1
    std::vector<Location> allLocations;
    allLocations = ParseInputfile(inputfile);
    Population myPop;
    myPop.mMembers.resize(popsize);
    ofile << "INITIAL POPULATION:" << endl;

    std::generate(myPop.mMembers.begin(), myPop.mMembers.end(), [&randGen, &allLocations](){
        std::vector<int> v(allLocations.size());
        int n=0;
        generate(v.begin(), v.end(), [&n] { return n++;});
        std::shuffle(v.begin()+1, v.end(), randGen);
        return v;
    });

    printGen(myPop, ofile);

    
    // Part 2
    std::vector<std::pair<int, double> > myFitness;
    myFitness.resize(popsize);
    ofile << "FITNESS:" << endl;
    int traker = -1;
    std::generate(myFitness.begin(), myFitness.end(), [&traker, &allLocations, &myPop, &ofile](){
        traker++;
        std::vector<double> allDifferences = getDifference(allLocations, myPop.mMembers[traker]);
        double totalDis = sumDifference(allDifferences);
        totalDis += getBackOriginDist(allLocations, myPop.mMembers[traker]);
        ofile << traker << ":" << totalDis << endl;
        return std::make_pair(traker, totalDis);
    });

    
    // Part 3
    std::sort(myFitness.begin(), myFitness.end(), sortbysec);
    std::vector<double> myProbability(popsize);
    myProbability = genProbVec(myFitness, popsize);
    double probSum = sumOfProb(myProbability);
    myProbability = divEachBy(myProbability, probSum);
    std::vector<std::pair<int, int>> allParentsPairs = GenParentsVector(popsize, myProbability, randGen);
    printSelectedPairs(ofile, allParentsPairs);


    // Part 4
    for(int gen = 0; gen < generations; ++gen)
    {
        Population myNewPop = genNewPopulation(myPop, allLocations.size(), allParentsPairs, randGen, mutationchance);
        ofile << "GENERATION: " << gen+1 << endl;
        printGen(myNewPop, ofile);

        std::vector<std::pair<int, double> > myNewFitness(popsize);
        ofile << "FITNESS:" << endl;
        int traker = -1;
        std::generate(myNewFitness.begin(), myNewFitness.end(), [&traker, &allLocations, &myNewPop, &ofile](){
            traker++;
            std::vector<double> allDifferences = getDifference(allLocations, myNewPop.mMembers[traker]);
            double totalDis = sumDifference(allDifferences);
            totalDis += getBackOriginDist(allLocations, myNewPop.mMembers[traker]);
            ofile << traker << ":" << totalDis << endl;
            return std::make_pair(traker, totalDis);
        });
        
        std::sort(myNewFitness.begin(), myNewFitness.end(), sortbysec);
        if(gen != generations-1)
        {
            std::vector<double> myNewPossibility(popsize);
            myNewPossibility = genProbVec(myNewFitness, popsize);
            double newProbSum = sumOfProb(myNewPossibility);
            myNewPossibility = divEachBy(myNewPossibility, newProbSum);
            std::vector<std::pair<int, int>> allNewParentsPairs = GenParentsVector(popsize, myNewPossibility, randGen);
            printSelectedPairs(ofile, allNewParentsPairs);
            allParentsPairs = allNewParentsPairs;
        }
        
        myPop = myNewPop;
        
        if(gen == generations-1)
        {
            printBestSol(myPop, myNewFitness, ofile, allLocations);
        }
    }
    ofile.close();
}


