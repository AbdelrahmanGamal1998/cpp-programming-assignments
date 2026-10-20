#include "shape.h"
#include <cmath>
#include <cstdlib>
#include<iostream>

using namespace std;
Shape::~Shape (){

}
Rect::Rect (int _x, int _y)
{
    x = _x;
    y = _y;
    w = 50 + rand() % 50;
    h = 50 + rand() % 50;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void Rect::Draw(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush (RGB (r, g, b)) ;
    SelectObject (hdc, hBrush) ;
    Rectangle (hdc, x-w, y-h, x+w, y+h) ;
    DeleteObject (hBrush) ;


//    int x_,y_;
//
//    cout << "Area of this shape is "<<Area()<<endl;
//
//    cout << " Enter x,y to test if it inside rect \n";
//    cin >> x_ >> y_ ;
//    if ( IsInside(x_,y_) == true)
//    {
//        cout << " point is inside shape "<<endl;
//    }
//    else{
//         cout << " point is not inside shape "<<endl;
//    }
}


/////////////////////////////////////////////////////////////

Square::Square (int _x, int _y)
{
    x = _x;
    y = _y;
    w = 50 + rand() % 50;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void Square::Draw(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush (RGB (r, g, b)) ;
    SelectObject (hdc, hBrush) ;
    Rectangle (hdc, x-w, y-w, x+w, y+w) ;
    DeleteObject (hBrush) ;

//     int x_,y_;
//
//    cout << "Area of this shape is "<<Area()<<endl;
//
//    cout << " Enter x,y to test if it inside rect \n";
//    cin >> x_ >> y_ ;
//    if ( IsInside(x_,y_) == true)
//    {
//        cout << " point is inside shape "<<endl;
//    }
//    else{
//         cout << " point is not inside shape "<<endl;
//    }
}

/////////////////////////////////////////////////////////////

Circle::Circle (int _x, int _y)
{
    x = _x;
    y = _y;
    w = 50 + rand() % 50;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void Circle::Draw(HDC hdc)
{
    HBRUSH hBrush = CreateSolidBrush (RGB (r, g, b)) ;
    SelectObject (hdc, hBrush) ;
    Ellipse (hdc, x-w, y-w, x+w, y+w) ;
    DeleteObject (hBrush) ;

   /* int x_,y_;

    cout << "Area of this shape is "<<Area()<<endl;

    cout << " Enter x,y to test if it inside rect \n";
    cin >> x_ >> y_ ;
    if ( IsInside(x_,y_) == true)
    {
        cout << " point is inside shape "<<endl;
    }
    else{
         cout << " point is not inside shape "<<endl;
    }*/
}

/////////////////////////////////////////////////////////////

ShapeGame::ShapeGame()
{
    numShapes = 0;
}

void ShapeGame::AddDrawShape(HDC hdc, int x, int y)
{
    int type = rand()%3;
    if(type==0) shapes[numShapes] = new Rect(x, y);
    else if(type==1) shapes[numShapes] = new Square(x, y);
    else if(type==2) shapes[numShapes] = new Circle(x, y);
    shapes[numShapes]->Draw(hdc);
    numShapes++;
}

void ShapeGame::DrawShapes(HDC hdc)
{
    int i;
    for(i=0;i<numShapes;i++) shapes[i]->Draw(hdc);
}

void ShapeGame::DestroyShapes()
{
    int i;
    for(i=0;i<numShapes;i++) delete shapes[i];
    numShapes = 0;
}

void ShapeGame::StartMove(int x, int y)
{
    stx = x;
    sty = y;
}

// Move the center of the last shape containing (stx,sty) to (x,y) and make it the top-most shape.
void ShapeGame::EndMove(int x, int y)
{
    for (int i = numShapes - 1; i >= 0; i--)
    {
        if (shapes[i]->IsInside(stx, sty))
        {
            Shape* moved = shapes[i];
            moved->MoveTo(x, y);
            for (int j = i; j < numShapes - 1; j++)
                shapes[j] = shapes[j + 1];
            shapes[numShapes - 1] = moved;
            return;
        }
    }
}

// Area of the last (top-most) shape, or 0 when there are no shapes.
double ShapeGame::GetArea()
{
    if (numShapes == 0)
        return 0;
    return shapes[numShapes - 1]->Area();
}

ShapeGame::~ShapeGame()
{
    DestroyShapes();
}

/////////////////////////////////////////////////////////////


// w and h are the half width and half height (see shape.h and Draw), so the shape spans
// [center - w, center + w] by [center - h, center + h].
bool Rect::IsInside(int x, int y)
{
    return abs(x - this->x) <= w && abs(y - this->y) <= h;
}

bool Square::IsInside(int x, int y)
{
    return abs(x - this->x) <= w && abs(y - this->y) <= w;
}

bool Circle::IsInside(int x, int y)
{
    double dx = x - this->x;
    double dy = y - this->y;
    return dx * dx + dy * dy <= (double)w * w;
}

double Rect::Area()
{
    return (2.0 * w) * (2.0 * h);
}

double Square::Area()
{
    return (2.0 * w) * (2.0 * w);
}

double Circle::Area()
{
    return 3.14159265358979 * w * w;
}

void Rect::MoveTo(int _x, int _y)    //sets new center of shape
{
x=_x ;
y=_y ;
}

void Square::MoveTo(int _x, int _y)               //sets new center of shape
{
x=_x ;
y=_y ;
}

void Circle::MoveTo(int _x, int _y)                       //sets new center of shape
{
x=_x ;
y=_y ;
}
