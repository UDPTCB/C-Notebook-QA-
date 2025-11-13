// QA.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#pragma comment(lib, "D:\\Sever\\MySQL\\Server9.5\\lib\\libmysql.lib")
#include <windows.h>



#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <filesystem>
#include <memory>
#include "D:\Sever\MySQL\Server9.5\include\mysql.h"
#include <limits>
#include <exception>
#include <thread>

// 最后包含 SFML
#include <SFML/System/Utf.hpp>
#include <SFML/Graphics.hpp>

// 库链接放在最后
#pragma comment(lib, "D:\\Sever\\MySQL\\Server9.5\\lib\\libmysql.lib")
#pragma comment(lib, "D:\\CL\\eeeee\\QA\\SFML-2.6.1\\lib\\sfml-graphics.lib")
#pragma comment(lib, "D:\\CL\\eeeee\\QA\\SFML-2.6.1\\lib\\sfml-window.lib")
#pragma comment(lib, "D:\\CL\\eeeee\\QA\\SFML-2.6.1\\lib\\sfml-system.lib")
// TODO: 在此处引用程序需要的其他标头。
