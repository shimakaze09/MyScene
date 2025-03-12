SET(components
        LocalToWorld
        Scale
)

SET(refls "")

FOREACH (cmpt ${components})
    SET(dst "${PROJECT_SOURCE_DIR}/include/MyScene/Components/details/${cmpt}_AutoRefl.inl")
    MYSREFL_AUTO_REFL(
            "${PROJECT_SOURCE_DIR}/include/MyScene/Components/${cmpt}.h"
            ${dst}
    )
    LIST(APPEND refls ${dst})
ENDFOREACH ()

ADD_TARGET(
        MODE STATIC
        SOURCE
        "${PROJECT_SOURCE_DIR}/include/MyScene"
        ${refls}
        INC
        "${PROJECT_SOURCE_DIR}/include"
        LIB
        My::MyGM_core
        My::MyECS_core
        My::MyDP_core
        My::MySRefl_core
)