#include <iostream>
#include <string>
#include <map>

#include <stdlib.h>

std::string fizzbuzz(std::map<int, std::string> fizzmap, int x) {
  std::string output = "";

  for(std::map<int, std::string>::const_iterator i = fizzmap.begin(); i != fizzmap.end(); ++i) {
    if(!(x % i->first)) output += i->second; // If x is a multiple of the key, append the value to output
  }

  if (output=="")
    return std::to_string(x);

  return output;
}

int main()
{
  char choice;
  std::map<int, std::string> fizzmap; 

  std::cout << "Welcome to fizzbuzz. Leave the input blank if you don't want to replace a particular number." << std::endl;
  std::cout << "I haven't checked the input for any Bobby Tables shenanigans, so have fun with that." << std::endl;
  std::cout << ("Would you like to run the default version of fizzbuzz? (y/n)") << std::endl;

  std::cin >> choice;

  if (choice == 'y' || choice == 'Y') {
    fizzmap.insert(std::pair<int, std::string>(3, "fizz"));
    fizzmap.insert(std::pair<int, std::string>(5, "buzz"));
  }
  else if (choice == 'n' || choice == 'N') {
    for(int i = 1; i <= 10; i++) {

      std::string word;

      std::cout << "What would you like me to say for multiples of ";
      std::cout << i;
      std::cout << "? (use 0 key for no substitution)" << std::endl;

      std::cin >> word;

      if (word != "0")
        fizzmap.insert(std::pair<int, std::string>(i, word));
    }
  }
  else {
    std::cout << "Please answer either \'y\' or \'n\'" << std::endl;
    abort();
  }

  for(int i = 1; i <= 100; i++)
    std::cout << fizzbuzz(fizzmap, i) << std::endl;
}
