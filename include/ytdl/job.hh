#ifndef __YTDL_JOB_HH__
#define __YTDL_JOB_HH__

#include <functional>
#include <optional>
#include <type_traits>

namespace ytdl {

struct basic_job { // abstract job
    virtual void execute() {};
    virtual const bool is_pure() { return true; }
};

template <typename Fn, typename... Args>
struct job : public basic_job, public std::enable_shared_from_this<job<Fn, Args...>> { // a job that could be execute  lately
    std::function<void()> _functor;
    std::optional<typename std::function<Fn>::result_type> _result;

    job(std::function<Fn>& fn, Args... args)
        : _functor { [this, fn, args...] { _result = fn(args...); } }
    {
    }

    void execute() override { _functor(); }
    const bool is_pure() override { return false; }
    auto get_result() { return _result; }
};

template <typename Fn, typename... Args>
struct pure_job : public basic_job { // A pure_job is some jobs without any return value
    std::function<void()> _functor;
    pure_job(std::function<Fn>& fn, Args... args)
        : _functor { [this, fn, args...] { fn(args...); } }
    {
    }
    void execute() override { _functor(); }
};

template <typename Fn, typename... Args>
auto to_job(std::function<Fn> fn, Args... args)
{
    if constexpr (std::is_same_v<typename std::function<Fn>::result_type, void>)
        return pure_job(fn, args...);
    else
        return job(fn, args...);
}

template <typename Fn, typename... Args>
auto to_pure_job(std::function<Fn> fn, Args... args) { return pure_job(fn, args...); }

}
#endif
