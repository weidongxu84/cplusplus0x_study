#include "foldr.h"

#include <iostream>

template<int i> struct
integer
{
    static const int value = i;
};

template<class t, int i> struct
accumulate
{
    static const int value = t::value + i;
};

template<int init, class...list> struct
sum
{
    static const int value = foldr<accumulate, init, list...>::value;
};

using namespace std;

int main()
{
    cout << sum<0, integer<1>, integer<2>, integer<3>, integer<4>, integer<5> >::value << endl;

    return 0;
}

