# Emojicode [ ![Codeship Status for emojicode/emojicode][image-1]][1] [![Join the chat at https://gitter.im/emojicode/emojicode][image-2]][2]

Emojicode is an open source, high-level, multi-paradigm
programming language consisting of emojis. It features Object-Orientation, Optionals, Generics and Closures.

## 👩‍🔬💥💡 Major Changes Ahead 🔥⚠️🚱

The Emojicode source is undergoing some major changes. Expect things to be broken in master. [Check out the 0.5 branch for stable code.][3]

## 🏁 Getting Started

To learn more about the language and get started quickly visit Emojicode’s [documentation][4].

You can easily install Emojicode from our stable prebuilt binaries. [See Installing Emojicode][5] for instructions.

We highly recommend to follow Emojicode’s Twitter account [@Real\_Emojicode][6] to stay up with the latest.

## 🔨 Building from source

If you don’t want to use the prebuilt binaries or want to work on Emojicode, you
can of course also build Emojicode from source.

### Building locally

Prerequisites (earlier versions might work but are not tested):

- clang and clang++ 3.9 or newer, or
- gcc and g++ 7.2 or newer (previous GCC versions are unsuitable due to a bug)
- CMake 3.5.1 or newer and (preferably) Ninja
- Python 3.5.2 or newer (for tests and packaging)
- Allegro 5 to compile the allegro package
  - `sudo apt-get install liballegro5-dev` on Debian/Ubuntu
  - `brew install allegro` on macOS

Steps:

1. Clone Emojicode (or download the source code and extract it) and navigate
  into it:

   ```sh
   git clone https://github.com/emojicode/emojicode
   cd emojicode
   ```

   If you want to build the latest stable version, check it out first. E.g.
   `git checkout v0.5`.

2. Create a `build` directory and run CMake in it:

   ```sh
   mkdir build
   cd build
   cmake .. -GNinja
   ```

   You can specify the heap size in bytes, which defaults to 512MB, with
   `-DheapSize` and the default package search path with
   `-DdefaultPackagesDirectory`.

   You can of course also run CMake in another directory or use another build
   system than Ninja. Refer to the CMake documentation for more information.

3. Build the Compiler and Real-Time Engine:

   ```sh
   ninja
   ```

4. You can now test Emojicode:

   ```sh
   ninja tests
   ```

5. The binaries are ready for use!
   You can the perform a magic installation right away

   ```sh
   ninja magicinstall
   ```

   or just package the binaries and headers properly

   ```sh
   ninja dist
   ```

   To create a distribution archive you must call the dist script yourself
   (e.g. `python3 ../dist.py .. archive`).

### Building in Docker container

This repository comes with two Dockerfiles `DockerfileClang` and
`DockerfileGCC`, which are used by our continuous integration service. However,
you can also use them to build Emojicode.

Prerequisites:
- Docker

Steps:

1. Clone Emojicode (or download the source code and extract it) and navigate
  into it:

   ```sh
   git clone https://github.com/emojicode/emojicode
   cd emojicode
   ```
2. Build and create a container

   ```sh
   docker build -f DockerfileClang -t emojicode_clang .
   docker create --name emojicontainer -ti emojicode_clang bash
   ```

3. Start and enter the container:

   ```sh
   docker start -ai emojicontainer
   ```

4. You can now build Emojicode:

   ```sh
   mkdir build && cd build && cmake .. -GNinja && ninja && ninja tests
   ```

## 📃 License

Emojicode [is licensed under the Artistic License 2.0][8].
If you don’t want to read the whole license, here’s a summary without legal force:

- You are allowed to download, use, copy, publish and distribute Emojicode.
- You are allowed to create modified versions of Emojicode but you may only distribute them on some conditions.
-  The license contains a grant of patent rights and does not allow you to use any trademark, service mark, tradename, or logo.
- Emojicode comes with absolutely no warranty.

[1]:	https://app.codeship.com/projects/209932
[2]:	https://gitter.im/emojicode/emojicode?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge
[3]:	https://github.com/emojicode/emojicode/tree/emojicode-0.5
[4]:	http://www.emojicode.org/docs
[5]:	http://www.emojicode.org/docs/guides/install.html
[6]:	https://twitter.com/Real_Emojicode
[7]:	https://github.com/emojicode/emojicode/blob/master/0.6.md#help-improving-emojicodes-syntax-
[8]:	LICENSE

[image-1]:	https://app.codeship.com/projects/edbc3220-f394-0134-fad2-66135ababc06/status?branch=master
[image-2]:	https://badges.gitter.im/emojicode/emojicode.svg
