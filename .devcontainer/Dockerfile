FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

RUN apt update \
    && apt -y install python3 python3-pip ruby-bundler ruby-dev \
    && apt -y upgrade

# Install the online-judge-verify-helper
RUN python3 -m pip install --no-cache-dir --break-system-packages online-judge-verify-helper 

# Install the googletest
RUN git clone https://github.com/google/googletest.git \
    && cd googletest && mkdir build && cd build && cmake .. -DBUILD_GMOCK=OFF && make && sudo make install
