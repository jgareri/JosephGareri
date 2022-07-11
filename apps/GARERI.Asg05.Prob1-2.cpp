// GARERI.Asg05.cpp 
// Joseph Gareri
// jgareri@my.athens.edu
// Assignment 05
// Problem 1-3

#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;


int anyEqual(int n, int** A);
void fillArray(int** A, int SIZE);

void fillArray(int **A, int SIZE)
{
    int counter = 0;
    int size = 0;
    auto duration_total = 0;
    int n = 0; 
    double averageAnyEqual = 0;
    int randomNumberLoop = 20;
    srand(0);
   
    for (int i = 0; i < size; i++) 
    {
        for (int j = 1; j < size; j++) 
        {
                   A[i][j] = (rand() % randomNumberLoop);
        }
   
    }
    for (int i = 1; i < randomNumberLoop; i++) 
    {
        auto startAnyEqual = std::chrono::steady_clock::now();
        anyEqual(n, A);
        auto endAnyEqual = std::chrono::steady_clock::now();
        (chrono::duration_cast<chrono::seconds>(endAnyEqual - startAnyEqual).count());
        std::cout << " anyEqual completed with elapsed time:\n " << (endAnyEqual - startAnyEqual).count() << "s" << endl;
        duration_total += (endAnyEqual - startAnyEqual).count();
      
    }
    
   averageAnyEqual = ((duration_total)/(randomNumberLoop));
   cout << endl << "The average time for the anyEqual is: " << averageAnyEqual << "s"<< endl;
     
    
}
  


int anyEqual(int n, int** A)
{
    
    int i, j, k, m;
    for (i = 1; i <= n; i++) {  
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                for (m = 1; m <= n; m++) {
                    if ((A[i][j] == A[k][m]) && (i == k && j == m))
                    {
                        cout << "The array is equal" << endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{ 
    double averageTimeToFill;
    const int sizeA = 10;
    int** array1 = new int*[sizeA];
    for (int i = 0; i < sizeA; i++)
    {
        array1 = new int* [sizeA];
    }
  
    auto start1 = std::chrono::steady_clock::now();
    fillArray(array1, sizeA);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
    delete[] array1;

    const int sizeB = 20;
    int** array2 = new int* [sizeB];
    for (int i = 0; i < sizeB; i++)
    {
        array2 = new int* [sizeB];
    }
    
    auto start2 = std::chrono::steady_clock::now();
     fillArray(array2, sizeB);
     auto end2 = std::chrono::steady_clock::now();
     std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
     delete[] array2;
    

    const int sizeC = 30;
    int** array3 = new int* [sizeC];
    for (int i = 0; i < sizeC; i++)
    {
        array3 = new int* [sizeC];
    }
   

    auto start3 = std::chrono::steady_clock::now();
     fillArray(array3, sizeC);
     auto end3 = std::chrono::steady_clock::now();
     std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
     delete[] array3;

    const int sizeD = 40;
    int** array4 = new int* [sizeD];
    for (int i = 0; i < sizeD; i++)
    {
        array4 = new int* [sizeD];
    }
   
    auto start4 = std::chrono::steady_clock::now();
     fillArray(array4, sizeD);
     auto end4 = std::chrono::steady_clock::now();
     std::chrono::duration<double> elapsed_seconds4 = end4 - start4;
     delete[] array4;

    const int sizeE = 50;
    int** array5 = new int* [sizeE];
    for (int i = 0; i < sizeE; i++)
    {
        array5 = new int* [sizeE];
    }
   
    auto start5 = std::chrono::steady_clock::now();
    fillArray(array5, sizeE);
    auto end5 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds5 = end5 - start5;
    delete[] array5;

    const int sizeF = 100;
    int** array6 = new int* [sizeF];
    for (int i = 0; i < sizeF; i++)
    {
        array6 = new int* [sizeF];
    }
   
    auto start6 = std::chrono::steady_clock::now();
    fillArray(array6, sizeF);
    auto end6 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds6 = end6 - start6;
    delete[] array6;

    const int sizeG = 500;
    int** array7 = new int*[sizeG];
    for (int i = 0; i < sizeG; i++)
    {
        array7 = new int* [sizeG];
    }
    
    auto start7 = std::chrono::steady_clock::now();
    fillArray(array7, sizeG);
    auto end7 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds7 = end7 - start7;
    delete[] array7;

    const int sizeH = 1000;
    int** array8 = new int* [sizeH];
    for (int i = 0; i < sizeH; i++)
    {
        array8 = new int* [sizeH];
    }

    auto start8 = std::chrono::steady_clock::now();
    fillArray(array8, sizeH);
    auto end8 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds8 = end8 - start8;
    delete[] array8;

    cout << setprecision(8) << fixed << showpoint;
    cout << endl<<"---------------------------------------------" << endl;
    cout<< " Array Size: "<<sizeA<< " with elapsed time: " << elapsed_seconds1.count() << "s\n";
    cout << "Array Size: "<<sizeB<<" with elapsed time: " << elapsed_seconds2.count() << "s\n";
    cout << "Array Size: "<<sizeC<<" with elapsed time : " << elapsed_seconds3.count() << "s\n";
    cout << "Array Size: "<<sizeD<<" with elapsed time : " << elapsed_seconds4.count() << "s\n";
    cout << "Array Size: "<<sizeE<<" with elapsed time : " << elapsed_seconds5.count() << "s\n";
    cout << "Array Size: "<<sizeF<<" with elapsed time : " << elapsed_seconds6.count() << "s\n";
    cout << "Array Size: "<<sizeG<<" with elapsed time : " << elapsed_seconds7.count() << "s\n";
    cout << "Array Size: "<<sizeH<<" with elapsed time : " << elapsed_seconds8.count() << "s\n";

    averageTimeToFill = ((elapsed_seconds1.count() + elapsed_seconds2.count() + elapsed_seconds3.count() +
        elapsed_seconds4.count() + elapsed_seconds5.count() + elapsed_seconds6.count() + elapsed_seconds7.count() + elapsed_seconds8.count()) / 8);
 
    cout <<endl<< "The average time for to pass all values through arrays: " << averageTimeToFill << endl;

    return 0;
}



