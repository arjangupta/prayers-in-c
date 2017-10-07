#!/bin/bash

export CC=arm-linux-androideabi-gcc

export CPP=arm-linux-androideabi-cpp

export CXX=arm-linux-androideabi-g++

export LD=arm-linux-androideabi-ld

export AR=arm-linux-androideabi-ar

export RANLIB=arm-linux-androideabi-ranlib

export STRIP=arm-linux-androideabi-strip

export C_INCLUDE_PATH=/Users/matt.scarpino/Library/Android/sdk/ndk-bundle/platforms/android-23/arch-arm/usr/include

export CFLAGS="-nostdlib -fno-builtin"

./configure --with-sysroot=/Users/matt.scarpino/Library/Android/sdk/ndk-bundle/platforms/android-23/arch-arm --build=x86_64 --host=arm-linux-gnueabi --enable-arm-neon=yes --enable-intel-sse=no --enable-powerpc-vsx=no --enable-mips-msa=no --enable-shared=no --enable-static=yes
