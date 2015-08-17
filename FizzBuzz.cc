#include <iostream>
#include <string>
#include <sstream>

std::string fizz(int n) {
	return n%3 == 0 ? "Fizz":"";
}

std::string buzz(int n) {
	return n%5 == 0 ? "Buzz":"";
}

std::string fizz_buzz_(int n) {
  std::string ret = fizz(n)+buzz(n);
  if (ret.empty()){
	std::stringstream ss ;
	ss<<n;
	ret = ss.str();
  }
  return ret;
}


int main () {

	for(int i = 0 ; i < 100 ; i++ ) {
		std::cout << fizz_buzz(i) << std::endl;
	}
return 0;
}


