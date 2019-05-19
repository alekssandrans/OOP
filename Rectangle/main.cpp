#include <iostream>

using namespace std;
struct Point
{
    double x,y;
};
void read (Point& p)
{
    cout<<"Enter the coordinates of the point:"<<endl;
    cout<<"x="; cin>>p.x;
    cout<<"y="; cin>>p.y;
}
struct Rectangle
{
    Point top_left;
    Point bottom_right;
};
void read (Rectangle& rec)
{
    cout<<"Enter the coordinates of the top left point:"<<endl;
    cout<<"x="; cin>>rec.top_left.x;
    cout<<"y="; cin>>rec.top_left.y;
    cout<<"Enter the coordinates of the bottom right point:"<<endl;
    do
    {
        cout<<"x=";
        cin>>rec.bottom_right.x;
    }
    while(rec.bottom_right.x<= rec.top_left.x);
    do
    {
        cout<<"y=";
        cin>>rec.bottom_right.y;
    }
    while(rec.bottom_right.y>=rec.top_left.y);

}
double Height (const Rectangle& rec)
{
    return rec.top_left.y-rec.bottom_right.y;
}
double Width (const Rectangle& rec)
{
    return rec.bottom_right.x-rec.top_left.x;
}
double Perimeter(const Rectangle& rec)
{
    return 2*Height(rec)+2*Width(rec);
}
double Area (const Rectangle& rec)
{
    return Height(rec)*Width(rec);
}
bool isInRectangle(const Rectangle& rec, const Point& p)
{
    if (p.x>=rec.top_left.x && p.x<=rec.bottom_right.x && p.y>=rec.bottom_right.y && p.y<=rec.top_left.y)
        return true;
    else return false;
}

int main()
{
    Rectangle rec;
    read(rec);
    cout<<"The height of the rectangle is: "<<Height(rec)<<endl;
    cout<<"The width of the rectangle is: "<<Width(rec)<<endl;
    cout<<"The perimeter of the rectangle is: "<<Perimeter(rec)<<endl;
    cout<<"The area of the rectangle is: "<<Area(rec)<<endl;
    Point p;
    read(p);
    cout<<"The point is in the rectangle: "<<boolalpha<<isInRectangle(rec,p);

    return 0;
}
