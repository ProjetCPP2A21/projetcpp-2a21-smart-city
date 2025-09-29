# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\events_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\events_autogen.dir\\ParseCache.txt"
  "events_autogen"
  )
endif()
