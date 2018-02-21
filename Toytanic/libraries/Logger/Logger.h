#ifndef LOGGER_H
#define LOGGER_h

#include "Arduino.h"

class Logger
{
public:
  Logger();
  enum class Level
  {
    none,
    error,
    summary,
    detail
  };

  void log(Level level, const char *text);
  void log(const char *text);
};

#endif
