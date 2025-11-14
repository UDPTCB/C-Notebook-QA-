# CMakeList.txt: QA 的 CMake 项目
cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("QA")

# === 添加 SFML 配置 ===
# 使用预编译的 SFML 2.6.1
set(SFML_ROOT "D:/CL/eeeee/QA/SFML-2.6.1")  # 修改为你的预编译 SFML 路径
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIB_DIR "${SFML_ROOT}/lib")
set(SFML_BIN_DIR "${SFML_ROOT}/bin")

# 手动设置 SFML 库
set(SFML_LIBRARIES
    "${SFML_LIB_DIR}/sfml-graphics.lib"
    "${SFML_LIB_DIR}/sfml-window.lib" 
    "${SFML_LIB_DIR}/sfml-system.lib"
)

# 设置 SFML DLL 文件
set(SFML_DLLS
    "${SFML_BIN_DIR}/sfml-graphics-2.dll"
    "${SFML_BIN_DIR}/sfml-window-2.dll"
    "${SFML_BIN_DIR}/sfml-system-2.dll"
)

# === 添加 MySQL 配置 ===
set(MYSQL_ROOT "D:/Sever/MySQL/Server9.5")
set(MYSQL_INCLUDE_DIR "${MYSQL_ROOT}/include")
set(MYSQL_LIB_DIR "${MYSQL_ROOT}/lib")

# 检查 MySQL 头文件是否存在
if(EXISTS "${MYSQL_INCLUDE_DIR}/mysql.h")
    message(STATUS "Found MySQL include at: ${MYSQL_INCLUDE_DIR}")
else()
    message(WARNING "MySQL include not found at: ${MYSQL_INCLUDE_DIR}")
endif()

# 检查库文件
file(GLOB MYSQL_LIBS "${MYSQL_LIB_DIR}/libmysql*")
if(MYSQL_LIBS)
    message(STATUS "Found MySQL libraries at: ${MYSQL_LIB_DIR}")
else()
    message(WARNING "MySQL libraries not found at: ${MYSQL_LIB_DIR}")
endif()

# 将源代码添加到此项目的可执行文件。
add_executable (QA "QA.cpp" "QA.h" "app.rc")

# 添加 SFML 包含路径和链接
target_include_directories(QA PRIVATE ${SFML_INCLUDE_DIR})
target_link_directories(QA PRIVATE ${SFML_LIB_DIR})
target_link_libraries(QA PRIVATE ${SFML_LIBRARIES})

# 添加 MySQL 包含路径
target_include_directories(QA PRIVATE ${MYSQL_INCLUDE_DIR})

# 添加 MySQL 库路径和链接
target_link_directories(QA PRIVATE ${MYSQL_LIB_DIR})
target_link_libraries(QA PRIVATE libmysql)

target_compile_features(QA PRIVATE cxx_std_23)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QA PROPERTY CXX_STANDARD 23)
endif()

# === 自动复制 DLL 文件到输出目录 ===
# 复制 SFML DLL 文件
add_custom_command(TARGET QA POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SFML_BIN_DIR}/sfml-graphics-2.dll"
        $<TARGET_FILE_DIR:QA>
)

add_custom_command(TARGET QA POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SFML_BIN_DIR}/sfml-window-2.dll"
        $<TARGET_FILE_DIR:QA>
)

add_custom_command(TARGET QA POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SFML_BIN_DIR}/sfml-system-2.dll"
        $<TARGET_FILE_DIR:QA>
)

# 如果有 MySQL DLL 也需要复制
if(EXISTS "${MYSQL_LIB_DIR}/libmysql.dll")
    add_custom_command(TARGET QA POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_LIB_DIR}/libmysql.dll"
            $<TARGET_FILE_DIR:QA>
    )
endif()