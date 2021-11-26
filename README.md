**ngine** is nothing more than opengl playground at the moment. I am learning things as this repository goes so there will be lots of problems.

# Running

On linux just go to cmake dir and create makefile

```sh
cd cmake
cmake ..
make
```

Then you can run binary

```sh
/build/ngine
```

---

**Dependencies:**

-   [GLFW](https://www.glfw.org/) - Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop.
-   [GLAD](https://github.com/Dav1dde/glad) - library that loads pointers to OpenGL functions at runtime, core as well as extensions.
-   [spdlog](https://github.com/gabime/spdlog) - Very fast, header-only/compiled, C++ logging library

Dev dependencies:

-   [CPM](https://github.com/cpm-cmake/CPM.cmake) - CMake script that adds dependency management capabilities to CMake.
