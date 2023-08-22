
# Ping Checker

Check your ping with this application or ping a specific website.


## Installation

### Windows

Download Ping-Checker from [Releases](https://github.com/mcshept/Ping-Checker/releases/latest). Execute the .exe file or download the .zip file, extract it and put it anywhere you want. After that open system environment variables and add to path the folder path. Now you can run `check`.

### Linux

Download Ping-Checker from [Releases](https://github.com/mcshept/Ping-Checker/releases/latest) (tested on Debian and Ubuntu). Extract the .tar.gz in any directory you want. After that navigate to **/check/bin**. There you'll find a file called **build.sh**. Execute it by typing
```sh
$ ./build.sh
```
Then copy the absolute path of bin and open your Terminal. Enter following command
```sh
$ export PATH="$PATH:COPIED_PATH"
```
You should now be able to use the ping checker when and wherever you want.


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
| `-i` | To get some information about the program |
| `-v` | To get the current version |


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

