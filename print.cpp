#include <iostream>
#include <vector>

template <typename T>
concept Printable = ! std::is_same<T, std::string>::value &&
					! std::is_same<T, std::wstring>::value &&
					requires (T ob) {
  						{ob.cbegin()} -> std::same_as<typename T::const_iterator>;
 						{ob.cend()} -> std::same_as<typename T::const_iterator>;
					};

template <Printable T>
std::ostream& operator<< (std::ostream& out, const T& ob)
{
  	out << "{ ";
	for (auto it = ob.begin(); it != ob.end(); ++it) {
    	out << *it << " ";
    }
    out << "}";
  	return out;
}

template <typename... Ts> 
void print(Ts ...args) {
	((std::cout << args << " " << std::endl), ... );
}

int main()
{
  std::vector<int> vec(5, 15);
  std::string str = "Hello";
  print(vec, str, 15, 3.68);
  
} 