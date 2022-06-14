#!/bin/bash

WORK_DIR=$(pwd)
KERNEL_SRC_DIR=${WORK_DIR}/linux-5.4.70
MODULES_DIR="modules_imx"

# Apply defconfig 
cp ${WORK_DIR}/build/config ${KERNEL_SRC_DIR}/arch/arm64/configs/audio_defconfig

# Go to kernel source
# Setup toolchains
cd ${KERNEL_SRC_DIR}
source ../build/env.sh

# Compile the kernel
make audio_defconfig
make -j$(nproc)

# Compile the modules
if [ -d "$MODULES_DIR" ]; then
    mkdir ${MODULES_DIR}
fi
make modules_install INSTALL_MOD_PATH=${MODULES_DIR}

# Back to workdir
cd ${WORK_DIR}