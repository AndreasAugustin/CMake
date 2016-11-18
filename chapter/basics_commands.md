## Basic commands

### Include

Sometimes you want to include some other CMakeLists.txt (for example using templates).

#### include

Load and run CMake code from a file or module.

```cmake
include(<file|module> [OPTIONAL] [RESULT_VARIABLE <VAR>]
                      [NO_POLICY_SCOPE])
```


#### add_subdirectory

Add a subdirectory to the build. CMakeLists.txt need to be present in the directory

```cmake
add_subdirectory(source_dir [binary_dir]
                 [EXCLUDE_FROM_ALL])
```

If the source_dir is not a subdirectory, you need to specify the binary_dir argument.

####

### Option

```cmake
# Can be set during build with -D <OPTION_VARIABLE>=[ON/OFF]
option(<OPTION_VARIABLE> "help string describing option"
       [initial value])
```

- Provides an option for the user to select as **ON** or **OFF**.
- Default is off.

### Set

```cmake
# Sets some build variables.
set(<variable> <value>
    [[CACHE <type> <docstring> [FORCE]] | PARENT_SCOPE])
```

#### Example

For using x11 compiler.

```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
```

#### Type

FILEPATH = File chooser dialog.
PATH     = Directory chooser dialog.
STRING   = Arbitrary string.
BOOL     = Boolean ON/OFF checkbox.
INTERNAL = No GUI entry (used for persistent variables). (Implies FORCE)

#### Cache

Creates a cache variable but does not modify it.

##### Example

If you include another CMakeLists.txt and want to change a default option in the included child cmake file from the parent.

```cmake
# This is in parent CMakeLists.txt
set(${PROJECT_NAME}_I_AM_AN_OPTION ON CACHE BOOL "Set option of child.cmake from parent scope" FORCE)
include(<PATH_TO_CHILD>/child.cmake)
```

```cmake
# This is in child.cmake
option(${PROJECT_NAME}_I_AM_AN_OPTION "Set me to on" OFF)
```

### PARENT_SCOPE

- Each new directory or function creates a new scope. This command will set the value of a variable into the parent directory or calling function (whichever is applicable to the case at hand).
- Cannot be combined with cache.

### Environment variables

```cmake
set( ENV{PATH} /home/andy )
```

### mark_as_advanced

```cmake
mark_as_advanced([CLEAR|FORCE] VAR [VAR2 ...])
```

- Variables will not be shown in any cmake GUIDs unless the show advanced option is on.
- CLEAR advanced variables will change back to unadvanced.

### Set/Option best practices

- Use prefix of PROJECT_NAME
- Capital letters
- Prefix _ for locally used variables
