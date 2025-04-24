#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "weather_table.h"
int min_temp(WeatherTable a);
void max_temp_years(WeatherTable a,int output[YEARS]);
void max_rainfall_years(WeatherTable a, month_t output[YEARS]);
#endif