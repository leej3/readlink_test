add_executable(whats_my_rundir whats_my_rundir.c)
if(APPLE)
target_compile_definitions(whats_my_rundir PRIVATE APPLE)
endif()

