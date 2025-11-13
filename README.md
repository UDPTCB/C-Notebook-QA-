# QA - Multi-purpose Tool Application

A versatile C++ application that provides both command-line and graphical interfaces for file management operations with basic encryption capabilities.

## Features

### Command Line Interface (Complete)
- **Text File Operations**: Create, read, append, delete, and rename text files
- **Binary File Operations**: Encrypted read/write/append/delete with XOR encryption
- **File Management**: List all files, rename files
- **Database Support**: Automatic directory creation and management

### Graphical Interface (In Development)
- Basic SFML-based GUI
- Text input with file operations
- Visual feedback system
- *Note: GUI functionality is limited and still under development*

## Prerequisites

### Required Dependencies
- **SFML 2.6.1** - Multimedia library for graphics, windowing, and system operations

### Optional Dependencies
- **MySQL** - Database support (currently redundant in this version)

## Installation & Setup

### Method 1: Pre-compiled Binary (Recommended for Windows)
1. Download the latest release from the Releases page
2. Extract the ZIP file
3. Run `QA.exe` directly - all required DLLs are included

### Method 2: Build from Source

#### Step 1: Configure SFML
- Download SFML 2.6.1 from [SFML Official Website](https://www.sfml-dev.org/)
- Extract SFML to your preferred location
- **Important**: Update the SFML path in `CMakeLists.txt`:
  ```cmake
  set(SFML_ROOT "YOUR_SFML_PATH_HERE")  # Change this to your SFML path
  ```

#### Step 2: Build with CMake
```bash
# Configure
cmake -B build -S .

# Build
cmake --build build --config Release
```

The executable will be generated in the `build` directory.

## Usage

### Starting the Application
Run the application from command line:
```bash
./QA
```

### Command Line Operations
```
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
help: Display help message
q: Exit the application
```

### Launching Graphical Interface
From the application's command line interface, type:
```
test
```

**Note**: The graphical interface is experimental and has limited functionality compared to the complete command-line interface.

## File Storage

The application automatically creates and uses a database directory:
- Primary: `D:\database\`
- Fallback: `C:\database\`

All files are stored with `.txt` extension for text files and encrypted binary format for secure files.

## Encryption

Binary files use simple XOR encryption (0xAA key) for basic data protection. This provides elementary security for casual use.

## Troubleshooting

### Common Issues

1. **SFML Path Error**:
   - Ensure the SFML path in `CMakeLists.txt` matches your installation directory
   - Verify SFML 2.6.1 is properly installed

2. **Missing DLLs** (when building from source):
   - Copy required SFML DLLs to the same directory as the executable
   - Required DLLs: `sfml-graphics-2.dll`, `sfml-window-2.dll`, `sfml-system-2.dll`

3. **GUI Not Working**:
   - The graphical interface is still in development
   - Use command-line interface for full functionality

## Development Status

- ✅ **Command Line Interface**: Fully functional and stable
- 🚧 **Graphical Interface**: Under development, basic functionality only
- ✅ **File Operations**: Complete
- ✅ **Encryption**: Basic XOR encryption implemented
- ❌ **MySQL Integration**: Currently redundant, planned for future versions

## Contributing

This project is open for contributions, especially for:
- Improving the graphical interface
- Enhancing encryption methods
- Adding new features

## License

This project is provided as-is for educational and personal use.

---

**Note**: The pre-compiled Windows binary includes all necessary DLLs and is ready to run without additional setup.
