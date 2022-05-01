FROM  ubuntu:20.04
LABEL mainter="hoahiepk10@gmail.com"

# Install dependency packages
RUN apt-get update && \
    apt-get install -y git libncurses-dev gawk flex bison openssl libssl-dev dkms libelf-dev \
    libudev-dev libpci-dev libiberty-dev autoconf axel bc

# Prepare toolchain
ENV GCC_VERSION=gcc-linaro-6.4.1-2017.11-x86_64_aarch64-linux-gnu
ENV GCC_LINK=https://releases.linaro.org/components/toolchain/binaries/latest-6/aarch64-linux-gnu/

RUN bash -c "cd /opt && \
            axel -n 8 ${GCC_LINK}/${GCC_VERSION}.tar.xz && \
            tar xvf ${GCC_VERSION}.tar.xz && \
            rm -rf ${GCC_VERSION}.tar.xz"
