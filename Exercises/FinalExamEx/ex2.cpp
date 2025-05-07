#include <iostream>
 #include <memory> 
 using namespace std;
 
 template<typename T>
 T Function(T f1, T f2){
     if (f1>f2){
         return f1;
     }
     else 
     return f2;
 }
 template <>
 string Function<string> (string f1, string f2){
     if(f1.length() >= f2.length()){
         return f1;
     }
     else 
     return f2;
 }
 int main(){
     int a=10;
     int b=15;
     cout<< Function(a,b);
  string s="New";
  string n="Hi";
  cout<< Function(s,n);

 }