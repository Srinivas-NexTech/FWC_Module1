cmake_minimum_required(VERSION 3.12)

# initialize pico_sdk from submodule
# note: this must happen before project()
#include(/home/user/txhome/pico-sdk/pico_sdk_init.cmake)
include(/root/pico-sdk/pico_sdk_init.cmake)
project(my_project)

# initialize the Pico SDK
pico_sdk_init()

# rest of your project

add_executable(main
        main.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(main pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(main)

# add url via pico_set_program_url
#example_auto_set_url(main)
