# gRPC_server_client_for_image_processing

## Contents
- Space Apocalypse
  - [1. Introduction](#1-introduction)
  - [2. Setup](#2-setup)
  - [3. Run](#3-run)
  - [4. Output](#4-output)

## 1. Introduction
A gRPC server and client to perform rotation and mean filtering to images

## 2. Setup
In order to setup the repo run the following commands.
Clone the repository:
```
git clone https://github.com/Vram97/gRPC_server_client_for_image_processing
```
From the root directory of the repo, run: (This will install all the required libraries for the task)
```
./setup
```
To build the code and generate the client and server executables, run:
```
./build
```

## 3. Run
- To run the server, run:
  ```
  ./server --port <valid port number> --host <valid host name>
  ```
  
- To run the client, run:
  ```
  ./client --port <valid port number> --host <valid host name> --input <path to read image from> --output <path to save to> --rotate <Specify rotate string> --mean(for mean filtering)
  ```
  - The rotate flag has the following options: NONE, NINETY_DEG, ONE_EIGHTY_DEG, TWO_SEVENTY_DEG
  - The mean flag is a boolean flag that you can use if you want to perform mean filtering

## 5. Output
![Working GIF](https://github.com/Vram97/gRPC_server_client_for_image_processing/blob/main/grpc.gif)
