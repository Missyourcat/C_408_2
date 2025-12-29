# C_408_2 Data Structures Project - AI Agent Instructions

## Project Overview
This is a C++ data structures learning project implementing fundamental algorithms and data structures (sequential lists, linked lists, stacks, queues, binary trees) using C-style programming in C++11.

## Architecture
- **Core Pattern**: Each data structure is implemented as a struct with operations as standalone functions
- **Genericity**: Use `typedef int ElemType` for element types; change this typedef to adapt structures for different data types
- **Memory Management**: Manual allocation with `malloc`/`calloc`; no RAII or smart pointers
- **Key Files**:
  - `chapter_01/demo_*.cpp`: Individual demo implementations
  - `chapter_01/demo_06_BiTree/demo_BiTree.h`: Header with struct definitions and function declarations

## Build System
- **Tool**: CMake with MinGW g++ compiler
- **Configuration**: `CMakeLists.txt` defines separate executables for each demo
- **Output**: Executables built to `exe/` subdirectories under each demo folder
- **Command**: Use VS Code's "C/C++: g++.exe build active file" task or CMake build

## Coding Conventions
- **Indexing**: 1-based positioning for list operations (insert/delete at position 1-based)
- **Function Signatures**: 
  - Modifying operations take struct references: `bool list_insert(SqList &L, int Position, ElemType element)`
  - Output parameters use references: `bool list_delete(SqList &L, int Position, ElemType &del)`
- **Error Handling**: Return `bool` for success/failure; no exceptions
- **I/O**: Mix of `printf` (C-style) and `std::cout` (C++-style); prefer `printf` for formatted output
- **Memory Allocation**: Use `calloc` for zero-initialized memory: `pnew = (BiTree)calloc(1, sizeof(BiTNode))`

## Common Patterns
- **Struct Definitions**: 
  ```cpp
  typedef struct{
      ElemType data[MaxSize];
      int length;
  }SqList;
  ```
- **Traversal Functions**: Recursive for trees, iterative for linear structures
- **Queue Usage**: Custom linked queue for level-order tree construction
- **Input Handling**: Read from `std::cin` for tree building, process character by character

## Development Workflow
1. Implement data structure in dedicated `.cpp` file under `chapter_01/`
2. Add executable target to `CMakeLists.txt` if needed
3. Build using CMake or VS Code task
4. Run executable from `exe/` directory
5. Test with sample inputs matching the data structure's expected format

## Key Examples
- **Sequential List**: `demo_01_sqlist.cpp` - insert/delete/lookup operations
- **Binary Tree**: `demo_06_BiTree/` - recursive traversals, level-order construction from input string
- **Positioning**: Always validate 1-based positions before operations</content>
<parameter name="filePath">d:\Code\C_Math_Mode\C_408_2\.github\copilot-instructions.md