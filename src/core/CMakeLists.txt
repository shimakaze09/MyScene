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