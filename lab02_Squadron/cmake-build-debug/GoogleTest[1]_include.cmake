if(EXISTS "/home/ajun/Documents/HEIG/POA/lab02_Squadron/lab02-squadron-roland-haeffner-junod/cmake-build-debug/GoogleTest[1]_tests.cmake")
  include("/home/ajun/Documents/HEIG/POA/lab02_Squadron/lab02-squadron-roland-haeffner-junod/cmake-build-debug/GoogleTest[1]_tests.cmake")
else()
  add_test(GoogleTest_NOT_BUILT GoogleTest_NOT_BUILT)
endif()
