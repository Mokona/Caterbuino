#pragma once

#include <cstdlib>

template<typename T, int MAX_SIZE>
class array {
  public:
    array() : size(0) {}

    array<T, MAX_SIZE> & push_back(const T & elt) {
      if (size < MAX_SIZE - 1) {
        elements[size] = elt;
        size += 1;
      }

      return *this;
    }

    array<T, MAX_SIZE> & pop_front() {
      if (size > 0) {
        for (int i = 1; i < size; i++) {
          elements[i - 1] = elements[i];
        }
        size -= 1;
      }

      return *this;
    }

    const T & last() const {
      if (size > 0) {
        return elements[size - 1];
      }
      return T{};
    }

    template<typename F>
    void foreach (F function) {
      for (int i = 0; i < size; i++) {
        function(elements[i]);
      }
    }

  private:
    T elements[MAX_SIZE];
    size_t size;
};

