#include <iostream>

class Point
{
private:
    int x = 0, y = 0; // Координаты точки
    char name; //Имя точки
public:
    //Перегруженные прототипы конструктора
    Point();
    Point(int x, int y);
    Point (int x, int y, char name);
    //Перегруженные прототипы конструктора

    //Перегрузка операторов
    Point operator + (Point p)
        { return Point(p.getX() + this->getX(), p.getY() + this->getY(), this->getName()); } //Складывает координаты точки p и координаты другой точки
    Point operator * (Point p)
        { return Point(p.getX() * this->getX(), p.getY() * this->getY(), this->getName()); } //Умножает координаты точки p на координаты другой точки
    Point operator - (Point p)
        { return Point(p.getX() - this->getX(), p.getY() - this->getY(), this->getName()); } //Вычитает координаты точки p из координаты другой точки
    Point operator / (Point p)
        { return Point(p.getX() / this->getX(), p.getY() / this->getY(), this->getName()); } //Делит координаты точки p на координаты другой точки
    Point operator ! ()
        { return Point(!this->getX(), ~this->getY(), this->getName()); } // Побитовая инверсия данной точки
    bool operator < (Point p) //Находится ли точка p правее или выше сравниваемой точки в декартовой системе координат
        { if (p.getX() < this->getX() && p.getY() < p.getY()) return true;
        else return false; }
    bool operator > (Point p) //Находится ли точка p левее или выше сравниваемой точки в декартовой системе координат
        { if (p.getX() > this->getX() && p.getY() > p.getY()) return true;
            else return false; }
    Point operator ^ (Point p) //Вычисление среднего расстояния между точками p и данной точки (В целых значениях с округлением в меньшую сторону)
        { return Point((p.getX() + this->getX())/2, (p.getY() + this->getY())/2, this->getName()); }
    //Конец перегрузки операторов

    //Описание методов
    int getX();
    int getY();
    char getName();
    void setName(char newName);
    void setX(int newX);
    void setY(int newY);
    //Конец описания методов
};

//Описание прототипов конструкторов
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
