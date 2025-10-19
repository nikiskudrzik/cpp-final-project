#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Each piece of data has an x coordinate, a character, and a y coordinate
struct DataPoint {
    int xCoordinate;
    string character;
    int yCoordinate;
};

int main() {
    // Open the CSV file to read data
    ifstream inputFile("InputData.csv");
    if (!inputFile) {
        cout << "Error: Could not open InputData.csv" << endl;
        return 1; // Stop if file not found
    }

    vector<DataPoint> dataList;
    string line;

    getline(inputFile, line); // skip the first line (header)

    // Read each line from the file
    while (getline(inputFile, line)) {
        if (line.empty()) continue; // Skip blank lines

        stringstream ss(line);
        string xValue, charValue, yValue;

        getline(ss, xValue, ',');
        getline(ss, charValue, ',');
        getline(ss, yValue, ',');

        // Skip the header line (the words at the top)
        if (xValue == "x-coordinate" || yValue == "y-coordinate")
            continue;

        // Convert x and y from text to numbers
        int x = stoi(xValue);
        int y = stoi(yValue);

        // Save the data into a list
        DataPoint point;
        point.xCoordinate = x;
        point.character = charValue;
        point.yCoordinate = y;
        dataList.push_back(point);
    }

    inputFile.close(); // Done reading file

    // Find how big the grid needs to be
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i < dataList.size(); i++) {
        if (dataList[i].xCoordinate > maxX) maxX = dataList[i].xCoordinate;
        if (dataList[i].yCoordinate > maxY) maxY = dataList[i].yCoordinate;
    }

    // Make a grid filled with spaces
    vector<vector<string> > grid(maxY + 1, vector<string>(maxX + 1, " "));

    // Place each character at the correct (x, y) coordinate
    for (int i = 0; i < dataList.size(); i++) {
        int x = dataList[i].xCoordinate;
        int y = dataList[i].yCoordinate;
        grid[y][x] = dataList[i].character;
    }

    // Show the pattern on the screen, which will display the text
    for (int y = 0; y <= maxY; y++) {
        for (int x = 0; x <= maxX; x++) {
            cout << grid[y][x];
        }
        cout << endl;
    }

    cout << "Program finished successfully!" << endl;
    return 0;
}
