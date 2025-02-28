DOWNLOAD_FILE(
        https://github.com/shimakaze09/MyData/blob/main/common/include/stb_image.h
        ${CMAKE_CURRENT_SOURCE_DIR}/_deps/stb_image.h
        SHA256 ca0456d64442d54f20ac4b42f72d080d0b90e0f7d7375931fbab82abe41ce3af
)

DOWNLOAD_FILE(
        https://github.com/shimakaze09/MyData/blob/main/common/include/stb_image_write.h
        ${CMAKE_CURRENT_SOURCE_DIR}/_deps/stb_image_write.h
        SHA256 ddc2f13ae95e42927dda169aac8eac59e3b312d36d33d4752676020c5d8d6e70
)

GLOBAL_GROUP_SOURCES(RST SOURCES PATHS
        ${CMAKE_CURRENT_SOURCE_DIR}
        "${PROJECT_SOURCE_DIR}/include/MyScene/core"
)

ADD_TARGET_GDR(MODE "LIB"
        SOURCES ${SOURCES}
        INTERFACE_INC ON
        PUBLIC_GLIBS
        "My::MyGM_core"
        "My::MyECS_core"
        "My::MyDP_core"
        "My::MyTemplate_core"
)

GET_TARGET_NAME(CORE ${PROJECT_SOURCE_DIR}/src/core)
GET_TARGET_NAME(PARSER ${PROJECT_SOURCE_DIR}/src/parser)

FUNCTION(GEN_REFL DIR)
    FILE(GLOB_RECURSE HEADERS LIST_DIRECTORIES false
            "${PROJECT_SOURCE_DIR}/include/MyScene/core/${dir}/*.h")

    ADD_CUSTOM_COMMAND(
            TARGET ${CORE}
            PRE_BUILD
            COMMAND ${PARSER} ARGS "${PROJECT_SOURCE_DIR}/src/core/${DIR}/detail/dynamic_reflection/" ${HEADERS}
            DEPENDS ${PARSER}
    )
ENDFUNCTION()

IF(false)
    GEN_REFL(Cmpt)
    GEN_REFL(Material)
    GEN_REFL(Light)
    GEN_REFL(Primitive)

    ADD_CUSTOM_COMMAND(
            TARGET ${CORE}
            PRE_BUILD
            COMMAND ${PARSER} ARGS "${PROJECT_SOURCE_DIR}/src/core/detail/dynamic_reflection/"
            "${PROJECT_SOURCE_DIR}/include/MyScene/core/SObj.h"
            "${PROJECT_SOURCE_DIR}/include/MyScene/core/Scene.h"
            DEPENDS ${PARSER}
    )
ENDIF ()