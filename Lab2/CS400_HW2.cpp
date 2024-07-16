// CS400_HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
using namespace std;

// TODO: implement this function to return a Pascal Triangle
vector<vector<int>> pascalTriangle(int row) {
    if (row < 1 || row > 16) {
        return {};
    }

    vector<vector<int>> pascalTriangle(row);

    for (int i = 0; i < row; i++) {
        // resizes the current row because each row has exactly 'i + 1'
        pascalTriangle[i].resize(i + 1);
        // sets the first and last element because each rows first and last element will always be 1
        pascalTriangle[i][0] = pascalTriangle[i][i] = 1;

        // this fills in the elements between the first and last element
        for (int j = 1; j < i; j++) {
            // calculating intermediate elements, calculating the sum of the two elements directly above it from the previous row
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
    }
    return pascalTriangle;
   
}

// TODO: implement this function to print Pascal Triangles 
void printPascalTriangle(const vector<vector<int>>& triangle) {
    int row = triangle.size();
    int width = 4;

    // The amount of leading space is calculated based on the currnet row number and the total row of numbers
    for (int i = 0; i < row; ++i) {
        cout << setw((row - i) * width / 2) << " ";

        // prints each element of the current row with a fixed width for aligment, using setw
        for (int j = 0; j <= i; ++j) {
            cout << setw(width) << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

// TODO: implement this function to return comparison result. See main() for usage. 
vector<bool> compare(const vector<vector<int>>& triangle,
    const vector<int> allegedSummations) {
    vector<bool> result;
    // checks if the size of the pascal triangle matches the size of the alleged summations vector
    //returns an empty boolean vector, if not
    if (triangle.size() != allegedSummations.size()) {
        return {};
    }

    // uses accumulate from <numeric> to compute the summation of each row in the triangle
    // compares each calculated summation with the corresponding alleged summation value
    for (size_t i = 0; i < triangle.size(); ++i) {
        int realSummation = accumulate(triangle[i].begin(), triangle[i].end(), 0);
        result.push_back(realSummation == allegedSummations[i]);
    }

    return result;

}




int main()
{
    // part 1: generate and print Pascal Triangle
    int rows = 8;
    auto triangle = pascalTriangle(rows);
    printPascalTriangle(triangle);
    cout << endl;

    // part 2: check alleged summations
    // expected returrn: {1, 1, 0, 1, 0, 1, 0, 1, 1, 0}
    vector<int> allegedSum{ 1, 2, 5, 8, 17, 32, 65, 128, 256, 511 };
    auto sumCheck = compare(pascalTriangle(allegedSum.size()), allegedSum);
    for (auto b : sumCheck) {
        cout << b << " ";
    }

    cout << endl;

}

