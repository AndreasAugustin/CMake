Project setup
=============

# Poject setup Basics

## First lines

```cmake
cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]] [FATAL_ERROR])
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [LANGUAGES <language-name>...])
```

### cmake_minimum_required

- Stops if the current version of cmake is lower than the required one.
- The option [FATAL_ERROR] is accepted but ignored by CMake 2.6 and higher.

### project

- The top level **CMakeLists.txt** must contain a direct call to project.
- The <PROJECT_NAME> is the name of the project and stored in the variable PROJECT_NAME and additionally the variables PROJECT_SOURCE_DIR, <PROJECT-NAME>_SOURCE_DIR, PROJECT_BINARY_DIR, <PROJECT-NAME>_BINARY_DIR
- Optional
	- **Version**. Default: empty string.
		- May not be used unless CMP0048 is set to new. (Default for cmake version >= 3.0)
		- Components must be non negative integers.
	- **Languages**. Default: C and CXX
		- C
		- CXX
		- Other (Fortran,..)
		- NONE

### Setting policies

See [https://cmake.org/Wiki/CMake/Policies](https://cmake.org/Wiki/CMake/Policies) for details.
Example:

```cmake
if(POLICY CMP0048)
 	cmake_policy(SET CMP0048 NEW)
else()
 	message(FATAL_ERROR "!!Policy CMP0048 not known!!")
endif(POLICY CMP0048)
```

### Comments

- Line Comments start with #
- Block comments (Supported cmake version >= 3.0) #[[Add a comment here]]

```cmake
# Hey I am a line comment
# Me too and we work with all cmake versions
cmake_minimum_required(3.0)
#[[ Hey guys, I am a
	multiline comment and
	I talk a lot.
    Sadly I am not available for cmake < 3.0]]
```

### CMake build

Details can be found at [https://cmake.org/cmake/help/v2.8.12/cmake.html](https://cmake.org/cmake/help/v2.8.12/cmake.html). Currently The commands are valid for all cmake versions.

```console
cmake [options] <path-to-source>
cmake [options] <path-to-existing-build>
```

#### Options

##### Variables

```console
-D <var>:<type>=<value>
```

Examles:
```console
- -D CMAKE_BUILD_TYPE=<BUILD_TYPE>
	- DEBUG For debug builds
	- RELEASE For release builds (Default)
- -D CMAKE_INSTALL_PREFIX=<INSTALL_PREFIX>
	- Where to get dependent libs
	- Where to install the targets (Install command need to be set, will be explained later)
	- For Cmake options (will be explained later)
- -D BUILD_SHARED_LIBS=[ON/OFF]
	- ON for building shared libs
	- OFF for building static libs
```

##### Generators

- -G GENERATOR_NAME
- CMake generates files relational to the generator. Available generators: [https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html](https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html)
- Default generator is make

#### Tools

- cmake-gui
- ccmake
- clion

## Debugging

AFAIK there is no cmake debugger available.
Only option I know is to use the message command:

```cmake
message([<mode>] "message to display" ...)
```

It is possible to use variables in the string part.

### Message modes

(none)         = Important information
STATUS         = Incidental information
WARNING        = CMake Warning, continue processing
AUTHOR_WARNING = CMake Warning (dev), continue processing
SEND_ERROR     = CMake Error, continue processing, but skip generation
FATAL_ERROR    = CMake Error, stop processing and generation
DEPRECATION    = CMake Deprecation Error or Warning if variable CMAKE_ERROR_DEPRECATED or MAKE_WARN_DEPRECATED is enabled, respectively, else no message.

### Example

```cmake
# Option only needed once in project. Will be explained later.
# Build with -D <PROJECT_NAME>_CMAKE_DEBUG=ON for enabling output.
option(${PROJECT_NAME}_CMAKE_DEBUG "Set to on if you want some debug output" OFF)
if(${PROJECT_NAME}_CMAKE_DEBUG)
    message(STATUS "[${CMAKE_CURRENT_LIST_DIR}:${CMAKE_CURRENT_LIST_LINE}] "
            "${PROJECT_NAME} creating cmake config file")
endif()
```



# Install

# How finding works

## Variables which need to be set

# Config

## Export

## ConfigVerstion.cmake

## Functions

### Usefull functions


## External project.



