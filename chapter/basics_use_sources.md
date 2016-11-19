## Basics for using sources

A project will include many

### Include directories

#### include_directories

```cmake
include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
```

This will add the specified include files to the whole project.

By default the directories specified will be appended to the current list of directories. This can be changed with the optional argument BEFORE.

The SYSTEM option will tell the compiler that the include dirs are meant as system include dirs.

Arguments to include directories may use generator expressions with the syntax "$<...>"

##### Example for generator expression

```cmake
include_directories(
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/lib/include>
        PUBLIC $<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/lib/include>)
```

The example is for exporting targets. Will be explained later.

#### target_include_directories

Sometimes it is necesarry to seperate the includes related to targets. For example one likes to seperate the install paths for different targets in a project. It is possible to set the includes for special target. The target need to be defined before using the command and must not be an imported target.

```cmake
target_include_directories(<target> [SYSTEM] [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
```

It is also possible to use the generator expressions.

##### Example

Common usage differ between build and install tree.

```cmake
target_include_directories(calc
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/lib/include>
        PUBLIC $<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/lib/include>)
```

### Build Libs

```cmake
# adds a lib with the target <name>
# [STATIC | SHARED] It is commonly said to be bad practice to specify it. 
# You are able to set it with -D BUILD_SHARED_LIBS=[ON | OFF] at cmake build time.
add_library(<name> [STATIC | SHARED | MODULE]
            [EXCLUDE_FROM_ALL]
            source1 [source2 ...])
```

- [STATIC | SHARED | MODULE] Specify which kind of lib you like to build.
- EXCLUCE_FROM_ALL If set target will not be built with the all target.

### Build executables

```cmake
# adds an executable with the target <name>
add_executable(<name> [WIN32] [MACOSX_BUNDLE]
               [EXCLUDE_FROM_ALL]
               source1 [source2 ...])
```

### Linking

```cmake
target_link_libraries(<target> [item1 [item2 [...]]]
                      [[debug|optimized|general] <item>] ...)
```

```cmake
target_link_libraries(<target>
                    <PRIVATE|PUBLIC|INTERFACE> <lib> ...
                    [<PRIVATE|PUBLIC|INTERFACE> <lib> ... ] ...])
```

#### Example

```cmake
target_link_libraries(example
        PRIVATE $<BUILD_INTERFACE:calc>
        PUBLIC $<INSTALL_INTERFACE:calc>)
```