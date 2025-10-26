#include<iostream>
#include "SharedPtr.h"
using namespace std;
int main() {
    SharedPtr<int> p1(new int(100));
    cout << "Count: " << p1.use_count() << endl; 

    {
        SharedPtr<int> p2 = p1;
        cout << "Count: " << p1.use_count() << endl; 
        cout << *p2 << endl; 
    }

    cout << "Count: " << p1.use_count() << endl; 
}
