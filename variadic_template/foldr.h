#ifndef FOLD_RIGHT_H
#define FOLD_RIGHT_H

template<template<class, int> class, int, class...> struct
foldr;

template<template<class, int> class f, int init> struct
foldr<f, init> {
    static const int value = init;
};

template<template<class, int> class f, int init, class head, class...tail> struct
foldr<f, init, head, tail...> {
    static const int value = f<head, foldr<f, init, tail...>::value>::value;
};

#endif // FOLD_RIGHT_H
