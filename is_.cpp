#include <iostream>

template <typename T, T val>
struct integral_constant {
	using type = T;
	static constexpr int value = val; 
    operator T () {return value;}
	T operator () () {return value;}
};

template <bool val>
using bool_constant = integral_constant<bool, val>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template <typename T>
struct is_integral : bool_constant<
                                    requires (T ob, T* ptr, void f(T))
                                    {
                                        ptr + ob; 
                                        f(0); 
                                        //reinterpret_cast<char*>(ptr);  
                                    }>
{
};

template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};


int main()
{
    enum b {NUM};
    class A {
    public:
        A(int var) : mem(var) {}
    private:
        int mem;
    };

    std::cout << is_integral<int>::value << std::endl;    
    std::cout << is_integral<float>::value << std::endl; 
    std::cout << is_integral<char>::value << std::endl; 
    std::cout << is_integral<short>::value << std::endl; 
    std::cout << is_integral<unsigned>::value << std::endl; 
    std::cout << is_integral<long long>::value << std::endl; 
    std::cout << is_integral<double>::value << std::endl; 
    std::cout << is_integral<b>::value << std::endl;  
    std::cout << is_integral<A>::value << std::endl; 


    std::cout << is_same<int, int>::value << std::endl;
    std::cout << is_same<int, double>::value << std::endl;
    std::cout << is_same<int, const int>::value << std::endl;
    std::cout << is_same<int, long>::value << std::endl;
  return 0;
}