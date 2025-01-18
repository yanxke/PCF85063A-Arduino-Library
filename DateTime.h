#ifndef DATETIME_H
#define DATETIME_H

#include <Arduino.h>
#include "TimeSpan.h"

class DateTime
{
public:
    // Constructors
    DateTime();
    DateTime(uint32_t t);
    DateTime(uint16_t year, uint8_t month, uint8_t day,
             uint8_t hour = 0, uint8_t min = 0, uint8_t sec = 0);
    DateTime(const char *date, const char *time);
    DateTime(const __FlashStringHelper *date, const __FlashStringHelper *time);

    // Accessors
    uint16_t year() const { return yOff + 2000; }
    uint8_t month() const { return m; }
    uint8_t day() const { return d; }
    uint8_t hour() const { return hh; }
    uint8_t minute() const { return mm; }
    uint8_t second() const { return ss; }
    uint8_t dayOfTheWeek() const;


    // Methods
    uint32_t unixtime() const;

    // Operator overloading
    bool operator!=(const DateTime &other) const;
    DateTime operator+(const TimeSpan &span) const;
    DateTime operator-(const TimeSpan &span) const;

private:
    uint8_t yOff, m, d, hh, mm, ss;
};

#endif