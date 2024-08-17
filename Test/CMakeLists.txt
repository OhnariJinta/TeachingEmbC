# cpp_src/CMakeLists.txt

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

if (WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

# app1
# ソースファイルの変数化
set(TEST_SOURCE_FILE test_app.cpp)
get_filename_component(target ${TEST_SOURCE_FILE} NAME_WE)
add_executable(${target} ${TEST_SOURCE_FILE})
target_link_libraries(${target} gtest_main MyCLibrary )
#target_include_directories(${target} PUBLIC ../inc)
include(GoogleTest)
gtest_discover_tests(${target})

# drv1
# ソースファイルの変数化
set(TEST_SOURCE_FILE test_drv.cpp)
# ターゲット名の取得
get_filename_component(target ${TEST_SOURCE_FILE} NAME_WE)
# 実行ファイルの生成
add_executable(${target} ${TEST_SOURCE_FILE})
# ライブラリのリンク
target_link_libraries(${target} gtest_main DRVLibrary)
# 必要に応じて、インクルードディレクトリを追加
# target_include_directories(${target} PUBLIC ../inc)
# GoogleTestを利用したテストの自動検出
include(GoogleTest)
gtest_discover_tests(${target})