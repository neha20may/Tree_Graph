//
// Created by neha2 on 08-01-2022.
//

#ifndef COURSERA_PART2_SIMPLE_STRING_H
#define COURSERA_PART2_SIMPLE_STRING_H

#include <cstring>
#include <unistd.h>

class simple_string{
private:
    size_t len;
    char * s;
    char * make_new(const char *s);
public:
    simple_string(const char *a);
    char * getString();
};
using namespace std;
int main(){
    while(true) {
        simple_string s("you can do it");
        char *n = s.getString();
        std::cout << n;
        cout<<endl;
        sleep(0.2);
    }
}
#endif //COURSERA_PART2_SIMPLE_STRING_H
