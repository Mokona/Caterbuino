#pragma once

#include <iterator>

template <typename I>
std::reverse_iterator<I> make_reverse_iterator(I i)
{
    return std::reverse_iterator<I>{ i };
}

template <typename T>
auto rbegin(T& iterable)
{
    return make_reverse_iterator(iterable.end());
}

template <typename T>
auto rend(T& iterable)
{
    return make_reverse_iterator(iterable.begin());
}

template <typename T>
struct reversion_wrapper {
    T& iterable;
};

template <typename T>
auto begin(reversion_wrapper<T> w) { return rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse(T&& iterable) { return { iterable }; }
