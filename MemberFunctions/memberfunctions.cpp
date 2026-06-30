#include<iostream>
using namespace std;
class Rectangle {
    public :
    double length;
    double width; 

    Rectangle (double l , double w){
        length = l ;
        width = w;
    }
  inline double area () {
            return length * width;
        }
        double perimeter() const {
            return 2 *(length + width);
        }
};
int main(){
    double l ,w ;
    cout <<"Enter the length of the rectangle: "<< endl ; 
    cin >> l; 

    cout <<"Enter the width of the rectangle :"<< endl; 
    cin >> w; 

    Rectangle rectangle1(l , w);
    
    cout << "The area of Rectangle 1: "<< rectangle1.area()<<endl;
    cout << "The perimeter of the Rectangle 1 :"<< rectangle1.perimeter()<<endl;
    return 0;
   

}
// Inline Member Function  this is a function that is inserted directly at the point where it 
// is called instead of creating a seperate function call 
// AdvNTAGES OF Inline member function 
// a)Reduces Function Overhed(no stack creation ,no parameter passsing)
// b)Faster executions for smaller functions 
// c)Improves performace in loops -useful when the function is called so many times 
// Its disavantages is that it may increase program size and the code is copied when the function is being called 
// Constant member functions is declared using the const keyword after the parameter 
// This means the function cannot modify ny data members of the object 