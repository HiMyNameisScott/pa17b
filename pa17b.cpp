#include "ForwardList.hpp"
#include <iostream>


static std::ostream& operator<<(std::ostream& output, const ForwardList<char>& info);
using namespace std;



int main(){
    char ch;
    bool add_to_end = false;
    bool add_to_front = false;
    bool add_current = false;
    ForwardList<char> info;
    
    while (cin >> ch && !cin.eof())
    {
        if(ch == '['){
            add_to_front = true;
            add_to_end = false;
        } else if (ch == ']') {
            add_to_end = true;
            add_to_front = false;    
        }

        if (add_to_end == true){
            info.insert(info.begin(), ch);
        } else if(add_to_front == true) {
            info.insert(info.end(), ch);
        } else {
            info.insert(info.begin(), ch);
        }
    }

    cout << info;

    
return 0;
}

static std::ostream& operator<<(std::ostream& output, const ForwardList<char>& info){
    for (auto it = info.begin() ; it != info.end(); ++it){
        output << it->info;
    };

    return output;
};