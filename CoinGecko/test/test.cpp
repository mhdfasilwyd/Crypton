#include "gecko.h"

int main() {
  // CoinGecko main class object
  gecko::api coinGecko;
  
  // check if CoinGecko API is online
  if (coinGecko.ping()) {
    // if online, get Bitcoin's most recent price in USD and print the JSON response
    std::cout << coinGecko.simple.getPrice("bitcoin", "usd").text << std::endl;
  } else {
    // if offline, print offline.
    std::cout << "CoinGecko offline!" << std::endl;
  }
  
  return 0;
}