#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct duration {
	int hours, mins;
}DURATION;

typedef struct departure {
	int day; 
	char month[4];
	int year;
	int Hour, Min;
}DEPARTURE;

typedef struct flight {
	const char* pStartingPoint;
	DEPARTURE Departure;
	DURATION Duration;
	int TimeZone;
}FLIGHT;

char** Exam(FLIGHT* pFlights, int nFlights);

int main()
{
	FLIGHT flights[] =
	{
		{"Buenos Aires", {1, "Mar", 2020, 19, 40}, {18, 0}, -3},
		{"Guatemala City", {20, "Feb", 2020, 12, 20}, {19, 15}, -6},
		{"Bangkok", {20, "Jan", 2020, 18, 30}, {10, 25}, 7},
		{"Helsinki", {27, "Dec", 2020, 23, 55}, {0, 35}, 2},
		{"Stockholm", {30, "Dec", 2020, 17, 40}, {1, 0}, 1}
	};
	char** ppSchedule = Exam(flights, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", *(ppSchedule + i));
	}
	return 0;
}

char** Exam(FLIGHT* pFlights, int nFlights)
{
	if (!pFlights || !nFlights)
	{
		return 0;
	}
	char** ppArrivals = (char**)malloc(nFlights * sizeof(char*));
	for (int i = 0; i < nFlights; i++)
	{
		int hdur = (pFlights[i].Departure.Hour + pFlights[i].Duration.hours); //Duration of flight in hours
		int mdur = (pFlights[i].Departure.Min + pFlights[i].Duration.mins); //Duration of flight in minutes
		if (pFlights[i].TimeZone < 0)
		{
			hdur -= pFlights[i].TimeZone; //Remove the hours of difference
			hdur += 2; //Timezone in Estonia
		}
		else if (pFlights[i].TimeZone > 2)
		{
			hdur -= pFlights[i].TimeZone - 2;
		}
		else if (pFlights[i].TimeZone < 2)
		{
			hdur += pFlights[i].TimeZone;
		}
		int depday = pFlights[i].Departure.day; //day of departure
		char* depmonth = pFlights[i].Departure.month; //month of departure
		if (mdur > 60)
		{
			hdur += 1;
			mdur -= 60;
		}
		if (hdur > 24)
		{
			depday += 1;
			hdur -= 24;
		}
		struct tm arrival;
		const char* months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		int imonth = 0;
		for (; imonth < 12; imonth++)
		{
			if (!strcmp(depmonth, months[imonth]))
			{
				arrival.tm_mon = imonth;
				break;
			}
		}
		arrival.tm_year = pFlights[i].Departure.year - 1900;
		arrival.tm_mday = depday;
		arrival.tm_hour = hdur;
		arrival.tm_min = mdur;
		arrival.tm_sec = 0;
		char buff[100];
		mktime(&arrival);
		strftime(buff, sizeof(buff), "%d-%m-%Y %H:%M:%S", &arrival);
		*(ppArrivals + i) = (char*)malloc(strlen(buff) + strlen(pFlights[i].pStartingPoint) + strlen("From  arrives at ") + 1);
		strcpy(*(ppArrivals + i), ("From "));
		strcat(*(ppArrivals + i), pFlights[i].pStartingPoint);
		strcat(*(ppArrivals + i), " arrives at ");
		strcat(*(ppArrivals + i), buff);
	}
	return ppArrivals;
}
