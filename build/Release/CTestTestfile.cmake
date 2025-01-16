# CMake generated Testfile for 
# Source directory: /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor
# Build directory: /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_allocator "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_allocator")
set_tests_properties(test_allocator PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;92;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_graph "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_graph")
set_tests_properties(test_graph PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;92;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_cast "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_cast")
set_tests_properties(test_cast PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;93;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_clip "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_clip")
set_tests_properties(test_clip PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;93;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_concat "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_concat")
set_tests_properties(test_concat PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;93;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_element_wise "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_element_wise")
set_tests_properties(test_element_wise PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;93;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_matmul "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_matmul")
set_tests_properties(test_matmul PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;93;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_transpose "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_transpose")
set_tests_properties(test_transpose PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;93;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_nativecpu_concat "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_nativecpu_concat")
set_tests_properties(test_nativecpu_concat PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;94;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_nativecpu_elementwise "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_nativecpu_elementwise")
set_tests_properties(test_nativecpu_elementwise PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;94;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
add_test(test_nativecpu_transpose "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/test_nativecpu_transpose")
set_tests_properties(test_nativecpu_transpose PROPERTIES  _BACKTRACE_TRIPLES "/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;84;add_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;94;build_test;/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/CMakeLists.txt;0;")
subdirs("3rd-party/googletest")
