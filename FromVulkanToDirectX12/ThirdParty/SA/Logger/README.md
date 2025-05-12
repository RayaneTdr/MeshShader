# Logger

[![Unix](https://github.com/SapphireSuite/Logger/actions/workflows/test_unix.yml/badge.svg)](https://github.com/SapphireSuite/Logger/actions/workflows/test_unix.yml)
[![Windows](https://github.com/SapphireSuite/Logger/actions/workflows/test_windows.yml/badge.svg)](https://github.com/SapphireSuite/Logger/actions/workflows/test_windows.yml)
[![MacOS](https://github.com/SapphireSuite/Logger/actions/workflows/test_macos.yml/badge.svg)](https://github.com/SapphireSuite/Logger/actions/workflows/test_macos.yml)

Sapphire Suite's C++ Logger.\
Links to the **official** [documentation](https://SapphireSuite.github.io/Logger/) and [wiki](https://github.com/SapphireSuite/Logger/wiki) for advanced details.



# Quick Use
```cpp
#include <SA/Collections/Debug>
```
## Initialization
See [_Initialization_](https://github.com/SapphireSuite/Logger/wiki/Initialization) for advanced implementation.\
No initialization is required to have **simple** console logging, however, a **one-line** initialization will provide **advanced** console (colors) and file logging.
```cpp
// No initialization

// OR

// Single-thread (thread-unsafe) logger.
// Console Color and file logging.
SA::Debug::InitDefaultLogger();
```

## Macros
See [_Macros_](https://github.com/SapphireSuite/Logger/wiki/Macros) for advanced implementation.

### SA_LOG
Log **anything** converted as a string with default LogLevel, channel, and details.\
See [_SA_LOG_](https://github.com/SapphireSuite/Logger/wiki/Macros#sa_log) for examples and advanced use.
```cpp
SA_LOG(_str, _level = Normal, _channel = Default, _details = "");
```
Example:
```cpp
SA_LOG("Hello, World!");
```
```
[18:44:14][0] {Normal - Default}   main.cpp:50 - int main()
Msg:    Hello, World!
```

### SA_WARN
Log a **warning** on false predicate with default channel and details.\
See [_SA_WARN_](https://github.com/SapphireSuite/Logger/wiki/Macros#sa_warn) for examples and advanced use.
```cpp
SA_WARN(_pred, _channel = Default, _details = "", _postCmd);
```
Example:
```cpp
int myInt = 2;
SA_WARN(myInt == 1, MyChannel, "myInt invalid: might cause issues");
```
```
[18:46:20][0] {Warning - MyChannel}        main.cpp:53 - int main()
Msg:    { myInt == 1 }  evaluated to false!
Dets:   myInt invalid: might cause issues
```

### SA_ERROR
Log an **error** on false predicate with default channel and details.\
See [_SA_ERROR_](https://github.com/SapphireSuite/Logger/wiki/Macros#sa_error) for examples and advanced use.
```cpp
SA_ERROR(_pred, _channel = Default, _details = "", _postCmd);
```
Example:
```cpp
int myInt = 2;
SA_ERROR(myInt == 1, MyChannel, "myInt invalid: possible crash");
```
```
[18:47:25][0] {Error - MyChannel}        main.cpp:53 - int main()
Msg:    { myInt == 1 }  evaluated to false!
Dets:   myInt invalid: possible crash
```

### SA_ASSERT
Assert an **exception** built from **type and parameters** with default channel and details.\
See [_SA_ASSERT_](https://github.com/SapphireSuite/Logger/wiki/Macros#sa_assert) for examples and advanced use.
```cpp
SA_ASSERT((_excType, params...), _channel = Default, _details = "")
```
Example:
```cpp
int myIndex = 7;
int minBound = 2;
int maxBound = 6;

// Throw SA::Exception_OutOfRange.
SA_ASSERT((OutOfRange, myIndex, minBound, maxBound), MyTestChannel, "Access index out of bound!")
```
```
[18:49:22][0] {AssertFailure - MyTestChannel}      main.cpp:53 - int main()
Msg:    Index 'myIndex' [7] is out of range ['minBound';'maxBound'] => [2;6]
Dets:   Access index out of bound!

terminate called after throwing an instance of 'SA::Exception_OutOfRange'
```

### SA_THROW
Throw an **exception** built from **type and parameters** with default channel and details.\
See [_SA_ASSERT_](https://github.com/SapphireSuite/Logger/wiki/Macros#sa_throw) for examples and advanced use.
```cpp
SA_THROW((_excType, params...), _channel = Default, _details = "")
```
Example:
```cpp
// Throw SA::Exception_ReachBadAPI.
SA_THROW((ReachBadAPI, Vulkan), Renderer.Vulkan, "Vulkan API reach with invalid object.")
```
```
[18:49:22][0] {AssertFailure - Renderer.Vulkan}      main.cpp:53 - int main()
Msg:    Reach bad [Vulkan] API call!
Dets:   Vulkan API reach with invalid object.

terminate called after throwing an instance of 'SA::Exception_ReachBadAPI'
```


## Exceptions
The _SA_ASSERT_ and _SA_THROW_ macros use their **own exception system**. See [exceptions](https://github.com/SapphireSuite/Logger/wiki/Exceptions) for a **list** of all exceptions, how to use them, and how to **extend** the system (custom exception type).



# Authors

**Maxime "mrouffet" ROUFFET** - main developer (maximerouffet@gmail.com)
