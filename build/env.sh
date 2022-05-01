#!/bin/sh

# Setup toolchains
# Export the environment
export ARCH=arm64
export CROSS_COMPILE=/opt/gcc-linaro-6.4.1-2017.11-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
export PATH=$PATH:/opt/gcc-linaro-6.4.1-2017.11-x86_64_aarch64-linux-gnu/bin/
