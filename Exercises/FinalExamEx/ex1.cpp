#include <iostream>
 #include <memory> 
 using namespace std;
 
 template<typename T>
 void swapFunction(T f1, T f2){
     T temp;
     temp=f1;
     f1=f2;
     f2=temp;
          cout<< "value of a "<< f1 <<endl;
     cout<< "value of b "<< f2 <<endl;

 }
 int main(){
     int a=10;
     int b=15;
     swapFunction(a,b);
     cout<< "value of a "<< a <<endl;
     cout<< "value of b "<< b <<endl;

 }