#!/bin/bash
echo "Starting build process..."

# Define the build directory
BUILD_DIR="build"

# Get the current script directory to handle relative paths correctly
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
    echo "Created build directory: $BUILD_DIR"
fi

# Compile individual files with correct paths
echo "Compiling modules..."
g++ -c -I"$SCRIPT_DIR/../../core/modules/scene_renderer" -I"$SCRIPT_DIR/../../assets/animations/characters" -I"$SCRIPT_DIR/../../core/modules/motion_blur" \
    -I"$SCRIPT_DIR/../../core/modules/sound_fx" -I"$SCRIPT_DIR/../../core/utils" -I"$SCRIPT_DIR/../../" \
    "$SCRIPT_DIR/../../core/main.cpp" -o "$BUILD_DIR/main.o"
g++ -c -I"$SCRIPT_DIR/../../core/modules/scene_renderer" -I"$SCRIPT_DIR/../../assets/animations/characters" -I"$SCRIPT_DIR/../../core/modules/motion_blur" \
    -I"$SCRIPT_DIR/../../core/modules/sound_fx" -I"$SCRIPT_DIR/../../core/utils" -I"$SCRIPT_DIR/../../" \
    "$SCRIPT_DIR/../../core/nova.cpp" -o "$BUILD_DIR/nova.o"
g++ -c -I"$SCRIPT_DIR/../../core/modules/scene_renderer" -I"$SCRIPT_DIR/../../assets/animations/characters" -I"$SCRIPT_DIR/../../core/modules/motion_blur" \
    -I"$SCRIPT_DIR/../../core/modules/sound_fx" -I"$SCRIPT_DIR/../../core/utils" -I"$SCRIPT_DIR/../../" \
    "$SCRIPT_DIR/../../core/modules/scene_renderer/scene_manager.cpp" -o "$BUILD_DIR/scene_manager.o"
g++ -c -I"$SCRIPT_DIR/../../core/modules/scene_renderer" -I"$SCRIPT_DIR/../../assets/animations/characters" -I"$SCRIPT_DIR/../../core/modules/motion_blur" \
    -I"$SCRIPT_DIR/../../core/modules/sound_fx" -I"$SCRIPT_DIR/../../core/utils" -I"$SCRIPT_DIR/../../" \
    "$SCRIPT_DIR/../../core/modules/scene_renderer/scene_renderer.cpp" -o "$BUILD_DIR/scene_renderer.o"

# Link object files
echo "Linking object files..."
g++ "$BUILD_DIR/main.o" "$BUILD_DIR/nova.o" "$BUILD_DIR/scene_manager.o" "$BUILD_DIR/scene_renderer.o" -o "$BUILD_DIR/nova_app"

# Run the application
if [ -f "$BUILD_DIR/nova_app" ]; then
    echo "Build complete."
    echo "Running the application..."
    "$BUILD_DIR/nova_app"
else
    echo "Executable not found. Something went wrong."
fi
