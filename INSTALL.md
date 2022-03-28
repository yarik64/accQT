## Build instructions for ALT-Linux using CMake

### Clone source code

    git clone https://github.com/yarik64/accQT.git

### Create build environment

	mkdir build
	cd build && cmake .. && make -j `nproc`


## Build instruction for ALT-Linux using Gear

### Clone source code

    git clone https://github.com/yarik64/accQT.git

### Install development packages ### not working yet

    cat .gear/example.spec | grep BuildRequires | awk '{ print $2; }' | xargs apt-get install -y

### Build using Gear

    gear-rpm -ba
