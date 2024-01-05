# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set the working directory in the container
WORKDIR /usr/src/app

# Install any needed packages specified in the instructions
RUN apt-get update && apt-get install -y \
    git \
    cmake \
    libssl-dev \
    libcurl4-openssl-dev \
    uncrustify \
    build-essential

# Clone the Kubernetes client C repository
RUN git clone https://github.com/kubernetes-client/c
ENV CLIENT_REPO_ROOT=/usr/src/app/c

# Clone and build libwebsockets
RUN git clone https://libwebsockets.org/repo/libwebsockets --depth 1 --branch v4.2-stable && \
    cd libwebsockets && \
    mkdir build && \
    cd build && \
    cmake -DLWS_WITHOUT_TESTAPPS=ON -DLWS_WITHOUT_TEST_SERVER=ON -DLWS_WITHOUT_TEST_SERVER_EXTPOLL=ON \
          -DLWS_WITHOUT_TEST_PING=ON -DLWS_WITHOUT_TEST_CLIENT=ON -DCMAKE_C_FLAGS="-fpic" -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
    make && \
    make install

# Clone and build libyaml
RUN git clone https://github.com/yaml/libyaml --depth 1 --branch release/0.2.5 && \
    cd libyaml && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_TESTING=OFF  -DBUILD_SHARED_LIBS=ON .. && \
    make && \
    make install

# Set the working directory to the Kubernetes directory in the client repository
WORKDIR ${CLIENT_REPO_ROOT}/kubernetes

# Build the Kubernetes client
RUN mkdir build && \
    cd build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
    make && \
    make install

RUN cd ${CLIENT_REPO_ROOT}/examples/configmap

RUN cd ../examples/ && ls && pwd && make all

# Mount the build directory on the host
# VOLUME ["/usr/src/app"]

# Define environment variable
ENV NAME KubernetesClientC

# Run shell when the container launches
CMD ["/bin/bash"]

# docker build -t kubernetes_client_c .

# docker run -it --name kubernetes_client_c_instance kubernetes_client_c

# docker cp kubernetes_client_c_instance:/usr/src/app/kubernetes/build/ build/
# docker cp kubernetes_client_c_instance:/usr/src/app/examples/ build/

# cp libkubernetes.so /usr/local/lib
# sudo ldconfig