# OpenCXX-CLI
A basic library providing an extensible CLI interface written in C++.
This library is meant to help with alot of argument boilerplating. Speeding up workflows of developing primarily CLI based applications.

## Usage:
Example program:
```cpp
#include <iostream>
#include <opencxx-cli/cli.h>

using namespace opencxx_cli;

int testFunc() {
    std::cout << "Hello World!\n";
    return 0;
}

int main(int argc, char *argv[]) {
    opencxx_cli::CLI cli;

    std::vector<CLI::entryData> entries;
    cli.addEntry("--test", "-t", testFunc, &entries, false, "This will show on help()");
    cli.parse(entries, cli.vectorize(argc, argv));

    return 0;
}
```

More information can be found in the wiki. But the general idea is to create a vector to store entries, add entries, then run `cli.parse()` to let it handle the rest. 

## Features:
- [x] Basic Color Manipulation.
- [X] Automated argument handling.
  - [X] Populate `--help` with new argument checks.
  - [x] Iterate over vector of arguments
  - [X] Call respective functions that were declared earlier in code.
  - [X] `returnArg()`, Used for getting the next argument for custom functions.
- [ ] Flavortext and colorizing of default commands.
  - [ ] Options for default menu colorizations through a basic function and structs.
- [ ] `libCURL` like configuration on the fly.
- [ ] `--version` default menu available for fetching too.

__More coming soon__


## Compiling/Installing
### Requirements:
- `meson >= 1.3.1`
- `ninja >= 1.11.1`
- `clang >= 16.0.6`

### Installation: 
#### Easy Way:
Use the provided `./install.sh` file, While it's currently a quick and dirty script, it does get everything where it needs to go. Looking to improve this in the future.
#### Manual Way:
- `meson setup <builddir> && cd <builddir>` (replace builddir with directory for build)
- `ninja`
- Once it is done compiling you will need to install the libraries (`<builddir>/src`) and `opencxx-cli.pc` (`<builddir>/meson-private`) into your preferred library folder and `pkg-config` cache.
- Copy `./include` into a subfolder in your include folder. For the sake of portability use `opencxx-cli` as the subfolder name.

--- 

Made with love. Started by JPD
<3

__Questions? Comments? Requests? Want to chat? Join our Discord:__ https://discord.gg/JCHa4h4Y55

hurbIndustries 2024
