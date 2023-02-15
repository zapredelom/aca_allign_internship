#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <cmath>

bool isPrime(uint64_t n) {
  if (n == 1) return false;
  if (n == 2) return true;

  for (uint64_t i = 2; i <= std::sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
std::mutex m;
void primes_in_range(uint64_t begin, uint64_t end,
                     std::vector<uint64_t>& prms) {
  while (begin < end) {
    if (isPrime(begin)) {
      std::scoped_lock sl(m);
      prms.push_back(begin);
    }
    begin++;
  }
}

std::vector<uint64_t> primes(uint64_t end) {
  std::vector<uint64_t> p1;
  auto thread_count = end / 1000;
  std::vector<std::thread> tds;
  for (uint64_t i = 0; i < thread_count; i++) {
    tds.emplace_back(
        [&p1, i]() { primes_in_range(i * 1000, (i + 1) * 1000, p1); });
  }
  for (auto& t : tds) {
    t.join();
  }
  return p1;
}