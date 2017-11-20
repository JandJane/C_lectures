#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

namespace mystd {
    template <typename Iter, typename Value>
    Iter find(Iter first, Iter last, const Value& value) {
        for (auto it = first; it != last; ++it) {
            if (*it == value)
                return it;
        }
        return last;
    }
}


int main() {
    std::vector<int> v = {3, 14, 15, 92, 6};

    auto it = mystd::find(v.begin(), v.end(), 15);  // our own realization of find method - linear search

    if (it == v.end()) {
        std::cout << "Not found\n";
    } else {
        std::cout << "Found at " << (it - v.begin()) << "\n";
    }

    auto it2 = std::find_if(v.begin(), v.end(),
                           [](int x) {
                               return x % 3 == 0;
                            }
    );
    if (it2 == v.end()) {
        std::cout << "Not found\n";
    } else {
        std::cout << "Found: " << *it2 << "\n";
    }

    // copy algorithm
    std::list<int> l = {3, 14, 15, 92, 6};
    std::vector<int> d(l.size());

    std::copy(l.begin(), l.end(), d.begin());

    for (auto x : d)
        std::cout << x << " ";
    std::cout << "\n";

    // transform
    std::transform(d.begin(), d.begin() + 3,
                   std::ostream_iterator<int>(std::cout, " "),
                   [](int x) {
                       return x * x;
                    }
    );
    std::cout << "\n";

    // remove
    auto iter = std::remove_if(v.begin(), v.end(),
                   [](int x) {
                       return x % 2 == 0;
                    }
    );

    v.erase(iter, v.end());

    for (int x : v) {
        std::cout << x <<  " ";
    }
    std::cout << "\n";

    std::cout << iter - v.begin();

}
