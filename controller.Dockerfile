# Use the latest version of Ubuntu as the base image
FROM ubuntu:latest

# Set the maintainer label
LABEL maintainer="caio.b.vilar@gmail.com"

# Set environment variables to non-interactive (this will prevent some prompts)
ENV DEBIAN_FRONTEND=non-interactive

# Update package lists, install basic tools, toolchains, stlink-tools, and clean up
RUN apt-get update -y && \
    apt-get install -y --no-install-recommends \
    autoconf \
    automake \
    curl \
    build-essential \
    git \
    libtool \
    make \
    pkg-config \
    ca-certificates \
    software-properties-common \
    clang-format \
    clang-tidy \
    stlink-tools \
    cmake \
    ninja-build && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Install some necessary tools and libraries
RUN apt-get update && \
    apt-get install -y wget libssl-dev

# Download and install the latest CMake
# This is an example of how to download and install the latest version of cmake. The linux
# packages often are behind on versions. 
# Be warned! This will take a while to do. . .
#WORKDIR /tmp
#RUN wget "https://github.com/Kitware/CMake/releases/download/v3.27.7/cmake-3.27.7.tar.gz" \
#    && tar -xzf cmake-3.27.7.tar.gz \
#    && cd cmake-3.27.7 \
#    && ./bootstrap \
#    && make \
#    && make install

# Setup a tool directory in /home/dev and download the ARM toolchain
WORKDIR /home/dev
RUN curl -L https://developer.arm.com/-/media/Files/downloads/gnu-rm/10-2020q4/gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2 | tar xj && \
    echo "export PATH=$PATH:/home/dev/gcc-arm-none-eabi-10-2020-q4-major/bin" >> ~/.bashrc

# Clone, build, and install CppUTest
WORKDIR /home
RUN git clone https://github.com/cpputest/cpputest.git && \
    cd cpputest && \
    ./autogen.sh && \
    ./configure && \
    make install

# Set the CPPUTEST_HOME environment variable
ENV CPPUTEST_HOME=/home/cpputest

# Create and set the working directory to /home/app
WORKDIR /home/app

# Set the default command to bash
CMD ["/bin/bash"]