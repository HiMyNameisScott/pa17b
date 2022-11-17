 /// @file pa17b.cpp
 /// @author Scott T. Koss
 /// @date 11/15/2022
 /// @note I pledge my word of honor that I have complied with the
 /// CSN Academic Integrity Policy while completing this assignment.
 /// @brief sorts characters based on whether they need to go to front/end/current
 /// @note 6-8 hours

#include "ForwardList.hpp"
#include <iostream>



int main(){
    using namespace std;
    
    auto text = string {};                 // holds char to check
    text.reserve(100000);
    
    while (getline(cin, text)){
        auto list = ForwardList<char>{};  // holds characters as they appear
        auto ip = list.begin();           // insertion point!
    
        for (char ch : text) {
            switch (ch) {
                case '[' : ip = list.begin();   break;
                case ']' : ip = list.end();     break;
                default:   list.insert(ip, ch); break;
            }
        }

    
return 0;
}

