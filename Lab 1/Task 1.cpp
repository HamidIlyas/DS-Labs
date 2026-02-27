#include <iostream>
using namespace std;

class Course
{
public:
    virtual void duration() = 0;
};

class OnlineCourse : public Course
{
    int weeks, hpw;
public:
    OnlineCourse(int w, int h)
    {
        weeks = w;
        hpw = h;
    }

    void duration()
    {
        int total = weeks * hpw;
        cout << "Online Course: " << total << endl;
    }
};

class OfflineCourse : public Course
{
    int months, hpd;
public:
    OfflineCourse(int m, int h)
    {
        months = m;
        hpd = h;
    }

    void duration()
    {
        int total = months * 30 * hpd;
        cout << "Offline Course: " << total << endl;
    }
};

int main()
{
    OnlineCourse c1(2, 3);
    OfflineCourse c2(4, 5);
    c1.duration();
    c2.duration();


    return 0;
}
