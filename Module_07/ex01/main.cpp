/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:22:11 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/22 17:53:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// === Generic addOne for numeric types ===
template <typename T>
void addOne(T &a) {
    ++a;
}

// === Generic print function ===
template <typename T>
void print(T &a) {
    std::cout << a << " ";
}

// === iter template ===
template <typename T>
void iter(T *arr, unsigned len, void (*func)(T &)) {
    for (unsigned i = 0; i < len; i++)
        func(arr[i]);
}

// === Specialized addOne for std::string ===
void addOne(std::string &s) {
    s += "+";
}

int main() {
    // === Test with int ===
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    iter(arr1, 5, print);
    std::cout << "\nAfter addOne: ";
    iter(arr1, 5, addOne);
    iter(arr1, 5, print);
    std::cout << "\n\n";

    // === Test with float ===
    float arr2[] = {1.5f, 2.5f, 3.5f};
    std::cout << "Original float array: ";
    iter(arr2, 3, print);
    std::cout << "\nAfter addOne: ";
    iter(arr2, 3, addOne);
    iter(arr2, 3, print);
    std::cout << "\n\n";

    // === Test with std::string ===
    std::string arr3[] = {"hello", "world", "cpp"};
    std::cout << "Original string array: ";
    iter(arr3, 3, print);
    std::cout << "\nAfter addOne: ";
    iter(arr3, 3, addOne);
    iter(arr3, 3, print);
    std::cout << "\n\n";

    return 0;
}
