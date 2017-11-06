#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
//        if (/*date is inorrect */) {
//            throw runtime_error();
//        }
    }

    int GetDay() const {
        return day;
    }

    int GetMonth() const {
        return month;
    }

    int GetYear() const {
        return year;
    }

    int DaysBetween(const Date& d2) const {
        return 0;
    }
};

struct Point {
    int x, y;
};

bool operator == (const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator < (const Point& p1, const Point& p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

double dastance(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y);
    }

template <typename T>
void swap_(T& a, T& b) {
    T c = move(a);
    a = move(b);
    b = move(c);
}


pair<size_t, size_t> foo() {
    return {0, 0};
}

int main() {
    //pairs
    pair <int, string> p{42, "hello"};
    cout << p.first << endl;
    cout << p.second << endl;

    //tuples
    tuple<int, double, string> t{0, 3.14, "hello"};
    cout << get<1>(t) << endl;

    //struct Point
    Point a{1, 2};
    a.x = 0;
    cout << a.x << a.y << "\n";

    vector<Point> points = {
        {1, 2},
        {9, -1}
    };
    points.push_back(Point{3, 2});

    sort(
        points.rbegin(), // rbegin => reversed sort
        points.rend()
//        [](const auto& p1, const auto& p2) {
//            return tie(p1.x, p1.y) > tie(p2.x, p2.y);
//        }
//        + optional argument - name of comparison function
    );

    for (const auto& p : points) {
        cout << p.x << " " << p.y << "\n";
    }

    //class Date
    //int d, m, y;
    //cin >> d >> m >> y;
    //Date d1(d, m, y);
    Date d2(7, 11, 2017);
    //cout << d1.GetYear() << "\n";

    //maps
    map<string, int> freqs;
    string word;
    while (cin >> word) {
        ++freqs[word];
    }
    for (const auto& pair : freqs) {
        cout << pair.first << "\t" << pair.second << "\n";
    }

    using T = pair<string, int>;
    vector<T> v(
                freqs, begin(),
                freqs.end()
    );

    sort(
         v.begin(),
         v.end(),
         [](const auto& p1, const auto =& p2) {
         return tie(p1.second, p1.first) > (p2.second, p2.first);
         }
    );

    for (const auto& pair : v) {
        cout << pair.first << " " << pair.second << "\n";
    }

}

