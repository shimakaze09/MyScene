DOWNLOAD_FILE(
        https://cdn.jsdelivr.net/gh/shimakaze09/MyData@main/MyScene/include/_deps/rapidjson.zip
        rapidjson.zip
        ${CMAKE_CURRENT_SOURCE_DIR}/_deps
        SHA256 10ac2a02217ba892558bed6b46b24818b1d087cfc04e15bcf7f9adf62b960e3d
)

GLOBAL_GROUP_SOURCES(RST SOURCES PATHS
        ${CMAKE_CURRENT_SOURCE_DIR}
        "${PROJECT_SOURCE_DIR}/include/MyScene/tool"
)

GET_TARGET_NAME(CORE "${PROJECT_SOURCE_DIR}/src/core")

ADD_TARGET_GDR(MODE "LIB"
        SOURCES ${SOURCES}
        INTERFACE_INC ON
        PUBLIC_GLIBS "My::${CORE}"
)

GET_TARGET_NAME(CUR ${CMAKE_CURRENT_SOURCE_DIR})