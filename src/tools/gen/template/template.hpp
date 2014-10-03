#compiler-settings
directiveStartToken = @
cheetahVarStartToken = $
#end compiler-settings
@from util import util
@from cpp_util import cpp_util
@from support.cpp import *
@set support = CppSupport()
$util.header($args.output)
#include "kdb.hpp"
#include "kdbtypes.h"

#include <string>

namespace kdb
{

$cpp_util.generateenum($support, $parameters)

$cpp_util.generatebool($support)

class Parameters
{
public:

	/** \brief Constructor
	 * \param ks the keyset to work with.
	 */
	Parameters(kdb::KeySet & ks) : ks(ks)
	{}

@for $key, $info in $parameters.items()
	$support.typeof(info) $support.getfuncname($key)() const;
	void $support.setfuncname($key)($support.typeof(info) n);
@end for

private:
	kdb::KeySet &ks;
};

@for $key, $info in $parameters.items()
/** \brief Get parameter $key
 *
 * $util.doxygen(support, key, info)
 *
 * \see $support.setfuncname($key)
 *
 * \return the value of the parameter, default if it could not be found
 */
inline $support.typeof(info) Parameters::$support.getfuncname($key)() const
{
	$cpp_util.generateGetBySpec(support, support.quote(key), info)

	$support.typeof(info) ret $support.valof(info)

	if(found)
	{
		ret = found.get<$support.typeof(info)>();
	}

	return ret;
}

/** \brief Set parameter $key
 *
 * $util.doxygen(support, key, info)
 *
 * \see $support.setfuncname($key)
 *
 * \param n is the value to set in the parameter
 */
inline void Parameters::$support.setfuncname($key)($support.typeof(info) n)
{
	kdb::Key found = ks.lookup("$key", 0);

	if(!found)
	{
		kdb::Key k("$support.userkey(key)", KEY_END);
		k.set<$support.typeof(info)>(n);
		ks.append(k);
	}
	else
	{
		found.set<$support.typeof(info)>(n);
	}
}

@end for

} // namespace kdb

$util.footer($args.output)