/*
*       * 
  *   *   
    *     
  *   *   
*       * 
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square grid: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1)  //i+j==n-1 for cross-diagonal
                cout << "* "; 
            else
                cout << "  ";
        }
        cout << endl;
    }

    return 0;
}
