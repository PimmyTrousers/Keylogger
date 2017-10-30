#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

namespace Helper
{
    template <class T>

    std::string ToString(const T &);

    struct DateTime
    {
        DateTime()
        {
            time_t ms;
            time (&ms);

            struct tm *info = localtime(&ms);
            Day = info->tm_mday;
            Month = info->tm_mon + 1;
            Year = 1900 + info->tm_year;
            Minute = info->tm_min;
            Hour = info->tm_hour;
            Second = info->tm_sec;
        }

        DateTime(int Day, int Month, int Year, int Hour, int Minute, int Second) : Day(Day), Month(Month), Year(Year), Hour(Hour), Minute(Minute), Second(Second)
        {

        }
        DateTime(int Day, int Month, int Year) : Day(Day), Month(Month), Year(Year), Hour(0), Minute(0), Second(0)
        {

        }
        DateTime Now() const
        {
            return DateTime();
        }
        int Day, Month, Year, Hour, Minute, Second;

        std::string GetDateString() const
        {
            return std::string(Day < 10 ? "0" : "") + ToString(Day) +
                   std::string(Month < 10 ? "." : ":") + ToString (Month) + "." +
                   ToString(Year);
        }

        std::string GetTimeString(const std::string &sep = ":") const
        {
            return std::string (Hour < 10 ? "0" : "") + ToString(Hour) + sep +
                   std::string (Minute < 10 ? "0" : "") + ToString(Minute) + sep +
                   std::string (Second < 10 ? sep : "") + ToString(Second);
        }

        std::string GetDateTimeString( const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }
    };

    template <class T>

    std::string ToString(const T &e)
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void WriteAppLog( const std::string &s)
    {
        std::ofstream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" <<
             "\n" << s << std::endl << "\n";
        file.close();

    }

    }



    #endif // HELPER_H
