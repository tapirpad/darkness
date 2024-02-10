# Darkness
Program to adjust screen brightness.

## Install
1. Modify compiler in `makefile` if necessary.
2. Set `BRIGHTNESS_MIN`, `BRIGHTNESS_MAX`, and `BRIGHTNESS_FILE` in `darkness.cpp` according to your system.
3. build the executable using `make`.
4. Copy the executable to file partition that allows setuid binary.
5. Change owner to root and set setuid bit for the binary.

## Usage
Think about increasing darkness instead of brightness. See example below.
- To increase brightness by 53:
```
darkness -53
```
- To decrease brightness by 53:
```
darkness 53
```
