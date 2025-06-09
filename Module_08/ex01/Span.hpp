/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:37:30 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/09 21:06:27 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <iterator>

class Span
{
	public:
		// Constructors
		Span();
		Span(const Span &copy);
		Span(const unsigned N);
		
		// Destructor
		~Span();

		// Operators
		Span & operator=(const Span &assign);

		// Getters
		const unsigned int		&getN() const;
		const std::vector<int>	&getContent() const;

		// Member functions
		void	addNumber(const int num);
		int		shortestSpan();
		int		longestSpan();
		template <typename Iter>
		void	insert(Iter begin, const Iter end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		};

		// Exceptions
		class FullStorage : public std::exception
		{
				virtual const char * what() const throw();
		};
		class NoSpan : public std::exception
		{
			virtual const char * what() const throw();
		};

	private:
		std::vector<int>	_content;
		unsigned			_N;
		bool				_isSorted;
};

#endif