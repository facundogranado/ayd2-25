#include <stdio.h>
#include <stdlib.h>
#include "weather_utils.h"
#include "weather.h"

int min_temp(WeatherTable a) {
    int min = 0;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._min_temp < min) {
                    min = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return min;
}

void max_temp_years(WeatherTable a, int output[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        int max = 0;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._max_temp > max) {
                    max = a[year][month][day]._max_temp;
                }
            }
        }
        output[year] = max;
    }
}

void max_rainfall_years(WeatherTable a, month_t output[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        int max = 0;
        month_t month_max = january;
        for (month_t month = january; month <= december; ++month) {
            int rainfall = 0;
            for (unsigned int day = 0u; day < DAYS; ++day) {
                rainfall += a[year][month][day]._rainfall;
            }
            if (rainfall > max) {
                max = rainfall;
                month_max = month;
            }
        }
        output[year] = month_max;
    }
}
