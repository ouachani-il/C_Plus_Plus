#include <cctype>
#include <ios>
#include <iostream>
#include <cstring>
#include <string>

int main(int ac, const char** av)
{
	if (ac == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	}
	else{
		for (int i = 1; i < ac; i++)
		{
			std::string s = av[i];

			for (size_t j = 0; j < s.length(); j++)
				s[j] = std::toupper(s[j]);

			std::cout << s;
		}
		std::cout<<std::endl;
	}

}