DOWNLOAD_ZIP_PRO(
        https://cdn.jsdelivr.net/gh/shimakaze09/MyData@main/MyScene/tiny_obj_loader.zip
        tiny_obj_loader.zip
        ${CMAKE_CURRENT_SOURCE_DIR}/Primitive/_deps
        SHA256 a3cf514eec322ce11c0b20590758e8d01053963de52dba2da9c3cbb780d87699
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

IF(true)
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