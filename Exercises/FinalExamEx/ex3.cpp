#include <iostream>
 #include <memory> 
 using namespace std;
 
 template<typename T, int size>
 void function( T (&a) [size] ){
    
     for(int i=0;i<size;i++){
         cout<< a[i]<<endl;
     }
 }
 
 
 

 
int main() {
    // Write C++ code here
 int array[8] ={1,2,3,4,6,7};
 function(array);
 cout<< sizeof(array)/sizeof(array[0])<<endl;
    return 0;
}