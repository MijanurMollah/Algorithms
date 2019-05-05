#include <iostream>
using namespace std;

float powa(float x, int y);
float powb(float x, int y);

int main(void){
    float x; 
    int y;
	cout << "Enter base and power "<<endl;
    cin >> x;
    cin >> y;
    float r1 = powa(x, y);
    cout << "Linear time: " << "pow(" << x << "," << y << ")= " << r1 << endl;
    float r2 = powb(x, y);
    cout << "lg n time: " << "pow(" << x << "," << y << ")= " << r2 << endl;
    return 0;
}

float powa(float x, int y){
    float result = 1;
    if (y > 0)
    {
    for(int i = 0; i < y; i++){
        result = result * x;
    }
    }
    else
    {
        for (int i = 0; i > y; i--){
            result = result / x;
        }
    }
    return result;
}

float powb(float x, int y){
    if (y==0)
    return 1;
    int z = y/2;
    float result = powb(x, z);
    if (y % 2 == 0){
        result = result * result;
        return result;
    }
    if (y > 0) {
    for (int i = z; i < y; i++) {
        result = result*x;
    }
    }
    else
    {
       for (int i = z; i > y; i--) {
        result = result/x;
    } 
    }
    return result;
}