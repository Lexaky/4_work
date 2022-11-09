#include <iostream>

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
