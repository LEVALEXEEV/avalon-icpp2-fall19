#include "Date.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ext;

namespace ext
{
	string monthToString(Month month)
	{
		switch (month)
		{
		case Month::January:
			return "january";
		case Month::February:
			return "february";
		case Month::March:
			return "march";
		case Month::April:
			return "April";
		case Month::May:
			return "May";
		case Month::June:
			return "June";
		case Month::July:
			return "July";
		case Month::August:
			return "August";
		case Month::September:
			return "September";
		case Month::October:
			return "October";
		case Month::Novemver:
			return "Novemver";
		case Month::December:
			return "December";
		default:
			throw exception("invalid month");
		}
	}

	void print(Date data, DateFormat format)
	{
		cout << data.year << " ";
		print(data.month, format);
		cout << data.day;
	}

	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsInt)
		{
			cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{
			cout << monthToString(month) << " ";
		}
		else
		{
			throw exception("invalid format of month");
		}
	}

	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}

	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		return TimeDelta{ lhs.delta + rhs.delta };
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) {
		return(lhs.delta - rhs.delta);
	}
	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		return(delta.delta * multiplier);
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta) {
		return(delta * multiplier.delta);
	}
	TimeDelta operator / (const TimeDelta delta, int multiplier) {
		return(delta.delta / multiplier);
	}
	TimeDelta operator ++ (TimeDelta& delta) {
		return delta.delta = delta.delta+ 1;
	}	
	
	void swap(TimeDelta& lhs, TimeDelta& rhs){
	    int m =lhs.delta;
	    lhs.delta=rhs.delta;
	    rhs.delta=m;
	}
	
	Date& max(Date& lhs, Date& rsh){
	    if (lhs.year>rsh.year) 
	    {return *rsh};
	    else if (lhs.year<rhs.year)
	    {return *lsh};
	    if (lhs.month>rhs.month)
	    {return *rsh};
	    else if (lhs.month<rhs.month)
	    {return *lsh};
	    if (lhs.day>rhs.day)
	    {return *rsh};
	    else if (lhs.day<rhs.day)
	    {return *lsh};
	    if (lhs.day==rhs.day and lhs.month==rhs.month and hs.year==rsh.year)
	    {return 0};
	}
	
		Date& getMinDate(Date dates[], int size){
		    int* max;
		
		    for(int i;i<size-1;i++){
		if (dates[i].year>[i+1].year) 
	    max*=&rsh;
	    else if (dates[i].year<[i+1].year)
	    max*=&lsh;
	    if (dates[i].month>[i+1].month)
	    max*=&rsh;
	    else if (dates[i].month<[i+1].month)
	   max*=&lsh;
	    if (dates[i].day>[i+1].day)
	    max*=&rsh;
	    else if (dates[i].day<dates[i+1].day)
	    max*=&lsh;
		    }
	return{max};
		}
	
	
	
	
	Season getSeason(Month month) {
		switch (month)
		{
		case Month::January:
			return Season::Winter;
		case Month::February:
			return Season::Winter;
		case Month::March:
			return Season::Spring;
		case Month::April:
			return Season::Spring;
		case Month::May:
			return Season::Spring;
		case Month::June:
			return Season::Summer;
		case Month::July:
			return Season::Summer;
		case Month::August:
			return Season::Summer;
		case Month::September:
			return Season::Autumn;
		case Month::October:
			return Season::Autumn;
		case Month::Novemver:
			return Season::Autumn;
		case Month::December:
			return Season::Winter;
		default:
			throw exception("invalid month");
		}
	}
		
	Season getSeason(Date date)
	{
		switch (date.month)
		{
		case Month::January:
			return Season::Winter;
		case Month::February:
			return Season::Winter;
		case Month::March:
			return Season::Spring;
		case Month::April:
			return Season::Spring;
		case Month::May:
			return Season::Spring;
		case Month::June:
			return Season::Summer;
		case Month::July:
			return Season::Summer;
		case Month::August:
			return Season::Summer;
		case Month::September:
			return Season::Autumn;
		case Month::October:
			return Season::Autumn;
		case Month::Novemver:
			return Season::Autumn;
		case Month::December:
			return Season::Winter;
		default:
			throw exception("invalid month");
		}

	}






	TimeDelta countJND(Date date)
	{
		TimeDelta a = TimeDelta{ 14 } -TimeDelta{ static_cast<int>(date.month) } / 12;
		TimeDelta y = TimeDelta{ date.year } +TimeDelta{ 4800 } -a;
		TimeDelta m = TimeDelta{ static_cast<int>(date.month) } + 12*a - TimeDelta{ 3 };
		return TimeDelta{ TimeDelta{date.day} +((153 * m + TimeDelta{2}) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - TimeDelta{32045} };
	}
}

