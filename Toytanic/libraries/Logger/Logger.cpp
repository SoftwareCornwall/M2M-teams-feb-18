#include "Arduino.h"
#include "Logger.h"

Logger::Logger()
{
  Serial.begin(115200);
}

void Logger::log(Level level, const char *text)
{
  Serial.println(text);
}

void Logger::log(const char *text)
{
  log(Level::detail, text);
}
