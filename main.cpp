//
//  koltso.cpp
//  ДЗ для проги 2
//
//  Created by Sergey on 15.01.2018.
//  Copyright © 2018 Sergey. All rights reserved

#include"koltso.hpp"
#include<cassert>
#include<iostream>
int main(){
     Ring::ring tss(5,3);
     assert(tss!=Ring::ring(5,2));
     assert(tss!=Ring::ring(6,3));
    Ring::ring pull(10,5);
    //convers by bool
    bool tr=static_cast<bool>(pull);
    Ring::ring p(10,0);
    assert(pull);
    assert(Ring::ring(10,5)!=Ring::ring(10,4));


   //assert(pull == Ring::ring(10,1));
    assert(tr  == 1);
    //convers by uint32_t;
    std::uint32_t sos = static_cast<std::uint32_t>(pull);
    assert(sos == 5);


   // conditional::initialization value==0
    assert( Ring::ring(3) == Ring::ring (3, 0));



   //control always n>value and n<2^31=2147483648;
    assert( Ring::ring(0x7FFFFFFF, 0x80000000) == Ring::ring (0x7FFFFFFF, 1));

    assert( Ring::ring (0x7FFFFFFF,  0x80000002) == Ring::ring (0x7FFFFFFF, 3));




    // control unary operation;

    Ring::ring a(5, 3);
    Ring::ring b(5, 2);
    //control unary operation:preservation of a sign;
    assert(+a == Ring::ring(5, 3));

    //control unary operation:changing of a sign;
    assert(-a == Ring::ring(5, 2));


    //control binary operation;
    Ring::ring a1(10, 3);
    Ring::ring b1(10, 2);

    Ring::ring c1(10,8);

   Ring::ring  r = Ring::ring(0x7FFFFFFF, 0x7FFFFFFE);

   Ring::ring l = Ring::ring(0x7FFFFFFF, 0x7FFFFFFD );


    //control binary operation:addition;


    assert( a1 + b1 == Ring::ring (10, 5));

    assert( a1 + c1 == Ring::ring(10, 1));

    assert( l + r == Ring::ring (0x7FFFFFFF, 0x7FFFFFFC));


    //control binary operation:multiplicate;
    r = Ring::ring(0x7FFFFFFF, 0x7FFFFFFE );

    l = Ring::ring(0x7FFFFFFF, 2 );

    assert(l * r == Ring::ring(0x7FFFFFFF, 0x7FFFFFFD));

    l = Ring::ring(0x7FFFFFFF, 0x7FFFFFFE );
    assert( a1 * b1 == Ring::ring (10, 6));
    assert( a1 * c1 == Ring::ring (10, 4));


    assert(l * r == Ring::ring(0x7FFFFFFF, 4));

    r = Ring::ring(10, 3 );
    l = Ring::ring(10);
    assert(r + l == Ring::ring(10, 3));

    //substraction;
    r = Ring::ring(5, 3);
    l = Ring::ring(5, 2);
    assert(r - l == Ring::ring(5, 1));
    r = Ring::ring(8, 3);
    l = Ring::ring(8, 6);

    assert(r-l == Ring::ring(8, 5));
    r = Ring::ring(0x7FFFFFFF, 0x1E16C);
    l = Ring::ring(0x7FFFFFFF, 0x1E16C);
    assert( r- l == Ring::ring(0x7FFFFFFF, 0) );
    r = Ring::ring(10, 3 );
    l = Ring::ring(10);
    assert(r - l == Ring::ring(10,  3));
    l = Ring::ring(0x7FFFFFFF, 5);
    r = Ring::ring(0x7FFFFFFF, 6);
    assert( l - r == Ring::ring(0x7FFFFFFF, 0x7FFFFFFE) );



    //control invers();
    l = Ring::ring(20, 13);


    assert(l.inverse() == Ring::ring(20,17));

    l = Ring::ring(9, 2);
    assert(l.inverse() == Ring::ring(9,5));
    l = Ring::ring(3,0);
    //std::cout<<l.inverse();
    assert(l.inverse() ==Ring::ring(3, 0));
    l = Ring::ring(26,3);
    assert(l.inverse() == Ring::ring(26,9));


    //output;
       Ring::ring out(10, 5);
         std::cout << out;







return 0;
}
