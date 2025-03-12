ADD_TARGET(
        MODE STATIC
        SOURCE
        "${PROJECT_SOURCE_DIR}/include/MyScene"
        INC
        SOURCE "${PROJECT_SOURCE_DIR}/include"
        LIB
        My::MyGM_core
        My::MyECS_core
        My::MyDP_core
)