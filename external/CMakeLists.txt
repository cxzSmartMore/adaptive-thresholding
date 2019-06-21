longlp_message ("Building external")

longlp_message ("Building external/indexed_view")
longlp_make_library (
    TARGET_NAME IndexedView
    ALIAS_NAME jss::IndexedView
    LIBRARY_TYPE INTERFACE
    SOURCES INTERFACE indexed_view/indexed_view.hpp
    INCLUDE_DIRECTORIES INTERFACE ${LONGLP_PROJECT_EXTERNAL_DIR}
)
