#include <sstream>
#include "simplex.io.StreamReader.h"
#include "simplex.base.Exception.h"
#include "simplex.io.FileExceptions.h"

namespace simplex
{
	namespace io
	{
		StreamReader::StreamReader(const String& stream)
		{
			streamData = ::std::make_unique<::std::istringstream>(stream.toStdString());
		}
		StreamReader::StreamReader(const ::std::istream& stream)
		{
			//streamData = ::std::make_unique<::std::istream>(stream);
		}

		bool StreamReader::readLine(String& line)
		{
				::std::string tempLine = "";
				::std::getline(*streamData, tempLine);
				line = String(tempLine);
				if (streamData->eof())
				{
					EndOfData = true;
					return false;
				}
				else
					return true;
		}
		Array<String> StreamReader::readAllLines()
		{
			Array<String> lines;

			String line = "";
			while (readLine(line))
			{
				lines.add(line);
			}

			return lines;
		}

		template<typename TypeToRead> TypeToRead StreamReader::readType()
		{
			char charTemp[sizeof(TypeToRead)];
			streamData->read(charTemp, sizeof(TypeToRead));
			return (TypeToRead)charTemp;
		}
		String StreamReader::read(int numberOfCharacters)
		{
			auto charTemp = ::std::make_unique<char>(sizeof(char)*numberOfCharacters);
			streamData->read(charTemp.get(), numberOfCharacters);
			return ::std::string(charTemp.get());
		}

		String StreamReader::readCString()
		{
			String concatnate = "";
			String lastCharacter = "";
			do
			{
				lastCharacter = read(1);
				if (!streamData->eof())
					concatnate += lastCharacter;
				else
					throw IOException("End of File Reached. Unable to parse further.");

			} 
			while (lastCharacter != String('\0'));
			
			return concatnate;
		}
		template<typename PrefixType> String StreamReader::readPrefixedString(PrefixType lengthOfString)
		{
            auto lengthOfStr = readType<PrefixType>();
            return read(lengthOfStr);
		}
	}
}
