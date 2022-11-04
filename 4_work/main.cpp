#include <iostream>

/*
���������� ���� ��������� ������, ������� ������ ����� + ��� ���-������ (����� + ��������?)
����� ���������� ����������� ��� ���������� ��������� �������� ( + ����� ��������� "���", * ��������� "�" � ��)
� ����� � ��������� �������� ����������������� ����� printf ��� ���� ��������� :)
*/
/*
21-25 ��������� �������������
27-46 ���������� ����������
48-55 ��������� �������
58-70 �������� ���������� �������������
72-85 �������� ���������� �������
*/
class Point
{
private:
    int x = 0, y = 0; // ���������� �����
    char name; //��� �����
public:
    //������������� ��������� ������������
    Point();
    Point(int x, int y);
    Point (int x, int y, char name);
    //������������� ��������� ������������

    //���������� ����������
    Point operator + (Point p)
        { return Point(p.getX() + this->getX(), p.getY() + this->getY(), this->getName()); } //���������� ���������� ����� p � ���������� ������ �����
    Point operator * (Point p)
        { return Point(p.getX() * this->getX(), p.getY() * this->getY(), this->getName()); } //�������� ���������� ����� p �� ���������� ������ �����
    Point operator - (Point p)
        { return Point(p.getX() - this->getX(), p.getY() - this->getY(), this->getName()); } //�������� ���������� ����� p �� ���������� ������ �����
    Point operator / (Point p)
        { return Point(p.getX() / this->getX(), p.getY() / this->getY(), this->getName()); } //����� ���������� ����� p �� ���������� ������ �����
    Point operator ! ()
        { return Point(!this->getX(), ~this->getY(), this->getName()); } // ��������� �������� ������ �����
    bool operator < (Point p) //��������� �� ����� p ������ ��� ���� ������������ ����� � ���������� ������� ���������
        { if (p.getX() < this->getX() && p.getY() < p.getY()) return true;
        else return false; }
    bool operator > (Point p) //��������� �� ����� p ����� ��� ���� ������������ ����� � ���������� ������� ���������
        { if (p.getX() > this->getX() && p.getY() > p.getY()) return true;
            else return false; }
    Point operator ^ (Point p) //���������� �������� ���������� ����� ������� p � ������ ����� (� ����� ��������� � ����������� � ������� �������)
        { return Point((p.getX() + this->getX())/2, (p.getY() + this->getY())/2, this->getName()); }
    //����� ���������� ����������

    //�������� �������
    int getX();
    int getY();
    char getName();
    void setName(char newName);
    void setX(int newX);
    void setY(int newY);
    //����� �������� �������
};

//�������� ���������� �������������
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
//����� �������� ���������� �������������

//���������� ���������� �������
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
//����� ���������� �������


void printPoint(Point p)
{ //����� ������ � ����� p: �������� �����, ����������
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
    std::cout << "\n\n������ ���������������� ������: \n";
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
