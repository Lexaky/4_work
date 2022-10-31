#include <iostream>

/*
Определить свою структуру данных, которая хранит числа + еще что-нибудь (число + название?)
Через перегрузку реализовать над структурой побитовые операции ( + будет побитовым "или", * побитовым "и" и тд)
И вывод в консольку красивый отформатированный через printf для этой структуры :)
*/

class Point
{
private:
    int x = 0, y = 0; // coordinates
    char name;
public:

    Point()
    {
        x = 0; y = 0;
        name = '0';
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        name = '0';
    }
    Point (int x, int y, char name)
    {
        this->x = x;
        this->y = y;
        this->name = name;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    char getName()
    {
        return name;
    }
    void setName(char newName)
    {
        name = newName;
    }
    void setX(int newX)
    {
        x = newX;
    }
    void setY(int newY)
    {
        y = newY;
    }
};

Point operator + (Point p1, Point p2)
{ return Point(p1.getX() | p2.getX(), p1.getY() | p2.getY(), p1.getName()); } //Побитово складывает координаты p1, p2; Имя первого параметра

Point operator * (Point p1, Point p2)
{ return Point(p1.getX() & p2.getX(), p1.getY() & p2.getY(), p1.getName()); } //Побитово умножает координаты p1, p2; Имя первого параметра

Point operator ! (Point p1)
{ return Point(~p1.getX(), ~p1.getY(), p1.getName()); } // Побитовая инверсия

/*
p1: name; coordinates (x1, y1)
p2: name; coordiantes (x2, y2);
*/

Point operator < (Point p1, Point p2)
//Поразрядный сдвиг влево координаты x1 на x2 бит влево, координаты y1 на y2 бит влево
{ return Point(p1.getX() << p2.getX(), p1.getY() << p2.getY(), p1.getName()); }

Point operator > (Point p1, Point p2)
//Поразрядный сдвиг влево координаты x1 на x2 бит вправо, координаты y1 на y2 бит вправо
{ return Point(p1.getX() >> p2.getX(), p1.getY() >> p2.getY(), p1.getName()); }

Point operator ^ (Point p1, Point p2)
//Исключающее ИЛИ координат x1 и x2; y1 и y2
{ return Point(p1.getX() ^ p2.getX(), p1.getY() ^ p2.getY(), p1.getName()); }

using namespace std;

void printPoint(Point p)
{ //Вывод данных о точке p: Название точки, координаты
 // cout << "(*)" << p.getName() <<  " (" << p.getX() << "; " << p.getY() << ") " << endl;
  printf("(*)%.4c (%.4d; %.4d) \n", p.getName(), p.getX(), p.getY());
}

int main()
{
    setlocale(LC_ALL, "rus");

    Point* newP1 = new Point(5, 12, 'A');
    Point* newP2 = new Point(8, 5, 'B');
    Point newP3 = *newP1 + *newP2;

    newP3.setName('C');

    printPoint(*newP1);
    printPoint(*newP2);
    printPoint(newP3);

    cout << "Побитовое И: ";
    newP3 = *newP1 * *newP2;
    newP3.setName('C');
    printPoint(newP3);
    cout << "Побитовая инверсия: ";
    newP3 = !newP3;
    newP3.setName('C');
    printPoint(newP3);

    cout << "Побитовое ИЛИ: ";
    newP3 = *newP1 + *newP2;
    newP3.setName('C');
    printPoint(newP3);

    cout << "Побитовый сдвиг влево: ";
    newP3 = *newP1 < *newP2;
    newP3.setName('C');
    printPoint(newP3);

    cout << "Побитовый сдвиг вправо: ";
    newP3 = *newP1 > *newP2;
    newP3.setName('C');
    printPoint(newP3);

    cout << "Побитовый исключающее ИЛИ: ";
    newP3 = *newP1 ^ *newP2;
    newP3.setName('C');
    printPoint(newP3);

    ///////////////////////////////////////////////////////////
    cout << "\n\nПример форматированного вывода: " << endl;
    newP3 = *newP1 * *newP2;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = !newP3;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = *newP1 + *newP2;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = *newP1 < *newP2;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = *newP1 > *newP2;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = *newP1 ^ *newP2;
    newP3.setName('C');
    printPoint(newP3);
    return 0;
}
