# Lib base64

Base64 encoding/decoding implemented in C

## How to build

```sh
make static

# or

make shared
```

## How to use

```sh
# Place libb64.a/libb64.so in your directory

# Compile your code with
gcc -L /path/to/directory/ -lb64


# If your project structure is like this 

project_dir
┃
┣━ bin
┣━ lib
┃  ┗━ libb64.a
┣━ obj
┗━ src 

# Then

$ gcc -L ./lib/ -lb64
```
