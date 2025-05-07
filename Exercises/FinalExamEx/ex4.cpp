#include <iostream>
 #include <memory> 
 #include <vector>
 using namespace std;
 
 template<typename T>
 void function( vector<T> & a ){
    
     for(int i=0;i<a.size();i++){
         cout<< a[i]<<endl;
     }
 }
 
 
 
 
 
int main() {
    // Write C++ code here
 vector<int> v1 ={1,2,3,4,6,7};
 function(v1);
    return 0;
}