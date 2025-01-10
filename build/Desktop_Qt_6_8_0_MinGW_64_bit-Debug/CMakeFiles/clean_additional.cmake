# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SiVaK_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SiVaK_autogen.dir\\ParseCache.txt"
  "SiVaK_autogen"
  )
endif()
