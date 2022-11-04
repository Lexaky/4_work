#include <iostream>

/*
ќпределить свою структуру данных, котора€ хранит числа + еще что-нибудь (число + название?)
„ерез перегрузку реализовать над структурой побитовые операции ( + будет побитовым "или", * побитовым "и" и тд)
» вывод в консольку красивый отформатированный через printf дл€ этой структуры :)
*/
/*
21-25 прототипы конструкторов
27-46 перегрузка операторов
48-55 прототипы методов
58-70 описание прототипов конструкторов
72-85 описание прототипов методов
*/
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

//ќписание прототипов конструкторов
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
// онец описани€ прототипов конструкторов

//–еализаци€ прототипов методов
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
// онец реализации методов


void printPoint(Point p)
{ //¬ывод данных о точке p: Ќазвание точки, координаты
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


    newP3 = *newP1 * *newP2;
    newP3.setName('C');
    printPoint(newP3);

    newP3 = !newP3;
    newP3.setName('C');
    printPoint(newP3);


    newP3 = *newP1 + *newP2;
    newP3.setName('C');
    printPoint(newP3);


    ///////////////////////////////////////////////////////////
    std::cout << "\n\nѕример форматированного вывода: \n";
    newP3 = *newP1 * *newP2;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = !newP3;
    newP3.setName('C');
    printPoint(newP3);
    newP3 = *newP1 + *newP2;
    newP3.setName('C');
    printPoint(newP3);
    std::cout << "p1 < p2? " << (*newP1 < *newP2) << std::endl;
    std::cout << "p1 > p2? " << (*newP1 > *newP2) << std::endl;
    newP3 = *newP1 ^ *newP2;
    newP3.setName('C');
    printPoint(newP3);
    return 0;
}
