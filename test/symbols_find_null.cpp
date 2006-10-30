/*=============================================================================
    Copyright (c) 2004 Joao Abecasis
    http://spirit.sourceforge.net/

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#include <boost/spirit/classic/core/config.hpp>
#include <boost/spirit/classic/core/scanner/scanner.hpp>
#if defined(BOOST_SPIRIT_CLASSIC_1_8)
# include <boost/spirit/classic/v1_8/symbols/impl/tst.ipp>
#else
# include <boost/spirit/classic/v1_6/symbols/impl/tst.ipp>
#endif
#include <boost/utility/addressof.hpp>

typedef char char_type;
typedef char const * iterator;

char_type data_[] = "whatever";

iterator begin = data_;
iterator end = data_
    + sizeof(data_)/sizeof(char_type); // Yes, this is an intencional bug ;)

int main()
{
    typedef boost::spirit::scanner<> scanner;
    typedef boost::spirit::impl::tst<void *, char_type> symbols;

    symbols symbols_;

    symbols_.add(begin, end - 1, (void*) boost::addressof(symbols_));

    // The symbol table parser should not choke on input containing the null
    // character.
    symbols_.find(scanner(begin, end));
}
