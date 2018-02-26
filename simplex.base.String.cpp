#include "simplex.base.String.h"
#include "simplex.base.Exception.h"
#include <cctype>

namespace simplex
{
	namespace base
	{
		String::String(const int data) : data(::std::to_string(data)) {}
		String::String(const float data) : data(::std::to_string(data)) {}
		String::String(const double data) : data(::std::to_string(data)) {}
		String::String(const char* data) : data(::std::string(data)) {}
		String::String(const char& data) : data(::std::string(1,data)) {}
		String::String(::std::string data) : data(data) {}

		String::operator double() const
		{
			return toDouble();
		}
		String::operator float() const
		{
			return toFloat();
		}
		String::operator int() const
		{
			return toInt();
		}
		String::operator::std::string() const
		{
			return toStdString();
		}
		String::operator size_t() const
		{
			return size_t(this);
		}
		String& String::operator=(String str)
		{
            data = str.toStdString();
			return *this;
		}
		String& String::operator+=(String str)
		{
            data += str.toStdString();
			return *this;
		}
		char String::operator[](size_t pos) const
		{
			if (pos < data.size() - 1)
				return data[pos];
			else
				throw IndexOutOfBoundsException();
		}

		::std::ostream& operator<<(::std::ostream& os, const String& st)
		{
			os << st.data;
			return os;
		}
		
		String operator+(const String& arg1, const char* arg2)
		{
			return String(arg1.data + ::std::string(arg2));
		}
		String operator+(const char* arg1, const String& arg2)
		{
			return String(::std::string(arg1) + arg2.data);
		}
		String operator+(const String& arg1, const char arg2)
		{
			return String(arg1.data + String(arg2));
		}
		String operator+(const char arg1, const String& arg2)
		{
			return String(String(arg1) + arg2.data);
		}
		String operator+(const String& arg1, const String& arg2)
		{
			return String(arg1.data + arg2.data);
		}
		String operator+(const String& arg1, const ::std::string& arg2)
		{
			return String(arg1.data + arg2);
		}
		String operator+(const ::std::string& arg1, const String& arg2)
		{
			return String(arg1 + arg2.data);
		}

		bool operator<(const String& str1, const String& str2)
		{
			return str1.data < str2.data;
		}
		bool operator>(const String& str1, const String& str2)
		{
			return str1.data < str2.data;
		}
		bool operator>=(const String& str1, const String& str2)
		{
			return str1.data < str2.data;
		}
		bool operator<=(const String& str1, const String& str2)
		{
			return str1.data < str2.data;
		}
		bool operator==(const String& str1, const String& str2) {
			return str1.data < str2.data;
		}
		bool operator!=(const String& str1, const String& str2)
		{
			return str1.data < str2.data;
		}

		float String::toFloat() const
		{
			return stof(data);
		}
		double String::toDouble() const
		{
			return stod(data);
		}
		int String::toInt() const
		{
			return stoi(data);
		}
		::std::string String::toStdString() const
		{
			return data;
		}
		const char* String::toCString() const
		{
			::std::string temp(data);
			return temp.c_str();
		}

        static String fromStdString(const ::std::string& str)
        {
            return String(str);
        }
        static String fromCString(const char* str)
        {
            return String(::std::string(str));
        }
        static String fromCString(const char& str)
        {
            String temp(str);
            return temp;
        }

		bool String::contains(const String& str) const
		{
            ::std::size_t searching = data.find(str.toStdString());
			if (searching != ::std::string::npos)
				return true;
			else
				return false;
		}
		int String::containsCount(const String& str) const
		{
			int count = 0;
            int nPos = data.find(str.toStdString(), 0);
			while (nPos != -1)
			{
				count++;
                nPos = data.find(str.toStdString(), nPos + 1);
			}
			return count;
		}
		int String::indexOf(const String& str) const
		{
			return data.find(str.data);
		}
		int String::indexOf(const String& str, int offset) const
		{
			return data.find(str.data, offset);
		}
		int String::lastIndexOf(const String& str) const
		{
			return data.find_last_of(str.data);
		}
		int String::lastIndexOf(const String& str, int offset) const
		{
			return data.find_last_of(str.data, offset);
		}
		int String::length() const
		{
			return data.size();
		}
		String String::toLower() const
		{
			::std::string temp = data;
			for (auto& ch : temp)
				ch = tolower(ch);
			return String(temp);
		}
		String String::toUpper() const
		{
			::std::string temp = data;
			for (auto& ch : temp)
				ch = toupper(ch);
			return String(temp);
		}
		String String::replace(const String& oldValue, const String& newValue) const
		{
			String temp = data;
			int index;
			while ((index = temp.indexOf(oldValue)) != -1)
				temp.data.replace(index, oldValue.length(), newValue.toStdString());
			return temp;
		}
		Array<String> String::split(const String& splitcharacter) const
		{
			Array<String> tempArr;
			int lastIndex = -1;
			int index;
			while ((index = indexOf(splitcharacter, lastIndex + 1)) != -1)
			{
				tempArr.add(subString(lastIndex + 1, index - (lastIndex + 1)));
				lastIndex = index;
			}
			tempArr.add(subString(lastIndex + 1, length() - lastIndex - 1));
			return tempArr;
		}
		String String::subString(int start, bool emptyStringOnOutOfBounds) const
		{
			if (start < 0)
				start = length() + start;

			if (start <= length())
				return String(data.substr(start));
			else if (emptyStringOnOutOfBounds == true)
				return String("");
			else
				throw IndexOutOfBoundsException();
		}
		String String::subString(int start, int lengthOfSub, bool emptyStringOnOutOfBounds) const
		{
			if (start < 0)
				start = length() + start;
			
			if (lengthOfSub < 0)
			{
				if (-lengthOfSub <= length() - start)
					return String(data.substr(start, length() - start + lengthOfSub));
			}
			else if (start + lengthOfSub <= length())
				return String(data.substr(start, lengthOfSub));
			
			if (emptyStringOnOutOfBounds == true)
				return String("");
			else
				throw IndexOutOfBoundsException();
		}
		String String::leftPad(const int& totalStringLength, const char character) const
		{
			if (data.length() < totalStringLength)
			{
				String temp = data;
				for (int length = totalStringLength - temp.length(); length > 0; length--)
					temp = character + temp;
				
				return temp;
			}
			else
				throw Exception("String too long");
		}
		String String::rightPad(const int& totalStringLength, const char character) const
		{
			if (data.length() < totalStringLength)
			{
				String temp = data;
				for (int length = totalStringLength - temp.length(); length > 0; length--)
					temp += character;

				return temp;
			}
			else
				throw Exception("String too long");
		}
		String String::trimLeft() const
		{
			int loop = 0;
			int strLength = length();
			for (; loop < strLength; loop++)
				if (!::std::isspace(data[loop]))
					break;
			return String(data).subString(loop);
		}
		String String::trimRight() const
		{
			int loop = -1;
			int strLength = length();
			for (; -loop < strLength; loop--)
				if (!::std::isspace(data[strLength + loop]))
					break;
			return String(data).subString(0, loop + 1);
		}
		String String::trim() const
		{
			return String(data).trimLeft().trimRight();
		}
	}
}
