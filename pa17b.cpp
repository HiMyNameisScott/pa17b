#include "ForwardList.hpp"


using namespace std;


int main(){
    ForwardList<int> test {10, 20, 30, 40, 50};

    cout << test.size() << endl;

return 0;
}