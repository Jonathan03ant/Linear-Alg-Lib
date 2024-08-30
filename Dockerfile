# Use an official Python runtime as a parent image
FROM python:3.12-slim

# Set environment variables
ENV PYTHONUNBUFFERED=1

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /app

# Copy the entire project into the container
COPY . /app

# Install Python dependencies
RUN pip install --upgrade pip
COPY requirements.txt /app/
RUN pip install -r requirements.txt

# Build the C libraries
RUN cd Matrix && make

# Set the PYTHONPATH to include the app directory
ENV PYTHONPATH=/app

# Default command to run tests (can be overridden)
CMD ["python", "Matrix/function_test.py"]

