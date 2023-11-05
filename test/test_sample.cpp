#include "gtest/gtest.h"
#include <tbb/concurrent_hash_map.h>
#include <thread>

struct MarketDataSnapshot {
    double lastPrice; 
};

using SecurityId = std::string;
using MarketDataMap = tbb::concurrent_hash_map<SecurityId, MarketDataSnapshot>;

class MarketDataMapTest : public ::testing::Test {
protected:
    MarketDataMap marketDataMap;

    MarketDataSnapshot createMarketDataSnapshot() {
        return MarketDataSnapshot();
    }
};

TEST_F(MarketDataMapTest, InsertAndRetrieve) {
    SecurityId key = "AAPL";
    MarketDataSnapshot snapshot = createMarketDataSnapshot();

    // Insert a MarketDataSnapshot into the hashmap
    {
        MarketDataMap::accessor accessor;
        marketDataMap.insert(accessor, key);
        accessor->second = snapshot;
    }

    // Retrieve the MarketDataSnapshot and verify it's the same as the inserted one
    {
        MarketDataMap::const_accessor accessor;
        ASSERT_TRUE(marketDataMap.find(accessor, key));
        // Compare the retrieved snapshot with the inserted one, using your preferred method
    }
}

TEST_F(MarketDataMapTest, MultiThreadedInsertAndRetrieve) {
    const int num_threads = 10;
    const int num_iterations = 100;

    auto insert_and_retrieve = [&]() {
        for (int i = 0; i < num_iterations; ++i) {
            SecurityId key = "AAPL" + std::to_string(i % 10);
            MarketDataSnapshot snapshot = createMarketDataSnapshot();

            // Insert a MarketDataSnapshot into the hashmap
            {
                MarketDataMap::accessor accessor;
                marketDataMap.insert(accessor, key);
                accessor->second = snapshot;
            }

            // Retrieve the MarketDataSnapshot and verify it's the same as the inserted one
            {
                MarketDataMap::const_accessor accessor;
                ASSERT_TRUE(marketDataMap.find(accessor, key));
                // Compare the retrieved snapshot with the inserted one, using your preferred method
            }
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(insert_and_retrieve);
    }

    for (auto& t : threads) {
        t.join();
    }
}

