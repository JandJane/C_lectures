#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>  // unordered map
#include <deque>  // double-ended queue - like two vectors growing in opposite directions
#include <list>  // doubly-linked list. You can't get an element by its index is not supported (but you can iterate)
#include <stack>  // LIFO - last in - first out
#include <queue>  // FIFO - first in - first out


int main () {
    std::unordered_map<char, int> freqs;
    std::string s;
    std::getline(std::cin, s);

    for (char c : s)
        ++freqs[c];

    auto it = freqs.find('a');
    if (it == freqs.end())
        std::cout << "'a' is not found\n";
    else
        std::cout << (*it).first << " " << it->second << "\n";  // it is recommended to do it in "->" way

    std::vector<std::pair<char, int>> v(
        freqs.begin(), freqs.end()
    );

    std::sort(
        v.begin(),
        v.end(),
        [](const auto& a, const auto&  b) {
              return a.second > b.second ||
              a.second == b.second &&
              a.first > b.second;
        }
    );

    for (const auto& item : v) {
        std::cout << item.first << " " << item.second << "\n";
    }
    std::string s;
    getline(std::cin, s);

    std::set<char> symbols(s.begin(), s.end());

    auto it = symbols.find('a');
    if (it == symbols.end())
        std::cout << "'a' is not found\n";
    else
        std::cout << "found!\n";

    for (char c : symbols)
        std::cout << c;
    std::cout << "\n";

auto it = symbols.lower_bound('a');  // will find first symbol >= a
    if (it == symbols.end())
        std::cout << "'a' is not found\n";
    else
        std::cout << it->first;

    std::deque<int> d = {1, 2, 3, 4};

    d.push_back(11);
    d.push_front(-1);

    for (int x : d)  // you can print all the elements this way
        std::cout << x << " ";
    std::cout << "\n";

    for (size_t i = 0; i != d.size(); ++i)  // or this way
        std::cout << d[i] << " ";
    std::cout << "\n";

    std::stack<int> s;

    s.push(3);
    s.push(14);
    s.push(15);

    std::cout << s.top() << "\n";  //  "front" instead of "top" in queues

    s.pop();
    s.pop();

    std::cout << s.top() << "\n";

    std::priority_queue<int> pq;

    pq.push(15);
    pq.push(12);
    pq.push(3);

    std::cout << pq.top();  // extracts the biggest number
}
