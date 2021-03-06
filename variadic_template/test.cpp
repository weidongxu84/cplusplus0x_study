#include "foldl.h"

#include <iostream>

template<class t, int i> struct
accumulate
{
    static const int value = t::value + i;
};

template<int init, class...list> struct
sum
{
    static const int value = foldl<accumulate, init, list...>::value;
};

template<int i> struct
integer
{
    static const int value = i;
};


using namespace std;

int main()
{
    cout << sum<0, integer<1>, integer<2>, integer<3>, integer<4>, integer<5> >::value << endl;

    return 0;
}

