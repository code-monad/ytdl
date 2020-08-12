#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <ytdl/job.hh>
#include <ytdl/log.hh>

using namespace std::chrono_literals;
int main()
{
    auto logger = ytdl::init_logger();
    logger.info("Starting YTDL!");

    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);
    std::vector<std::thread> v;

    std::function<void()> fn = [&logger] { logger.info("fn here."); };

    std::function<void(int)> fn2 = [&logger](int a) { logger.info("fn2 here"); };

    auto job = ytdl::to_job(fn);
    auto job2 = ytdl::to_job(fn2, 2);

    job.execute();
    job2.execute();
    return 0;
}
