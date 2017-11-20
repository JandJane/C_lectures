#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main() {
    vector<int> v = {3, 1, 1, 4 , 2, 2, 4, 5, 6};
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    //set<int> s(v.begin(), v.end());
    //v.assign(s.begin(), s.end());

    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // checking if the string is palindrome
    string s = "hellolleh";
    cout << equal(s.begin(), s.end(), s.rbegin());


    string s1 = "aba";
    sort(s1.begin(), s1.end());
    do {
        cout << s1 << '\n';
    } while(next_permutation(s1.begin(), s1.end()));

    vector<int> v1 = {2, 3, 5, 7, 11, 13};
    vector<int> v2 = {1, 3, 5, 7, 9};
    vector<int> v3(min(v1.size(), v2.size()));
    vector<int> v4;

    // 3 ways to write down intersection of two arrays
    set_intersection(
                     v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     ostream_iterator<int>(cout, " ")
    );

    auto it1 = set_intersection(
                     v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     v3.begin()
    );
    v3.erase(it1, v3.end());
    for (int x : v3)
        cout << x << " ";
    cout << "\n";

    set_intersection(
                     v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     back_inserter(v4)
    );
    for (int x : v4)
        cout << x << " ";
    cout << "\n";

    int p = 1 << 10; // 1^10
    cout << p;
}
