DOWNLOAD_ZIP_PRO(
        https://cdn.jsdelivr.net/gh/shimakaze09/MyData@main/MyScene/include/_deps/rapidjson.zip
        rapidjson.zip
        ${CMAKE_CURRENT_SOURCE_DIR}/_deps
        SHA256 10ac2a02217ba892558bed6b46b24818b1d087cfc04e15bcf7f9adf62b960e3d
)

GET_TARGET_NAME(CORE "${PROJECT_SOURCE_DIR}/src/core")

ADD_TARGET(
        MODE STATIC
        SOURCE "${PROJECT_SOURCE_DIR}/include/UScene/tool"
        LIB ${CORE}
)