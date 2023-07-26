cmake_minimum_required(VERSION 3.8)

add_executable(test_ipv4 test_ipv4.c)
target_link_libraries(test_ipv4 ipaddrs)


enable_testing()

add_test(NAME test_ipv4
         COMMAND test_ipv4)
