
# Ping Checker

Check your ping with this application or ping a specific website.


## Installation

Download Ping-Checker from [Releases](https://github.com/mcshept/Ping-Checker/releases/latest). Execute the .exe file or download the .zip file, extract it and put it anywhere you want. After that open system environment variables and add to path the folder path. Now you can run `check`.
    
    
## Usage

To check your ping type:

```sh
$ check
```

### Options

| Parameter | Description                |
| :-------- | :------------------------- |
| `-h` | Displays the help menu |
| `-w` `WEBSITE` | To ping the specified website |


## Building

Use CMake or GCC for building.

### CMake

```sh
$ cmake . # For enabling Unicode support: cmake -DENABLE_UNICODE=ON .
```

### GCC

```sh
$ gcc main.c -o check.exe
```

