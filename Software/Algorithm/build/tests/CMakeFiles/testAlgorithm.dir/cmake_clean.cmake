file(REMOVE_RECURSE
  "../../bin/testAlgorithm.pdb"
  "../../bin/testAlgorithm"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/testAlgorithm.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
