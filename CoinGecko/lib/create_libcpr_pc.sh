# Install OpenSSL
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libssl-dev

# Build CPR Library
git clone https://github.com/whoshuu/cpr
cd cpr
mkdir build && cd build
cmake ..
make
sudo make install

# Copy Library to Local
cp -ar lib/. ../../../lib/lib_pc
