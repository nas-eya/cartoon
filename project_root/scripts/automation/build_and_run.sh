#!/bin/bash
echo "Starting build process..."

# Define the build directory
BUILD_DIR="build"

# Get the current script directory to handle relative paths correctly
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/../.."

# Create the build directory if it doesn't exist
if [ ! -d "$SCRIPT_DIR/$BUILD_DIR" ]; then
    mkdir "$SCRIPT_DIR/$BUILD_DIR"
    echo "Created build directory: $SCRIPT_DIR/$BUILD_DIR"
fi

# Navigate to the build directory
cd "$SCRIPT_DIR/$BUILD_DIR"

# Run CMake to configure the project
cmake ..

# Build the project
make

# Run the application
./nova_app
