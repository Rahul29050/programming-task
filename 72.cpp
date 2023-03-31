#include <iostream>
#include <vector>

int main()
{
  unsigned int limit = 1000000;
  std::vector<unsigned int> phi(limit + 1); 
  for (size_t i = 0; i < phi.size(); i++)
    phi[i] = i;

  for (unsigned int i = 2; i <= limit; i++)
  {
    if (phi[i] == i)
      for (unsigned int k = 1; k * i <= limit; k++)
        phi[k * i] -= phi[k * i] / i;
  }


  std::vector<unsigned long long> sums(phi.size(), 0);
  for (unsigned int i = 2; i <= limit; i++)
    sums[i] = sums[i - 1] + phi[i];

  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    std::cin >> limit;
    std::cout << sums[limit] << std::endl;
  }
}
