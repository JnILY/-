#pragma once
#ifndef NODEFAULT_H
#define NODEFAULT_H
struct NoDefault {
    NoDefault(int i){}
    NoDefault() = default;
};  
struct C {
    C() = default;
    NoDefault n;
};
#endif