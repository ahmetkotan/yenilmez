# Installation Yenilmez Test Framework
The instructions below are described on ubuntu. But it doesn't matter your unix choice. Everything is ok if you got CMake :)

* Check your C Compiler
```bash
apt-get install cmake pkg-config gcc -y
```

* Install Glib (Required)
```bash
apt-get install libglib2.0-dev -y
```

* Build and Install
```bash
mkdir -p build
cd build
cmake ..
make
make install # root permission
```

* Check
```bash
pkg-config --libs libyenilmez
pkg-config --cflags libyenilmez
```

Please see [example](../example) for usage.
