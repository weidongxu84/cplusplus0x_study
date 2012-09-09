#ifndef FOLD_RIGHT_H
#define FOLD_RIGHT_H

template<template<class, int> class, int, class...> struct
foldl;

template<template<class, int> class f, int init> struct
foldl<f, init> {
    static const int value = init;
};

template<template<class, int> class f, int init, class head, class...tail> struct
foldl<f, init, head, tail...> {
    static const int value = f<head, foldl<f, init, tail...>::value>::value;
};

#endif // FOLD_RIGHT_H
