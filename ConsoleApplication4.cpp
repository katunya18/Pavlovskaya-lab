#include "pch.h"
#include <locale>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Класс-точка
class point
{
public:
	point(double x = 0, double y = 0);
	double x() const;
	double y() const;
private:
	double _x, _y;
};

// Класс-многоугольник
class polygon
{
public:
	// Конструктор
	polygon(const point& start, const point& end);
	polygon(std::vector<point> points);
	// Площадь
	double square() const;
	// Если многоугольник-аргумент находится внутри 
	bool contain(const polygon& p) const;
private:
	// Класс-сторона используется внутри класса. Можно и без него обойтись
	class side
	{
	public:
		side(point p1, point p2);
		const point& p1() const;
		const point& p2() const;
	private:
		point _p1, _p2;
	};
	// Площадь треугольника
	double square(point p1, point p2, point p3) const;
	// Возвращает положительное значение, если p лежит слева от вектора side и отрицательное если наоборот
	double pointposition(side v, point p) const;
	typedef std::vector<point> points;
	typedef points::const_iterator cit;
	points _points;
};
int main()
{
	locale::global(locale("russian_russia.866"));
	// Массивы точек для каждого многоугольника
	point firstPoints[4] = { point(0,0),point(10,0),point(10,10),point(0,10) };
	point secondPoints[3] = { point(0,0),point(5,0),point(5,5) };
	// Многоугольники
	polygon first(firstPoints[0], firstPoints[sizeof(firstPoints) / sizeof(point)]);
	polygon second(secondPoints[0], secondPoints[sizeof(secondPoints) / sizeof(point)]);
	wcout << L"first.square():" << first.square() << endl;
	wcout << L"second.square():" << second.square() << endl;
	wcout << L"first.contain(second):" << boolalpha << first.contain(second) << endl;
	wcout << L"second.contain(first):" << boolalpha << second.contain(first) << endl;
	system("PAUSE");
	return 0;
}
point::point(double x/*=0*/, double y/*=0*/)
	:_x(x)
	, _y(y)
{
}

inline double point::x() const
{
	return _x;
}
inline double point::y() const
{
	return _y;
}
polygon::polygon(const point& start, const point& end)
{
	_points = points(&start, &end);
}
polygon::polygon(std::vector<point> points) :_points(points)
{
}

// Площадь многоугольника вычисляется как сумма площадей треугольников в него входящих
double polygon::square() const
{
	if (_points.size() > 2)
	{
		cit first = _points.begin();
		cit second = first + 1;
		cit third = second + 1;
		double res = 0;
		do
		{

			res += square(*first, *second, *third);
			++second; ++third;
		} while (third != _points.end());
		return res;

	}

	else
	{
		throw L"Это не многоугольник";
	}

}

double polygon::square(point p1, point p2, point p3) const
{
	return abs((p2.x() - p1.x())*(p3.y() - p1.y()) - (p3.x() - p1.x())*(p2.y() - p1.y())) / 2.0;
}
bool polygon::contain(const polygon& p) const
{
	if (_points.size() > 2 && p._points.size() > 2)
	{
		cit first = _points.begin();
		cit second = first + 1;
		double sign = 0;
		do
		{

			for (cit it = p._points.begin(); it != p._points.end(); ++it)
			{
				double pos = pointposition(side(*first, *second), *it);
				if (!sign)
				{
					sign = pos;
				}
				else
				{
					if (sign*pos < 0)
					{
						return false;
					}
				}
			}

			++second;
			if (second == _points.end())
			{
				second = _points.begin();
			}
		} while (++first != _points.end());
		return true;
	}

	else
	{
		throw L"Требуется два многоугольника";
	}
}
double polygon::pointposition(side v, point p) const
{
	return (v.p2().x() - v.p1().x())*(p.y() - v.p1().y()) - (p.x() - v.p1().x())*(v.p2().y() - v.p1().y());
}
polygon::side::side(point p1, point p2)
	:_p1(p1)
	, _p2(p2)
{
}
inline const point& polygon::side::p1() const
{
	return _p1;
}
inline const point& polygon::side::p2() const
{
	return _p2;
}