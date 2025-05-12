# Maths

[![Unix](https://github.com/SapphireSuite/Maths/actions/workflows/test_unix.yml/badge.svg)](https://github.com/SapphireSuite/Maths/actions/workflows/test_unix.yml)
[![Windows](https://github.com/SapphireSuite/Maths/actions/workflows/test_windows.yml/badge.svg)](https://github.com/SapphireSuite/Maths/actions/workflows/test_windows.yml)
[![MacOS](https://github.com/SapphireSuite/Maths/actions/workflows/test_macos.yml/badge.svg)](https://github.com/SapphireSuite/Maths/actions/workflows/test_macos.yml)

Sapphire Suite's C++ Maths library.\
Links to the **official** [documentation](https://SapphireSuite.github.io/Maths/) and [wiki](https://github.com/SapphireSuite/Maths/wiki) for advanced details.

# How To Use

### Collection Headers
```cpp
#include <SA/Collections/Maths> 		// Include all modules

#include <SA/Collections/Angle>
#include <SA/Collections/Algorithms>
#include <SA/Collections/Space> 		// Vec2, Vec3, Vec4, and Quaternion.
#include <SA/Collections/Matrix> 		// Mat3 and Mat4
#include <SA/Collections/Transform>
```


## CMake
Add the subdirectory to the build tree and link the library to your taget:
```cmake
add_subdirectory(Maths)
target_link_libraries(<target> <link> SA_Maths)
```



# Authors

**Maxime "mrouffet" ROUFFET** - main developer (maximerouffet@gmail.com)

## Special Thanks

[Guillaume JUSTE](https://github.com/GuillaumeJuste) - LookAt/View/InverseView matrix optimization.
