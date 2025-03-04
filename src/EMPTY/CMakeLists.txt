GET_TARGET_NAME(TOOL "${PROJECT_SOURCE_DIR}/src/tool")
ADD_TARGET(
        TEST
        MODE EXE
        SOURCE "${PROJECT_SOURCE_DIR}/include/MyScene"
        LIB ${TOOL}
)