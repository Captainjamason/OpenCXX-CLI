# OpenCXX-CLI
A basic library providing an extensible CLI interface written in C++.
This library is meant to help with alot of argument boilerplating. Speeding up workflows of developing primarily CLI based applications.

## Usage:
*WIP*

## Planned Features:
- [x] Basic Color Manipulation.
- [ ] Automated argument handling.
  - [ ] Populate `--help` with new argument checks.
  - [ ] Iterate over vector of arguments
  - [ ] Call respective functions that were declared earlier in code.
- [ ] Flavortext and colorizing of default commands.

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

hurbIndustries 2024
