
#include "head.hpp"
Point::Point()
    {   x = 0; y = 0;
        name = '0'; }
Point::Point (int x, int y, char name)
    {   this->x = x;
        this->y = y;
        this->name = name; }
Point::Point(int x, int y)
    {   this->x = x;
        this->y = y;
        name = '0'; }
//Конец описания прототипов конструкторов

//Реализация прототипов методов
int Point::getX()
    { return (this->x); }
int Point::getY()
    { return y; }
char Point::getName()
    { return this->name; }
void Point::setName(char newName)
    { name = newName; }
void Point::setX(int newX)
    { x = newX; }
void Point::setY(int newY)
    { y = newY; }
//Конец реализации методов


void printPoint(Point p)
{ //Вывод данных о точке p: Название точки, координаты
  printf("(*)%.4c (%.4d; %.4d) \n", p.getName(), p.getX(), p.getY());
}
