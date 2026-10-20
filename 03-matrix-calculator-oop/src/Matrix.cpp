#include "Matrix.h"
#include <iostream>
using namespace std;

ostream& operator<< (ostream& out, const Matrix& mat)
{
    for(int i=0 ; i<mat.row ; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
          out<<mat.data[i][j] << "    ";

        }
        out<<endl ;
    }
    return out ;
}

void createMatrix (int row,int col, int num[],Matrix& mat)
{
    mat.row = row ;
    mat.col = col ;
    mat.data = new int*[row] ;
    for(int i=0 ; i<row ; i++)
    {
        mat.data[i] = new int[col] ;
    }
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            mat.data[i][j] = num[i*col+j] ;
        }
    }
}

istream& operator>> (istream& in, Matrix& mat)
{
    cout<< "Enter no of rows :"<<endl ;
    in>>mat.row;
    cout<< "Enter no of cols :"<<endl ;
    in>>mat.col ;
    mat.data = new int*[mat.row] ;
    for(int i=0 ; i<mat.row ; i++)
    {
        mat.data[i] = new int[mat.col] ;
    }
    cout<< "Enter the elements of the array :"<<endl ;
    for(int i=0 ; i<mat.row ; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
          in>>mat.data[i][j] ;
        }
    }
    return in ;
}

Matrix Matrix::operator+(Matrix mat1)
{
    Matrix newmatrix ;
    newmatrix.row = row ;
    newmatrix.col = col ;
    newmatrix.data = new int*[newmatrix.row] ;
    for(int i=0 ; i<newmatrix.row ; i++)
    {
        newmatrix.data[i] = new int[newmatrix.col] ;
    }
    if(row == mat1.row && col == mat1.col)
    {
        for(int i=0 ; i<mat1.row ; i++)
        {
            for (int j=0 ; j<mat1.col ; j++)
            {
                newmatrix.data[i][j] = data[i][j] + mat1.data[i][j] ;
            }
        }
        return newmatrix ;
    }
}

Matrix Matrix::operator-(Matrix mat1)
{
    Matrix newmatrix ;
    newmatrix.row = row ;
    newmatrix.col = col ;
    newmatrix.data = new int*[newmatrix.row] ;
    for(int i=0 ; i<newmatrix.row ; i++)
    {
        newmatrix.data[i] = new int[newmatrix.col] ;
    }
    if(row == mat1.row && col == mat1.col)
    {
        for(int i=0 ; i<mat1.row ; i++)
        {
            for (int j=0 ; j<mat1.col ; j++)
            {
                newmatrix.data[i][j] = data[i][j] - mat1.data[i][j] ;
            }
        }
        return newmatrix ;
    }
}

Matrix Matrix::operator*(Matrix mat1)
{
    Matrix newmatrix ;
    newmatrix.row = row ;
    newmatrix.col = mat1.col ;
    newmatrix.data = new int*[newmatrix.row] ;
    for(int i=0 ; i<newmatrix.row ; i++)
    {
        newmatrix.data[i] = new int[newmatrix.col] ;
    }
    if (mat1.col == newmatrix.row)
    {
        for(int i=0 ; i<mat1.row ; i++)
        {
            for(int j=0 ; j<mat1.col ; j++)
            {
                newmatrix.data[i][j] = mat1.data[i][j]*data[i][j] ;
            }
        }
        return newmatrix ;
    }

}

Matrix Matrix::operator+(int scalar)
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j] += scalar ;
        }
    }
}

Matrix Matrix::operator-(int scalar)
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j] -= scalar ;
        }
    }
}

Matrix Matrix::operator*(int scalar)
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j] *= scalar ;
        }
    }
}

Matrix Matrix::transpose()
{
    Matrix newmatrix ;
    newmatrix.row = col ;
    newmatrix.col = row ;
    newmatrix.data = new int*[newmatrix.row] ;
    for(int i=0 ; i<newmatrix.row ; i++)
    {
      newmatrix.data[i] = new int[newmatrix.col] ;
    }
    for(int i=0 ; i<newmatrix.col ; i++)
    {
        for(int j=0 ; j<newmatrix.row ; j++)
        {
            newmatrix.data[j][i] = data[i][j] ;
        }
    }
    return newmatrix ;
}

bool Matrix::isSquare()
{
    bool a ;
    row == col ? a=true : a=false ;
    return a ;
}

bool Matrix::isIdentity()
{
    bool a  ;
    if (isSquare()== true)
    {
        for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            if(i!=j&&data[i][j]==0)
            {
                a=true ;
            }
            if(i==j&&data[i][j]==1)
            {
                a=true ;
            }
            else
            {
            a= false ;
            break ;
            }
        }
    }
    }
    return a ;
}

Matrix Matrix::operator+= (Matrix mat1)
{

    for(int i=0 ; i<mat1.row ; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            data[i][j] += mat1.data[i][j] ;
        }
    }
    return *this ;
}

Matrix Matrix::operator-=(Matrix mat1)
{
    for(int i=0 ; i<mat1.row ; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            data[i][j] -= mat1.data[i][j] ;
        }
    }
    return *this ;
}

Matrix Matrix::operator+=(int scalar)
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j] += scalar ;
        }
    }
    return *this ;
}

Matrix Matrix::operator-=(int scalar)
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j] -= scalar ;
        }
    }
    return *this ;
}

Matrix Matrix::operator++()
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j]++ ;
        }
    }
    return *this ;
}

Matrix Matrix::operator--()
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            data[i][j]-- ;
        }
    }
    return *this ;
}

bool Matrix::operator==(Matrix mat1)
{
    for(int i =0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(data[i][j] != mat1.data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(Matrix mat1)
{
    for(int i =0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(data[i][j] == mat1.data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::isSymmetric()
{
    if(isSquare()==true)
    {
        for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            if(data[i][j]==data[j][i])
            {
                continue ;
            }
            return false ;
        }
    }
    return true ;
    }
    else return false ;

}
