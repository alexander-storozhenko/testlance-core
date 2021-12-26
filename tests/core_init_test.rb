require_relative '../testlance_core'
require_relative './ext_class'

STUB = nil

def init_core_test
    raise unless Testlance::Core
    raise unless Testlance::Core::Cache

    raise unless Testlance::Core::Cache.new.cache_test_result('1', 2) == -1
    raise unless Testlance::Core::Cache.new.cache_test_result(nil, 2) == -2
    raise unless Testlance::Core::Cache.new.cache_test_result(nil, '1') == -2

    raise unless Testlance::Core::Cache.new.ext == 1

    raise unless Testlance::Core::Cache.new.cache_test_result(5, 1.2551) == 1
    raise unless Testlance::Core::Cache.new.get_cached_test_result(5) == 1.2551


    puts 'test success'
end

init_core_test