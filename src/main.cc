#include <iostream>
#include <ytdl/log.hh>
#include <thread>
#include <chrono>
#include <random>

using namespace std::chrono_literals;
int main() {
    auto logger = ytdl::init_logger();
    logger.info("Starting YTDL!");
    
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);
    std::vector<std::thread> v;
	
    for(int i = 0; i < 8; i++){
        v.push_back(std::move(std::thread([&, i]{std::this_thread::sleep_for(std::chrono::seconds(dist(rd)));logger.info(i);})));
    }

    for (auto& x: v){
        x.join();
    }
	
    return 0;
}
