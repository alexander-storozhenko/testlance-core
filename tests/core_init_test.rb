require_relative '../testlance_core'

STUB = nil

def init_core_test
    raise unless Testlance::Core
    raise unless Testlance::Core::Cache

    raise if Testlance::Core::Cache.new.cache_test_result("str1", "str2", STUB) < 1
end

init_core_test