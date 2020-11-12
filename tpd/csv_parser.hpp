
#pragma once

// std
#include <algorithm>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>

// local
#include "util/exception_builder.hpp"
#include "util/string_utils.hpp"

//
// conversion functions: must specialize convert_to<>
//
template <typename T>
T convert_to(const std::string& s);

template <>
double convert_to<double>(const std::string& s)
{
    if ( s.empty() )
        return {};

    return std::stod(s);
}

template <>
std::string convert_to<std::string>(const std::string& s)
{
    return s;
}

template <>
int64_t convert_to<int64_t>(const std::string& s)
{
    if ( s.empty() )
        return {};

    return std::stoll(s);
}


// helper to consume strings from \a stringlist and populate \a t
template <typename Tuple, size_t... Is>
void fill_tuple( Tuple& t, const std::vector<std::string>& stringlist, std::index_sequence<Is...> )
{
    (( std::get<Is>(t) = convert_to< std::decay_t<decltype(std::get<Is>(t))> >(stringlist[Is]) ), ...);
}

template <typename... Ts>
std::tuple<Ts...> parse_line(const std::string& s)
{
    // naive CSV line parser: splits on any comma, no escaping i.e.
    // one, two, "three, four", five -> one | two | "three | four" | five
    // when it should be one | two | three, four | five
    //
    // strategy:
    // - split s and trim
    // - check s is the same length as sizeof...(Ts)
    // - convert each substring to the matching Ts
    auto split_input = util::split(s, ',');
    std::for_each(std::begin(split_input), std::end(split_input), [](std::string& s){ s = util::trim(s); });

    if ( sizeof...(Ts) != split_input.size() )
        exception_builder<std::runtime_error>() << "failed to split input into " << sizeof...(Ts) << " columns: " << s;

    std::tuple<Ts...> result;
    fill_tuple(result, split_input, std::index_sequence_for<Ts...>{});

    return result;
}

