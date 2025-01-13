FROM ubuntu:20.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    ffmpeg \
    libc6 \
    libstdc++6 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY . /app

# Run the build script
RUN chmod +x scripts/automation/build_and_run.sh
CMD ["./scripts/automation/build_and_run.sh"]