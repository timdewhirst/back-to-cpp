
#include "csv_parser.hpp"

#if defined(CSV_PARSER_TEST_MAIN)

// std
#include <iostream>
#include <tuple>

// local
#include "util/simple_unit_test.hpp"

using stringvector = std::vector<std::string>;

std::ostream& operator<<(std::ostream& os, const stringvector& v)
{
    static const char separator[] = ", ";
    const char* separator_p = "";
    for (auto I=std::begin(v); I!=std::end(v); ++I)
    {
        os << separator_p << *I;
        separator_p = separator;
    }

    return os;
}

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& v)
{
    std::apply
    (
        [&os](const Ts&... tuple_args)
        {
            os << '(';
            std::size_t n{0};
            ((os << tuple_args << (++n != sizeof...(Ts) ? ", " : "")), ...);
            os << ')';
        },
        v
    );
    return os;
}

//
int main(int argc, char* argv[])
{
    using namespace std::string_literals;
    using namespace util::test;
    using namespace util;

    ASSERT_EQUAL( (parse_line<int64_t, std::string, double>("1, foo, 3.14")), (std::tuple<int64_t, std::string, double>(1, "foo", 3.14)) );
    ASSERT_EQUAL( (parse_line<int64_t, std::string>("1, ")), (std::tuple<int64_t, std::string>(1, "")) );
    ASSERT_EQUAL( (parse_line<int64_t, std::string>(", foo")), (std::tuple<int64_t, std::string>(0, "foo")) );
    ASSERT_EXCEPTION( ([](){ parse_line<int64_t, std::string, double>(""); }), std::runtime_error );
    ASSERT_EXCEPTION( ([](){ parse_line<int64_t>("boo"); }), std::invalid_argument );

    return 0;
}

#endif
