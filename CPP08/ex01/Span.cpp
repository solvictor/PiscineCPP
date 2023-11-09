/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:41:27 by vegret            #+#    #+#             */
/*   Updated: 2023/11/09 18:12:47 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span() : _max_size(0) {}

Span::Span(const Span &source) : _data(source._data), _max_size(source._max_size) {}

Span& Span::operator=(const Span &source) {
	if (this == &source)
		return *this;
	_max_size = source._max_size;
	_data = source._data;
	return *this;
}

Span::~Span() {}

Span::Span(unsigned int N) : _max_size(N) {}

unsigned int Span::size() const { return _data.size(); }
unsigned int Span::max_size() const { return _max_size; }

void Span::addNumber(int nb) {
	if (size() >= _max_size)
		throw Span::SpanFullException();
	
	_data.insert(nb);
}

int Span::shortestSpan() {
	if (size() < 2)
		throw Span::SpanEmptyException();

	std::multiset<int>::const_iterator it = _data.begin();
	int previous = *it++;
	unsigned int min_span = *it - previous;
	while (it != _data.end()) {
		unsigned int span = *it - previous;
		if (span < min_span)
			min_span = span;
		previous = *it;
		it++;
	}

	return min_span;
}

int Span::longestSpan() {
	if (size() < 2)
		throw Span::SpanEmptyException();

	return *_data.rbegin() - *_data.begin();
}

std::multiset<int>::iterator Span::begin() { return _data.begin(); }

std::multiset<int>::iterator Span::end() { return _data.end(); }