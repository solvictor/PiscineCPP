/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:05:26 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 15:10:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <stdexcept>

typedef unsigned int uint;

template <typename T>
class Array {
	private:
		T* _elems;
		uint _size;

	public:
		Array() : _elems(NULL), _size(0) {}

		Array(uint n) : _size(n) {
			_elems = new T[n];
			for (uint i = 0; i < _size; i++)
				_elems[i] = T();
		}

		Array(const Array& source) : _size(source._size) {
			_elems = new T[_size];
			for (size_t i = 0; i < source.size(); i++)
				_elems[i] = source[i];
		}

		Array& operator=(const Array& source) {
			if (this == &source) 
				return *this;

			delete[] _elems;
			_size = source._size;
			_elems = new T[_size];
			for (size_t i = 0; i < source.size(); i++)
				_elems[i] = source[i];

			return *this;
		}

		~Array() { delete[] _elems; }

		T& operator[](uint i) {
			if (i < 0 || i >= _size)
				throw std::out_of_range("Array index out of bounds");
			return _elems[i];
		}

		const T& operator[](uint i) const {
			if (i < 0 || i >= _size)
				throw std::out_of_range("Array index out of bounds");
			return _elems[i];
		}

		uint size() const { return _size; }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
	os << '{';
	for (size_t i = 0; i < arr.size(); i++) {
		if (i != 0)
			os << ", ";
		os << arr[i];
	}
	os << '}';
	return os;
}

#endif