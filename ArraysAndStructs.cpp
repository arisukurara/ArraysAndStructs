// ArraysAndStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_RUNNERS = 99;
const int NUM_DAYS = 7;

struct Runner {
    string name;
    int miles[NUM_DAYS];
};

Runner runners[NUM_RUNNERS];

int getData(Runner runners[]) {
    ifstream textFile("runners.txt");
    int index = 0;
    while (textFile >> runners[index].name) { // Reads the name from struct and puts it into the names array
        for (int day = 0; day < NUM_DAYS; day++) {
            textFile >> runners[index].miles[day]; // Read miles into runnerData array for each day while on that runner
        }
        index++;
    }
    textFile.close();
    return index;
}

double totalMiles(const Runner& runner) {
    double totalMiles = 0;
    for (int day = 0; day < NUM_DAYS; day++) {
        totalMiles += runner.miles[day];
    }
    return totalMiles;
}

double averageMiles(double totalMiles) {
    return totalMiles / 7;
}

void outputResults(const Runner& runner, bool isFirstRow) {
    if (isFirstRow) { // only do this for first row
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

    // Print runner's name
    cout << left << setw(10) << runner.name;

    // Print miles for each day
    for (int day = 0; day < NUM_DAYS; day++) {
        cout << right << setw(10) << runner.miles[day];
    }

    // Calculate and print total and average miles
    double total = totalMiles(runner);
    cout << right << setw(10) << total;
    cout << right << setprecision(3) << setw(10) << averageMiles(total);
    cout << endl;
}


int main() {
    int numberOfRunners = getData(runners); // Load data into struct array
    for (int i = 0; i < numberOfRunners; i++) {
        outputResults(runners[i], i == 0); // Output results for each runner
    }
}

