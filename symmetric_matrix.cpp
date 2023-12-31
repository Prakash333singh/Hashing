#include <bits/stdc++.h>
using namespace std;

// A C++ program to find all symmetric pairs in a given array of pairs
// Print all pairs that have a symmetric counterpart
void findSymPairs(int arr[][2], int row)
{
    // Creates an empty hashMap hM
    unordered_map<int, int> hM;

    //  11,20,
    //  30,40;
    //  5, 10;
    //  40,30;
    //   10,5;
    // Traverse through the given array

    for (int i = 0; i < row; i++)
    {
        // First and second elements of current pair
        int first = arr[i][0]; // 40
        int sec = arr[i][1];   // 30

        // If found and value in hash matches with first
        // element of this pair, we found symmetry
        if (hM.find(sec) != hM.end() && hM[sec] == first)
            cout << "(" << sec << ", " << first << ")" << endl;

        else                 // Else put sec element of this pair in hash
            hM[first] = sec; //<0,20> <0,40> <0,10>
        cout << hM[first] << endl;
    }
}

// Driver method
int main()
{
    int arr[5][2];
    arr[0][0] = 11;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 5;
    arr[2][1] = 10;
    arr[3][0] = 40;
    arr[3][1] = 30;
    arr[4][0] = 10;
    arr[4][1] = 5;
    cout << "Following pairs have symmetric pairs\n";
    findSymPairs(arr, 5);
}

// This is contributed by Chhavi
