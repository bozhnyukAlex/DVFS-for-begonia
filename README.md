# Stochastic DVFS for begonia kernel 
## About
This project is an implementation of a stochastic DVFS algorithm for Xiaomi redmi note 8 pro smartphone. The algorithm is developed by the Faculty of Mathematics and Mechanics of St Petersburg University.

The kernel source is taken from [AgentFabulous begonia kernel project](https://github.com/AgentFabulous/begonia). 

## Build using [Proton Clang](https://github.com/kdrag0n/proton-clang) compiler
**For ubuntu 18.04:**

Setup Build Environment:

```
sudo apt-get install git ccache automake flex lzop bison \
gperf build-essential zip curl zlib1g-dev zlib1g-dev:i386 \
g++-multilib python-networkx libxml2-utils bzip2 libbz2-dev \
libbz2-1.0 libghc-bzlib-dev squashfs-tools pngcrush \
schedtool dpkg-dev liblz4-tool make optipng maven libssl-dev \
pwgen libswitch-perl policycoreutils minicom libxml-sax-base-perl \
libxml-simple-perl bc libc6-dev-i386 lib32ncurses5-dev \
x11proto-core-dev libx11-dev lib32z-dev libgl1-mesa-dev xsltproc unzip
```

Download Proton Clang compiler:
```
git clone https://github.com/kdrag0n/proton-clang.git --depth=1

export PATH="$(pwd)/proton-clang/bin:$PATH"
export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
export CROSS_COMPILE_ARM32=arm-linux-gnueabi-
```
Build kernel:
```
make O=out begonia_user_defconfig
make -j$(nproc --all) O=out CC=clang
```
