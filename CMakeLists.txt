cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(train)

find_package(Torch REQUIRED)

# add_executable(test-app test.cpp model.cpp)
add_executable(test-app trainer.cpp model.cpp mnist.cpp callback.cpp logger.cpp)
target_link_libraries(test-app "${TORCH_LIBRARIES}")
set_property(TARGET test-app PROPERTY CXX_STANDARD 11)

