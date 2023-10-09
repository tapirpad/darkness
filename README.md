# Darkness
Program to adjust screen brightness.

## Install
1. Build the executable using `make`.
2. Copy the executable to file partition that allows setuid binary.
3. Change owner to root and set setuid bit for the binary.

## Usage
Think aobut increasing darkness instead of brightness. See example below.
- To increase brightness by 53:
```
darkness -53
```
- To decrease brightness by 53:
```
darkness 53
```
