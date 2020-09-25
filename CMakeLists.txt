cmake_minimum_required(VERSION 3.0)
project(Ext_NaughtsAndCrosses)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(ext_naughtsandcrosses_SRC
  src/main.cpp
  src/NaughtsAndCrosses.cpp
  src/Cell.cpp
  src/Application.cpp
  src/Board.cpp
  src/SquareLayout.cpp
  src/GameGrid.cpp
  src/WinningLinePainter.cpp
)

# Tell CMake to create the helloworld executable
add_executable(ext_naughtsandcrosses ${ext_naughtsandcrosses_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(ext_naughtsandcrosses PRIVATE Qt5::Widgets)

# Install the executable
install(TARGETS ext_naughtsandcrosses DESTINATION bin)