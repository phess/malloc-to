# malloc-to
Quick and dirty memory allocator to an arbitrary size

Allocates **and uses** a given number of MiB (mebibytes i.e. 2 ^ 20 bytes).

Use cases: occupy an arbitrary part of system RAM (RSS or resident memory) to see how the system responds.


# Usage
~~~
./malloc-to <memory size to allocate, in MiB>
~~~

# Example usage

Will allocate 1234 MiB of RAM
~~~
$ ./malloc-to 1234
~~~

Once the allotted size is reached, the program will stop allocating more memory and will wait until you press ENTER to quit and thus free up all memory it was using.

# How to build

1. Install a C compiler. (Example given for gcc on a Fedora system.)
~~~
$ sudo dnf -y install gcc
~~~
2. Compile this single-file source-code.
~~~
$ make malloc-to
~~~
