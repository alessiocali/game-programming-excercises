set(GENEX_CONFIG_SUFFIX "_$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:r>")
set(GENEX_SHARED_SYS_SUFFIX "$<IF:$<BOOL:${WIN32}>,dll,so>")
set(GENEX_STATIC_SYS_SUFFIX "$<IF:$<BOOL:${WIN32}>,lib,a>")
set(GENEX_LIBTYPE_SUFFIX "_$<IF:$<BOOL:${BUILD_LAZYKNIGHT_SHARED}>,${GENEX_SHARED_SYS_SUFFIX},${GENEX_STATIC_SYS_SUFFIX}>")

set(GENEX_EXEC_OUTPUT_SUFFIX "${GENEX_LIBTYPE_SUFFIX}${GENEX_CONFIG_SUFFIX}")
set(GENEX_LIB_OUTPUT_SUFFIX ${GENEX_CONFIG_SUFFIX})

function(GetFullTargetOutputName TargetName TargetBaseOutputName Output)
    
    if (${ARGC} GREATER 1)
        set (TargetBaseOutputName ${ARGV1})
    else()
        set (TargetBaseOutputName ${TargetName})
    endif()

    set( ${Output} "${TargetBaseOutputName}$<IF:$<STREQUAL:$<TARGET_PROPERTY:${TargetName},TYPE>,EXECUTABLE>,${GENEX_EXEC_OUTPUT_SUFFIX},${GENEX_LIB_OUTPUT_SUFFIX}>" PARENT_SCOPE)

endfunction()