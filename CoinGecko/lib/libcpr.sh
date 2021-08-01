# Build CPR Library
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libssl-dev 
git clone https://github.com/whoshuu/cpr
cd cpr
mkdir build && cd build
cmake ..
make
sudo make install
