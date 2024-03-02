# What is this?
- A simple kd-tree implementation with `raylib` and `web` visualization.

# Requirements
| Name                                        | Version |
|:--------------------------------------------|--------:|
| [Raylib](https://github.com/raysan5/raylib) | `5.1`   |
| clang                                       | `16.0`  |
| gcc                                         | `13.2`  |

# How to run?

## Web

First, build the wasm module.
```console
$ make -B wasm
```

After build, start a http server on wasm folder.

```console
$ cd wasm
$ python -m http.server 3000
```

After start the server, access `localhost:3000` on your browser.

## Linux with Raylib

First, build the raylib binary.
```console
$ make -B raylib
```

After build, run the raylib program.

```console
$ ./build/raylib.out
```
