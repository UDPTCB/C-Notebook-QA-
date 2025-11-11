# C-Notebook-QA-

# QA - Simple Notebook Application

A lightweight and user-friendly notebook application built with C++ for Windows 11 x64 systems. This project demonstrates file handling operations with both plain text and binary encryption capabilities.

## Features

- **Text File Operations**: Create, read, append, and delete notebook files
- **Binary Encryption**: Secure your notes with simple XOR encryption
- **Cross-Drive Support**: Automatically uses D:\database\ or falls back to C:\database\
- **File Management**: List all existing notebooks in the database directory
- **Interactive CLI**: Easy-to-use command-line interface

## Project Structure

- **QA.cpp**: Main application source code
- **QA.h**: Header file with dependencies
- **CMakeLists.txt**: CMake configuration for building the project

## Building the Project

### Prerequisites
- Windows 11 x64
- Visual Studio 2022
- CMake 3.8 or higher
- C++20 or higher
### Build Instructions
1. Clone this repository
2. Open the project in Visual Studio 2022
3. Configure with CMake
4. Build the solution

### Important Note about MySQL Configuration
⚠️ **The MySQL linking in CMakeLists.txt is redundant and can be safely removed.** The current codebase doesn't actually use MySQL functionality - the include directive and library linking were added but never implemented. You can delete these MySQL-related lines from both QA.h and CMakeLists.txt:

**In QA.h:**
```cpp
// Remove this line:
#pragma comment(lib, "D:\\Sever\\MySQL\\Server9.5\\lib\\libmysql.lib")
// And this include:
#include "D:\Sever\MySQL\Server9.5\include\mysql.h"
```

**In CMakeLists.txt:**
Remove the entire MySQL configuration section (lines 14-32) as the application only uses local file storage.

## Usage

After launching the application, you can choose from the following operations:

- **0**: Write (overwrite) content to a notebook
- **1**: Append content to an existing notebook
- **2**: Read content from a notebook
- **3**: Delete a notebook
- **4**: List all notebooks
- **5-8**: Binary encrypted operations (write, read, append, delete)
- **help**: Display help message
- **q**: Exit the application

## Technical Details

- Built with C++20 standard
- Uses modern C++ features like `std::unique_ptr` and `std::filesystem`
- Implements simple XOR encryption (0xAA key) for binary files
- UTF-8 console support for international characters

## License

This project is open source and available under the [MIT License](LICENSE).

---

*Note: This project was originally developed for learning purposes and demonstrates file I/O operations, memory management, and basic encryption techniques in C++.*
