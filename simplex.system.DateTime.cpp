#include "simplex.system.DateTime.h"

namespace simplex
{
	namespace system
	{
		int DateTime::localSecond()
		{
			return DateTime::getLocal()->tm_sec;
		}

		int DateTime::localMinute()
		{
			return DateTime::getLocal()->tm_min;
		}

		int DateTime::local24Hour()
		{
			return DateTime::getLocal()->tm_hour;
		}

		int DateTime::local12Hour()
		{
			int hour = DateTime::getLocal()->tm_hour % 12;
			return (hour == 0) ? 12 : hour;
		}

		int DateTime::localAmPm()
		{
			return DateTime::getLocal()->tm_hour / 12;
		}

		int DateTime::localDay()
		{
			return DateTime::getLocal()->tm_mday;
		}

		int DateTime::localMonth()
		{
			return DateTime::getLocal()->tm_mon + 1;
		}

		int DateTime::localYYYY()
		{
			return DateTime::getLocal()->tm_year + 1900;
		}

		int DateTime::localYY()
		{
			return (DateTime::getLocal()->tm_year + 1900) % 100;
		}

		int DateTime::currentCentury()
		{
			return (DateTime::getLocal()->tm_year + 1900) / 100 + 1;
		}

		bool DateTime::isDST()
		{
			return (bool)DateTime::getLocal()->tm_isdst;
		}

		int DateTime::utcSecond()
		{
			return DateTime::getUtc()->tm_sec;
		}

		int DateTime::utcMinute()
		{
			return DateTime::getUtc()->tm_min;
		}

		int DateTime::utc24Hour()
		{
			return DateTime::getUtc()->tm_hour;
		}

		int DateTime::utc12Hour()
		{
			int hour = DateTime::getUtc()->tm_hour % 12;
			return (hour == 0) ? 12 : hour;
		}

		int DateTime::utcAmPm()
		{
			return DateTime::getUtc()->tm_hour / 12;
		}

		int DateTime::utcDay()
		{
			return DateTime::getUtc()->tm_mday;
		}

		int DateTime::utcMonth()
		{
			return DateTime::getUtc()->tm_mon + 1;
		}

		int DateTime::utcYYYY()
		{
			return DateTime::getUtc()->tm_year + 1900;
		}

		int DateTime::utcYY()
		{
			return (DateTime::getUtc()->tm_year + 1900) % 100;
		}

		tm* DateTime::getLocal()
		{
			time_t t = time(0);
			struct tm *timeinfo = localtime(&t);
			return timeinfo;
		}

		tm* DateTime::getUtc()
		{
			time_t t = time(0);
			struct tm *timeinfo = gmtime(&t);
			return timeinfo;
		}
	}
}
