#include "ForwardList.hpp"
#include <iostream>


static std::ostream& operator<<(std::ostream& output, const ForwardList<char>& info);
using namespace std;



int main(){
    char ch;
    bool add_to_end = false;                                // check to add front
    bool add_to_front = false;                              // check to add back
                              
    ForwardList<char> info;                                 // holds char to check
    
    while (cin >> ch && !cin.eof())
    {
        if(ch == '['){                                      // inserts front/back depending on ch
            add_to_front = true;
            add_to_end = false;

        } else if (ch == ']') {
            add_to_end = true;
            add_to_front = false;    
        }

        if (add_to_end == true && ch != ']'){               // inserts front/back depending on ch 
            info.insert(info.begin(), ch);
        } else if(add_to_front == true && ch != '[') {
            info.insert(info.end(), ch);
        } else if (ch != '[' && ch != ']') {
            info.insert(info.begin(), ch);
        }
    }

    cout << info;                                           // displays info

    
return 0;
}


/// @brief This will output the list to a specified output type
/// @param output used for declaring which output to display to 
/// @param info  is the list we are processing
/// @return output so that we have processed.
static std::ostream& operator<<(std::ostream& output, const ForwardList<char>& info){
    for (auto it = info.begin() ; it != info.end(); ++it){
        output << it->info;
    };

    return output;
};