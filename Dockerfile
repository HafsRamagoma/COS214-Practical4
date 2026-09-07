FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    make \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt-lists/*

# Set working directory inside container
WORKDIR /workspace

# Copy repository contents into the container
COPY . .

# Build the taskforge executable using your Makefile
RUN make

# Set default execution command
CMD ["./taskforge"]
