#include <iostream>

/*
���������� ���� ��������� ������, ������� ������ ����� + ��� ���-������ (����� + ��������?)
����� ���������� ����������� ��� ���������� ��������� �������� ( + ����� ��������� "���", * ��������� "�" � ��)
� ����� � ��������� �������� ����������������� ����� printf ��� ���� ��������� :)
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
{ return Point(p1.getX() | p2.getX(), p1.getY() | p2.getY(), p1.getName()); } //�������� ���������� ���������� p1, p2; ��� ������� ���������

Point operator * (Point p1, Point p2)
{ return Point(p1.getX() & p2.getX(), p1.getY() & p2.getY(), p1.getName()); } //�������� �������� ���������� p1, p2; ��� ������� ���������

Point operator ! (Point p1)
{ return Point(~p1.getX(), ~p1.getY(), p1.getName()); } // ��������� ��������

/*
p1: name; coordinates (x1, y1)
p2: name; coordiantes (x2, y2);
*/

Point operator < (Point p1, Point p2)
//����������� ����� ����� ���������� x1 �� x2 ��� �����, ���������� y1 �� y2 ��� �����
{ return Point(p1.getX() << p2.getX(), p1.getY() << p2.getY(), p1.getName()); }

Point operator > (Point p1, Point p2)
//����������� ����� ����� ���������� x1 �� x2 ��� ������, ���������� y1 �� y2 ��� ������
{ return Point(p1.getX() >> p2.getX(), p1.getY() >> p2.getY(), p1.getName()); }

Point operator ^ (Point p1, Point p2)
//����������� ��� ��������� x1 � x2; y1 � y2
{ return Point(p1.getX() ^ p2.getX(), p1.getY() ^ p2.getY(), p1.getName()); }

using namespace std;

void printPoint(Point p)
{ //����� ������ � ����� p: �������� �����, ����������
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

    cout << "��������� �: ";
    newP3 = *newP1 * *newP2;
    newP3.setName('C');
    printPoint(newP3);
    cout << "��������� ��������: ";
    newP3 = !newP3;
    newP3.setName('C');
    printPoint(newP3);

    cout << "��������� ���: ";
    newP3 = *newP1 + *newP2;
    newP3.setName('C');
    printPoint(newP3);

    cout << "��������� ����� �����: ";
    newP3 = *newP1 < *newP2;
    newP3.setName('C');
    printPoint(newP3);

    cout << "��������� ����� ������: ";
    newP3 = *newP1 > *newP2;
    newP3.setName('C');
    printPoint(newP3);

    cout << "��������� ����������� ���: ";
    newP3 = *newP1 ^ *newP2;
    newP3.setName('C');
    printPoint(newP3);

    ///////////////////////////////////////////////////////////
    cout << "\n\n������ ���������������� ������: " << endl;
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
