#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int size, const int Low, const int High);
void Input(int** a, const int size);
void Print(int** a, const int size);
void CountLocalMinima(int** a, const int size);
bool IsLocalMinimum(int** a, const int size, int i, int j);
int SumAboveMainDiagonal(int** a, const int size);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;

    int size;
    cout << "Enter the size: ";
    cin >> size;

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
        a[i] = new int[size];

   // Create(a, size, Low, High);
   Input(a, size);
    Print(a, size);

    CountLocalMinima(a, size);

    int sumAboveDiagonal = SumAboveMainDiagonal(a, size);
    cout << "Sum above the main diagonal: " << sumAboveDiagonal << endl;

    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool IsLocalMinimum(int** a, const int size, int i, int j) {
    int currentElement = a[i][j];

    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < size && y >= 0 && y < size) {
                if (a[x][y] < currentElement) {
                    return false;
                }
            }
        }
    }
    return true;
}

void CountLocalMinima(int** a, const int size) {
    int localMinimaCount = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (IsLocalMinimum(a, size, i, j)) {
                localMinimaCount++;
            }
        }
    }

    cout << "The number of local minima : " << localMinimaCount << endl;
}

int SumAboveMainDiagonal(int** a, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            sum += abs(a[i][j]);
        }
    }
    return sum;
}
