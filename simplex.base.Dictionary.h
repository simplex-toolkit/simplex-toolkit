/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Array.h
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 */

#ifndef SIMPLEX_BASE_DICTIONARY_H
#define SIMPLEX_BASE_DICTIONARY_H

#include <unordered_map>
#include <utility>
#include <vector>
#include "simplex.base.Array.h"
#include "simplex.base.Exception.h"

namespace simplex
{
	namespace base
	{
		class KeyNotFoundException : public Exception
		{
			public:
				KeyNotFoundException() {}
				KeyNotFoundException(const ::std::string& text) : Exception(text) {}
		};

		template <typename KeyType, typename valueType> class Dictionary
		{
			public:
				//Constructors
				Dictionary() {}
				Dictionary(::std::initializer_list<::std::pair<KeyType const, valueType>> iPairs)
				{
					for (auto keyvalue : iPairs)
					{
						add(keyvalue.first, keyvalue.second);
					}
				}

				//Operators
				valueType operator [](KeyType key) const
				{
					return at(key);
				}
				valueType operator [](KeyType key)
				{
					return at(key);
				}

				//Methods
				Dictionary& add(KeyType key, valueType value)
				{
					dictionary_.emplace(::std::move(key), ::std::move(value));
					return *this;
				}
				void add(::std::initializer_list<::std::pair<KeyType const, valueType>> iPairs)
				{
					for (auto keyvalue : iPairs)
						add(keyvalue.first, keyvalue.second);
				}
				valueType at(KeyType key) const
				{
					try
					{
						return dictionary_.at(key);
					}
					catch (...)
					{
						throw KeyNotFoundException();
					}
				}
				void clear()
				{
					dictionary_.clear();
				}
				bool containsKey(KeyType key) const
				{
					return (dictionary_.count(key) > 0);
				}
				Dictionary& removeByKey(KeyType key)
				{
					dictionary_.erase(key);
					return *this;
				}
				Dictionary& removeAll()
				{
					dictionary_.clear();
					return *this;
				}

				//Variables
				Array<KeyType> keys() const
				{
					Array<KeyType> keys;
					keys.reserveSpace(dictionary_.size());

					/*for (auto key : dictionary_)
						keys.add(key.first);*/

					return keys;
				}
				Array<valueType> values() const
				{
					Array<valueType> values;
					values.ReserveSpace(dictionary_.size());

					for (valueType value : dictionary_)
						values.add(value.second);

					return values;
				}

				//Standard c++ aliases
				Dictionary& insert(KeyType key, valueType value)
				{
					Add(key, value);
					return *this;
				}
				int size() const
				{
					return dictionary_.size();
				}

				auto begin() const
				{
					return dictionary_.begin();
				}
				auto end() const
				{
					return dictionary_.end();
				}

			protected:
				::std::unordered_map<KeyType, valueType> dictionary_;
		};
	}
}

#endif // SIMPLEX_BASE_DICTIONARY_H
