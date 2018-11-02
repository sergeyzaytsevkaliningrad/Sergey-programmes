#ifndef RING_HPP
#define RING_HPP
#include<iostream>
#include<cassert>
#include<cstdint>
namespace Ring {

    class ring{
        private:
            std::uint32_t n;
            std::uint32_t value; //n>value and  (value>0 no always) ,n>0  ,n =[2,2^31) ;
        public:


           explicit ring(std::uint32_t init_n, std::int64_t init_v=0);

            bool operator==(const ring& b)const;
            bool operator!=(const ring& b)const;




            //unary operation;
            ring operator+()const {return *this;}
            ring operator-()const {return ring{n,(n-value)};}

            //binary operation;
            ring operator+(const ring& b)const;
            ring operator -(const ring& b)const;
             ring operator *(const ring& b)const;

            //finding reverse element;
            ring inverse() const;

            //output value;
            friend std::ostream& operator<<(std::ostream& out_line, const ring& r);


             //converse bool and uint32_t
            explicit operator bool() const { return  (value);}
            explicit operator std::uint32_t()const {return(value);}


   };
}
#endif // RING_HPP
