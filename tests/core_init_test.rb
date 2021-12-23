require_relative '../testlance_core'

def init_core_test
    raise unless Testlance::Core
    raise unless Testlance::Core::Cache

    Testlance::Core::Cache.new.cache_test_result("field2", "value3", nil)
end

init_core_test

