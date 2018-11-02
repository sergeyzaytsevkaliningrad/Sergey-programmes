//
//  koltso.cpp
//  ДЗ для проги 2
//
//  Created by Sergey on 15.01.2018.
//  Copyright © 2018 Sergey. All rights reserved

#include "koltso.hpp"
namespace Ring {
    static inline std::int32_t minus( std::uint32_t a,std::int32_t b,std::int32_t b1){

            return (a-(b1-b));
    }
    static inline std::int32_t recovery( std::uint32_t a,std::int64_t b){
         return (a-((b*(-1))%a));
    }


       ring::ring(std::uint32_t init_n, std::int64_t init_v): n(init_n),value(init_v%n){
        assert(n > 1);
         assert(n < 0x80000000);
       }
    bool ring::operator==( const ring& b)const{

         return ((n == b.n) && (value == b.value));
    }
    bool ring::operator!=( const ring& b)const{

         return !((b.n == n) && (value == b.value));
    }


    //binary operation;
    ring ring::operator +( const ring& b) const{
         assert(n == b.n);


        return  ring{n,value  +  b.value};
    }
    ring ring:: operator -( const ring& b)const{
         assert(n == b.n);
         if(b.value>value){


             return ring{n,minus(n,value,b.value)};
           }
        return ring{n,value -b.value};
   }
    ring ring::operator *(const ring& b) const{
      assert(n == b.n);


      return ring{n,(value)*(b.value)} ;
  }


    static std::uint32_t extended_gcd( std::uint32_t a, std::uint32_t b, std::int64_t &u, std::int64_t &v){ //extended algorithm Evklida;
         std::int64_t q, r, u1, u2, v1, v2, d;
         if (b == 0) {

            d = a;
            u = 1;
            v = 0;

            return d;

           }

         u2 = 1;
         u1 = 0;
         v2 = 0;
         v1 = 1;
         while (b > 0) {
            q = a / b;
            r = a - q * b;
            u = u2 - q * u1;
            v = v2 - q * v1;
            a = b;
            b = r;
            u2 = u1;
            u1 = u;
            v2 = v1;
            v1 = v;
        }
          d = a;
          u = u2;
          v = v2;
          return d;
    }

    ring  ring::inverse() const {  //finding reverse element;
        std::int64_t invers, v, nod;

        nod = extended_gcd(n, value, v, invers);
        if(nod == 1){
            if(invers<0)
                return ring{n,recovery(n,invers)};


            return ring{n, invers};

        }
        return ring {n, 0};
    }

    std::ostream& operator<<(std::ostream& out_line, const ring& r) {   //output;
        return out_line << r.value ;
    }



}
