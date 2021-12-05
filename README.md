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

# Code conduct

At the moment I am going to write this as object oriented as possible in resonable way. If there is really no point in making a class just define this as static method or define namespace (or use existing one) in which functions from a certain category will be stored.

Naming convention should follow this rules:

1. Use **Captial** letter for following elements:

-   filenames
-   calss, struct or enum names
-   class/struct methods
-   namespace
-   function names

2. Use **lowercase** for:

-   variables names
-   class and structs member names (for example `m_AppWidnow`)

3. Use **UPPERCASE** for all macros and defines

If something is unclear just see files for reference.

---

**Dependencies:**

-   [GLFW](https://www.glfw.org/) - Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop.
-   [GLAD](https://github.com/Dav1dde/glad) - library that loads pointers to OpenGL functions at runtime, core as well as extensions.
-   [spdlog](https://github.com/gabime/spdlog) - Very fast, header-only/compiled, C++ logging library
-   [glm](https://github.com/g-truc/glm) - is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specifications.

Dev dependencies:

-   [CPM](https://github.com/cpm-cmake/CPM.cmake) - CMake script that adds dependency management capabilities to CMake.
