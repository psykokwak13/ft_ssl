# ft_ssl

A C reimplementation of part of the `openssl` program, focusing on the
**MD5** and **SHA-256** cryptographic hashing functions.

Project done as part of the 42 curriculum.

## Table of contents

- [Description](#description)
- [Build](#build)
- [Usage](#usage)
- [Commands](#commands)
- [Flags](#flags)
- [Examples](#examples)
- [Author](#author)

## Description

`ft_ssl` recreates the behavior of the `md5sum` and `sha256sum` utilities, with an
output format inspired by `openssl md5` / `openssl sha256`.

The project implements the hashing algorithms **from scratch**, without using any
external cryptographic library (no `libcrypto`, no `libssl`).

## Build

```bash
make all
```

Generates the `ft_ssl` executable at the root of the project.

Other available rules:

```bash
make clean     # removes object files
make fclean    # removes object files + the executable
make re        # fclean + make
```

## Usage

```bash
./ft_ssl command [flags] [file/string]
```

```
Commands:
md5
sha256

Flags:
-p -q -r -s
```

## Commands

| Command  | Description |
|---|---|
| `md5`    | Computes the MD5 hash (128 bits) of an input |
| `sha256` | Computes the SHA-256 hash (256 bits) of an input |

If no flag is provided, the command reads from `STDIN` and writes to `STDOUT`.

## Flags

| Flag | Effect |
|---|---|
| `-p` | Echoes the `STDIN` input as-is, then prints its checksum |
| `-q` | Quiet mode: only prints the raw hash, without the usual file name/format |
| `-r` | Reverses the output format (hash before the name, like `md5sum`/`sha256sum`) |
| `-s` | Computes the hash of the given string argument |

These flags can be combined, and several `-s`/files can be passed in a single call.

## Examples

```bash
> echo "42 is nice" | ./ft_ssl md5
(stdin)= 35f1d6de0302e2086a4e472266efb3a9

> echo "42 is nice" | ./ft_ssl md5 -p
("42 is nice")= 35f1d6de0302e2086a4e472266efb3a9

> echo "Pity the living." | ./ft_ssl md5 -q -r
e20c3b973f63482a778f3fd1869b7f25

> ./ft_ssl md5 file
MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a

> ./ft_ssl md5 -r file
53d53ea94217b259c11a5a2d104ec58a file

> ./ft_ssl md5 -s "pity those that aren't following baerista on spotify."
MD5 ("pity those that aren't following baerista on spotify.") = a3c990a1964705d9bf0e602f44572f5

> ./ft_ssl sha256 -s "42 is nice"
SHA256 ("42 is nice") = b7e44c7a40c5f80139f0a50f3650fb2bd8d00b0d24667c4c2ca32c88e13b758f
```

## Author
egatien