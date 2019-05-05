#include <iostream>
using namespace std;

int canBook(int arrive_dates[], int leave_dates[], int n, int b)
{
    int m = n;
    for(int i = 0; i < b; i++) {
        n = n-1;
        for (int j = i; j < b; j++){
            if (leave_dates[i] <= arrive_dates[j] && n != m){
                n = n+1;
                break;
            }
        }
    }
    if (n < 0)
    return 0;
    else
    return 1;
}

int main(void){
    int arrive_dates[] = {1,2,4,5,8};
    int leave_dates[] = {1,5,9,8,9};
    int b = sizeof(arrive_dates)/sizeof(arrive_dates[0]);
    int n = 2;
    cout << canBook(arrive_dates, leave_dates, n,b) << "\n";
    return 0;
}
