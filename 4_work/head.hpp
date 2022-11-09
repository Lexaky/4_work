#ifndef HEAD
#define HEAD

#include <iostream>

class Point
{
private:
    int x = 0, y = 0; //  оординаты точки
    char name; //»м€ точки
public:
    //ѕерегруженные прототипы конструктора
    Point();
    Point(int x, int y);
    Point (int x, int y, char name);
    //ѕерегруженные прототипы конструктора

    //ѕерегрузка операторов
    Point operator + (Point p)
        { return Point(p.getX() + this->getX(), p.getY() + this->getY(), this->getName()); } //—кладывает координаты точки p и координаты другой точки
    Point operator * (Point p)
        { return Point(p.getX() * this->getX(), p.getY() * this->getY(), this->getName()); } //”множает координаты точки p на координаты другой точки
    Point operator - (Point p)
        { return Point(p.getX() - this->getX(), p.getY() - this->getY(), this->getName()); } //¬ычитает координаты точки p из координаты другой точки
    Point operator / (Point p)
        { return Point(p.getX() / this->getX(), p.getY() / this->getY(), this->getName()); } //ƒелит координаты точки p на координаты другой точки
    Point operator ! ()
        { return Point(!this->getX(), ~this->getY(), this->getName()); } // ѕобитова€ инверси€ данной точки
    bool operator < (Point p) //Ќаходитс€ ли точка p правее или выше сравниваемой точки в декартовой системе координат
        { if (p.getX() < this->getX() && p.getY() < p.getY()) return true;
        else return false; }
    bool operator > (Point p) //Ќаходитс€ ли точка p левее или выше сравниваемой точки в декартовой системе координат
        { if (p.getX() > this->getX() && p.getY() > p.getY()) return true;
            else return false; }
    Point operator ^ (Point p) //¬ычисление среднего рассто€ни€ между точками p и данной точки (¬ целых значени€х с округлением в меньшую сторону)
        { return Point((p.getX() + this->getX())/2, (p.getY() + this->getY())/2, this->getName()); }
    // онец перегрузки операторов

    //ќписание методов
    int getX();
    int getY();
    char getName();
    void setName(char newName);
    void setX(int newX);
    void setY(int newY);
    // онец описани€ методов
};
void printPoint(Point p);
//ќписание прототипов конструкторов
#endif // HEAD
