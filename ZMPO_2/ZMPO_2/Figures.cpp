#include "stdafx.h"
#include "Figures.h"
#include "math.h"


using namespace std;
/*
CRectangle::CRectangle(double x1, double y1, double x2, double y2)
{
	point1 = new CPoint2D(x1, y1);
	point2 = new CPoint2D(x2, y2);
}
CRectangle::CRectangle(CPoint2D *cPoint1, CPoint2D *cPoint2)
{
	point1 = cPoint1;
	point2 = cPoint2;
}

CRectangle::CRectangle(CRectangle &cRectangle)
{
	point1 = new CPoint2D(*cRectangle.point1);
	point2 = new CPoint2D(*cRectangle.point2);
}
CRectangle::~CRectangle()
{
	
}*/
double CRectangle::dArea()
{
	return abs(point1.getX() - point2.getX())*abs(point1.getY() - point2.getY());
}

string CRectangle::sShowRect()
{
	
	return "CRectangle(CPoint(" + to_string(point1.getX()) + "," + to_string(point1.getY()) + ",CPoint(" + to_string(point2.getX()) + "," + to_string(point2.getY()) + "))";
}

CPoint2D::CPoint2D(double x, double y)
{
	dX = new double(x);
	dY = new double(y);
}
CPoint2D::CPoint2D(CPoint2D &cPointToCopy)
{
	dX = new double(cPointToCopy.getX());
	dY = new double(cPointToCopy.getY());
}
CPoint2D::~CPoint2D()
{
	delete dX;
	delete dY;
}
double CPoint2D::getX()
{
	return *dX;
}
double CPoint2D::getY()
{
	return *dY;
}
void CPoint2D::setX(double x)
{
	*dX = x;
	
}
void CPoint2D::setY(double y)
{
	*dY = y;
}
string CPoint2D::sShowPoint()
{
	return "CPoint(" + to_string(*dX) + "," + to_string(*dY) + ")";
}
double distance(CPoint2D p1, CPoint2D p2 )
{
	return sqrt(pow((p1.getX() - p2.getX()), 2) + pow((p1.getY() - p2.getY()), 2));
}
void CRectangle::operator +(CPoint2D p)
{
	
	CPoint2D ps1 = CPoint2D(point1.getX(), point2.getY());
	CPoint2D ps2 = CPoint2D(point2.getX(), point1.getY());
	CPoint2D cTab[4] = { point1, point2, ps1, ps2 };
	CPoint2D shortest = point1;
	for (int i = 0; i < 4; i++)
	{

		if (distance(p, cTab[i]) < distance(p, shortest))
		{
			shortest = cTab[i];
		}

	}
	if (((p.getX() < point1.getX() && p.getX() < point2.getX()) || (p.getX() > point1.getX() && p.getX() > point2.getX())) && ((p.getY() < point1.getY() &&
		p.getY() < point2.getY()) || (p.getY() > point1.getY() && p.getY() > point2.getY())))
	{
		

		if (shortest == point1)
		{
			point1 = point2;
		}
		else if (shortest == point2)					//i reversy ewentualnie
		{
		}
		else if (shortest == ps1)
		{
			point1 = ps2;
		}
		else
		{
			point1 = ps1;
		}
		point2 = p;
	}
	else if (((p.getX() < point1.getX() && p.getX() > point2.getX()) || (p.getX() > point1.getX() && p.getX() < point2.getX()))
		&& ((p.getY() < point1.getX() && p.getY() < point2.getY()) || (p.getY() > point1.getY() && p.getY() > point2.getY())))
	{
		if (shortest == point1)
		{
			point1.setY(p.getY());
		}
		else if (shortest == point2)					//i reversy ewentualnie
		{
			point2.setY(p.getY());
		}
		else if (shortest == ps1)
		{
			ps1.setY(p.getY());
			point1 = ps1;
			point2 = ps2;
		}
		else
		{
			ps2.setY(p.getY());
			point1 = ps2;
			point2 = ps1;
		}
	}
	else if (((p.getX() < point1.getX() && p.getX() < point2.getX()) || (p.getX() > point1.getX() && p.getX() > point2.getX()))
		&& ((p.getY() < point1.getX() && p.getY() > point2.getY()) || (p.getY() > point1.getY() && p.getY() < point2.getY())))
	{
		if (shortest == point1)
		{
			point1.setX(p.getX());
		}
		else if (shortest == point2)					//i reversy ewentualnie
		{
			point2.setX(p.getX());
		}
		else if (shortest == ps1)
		{
			ps1.setX(p.getX());
			point1 = ps1;
			point2 = ps2;
		}
		else
		{
			ps2.setX(p.getX());
			point1 = ps2;
			point2 = ps1;
		}
	}
}
void CRectangle::operator+(CRectangle r)
{
	*this + r.point1;
	*this + r.point2;
}
bool CPoint2D::operator ==(CPoint2D v)
{
	if ((*dX == v.getX()) && (*dY == v.getY()))
		return true;
	else
		return false;

}
void CPoint2D:: operator =(CPoint2D p)
{
	setX(p.getX());
	setY(p.getY());
}