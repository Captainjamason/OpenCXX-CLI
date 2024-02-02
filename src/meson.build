pkg = import('pkgconfig')

source_files = [
    'test.cpp'
]

opencxx_cli = library('opencxx-cli',
    source_files,
    include_directories : inc,
)

pkg.generate(opencxx_cli)