#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

int multiply4(string str1, string str2);
int multiply3(string str1, string str2);

int main(void){
    auto s1 = high_resolution_clock::now();
    printf("%ld\n", multiply4("123", "456"));
    auto s2 = high_resolution_clock::now();
    auto time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply4" << endl;
    s1 = high_resolution_clock::now();
    printf("%ld\n", multiply3("123", "456"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply3" << endl;
    
    s1 = high_resolution_clock::now();
    printf("%ld\n", multiply4("10", "10"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply4" << endl;
    s1 = high_resolution_clock::now();
    printf("%ld\n", multiply3("10", "10"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply3" << endl;
    
    s1 = high_resolution_clock::now();
    printf("%ld\n", multiply4("1222", "4566"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply4" << endl;
    s1 = high_resolution_clock::now();
    printf("%ld\n", multiply3("1222", "4566"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply3" << endl;
    
     s1 = high_resolution_clock::now();
    printf("%ld\n", multiply4("125", "4560"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply4" << endl;
    s1 = high_resolution_clock::now();
    printf("%ld\n", multiply3("125", "4560"));
    s2 = high_resolution_clock::now();
    time = duration_cast<microseconds> (s2 - s1);
    cout << time.count() << " microseconds for multiply3" << endl;
    
    return 0;
}

int multiply4(string str1, string str2){
    int total = 0;
    int big_count = 0;
    for (int i = str1.length()-1; i >= 0; i--){
        int curr1 = str1[i] -'0';
        curr1 = curr1 * pow(10, big_count);
        int count = 0;
        int sum = 0;
        for (int j = str2.length()-1; j >= 0; j--){
            int curr2 = str2[j] -'0';
            int prod = curr1 * curr2;
            prod = prod * pow(10, count);
            count++;
            sum += prod;
        }
        total += sum;
        big_count++;
    }
    return total;
}

int multiply3(string str1, string str2){
    int val1 = max(str1.length(), str2.length());
    if (stoi(str1) <= 9 && stoi(str2) <= 9){
    return stoi(str1)*stoi(str2);
    }
    int val2 = val1/2;
    int val3 = stoi(str1)%(int)(pow(10,val2));
    int val4 = stoi(str2)%(int)(pow(10,val2));
    int val5 = stoi(str1)/pow(10,val2);
    int val6 = stoi(str2)/pow(10,val2);
    int x = multiply3(to_string(val5), to_string(val6));
    int y = multiply3(to_string(val3), to_string(val4));
    int z = multiply3(to_string(val3+val5), to_string(val6+val4))-y-x;
    return z*(pow(10,val2)) + x*pow(10,val2*2) + y;
}