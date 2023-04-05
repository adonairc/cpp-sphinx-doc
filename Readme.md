# Cpp-Sphinx-Doc

Cpp-sphinx-doc is a C++/CMake template project that generates Sphinx documentation from Doxygen annotated C++ code.

## Installation
Before running the CMake script make sure the following packages are installed in your system:
- Python (>= 3.2)
- CMake (>= 3.9)
- Doxygen
- Sphinx
- Breathe

## Usage

1. Clone this repository: 
```
git clone https://github.com/adonairc/cpp-sphinx-doc.git
```
3. Change to the new created directory: 
```
cd cpp-sphinx-doc
```
5. Create and move to the build directory:
```
mkdir build && cd build
```
7. Run CMake:
```
cmake ..
```
9. Compile the documentation:
```
make docs
```

The Sphinx documentation files will be generated at ./build/docs 
