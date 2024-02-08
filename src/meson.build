##  opencxx_cli
##  ./src/meson.build
##  Copyright 2024 - hurbIndustries
##  JPD

testDep = dependency('opencxx-cli')

pkg = import('pkgconfig')

source_files = [
    'colors.cpp',
    'cli.cpp'
]

opencxx_cli = library('opencxx-cli',
    source_files,
    include_directories : inc,
)

unitTests = executable('unitTests', 
    'unitTests.cpp',
    include_directories : inc,
    dependencies : [testDep]
)

test('test', unitTests)

pkg.generate(opencxx_cli)