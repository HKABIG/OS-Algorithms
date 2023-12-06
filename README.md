# OS-Algorithms
# System Programming Project

This project encompasses various system programming concepts implemented in C, covering process management, file operations, and resource allocation algorithms.

## Introduction

This project demonstrates system programming concepts using C, covering a variety of topics such as process management, file operations, and resource allocation algorithms. Additionally, it includes basic Bash scripts for system-related tasks.

## Features

- **Process Management:** Implementations of process creation, parent-child relationships, and concepts like orphan and zombie processes.
- **File Operations:** Examples of file creation, reading, writing, linking, and obtaining file information.
- **Resource Allocation Algorithms:** Illustrations of avoidance and detection methods for handling resource allocation in a multi-process system.
- **Basic Bash Scripts:** Simple Bash scripts to perform system-related tasks.

## Code Sections

### Process Management

- `process_management.c`: Demonstrates basic process creation, parent-child relationships, and concepts like orphan and zombie processes.

### File Operations

- `file_operations.c`: Illustrates file creation, reading, writing, linking, unlinking, and obtaining file information.

### Resource Allocation Algorithms

- `resource_allocation.c`: Implements the Banker's algorithm for resource allocation, focusing on both avoidance and detection strategies.

### Basic Bash Scripts

- `armstrong.sh`: A Bash script for [e.g. Find Armstrong number].
- `count_vowels.sh`: Another Bash script for [e.g. Finding vowels count in a file].

## Installation

Clone the repository to your local machine and compile the C programs using a C compiler.

```bash
git clone https://github.com/your_username/system-programming-project.git
cd system-programming-project
gcc process_management.c -o process_management
gcc file_operations.c -o file_operations
gcc resource_allocation.c -o resource_allocation
```

## Usage 
- Run Compiled C programs:
```bash
./process_management
./file_operations
./resource_allocation
```

- Execute Bash Scripts:
```bash
bash basic_script_1.sh
bash basic_script_2.sh
```

## Contributing 
- Feel free to contribute by submitting bug reports, feature requests, or code contributions. Follow these steps:
  - Fork the repository.
  - Create a new branch: git checkout -b feature-name.
  - Commit your changes: git commit -am 'Add feature'.
  - Push to the branch: git push origin feature-name.
  - Submit a pull request.

