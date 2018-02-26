#include "simplex.io.FileWriter.h"
#include "simplex.base.Exception.h"
#include "simplex.io.FileExceptions.h"
#include <sstream>

namespace simplex
{
	namespace io
	{
		FileWriter::FileWriter() { }
		FileWriter::FileWriter(const String& fileName)
		{
			setFileName(fileName);
		}
		FileWriter::~FileWriter()
		{
			if(writeIsOpen)
				writeFile->close();
		}

		void FileWriter::open()
		{
			if(fileName_ != "")
			{
				if(writeIsOpen == false)
				{
					try
					{
						writeFile = ::std::make_unique<::std::ofstream>(fileName_);
						writeIsOpen = true;
					}
					catch(...)
					{
						throw IOException("Error: File could not be Opened for reading.");
					}
				}
			}
			else
				throw NullException("Error: File Name cannot be empty.");
		}
		void FileWriter::setFileName(const String& fileName)
		{
			if(writeIsOpen)
			{
				writeIsOpen = false;
				writeFile.reset(nullptr);
			}
			fileName_ = fileName;
		}
		void FileWriter::write(const String& toWrite)
		{
			if(!writeIsOpen)
				open();
			::std::ostringstream strstream;
			strstream << toWrite;
			*writeFile << strstream.str();
		}
		void FileWriter::writeLine(const String& toWrite)
		{
			write(toWrite + "\n");
		}
		void FileWriter::writeAllLines(Array<String>& toWrite)
		{
			int arraySize = toWrite.size();
			for(int loop = 0; loop < arraySize; loop++)
				FileWriter::writeLine(toWrite[loop]);
		}
	}
}
