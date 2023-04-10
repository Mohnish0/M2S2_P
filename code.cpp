#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <string>
using namespace std;

#define MAX 1000000

int Data[MAX];
long global_sum = 0;

int main(int argc, char *argv[])
{ 
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        Data[i] = rand() % 20;
    }

    clock_t start = clock();
#pragma omp parallel for reduction(+:global_sum)
    for(int i = 0; i < MAX; i++) {
        global_sum += Data[i];
    }
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "The final sum is " << global_sum << endl;
    cout << "Execution time for openMp: " << elapsed_time << " seconds" << endl;
}
