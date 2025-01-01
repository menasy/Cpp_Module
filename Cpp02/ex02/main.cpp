/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;


	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "====== Values ===="<<std::endl;
	std::cout<<"a: ";
	std::cout<<a<<std::endl;
	std::cout<<"b: ";
	std::cout<<b<<std::endl;
	std::cout<<"c: ";
	std::cout<<c<<std::endl;
	
	std::cout << "====== Comparison operators ===="<<std::endl;
	std::cout<<"< :"<< (b < c) <<std::endl;
	std::cout<<"> :"<< (b > c) <<std::endl;
	std::cout<<"<= :"<< (b <= c) <<std::endl;
	std::cout<<">= :"<< (b >= c) <<std::endl;
	std::cout<<"== :"<< (b == c) <<std::endl;
	std::cout<<"!= :"<< (b != c) <<std::endl;
	
	std::cout << "====== Max-Min ===="<<std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;
	std::cout << Fixed::max( b, c ) << std::endl;
	
	std::cout << "====== Basic operators ===="<<std::endl;
	std::cout<<"+ :"<< (b + c) <<std::endl;
	std::cout<<"- :"<< (b - c) <<std::endl;
	std::cout<<"/ :"<< (b / c) <<std::endl;
	std::cout<<"* :"<< (b * c) <<std::endl;
	
	
	std::cout << "====== Increment (++) and Decrement(--) ===="<<std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;

	return 0;
}
