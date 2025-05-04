#include<iostream>

using namespace std;

class area
{
public:
int length;
int breadth;
int height;

public:
void square(int length)   //area of square
{
int area=length*length;
cout<<"Area of square= "<<area<<endl;
}
void cube(int length)  //area of cube
{
int area=6*length*length;
cout<<"Area of cube= "<<area<<endl;
}
void rectangle(int l,int b)  //area of rectangle
{
int area=l*b;
cout<<"Area of rectangle= "<<area<<endl;
}
void cuboid(int l,int b,int h)  //area of cuboid
{
int area=2*((l*b)+(l*h)+b*h);
cout<<"Area of cuboid= "<<area<<endl;
}
};

int main()
{
    int choice;
    area obj;

    while(choice!=5)
    {
        cout<<"1:Area of Square"<<endl;
        cout<<"2:Area of cube"<<endl;
        cout<<"3:Area of Rectangle"<<endl;
        cout<<"4:Area of Cuboid"<<endl;
        cout<<"5:To exit the program"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:  //area of square
        cout << "Enter the side of the Square: ";
        cin >> obj.length;
        obj.square(obj.length);
        break;

        case 2:   //area of cube
        cout << "Enter the side of the Cube: ";
        cin >> obj.length;
        obj.cube(obj.length);
        break;

        case 3:    //area of rectangle
        cout << "Enter the length of the Rectangle: ";
        cin >> obj.length;
        cout << "Enter the breadth of the Rectangle: ";
        cin >> obj.breadth;
        obj.rectangle(obj.length,obj.breadth);
        break;

        case 4:  //area of cuboid
        cout << "Enter the length of the Cuboid: ";
        cin >> obj.length;
        cout << "Enter the breadth of the Cuboid: ";
        cin >> obj.breadth;
        cout << "Enter the height of the Cuboid: ";
        cin >> obj.height;
        obj.cuboid(obj.length,obj.breadth,obj.height);
        break;

        case 5:  //exit program
        cout<< "Program Ended"<< endl;
        cout << "Thank You";
        break;

        default :
        cout << " Please enter the number between 1 to 5 " << endl;
        }
        
    }
}
