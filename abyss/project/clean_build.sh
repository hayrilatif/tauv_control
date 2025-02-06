echo "Removing existing build directory..."
rm -rf build

echo "Creating new build directory..."
mkdir build
cd build || exit 1

echo "Running CMake configuration..."
cmake ..

echo "Building the project..."
cmake --build . --parallel 

cd ..

echo "Generating stubs..."
.venv/bin/python generate_stubs.py

echo "Installing the package..."
pip install -e . --force-reinstall --no-deps

echo "Build and installation complete!"
