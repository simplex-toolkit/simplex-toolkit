/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 */

#ifndef SIMPLEX_BASE_ARRAY_H
#define SIMPLEX_BASE_ARRAY_H

#include <string>
#include <vector>
#include <algorithm>
#include "simplex.base.Exception.h"

namespace simplex
{
	namespace base
	{
		template <typename ArrayMemberType> class Array
		{
			public:
				Array() {}

				Array(::std::initializer_list<ArrayMemberType> iList)
				{
					for (ArrayMemberType item : iList)
						add(item);
				}
				Array(int arraySize, char* characterArray[])
				{
					for (int i = 0; i < arraySize; i++)
						array_.emplace_back(::std::string(characterArray[i]));
				}
				Array(::std::vector<ArrayMemberType> vectorObject)
				{
					convertFromVector(vectorObject);
				}

				//Operators
				ArrayMemberType& operator [](int index) const
				{
					return at(index);
				}
				ArrayMemberType& operator [](int index)
				{
					return at(index);
				}

				//Methods
				Array<ArrayMemberType>& add(ArrayMemberType value)
				{
					array_.emplace_back(value);
					return *this;
				}
				Array<ArrayMemberType>& add(ArrayMemberType value, int index)
				{
					if (index < size() + 1)
					{
						array_.insert(array_.begin(), index, value);
					}
					else
						throw IndexOutOfBoundsException();

					return *this;
				}
				Array<ArrayMemberType>& add(::std::initializer_list<ArrayMemberType> iList)
				{
					for (ArrayMemberType item : iList)
						add(item);
					return *this;
				}
				Array<ArrayMemberType>& add(Array<ArrayMemberType> arrayValues)
				{
					array_.insert(array_.end(), arrayValues.begin(), arrayValues.end());
					return *this;
				}
				Array<ArrayMemberType>& add(::std::vector<ArrayMemberType> arrayValues)
				{
					array_.insert(array_.end(), arrayValues.begin(), arrayValues.end());
					return *this;
				}
				Array<ArrayMemberType>& addAt(ArrayMemberType value, int index)
				{
					add(value, index);
					return *this;
				}
				
				Array<ArrayMemberType>& convertFromVector(::std::vector<ArrayMemberType> vectorObject)
				{
					array_ = vectorObject;
					return *this;
				}
				::std::vector<ArrayMemberType> convertToVector()
				{
					return array_;
				}
				
				ArrayMemberType& at(int index)
				{
					try
					{
						return array_.at(index);
					}
					catch (...)
					{
						throw IndexOutOfBoundsException();
					}
				}
				Array<ArrayMemberType>& clear()
				{
					array_.clear();
					return *this;
				}
				
				Array<ArrayMemberType> getPartialArray(int start)
				{
					int arraySize = array_.size();
					if (start < 0)
						start = arraySize + start;

					if (start > arraySize)
						throw IndexOutOfBoundsException("Starting beyond size of Array.");

					return Array<ArrayMemberType>(::std::vector<ArrayMemberType>(array_.begin() + start, array_.end()));
				}
				Array<ArrayMemberType> getPartialArray(int start, int count)
				{
					int arraySize = array_.size();
					if (start < 0)
						start = arraySize + start;
					if (count < 0)
						count = arraySize - start + count;

					if (start > arraySize)
						throw IndexOutOfBoundsException("Starting beyond size of Array.");
					else if (start + count > arraySize)
						throw IndexOutOfBoundsException("Starting beyond size of Array.");

					if (start + count == arraySize)
						return Array<ArrayMemberType>(::std::vector<ArrayMemberType>(array_.begin() + start, array_.end()));
					else
						return Array<ArrayMemberType>(::std::vector<ArrayMemberType>(array_.begin() + start, array_.begin() + start + count));
				}
				
				bool contains(ArrayMemberType value) const
				{
					return (::std::find(array_.begin(), array_.end(), value) != array_.end()) ? true : false;
				}
				int containsCount(ArrayMemberType value) const
				{
					return ::std::count(array_.begin(), array_.end(), value);
				}
				int indexOf(ArrayMemberType value) const
				{
					return ::std::distance(array_.begin(), ::std::find(array_.begin(), array_.end(), value));
				}
				int lastIndexOf(ArrayMemberType value) const
				{
					return ::std::distance(array_.begin(), ::std::find(array_.end(), array_.begin(), value));
				}
				Array<ArrayMemberType>& pop()
				{
					array_.pop_back();
					return *this;
				}
				ArrayMemberType& popAndReturn()
				{
					ArrayMemberType temp = array_.at(array_.size() - 1);
					array_.pop_back();
					return temp;
				}
				Array<ArrayMemberType>& push(ArrayMemberType value)
				{
					add(value);
					return *this;
				}
				
				Array<ArrayMemberType>& remove(ArrayMemberType value)
				{
					for (int loop = 0; loop < size(); loop++)
						if (array_[loop] == value)
						{
							removeAt(loop);
							break;
						}

					return *this;
				}
				Array<ArrayMemberType>& removeAll(ArrayMemberType value)
				{
					array_.erase(::std::remove(array_.begin(), array_.end(), value), array_.end());
					return *this;
				}
				Array<ArrayMemberType>& removeAt(int index)
				{
					array_.erase(array_.begin() + index);
					return *this;
				}
				
				Array<ArrayMemberType>& reserveSpace(size_t spaceToReserve)
				{
					array_.reserve(spaceToReserve);
					return *this;
				}
				
				Array<ArrayMemberType>& reverse()
				{
					::std::reverse(array_.begin(), array_.end());
					return *this;
				}
				Array<ArrayMemberType>& reverseSort()
				{
					sort();
					reverse();
					return *this;
				}
				struct sorter
				{
					inline bool operator() (ArrayMemberType type1, ArrayMemberType type2)
					{
						return ((::std::string)type1 < (::std::string)type2);
					}
				};
				Array<ArrayMemberType>& sort()
				{
					::std::sort(array_.begin(), array_.end(), sorter());
					return *this;
				}
				
				auto begin() const
				{
					return array_.begin();
				}
				auto end() const
				{
					return array_.end();
				}
				
				//Math Related -- Future
				/*double Average();
				ArrayMemberType Min();
				ArrayMemberType Max();*/

				size_t size() const
				{
					return array_.size();
				}

			protected:
				::std::vector<ArrayMemberType> array_;
				
				/*
				  class ArrayInterator
				{
				public:
					ArrayInterator(int location, ::std::vector<ArrayMemberType>& dataLocation) : location(location), dataLocation(dataLocation) {}

					bool operator!=(ArrayInterator other)
					{
						return other.location != location;
					}
					bool operator==(ArrayInterator other)
					{
						return other.location == location;
					}

					ArrayInterator operator++()
					{
						 ++location;
						 return *this;
					}
					ArrayInterator operator--()
					{
						 --location;
						 return *this;
					}

					ArrayMemberType& operator*()
					{
						return dataLocation[location];
					}

				private:
					int location;
					::std::vector<ArrayMemberType>& dataLocation;
				};

				ArrayInterator begin()
				{
					return ArrayInterator(0, array_);
				}
				ArrayInterator end()
				{
					return ArrayInterator(size(), array_);
				}
				*/ 
		};
	}
}

#endif // SIMPLEX_BASE_ARRAY_H
