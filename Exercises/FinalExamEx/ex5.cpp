// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
template<typename T1, typename T2>
class Pair{
    T1 va1;
    T2 va2;
  public:
    Pair(T1 va3, T2 va4){
        va1=va3;
        va2=va4;
    }
  void  print(){
        cout<< " First value " << va1<<endl;
         cout<< " second value " << va2<<endl;
    }
};
int main() {
Pair p1("Rama",8);
p1.print();
    return 0;
}