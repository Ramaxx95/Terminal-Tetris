find_package(SDL2 REQUIRED)

if(OFF)
	find_package(SDL2_image REQUIRED)
endif()

if(OFF)
	find_package(SDL2_ttf REQUIRED)
endif()

if(OFF)
	find_package(SDL2_mixer REQUIRED)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/SDL2ppTargets.cmake")
