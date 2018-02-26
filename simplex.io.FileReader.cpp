#include "simplex.io.FileReader.h"
#include "simplex.base.Exception.h"
#include "simplex.io.FileExceptions.h"

namespace simplex
{
	namespace io
	{
		FileReader::FileReader() { }
		FileReader::FileReader(const String& fileName)
		{
			setFileName(fileName);
		}

		void FileReader::open()
		{
			if(fileName_ != "")
			{
				if(readIsOpen == false)
				{
					try
					{
						readFile = ::std::make_unique<StreamReader>(::std::ifstream(fileName_));
						readIsOpen = true;
						EndOfFile = false;
					}
					catch(...)
					{
						throw IOException("Error: File could not be opened for reading.");
					}
				}
			}
			else
				throw NullException("Error: File Name cannot be empty.");
		}
		void FileReader::setFileName(const String& fileName)
		{
			if(readIsOpen == true)
				readIsOpen = false;

			fileName_ = fileName;
		}
		bool FileReader::readLine(String& line)
		{
			return readFile->readLine(line);
		}
		Array<String> FileReader::readAllLines()
		{
			return readFile->readAllLines();
		}

		template<typename TypeToRead> TypeToRead FileReader::readType()
		{
			return readFile->readType<TypeToRead>();
		}
		String FileReader::read(int numberOfCharacters)
		{
			return readFile->read(numberOfCharacters);
		}

		String FileReader::readCString()
		{
			return readFile->readCString();
		}
		template<typename PrefixType> String FileReader::readPrefixedString(PrefixType lengthOfString)
		{
			return readFile->readPrefixedString(lengthOfString);
		}
	}
}
