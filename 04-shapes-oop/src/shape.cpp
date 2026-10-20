#include "shape.h"
#include "cmath"
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

void ShapeGame::EndMove(int x, int y)
{
   stx =  x;
   sty =  y;
   DestroyShapes();
}
ShapeGame::~ShapeGame()
{
    DestroyShapes();
}

/////////////////////////////////////////////////////////////


bool Rect::IsInside(int x, int y)
{
    int max_x , min_x, max_y , min_y;

    max_x = this->x + (w / 2);

    min_x = this->x - (w / 2);

    max_y = this->y + (h / 2);

    min_y = this->y - (h / 2);

    if( (x >= min_x && x <= max_x) &&  (y >= min_y && y <= max_y) )
    {
        return true;
    }

    else{
        return false;
        }
}

bool Square::IsInside(int x, int y)
{
    int max_x , min_x, max_y , min_y;

    max_x = this->x + (w / 2);

    min_x = this->x - (w / 2);

    max_y = this->y + (w / 2);

    min_y = this->y - (w / 2);

    if( (x >= min_x && x <= max_x) &&  (y >= min_y && y <= max_y) )
    {
        return true;
    }

    else{
        return false;
        }
}

bool Circle::IsInside(int x, int y)
{
  if ((pow((x - this->x),2) + pow((y - this->y),2)) < pow(w,2))
    return true;
  else
    return false;
}

double Rect::Area()
{
    return w*h;
}


double Square::Area()
{
    return w*4;
}



double Circle::Area()
{
    return 3.14 * pow(w,2);
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
