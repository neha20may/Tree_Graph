//
// Created by neha2 on 08-01-2022.
//

#include <string>
#include <iostream>
#include "simple_string.h"

char *simple_string::getString() {
    return s;
}

simple_string::simple_string(const char *a) : len(0), s(make_new(a)) {
}

char *simple_string::make_new(const char *s) {
    std::string s1(s);
//    std::cout << s1.size() << std::endl;
    len = strlen(s);
//    std::cout << len << std::endl;
    char *p = new char[len + 1];
    char *q = strcpy(p, s);
//    return (strcpy(new char[len + 1], s));
    return q;//The object created by new doesnt get deallocated after scope. or it doesnt get deallocated untill delete is called.
    //Basically, you should only use heap allocation if you want an object to live beyond the lifetime of the scope you create it in.
    //If you want an object to live in a scope only, don’t use heap allocation at all but simply define a variable:
//    {
//        ClassName x;
//        // use x
//    }
}