FROM mcr.microsoft.com/vscode/devcontainers/base:debian
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update -y && apt install -y \
    build-essential cmake \
    gcc-arm-none-eabi gdb-multiarch binutils-multiarch \
    usbutils openocd