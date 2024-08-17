# c_src/CMakeLists.txt

# ソースファイルを指定
set(C_SOURCES
    APP/SRC/add.c
)

# C言語のライブラリを生成
add_library(MyCLibrary STATIC ${C_SOURCES})

# インクルードディレクトリを設定
target_include_directories(MyCLibrary PUBLIC
    APP/INC
    DRV/INC
)

# ソースファイルを指定
set(DRV_SOURCES
    DRV/SRC/drv1.c
)

# C言語のライブラリを生成
add_library(DRVLibrary STATIC ${DRV_SOURCES})

# インクルードディレクトリを設定
target_include_directories(DRVLibrary PUBLIC
    APP/INC
    DRV/INC
)
