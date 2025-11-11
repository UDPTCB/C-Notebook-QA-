# CMakeList.txt: QA's CMake project, include source code and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable hot reload for MSVC compiler if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("QA")

# === Add MySQL Configuration ===
# Set MySQL path
set(MYSQL_ROOT "D:/Sever/MySQL/Server9.5")
set(MYSQL_INCLUDE_DIR "${MYSQL_ROOT}/include")
set(MYSQL_LIB_DIR "${MYSQL_ROOT}/lib")

# Check if MySQL header files exist
if(EXISTS "${MYSQL_INCLUDE_DIR}/mysql.h")
    message(STATUS "Found MySQL include at: ${MYSQL_INCLUDE_DIR}")
else()
    message(WARNING "MySQL include not found at: ${MYSQL_INCLUDE_DIR}")
endif()

# Check library files
file(GLOB MYSQL_LIBS "${MYSQL_LIB_DIR}/libmysql*")
if(MYSQL_LIBS)
    message(STATUS "Found MySQL libraries at: ${MYSQL_LIB_DIR}")
else()
    message(WARNING "MySQL libraries not found at: ${MYSQL_LIB_DIR}")
endif()

# Add source code to this project's executable.
add_executable (QA "QA.cpp" "QA.h" "app.rc")

# Add MySQL include path
target_include_directories(QA PRIVATE ${MYSQL_INCLUDE_DIR})

# Add MySQL library path and linking
target_link_directories(QA PRIVATE ${MYSQL_LIB_DIR})
target_link_libraries(QA PRIVATE libmysql)

target_compile_features(QA PRIVATE cxx_std_20)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QA PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
