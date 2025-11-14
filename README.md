QA - Multi-purpose Tool Application
A versatile C++ application that provides both graphical and command-line interfaces for file management operations with basic encryption capabilities.

Features
Graphical Interface (Default)
Complete GUI: Full-featured SFML-based graphical interface

File Operations: Create, read, append, delete, and rename files

Encryption Support: XOR-encrypted binary file operations

Visual Feedback: Real-time output display and interactive controls

Background Support: Custom background image support

Command Line Interface
Full Functionality: Complete command-line interface with all features

Text File Operations: Create, read, append, delete, and rename text files

Binary File Operations: Encrypted read/write/append/delete with XOR encryption

File Management: List all files, batch operations

Interactive Shell: User-friendly menu system

Quick Start
Method 1: Graphical Interface (Recommended)
Download the latest pre-compiled binary from the Releases page

Extract the ZIP file

Run QA.exe - it will automatically start with the full graphical interface

All required DLLs are included

Method 2: Command Line Interface
Open terminal/command prompt in the executable directory

Run: QA.exe shell

Use the interactive menu system

Installation & Building from Source
Prerequisites
SFML 2.6.1 - Multimedia library for graphics, windowing, and system operations

CMake 3.8+ - Build system

C++23 Compatible Compiler - Visual Studio 2019+ recommended

Optional Dependencies
MySQL - Database support (currently redundant in this version)

Build Instructions
Step 1: Configure SFML
Download SFML 2.6.1 from SFML Official Website

Extract SFML to your preferred location

Important: Update the SFML path in CMakeLists.txt:

cmake
set(SFML_ROOT "YOUR_SFML_PATH_HERE")  # Change this to your actual SFML path
Step 2: Build with CMake
bash
# Configure the project
cmake -B build -S .

# Build the executable
cmake --build build --config Release
The executable will be generated in the build/Release directory.

Usage
Graphical Interface Operations
The GUI provides a comprehensive interface with:

Input Box: Enter commands in format: choice/filename|content

Output Box: Real-time operation results and file contents

Clear Button: Clear output display

Background Support: Custom background images (place QA.png in database directory)

Command Format Examples:
Write: 0/mynote|Hello World

Read: 8/mynote|

Rename: 6/oldname|newname-

List All: 10/|

Help: help/|

Command Line Operations
When running QA.exe shell, you get access to:

text
0. write: Save content to a notebook file (overwrites existing)
1. append: Append content to a notebook file
2. read: Read content from a notebook file
3. delete: Delete a notebook file
4. listAll: List all notebook files
5. Binary encrypted write: Save encrypted content
6. Binary encrypted read: Read encrypted content
7. Binary encrypted append: Append encrypted content
8. Binary encrypted delete: Delete encrypted file
9. rename: Rename a notebook file
10. Binary encrypted rename: Rename an encrypted file
test: Launch graphical interface
help: Display help message
q: Exit the application
File Storage
The application automatically creates and uses a database directory:

Primary: D:\database\

Fallback: C:\database\

All files are stored with appropriate extensions:

Text files: .txt

Encrypted binary files: .txt (with XOR encryption)

Encryption
Binary files use simple XOR encryption (0xAA key) for basic data protection:

Encryption: Each byte is XORed with 0xAA

Decryption: Same operation restores original content

Purpose: Provides elementary security for casual use

Troubleshooting
Common Issues
SFML Path Error (When building from source):

Ensure the SFML path in CMakeLists.txt matches your installation directory

Verify SFML 2.6.1 is properly installed

Missing DLLs (When building from source):

Copy required SFML DLLs to the same directory as the executable

Required DLLs: sfml-graphics-2.dll, sfml-window-2.dll, sfml-system-2.dll

Font Issues:

The application uses simsun.ttc from Windows fonts directory

If unavailable, it will fall back to system default fonts

Background Image:

Place QA.png in your database directory for custom background

Supported formats: PNG, JPG, BMP

Launch Modes
Default: QA.exe - Starts graphical interface directly

CLI Mode: QA.exe shell - Starts command-line interface

GUI from CLI: Type test in CLI to launch graphical interface

Development Status
✅ Graphical Interface: Fully functional and feature-complete

✅ Command Line Interface: Fully functional and stable

✅ File Operations: Complete with text and binary support

✅ Encryption: Basic XOR encryption implemented

✅ Background Support: Custom background images

❌ MySQL Integration: Currently redundant, planned for future versions

File Structure
text
QA/
├── QA.exe                 # Main executable
├── sfml-graphics-2.dll    # SFML graphics module
├── sfml-window-2.dll      # SFML window module
├── sfml-system-2.dll      # SFML system module
├── CMakeLists.txt         # Build configuration
├── QA.h                   # Main header file
├── QA.cpp                 # Main source file
└── CMakePresets.json      # CMake presets
Contributing
This project is open for contributions! Areas of interest:

Enhancing the graphical interface

Improving encryption methods

Adding new file formats

Performance optimizations

License
This project is provided as-is for educational and personal use.

Note: The pre-compiled Windows binary includes all necessary DLLs and is ready to run without additional setup. Choose between the beautiful graphical interface or the powerful command-line interface based on your needs!

