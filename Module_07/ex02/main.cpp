/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:22:11 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/10 16:32:35 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    // Test 1: Default constructor
    Array<int> arr1;
    std::cout << "arr1.size(): " << arr1.size() << std::endl;

    // Test 2: Constructor with size
    Array<int> arr2(5);
    std::cout << "arr2.size(): " << arr2.size() << std::endl;
    for (unsigned int i = 0; i < arr2.size(); ++i)
        arr2[i] = i * 10;
    for (unsigned int i = 0; i < arr2.size(); ++i)
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;

    // Test 3: Copy constructor
    Array<int> arr3(arr2);
    std::cout << "arr3 (copy of arr2): ";
    for (unsigned int i = 0; i < arr3.size(); ++i)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;

    // Test 4: Assignment operator
    Array<int> arr4;
    arr4 = arr2;
    std::cout << "arr4 was assigned from arr2" << std::endl;
    arr2[0] = 100;
    std::cout << "changed arr2[0] to " << arr2[0] << std::endl;
    std::cout << "arr4: ";
    for (unsigned int i = 0; i < arr4.size(); ++i)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;

    // Test 5: Out of bounds access
    try {
        std::cout << arr2[10] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught exception (out of bounds): " << e.what() << std::endl;
    }

    // Test 6: Array of strings
    Array<std::string> arr5(3);
    arr5[0] = "Hello";
    arr5[1] = "World";
    arr5[2] = "!";
    for (unsigned int i = 0; i < arr5.size(); ++i)
        std::cout << "arr5[" << i << "] = " << arr5[i] << std::endl;

    // Test 7: Const correctness
    const Array<int> arr6(arr2);
    std::cout << "arr6 (const copy of arr2): ";
    for (unsigned int i = 0; i < arr6.size(); ++i)
        std::cout << arr6[i] << " ";
    std::cout << std::endl;

    // Test 8: Array of doubles
    Array<double> arr7(4);
    for (unsigned int i = 0; i < arr7.size(); ++i)
        arr7[i] = 3.14 * i;
    for (unsigned int i = 0; i < arr7.size(); ++i)
        std::cout << "arr7[" << i << "] = " << arr7[i] << std::endl;

    // Test 9: Self-assignment
    arr2 = arr2;
    std::cout << "arr2 after self-assignment: ";
    for (unsigned int i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    // Test 10: Zero-sized array
    Array<char> arr8(0);
    std::cout << "arr8.size(): " << arr8.size() << std::endl;
    try {
        arr8[0] = 'a';
    } catch (const std::exception &e) {
        std::cout << "Caught exception (zero-sized array): " << e.what() << std::endl;
    }

    return 0;
}
