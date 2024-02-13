#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    // Creating a vector
    vector<int> v;

    // Adding elements to the vector
    v.push_back(1);
    v.push_back(3);
    v.push_back(10);
    v.push_back(7);
    v.push_back(9);

    // (i) Binary Search
    cout << "(i) Binary Search" << endl;
    cout << "array : [ 1 3 10 7 9 ] " << endl;
    
    // Binary search for elements in the vector
    cout << "find 6 : " << binary_search(v.begin(),v.end(), 6) << endl;
    cout << "find 7 : " << binary_search(v.begin(),v.end(), 7) << endl;
    cout << endl;

    // (ii) Sort
    cout << "(ii) Sort" << endl;
    // Sorting the vector
    sort(v.begin(), v.end());
    // Displaying the sorted vector
    for(int i:v){
        cout << i << endl;
    }
    cout << endl;

    // (iii) Lower/Upper Bound
    cout << "(iii) Lower/Upper Bound" << endl;
    cout << "lower bound 5 : " << lower_bound(v.begin(),v.end(),5) - v.begin() << endl;
    cout << "lower bound 7 : " << lower_bound(v.begin(),v.end(),7) - v.begin() << endl;
    cout << "lower bound 3 : " << lower_bound(v.begin(),v.end(),3) - v.begin() << endl;
    cout << endl;
    cout << "upper bound 5 :" << upper_bound(v.begin(),v.end(),5) - v.begin() << endl;
    cout << "upper bound 7 :" << upper_bound(v.begin(),v.end(),7) - v.begin() << endl;
    cout << "upper bound 3 :" << upper_bound(v.begin(),v.end(),3) - v.begin() << endl;
    cout << endl;

    // (iv) Min/Max
    cout << "(iv) Min/Max" << endl;
    int a = 10;
    int b = 20;
    // Finding maximum and minimum
    cout << " MAX : " << max(a,b) << endl;
    cout << " MIN : " << min(a,b) << endl;
    cout << endl;

    // (v) Swap
    cout << "(v) Swap" << endl;
    // Swapping two values
    cout << "after swap" << endl;
    cout << " A : " << a << endl;
    cout << " B : " << b << endl;
    swap(a,b);
    cout << "before swap" << endl;
    cout << " A : " << a << endl;
    cout << " B : " << b << endl;
    cout << endl;

    // (vi) Reverse String
    cout << "(vi) Reverse String" << endl;
    string abcd = "abcd";
    // Reversing a string
    cout << "string : " << abcd << endl;
    reverse(abcd.begin(),abcd.end());
    cout << "reverse string : " << abcd << endl;
    cout << endl;

    // (vii) Rotate
    cout << "(vii) Rotate" << endl;
    cout << "after rotate" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;
    // Rotating elements in the vector
    rotate(v.begin(),v.begin()+1,v.end());
    cout << "before rotate" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
