##  opencxx_cli
##  ./src/meson.build
##  Copyright 2024 - hurbIndustries
##  JPD


pkg = import('pkgconfig')

source_files = [
    'colors.cpp'
]

opencxx_cli = library('opencxx-cli',
    source_files,
    include_directories : inc,
)

pkg.generate(opencxx_cli)