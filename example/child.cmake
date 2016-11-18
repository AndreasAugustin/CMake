# Example for include another cmake file
# option will be changed from parent cmake file.
option(I_AM_AN_OPTION "Set me to on" OFF)

if (I_AM_AN_OPTION)
    message(WARNING "---" Called from ${PROJECT_NAME} CMakeLists.txt and I am in ${CMAKE_CURRENT_LIST_DIR})
endif()