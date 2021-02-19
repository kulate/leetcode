#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

template <typename T, typename InputIterator, typename OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<T> elements;
    for (; first != last; first++)
        elements.push_back(*first);
    sort(elements.begin(), elements.end());
    copy(elements.begin(), elements.end(), result);
}

void test_iter()
{
    // vector示例第一类容器（list作为中间容器示例第二类容器）
    vector<string> vec_str;
    vec_str.push_back("hello");
    vec_str.push_back("hi");
    vec_str.push_back("world");
    list<string> list_str;
    list_str.resize(vec_str.size()); // resize必须，否则copy越界
    copy(vec_str.begin(), vec_str.end(), list_str.begin());
    for (auto it1 = list_str.begin(); it1 != list_str.end(); it1++)
    {
        if (it1->size() == 5)
            list_str.insert(it1, "test"); //直接插入，迭代器不会失效
    }
    vec_str.resize(list_str.size()); // resize必须，list_str大小已变，否则copy越界
    copy(list_str.begin(), list_str.end(), vec_str.begin());
    for (auto e : vec_str)
    {
        cout << e << endl;
    }
}

class Point
{
public:
    Point() : x(0), y(0) { cout << "默认构造函数调用" << endl; }

    Point(int x, int y) : x(x), y(y) { cout << "带参构造函数调用" << endl; }

    ~Point() { cout << "析构函数调用!" << endl; }

    int getx() const { return x; }

    int gety() const { return y; }

    void move(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

private:
    int x;
    int y;
};

class PointArr
{
public:
    PointArr() : size(0)
    {
        cout << "PointArr默认构造函数" << endl;
    }
    PointArr(int size) : size(size)
    {
        element = new Point[size];
        cout << "PointArr带参构造函数" << endl;
    }
    ~PointArr()
    {
        delete[] element;
        cout << "PointArr析构函数" << endl;
    }
    PointArr(const PointArr &pa) : size(pa.size)
    {
        element = new Point[size];
        for (int i = 0; i < size; i++)
        {
            element[i] = pa.element[i];
        }
        cout << "PointArr复制构造函数" << endl;
    }

    PointArr(PointArr &&pa) : size(pa.size), element(pa.element)
    {
        pa.element = nullptr;
        cout << "PointArr移动构造函数" << endl;
    }

    Point &at(int n)
    {
        return element[n];
    }

private:
    int size;
    Point *element;
};

PointArr build(int n);

int main()
{
    char str[] = "Hello world";
    char str2[] = "Hello world";
    str[1] = 'a';
    str2[1] = 'b';
    cout << str << endl;
    cout << str2 << endl;
    return 0;
}

PointArr build(int n)
{
    PointArr pa(n);
    pa.at(0).move(1, 1);
    return pa;
}