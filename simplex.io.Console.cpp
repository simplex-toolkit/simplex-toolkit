#include "simplex.io.Console.h"

namespace simplex
{
	namespace io
	{
		void Console::write(const String& text)
		{
			::std::cout << text;
		}
		void Console::writeLine(const String& text)
		{
			Console::write(text + "\n");
		}
		void Console::writeStderr(const String& text)
		{
			::std::cerr << text;
		}
		void Console::writeStderrLine(const String& text)
		{
			Console::writeStderr(text + "\n");
		}
		String Console::read()
		{
			::std::string text = "";
			::std::cin >> text;
			return String(text);
		}
		String Console::read(const String& defaultIfBlank)
		{
			String text = Console::read();
			if(text == "")
				return defaultIfBlank;
			else
				return text;
		}
		String Console::prompt(const String& output)
		{
			Console::write(output);
			return Console::read();
		}
		String Console::prompt(const String& output, const String& defaultIfBlank)
		{
			Console::write(output);
			return Console::read(defaultIfBlank);
		}
	}
}
