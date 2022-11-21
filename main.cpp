// Copyright 2022 Daniel

#include <iostream>
#include <algorithm>

using namespace std;

// All prototypes
void printSquare(int arr[]);
bool checkDup(int arrIn[]);
bool checkSquare(int arr[]);
void magic(int possibleNums[], int magicSquare[], int index);

// Main
int main() {
    int magicSquare[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int extraArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    magic(magicSquare, extraArray, 0);
    return 0;
}

// Print square
void printSquare(int arr[]) {
    for (int y = 0; y < 9; y++) {
        cout << arr[y] << " ";
        if (y == 2 || y == 5 || y == 8) {
            cout << endl;
        }
    }
    cout << endl;
}

bool checkDup(int arrIn[]) {
    // My version of deep copy(not sure if I need it but seemed to fix bug)
    int arr[9];
    for (int element = 0; element < 9; element++) {
        arr[element] = arrIn[element];
    }

    // Sorting it
    sort(arr, arr + 9);

    // Checking for doubles
    for (int element = 1; element < 9; element++) {
        if (arr[element] == arr[element - 1]) {
            return true;
        }
    }

    // No doubles, return false
    return false;
}

// Check to see if square is valid
bool checkSquare(int arr[]) {
    if (checkDup(arr)) {
        return false;
    } else {
        int row1 = arr[0] + arr[1] + arr[2];
        int row2 = arr[3] + arr[4] + arr[5];
        int row3 = arr[6] + arr[7] + arr[8];

        int col1 = arr[0] + arr[3] + arr[6];
        int col2 = arr[1] + arr[4] + arr[7];
        int col3 = arr[2] + arr[5] + arr[8];

        int diag1 = arr[0] + arr[4] + arr[8];
        int diag2 = arr[6] + arr[4] + arr[2];

        if (diag1 != 15 || diag2 != 15 || col1 != 15 ||
        col2 != 15 || col3 != 15 || row1 != 15 || row2 != 15
        || row3 != 15) {
            return false;
        } else {
            return true;
        }
    }
}

// Recursive function to make all posibilities for magic square
void magic(int possibleNums[], int magicSquare[], int index) {
    if (index == 9 && checkSquare(magicSquare)) {
        printSquare(magicSquare);
    } else {
        if (index != 9) {
            for (int count = 0; count < 9; count++) {
                magicSquare[index] = possibleNums[count];
                magic(possibleNums, magicSquare, index + 1);
            }
        }
    }
}

