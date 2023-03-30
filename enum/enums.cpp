#include <iostream>
#include <filesystem>
#include <stack>
#include <string>
namespace enumns {
    namespace v1{
        enum geometry: char { circle, square, triangle };
    }

     inline namespace v2{
        enum geometry: uint16_t { circle, square, triangle };
    }
}

int main () {
    enumns::v1::geometry g1 = enumns::v1::geometry::circle;
    enumns::v2::geometry g2 = enumns::v2::circle;
        std::filesystem::path p("../");
        std::string sss = p;
    std::cout << p << std::endl;
    std::stack<std::filesystem::path> s;
    s.push(std::filesystem::canonical(p));
    while(!s.empty()){
        auto p = s.top();
        s.pop();
        for(auto& it: std::filesystem::directory_iterator(p)){
            if(it.is_directory())
                s.push(it.path());
            else
                std::cout << it.path() << std::endl;
        }
    }
}