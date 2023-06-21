#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <tuple>
#include <vector>
//uzycie algorytmu std::copy()


namespace std {
    std::ostream& operator<<(std::ostream& os, const std::pair<int, std::string>& p){
        return os << '(' << p.first << ',' << p.second << ')';
    }    
}

int main() {
    std::vector<std::pair<int, std::string>> v{
        {1, "jeden"}, {2, "dwa"}, {3, "trzy"},
        {4, "cztery"}, {5, "pięć"}
    };
    std::map<int, std::string>m;

    std::copy_n(begin(v), 3, std::inserter(m, begin(m)));
    auto shell_it(std::ostream_iterator<std::pair<int, std::string>>{std::cout, ", "});
    std::cout << "Mapa z skopiowanymi 3 elementami\n";
    std::copy(begin(m), end(m), shell_it);
    std::cout << '\n';
    
    std::cout << "Czyszczenie mapy\n";
    m.clear();

    std::cout << "Zawartosc mapy po operacji move\n";
    std::move(begin(v), end(v), std::inserter(m, begin(m)));
    std::copy(begin(m), end(m), shell_it);
    
    std::cout << "\nZawartos vectora po move\n";
    std::copy(begin(v), end(v), shell_it);
    std::cout << '\n';
    
    return 0;
}