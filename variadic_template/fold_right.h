#ifndef FOLD_RIGHT_H
#define FOLD_RIGHT_H

template<template<class, int> class, int, class...> struct
fold_right;

template<template<class, int> class f, int init> struct
fold_right<f, init> {
    static const int value = init;
};

template<template<class, int> class f, int init, class head, class...tail> struct
fold_right<f, init, head, tail...> {
    static const int value = f<head, fold_right<f, init, tail...>::value>::value;
};

#endif // FOLD_RIGHT_H
