// ArraysAndStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_RUNNERS = 99;
const int NUM_DAYS = 7;

string names[NUM_RUNNERS];
int runnerData[NUM_RUNNERS][NUM_DAYS];

int getData(string names[], int runnerData[][NUM_DAYS]) {
    std::ifstream runners("runners.txt");
    int rowIndex = 0;
    while (runners >> names[rowIndex]) { // Read the name and puts it into the names array
        for (int col = 0; col < NUM_DAYS; col++) {
            runners >> runnerData[rowIndex][col]; // Read miles into milesRan array for each day while on that runner
            //cout << milesRan[rowIndex][col] << endl;
        }
        //cout << names[rowIndex] << endl;
        rowIndex++; // Move to the next row (next runner)
    }
    runners.close();
    return rowIndex;
}

double totalMiles(int rowIndex) {
    double totalMiles = 0;
    for (int col = 0; col < NUM_DAYS; col++) {
        totalMiles += runnerData[rowIndex][col];
    }
    return totalMiles;
}

double averageMiles(double totalMiles) {
    return totalMiles / 7;
}

void outputResults(int rowIndex) {
    if (rowIndex == 0) {
        cout << left << setw(10) << "Name";
        for (int i = 0; i < NUM_DAYS; i++) {
            cout << right << setw(10) << ("Day " + to_string(i + 1));
        }
        cout << right << setw(10) << "Total";
        cout << right << setw(10) << "Average";
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------";
        cout << endl;
    }
    cout << left << setw(10) << names[rowIndex]; //prints name for that index
    for (int col = 0; col < NUM_DAYS; col++) {
        cout << right << setw(10) << runnerData[rowIndex][col]; // prints data for each day
    }

    double total = totalMiles(rowIndex);

    cout << right << setw(10) << total;
    cout << right << setprecision(3) << setw(10) << averageMiles(total);
    cout << endl;
}


int main()
{
    int numberOfRows = getData(names, runnerData);
    for (int i = 0; i < numberOfRows; i++) {
        outputResults(i);
    }
}

