/* License: 3-Clause BSD
 * Required Includes:
 * simplex.base.Array.h
 * simplex.base.Exception.h
 * simplex.base.Exception.cpp
 * simplex.base.String.cpp
 */

#ifndef SIMPLEX_BASE_STRING_H
#define SIMPLEX_BASE_STRING_H

#include <ostream>
#include <string>
#include "simplex.base.Array.h"
namespace simplex
{
	namespace base
	{
		class String
		{
			::std::string data;

		public:
			//Constructors
			String() {}
			String(const int data);
			String(const float data);
			String(const double data);
			String(const char* data);
			String(const char& data);
			String(::std::string data);

			//Casts
			operator double() const;
			operator float() const;
			operator int() const;
			operator ::std::string() const;
			operator size_t() const;
			
			//Operators
			String& operator=(String str);
			String& operator+=(String str);
			char operator[] (size_t pos) const;

			//Outside Operators when String encouters another object
			friend String operator+(const String& arg1, const char* arg2);
			friend String operator+(const char* arg1, const String& arg2);
			friend String operator+(const String& arg1, const char arg2);
			friend String operator+(const char arg1, const String& arg2);
			friend String operator+(const String& arg1, const String& arg2);
			friend String operator+(const String& arg1, const ::std::string& arg2);
			friend String operator+(const ::std::string& arg1, const String& arg2);
			
			friend ::std::ostream& operator<<(::std::ostream& os, const String& st);
			
			friend bool operator<(const String& str1, const String& str2);
			friend bool operator>(const String& str1, const String& str2);
			friend bool operator>=(const String& str1, const String& str2);
			friend bool operator<=(const String& str1, const String& str2);
			friend bool operator==(const String& str1, const String& str2);
			friend bool operator!=(const String& str1, const String& str2);


            //Export Types
			double toDouble() const;
			float toFloat() const;
			int toInt() const;
			::std::string toStdString() const;
			const char* toCString() const;

            //Static Import Types
            static String fromStdString(const ::std::string& str);
            static String fromCString(const char* str);
            static String fromCString(const char& str);

			//Methods
			bool contains(const String& str) const;
			int containsCount(const String& str) const;
			int indexOf(const String& str) const;
			int indexOf(const String& str, int offset) const;
			int lastIndexOf(const String& str) const;
			int lastIndexOf(const String& str, int offset) const;
			int length() const;
			String toLower() const;
			String toUpper() const;
			String replace(const String& oldValue, const String& newValue) const;
			Array<String> split(const String& splitcharacter) const;
			String subString(int start, bool emptyStringOnOutOfBounds = true) const;
			String subString(int start, int lengthOfSub, bool emptyStringOnOutOfBounds = true) const;
			String leftPad(const int& totalStringLength, const char character = ' ') const;
			String rightPad(const int& totalStringLength, const char character = ' ') const;
			String trimLeft() const;
			String trimRight() const;
			String trim() const;

			::std::string::iterator begin()
			{
				return data.begin();
			}
			::std::string::iterator end()
			{
				return data.end();
			}
		};
	}
}
namespace std
{
	template <>
	struct hash<simplex::base::String>
	{
		size_t operator() (const simplex::base::String &t) const
		{
			return size_t(t);
		}
	};
}
#endif // SIMPLEX_BASE_STRING_H
