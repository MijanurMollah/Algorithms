#include <iostream>
using namespace std;

int knapsack(int weight[], int value[], int we, int n){
    int sack[n+1][we+1];
    for (int i = 0; i <= n; i++){
       for (int j = 0; j <= we; j++) 
       { 
           if (i == 0 || j == 0) 
               sack[i][j] = 0; 
           else if (weight[i-1] > j) 
                sack[i][j] = sack[i-1][j]; 
           else
                sack[i][j] = max(sack[i-1][j], sack[i-1][j-weight[i-1]] + value[i-1]);
       } 
    }
    return sack[n][we];
}

int main(void){
    int value[] = {210, 220, 180, 120, 160, 170, 90, 40, 60, 10};
    int weight[] = {15, 12, 10, 9, 8, 7, 5, 4, 3, 1};
    int W = 26;
    int n = 10;
    cout << knapsack(weight, value, W, n) << endl;
    return 0;
}
