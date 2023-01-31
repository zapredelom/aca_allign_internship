
#include <vector>
#include <unordered_map>
int Cut(const std::vector<int>& prices, int len){
  if(len == 0) return 0;
  int ret = -1;
  for(int i = 0; i < len; i++ ){
   int current = Cut(prices, len - i - 1) + prices[i];
   if(current > ret) ret = current;
  }
  return ret;
}

int Cut(const std::vector<int>& prices, int len, std::unordered_map<int, int>& m){
  if(len == 0) return 0;
  if(m.contains(len) ) return m[len];
  int ret = -1;
  for(int i = 0; i < len; i++ ){
   int current = Cut(prices, len - i - 1, m) + prices[i];
   if(current > ret) ret = current;
  }
  m[len] = ret;
  return ret;

}

int Cut_buttom_up(const std::vector<int>& prices, int len) {
  std::vector<int> results(prices.size() + 1, -1);
  results[0] = 0;
  for(int i =0; i<len; i++){
    results[i+1] = prices[i];
  }
  for(int i = 2; i <= len; i++ ){
    for(int j = 0; j < i; j++) {
      results[i] = std::max(results[i], results[j] + results[i - j]);
    }
  }
  return results[len];
}
