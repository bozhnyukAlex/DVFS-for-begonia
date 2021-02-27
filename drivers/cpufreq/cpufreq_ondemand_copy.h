#include "cpufreq_governor.h"

static struct od_ops od_ops;

static unsigned int default_powersave_bias;

struct spsa_dbs_tuners {
	unsigned int betta;
	unsigned int alpha;
	unsigned int eta;
	unsigned int gamma;
};

struct spsa_policy_dbs_info
{
	struct policy_dbs_info policy_dbs;

	//----------for working with ondemand params--------------
	unsigned int freq_lo;
	unsigned int freq_lo_delay_us;
	unsigned int freq_hi_delay_us;

	signed int delta;
	unsigned int cur_estimation;

	unsigned int sample_type:1;
};

//--------------for ondemand working--------------------------
struct od_dbs_tuners {
	unsigned int powersave_bias;
};
//-----------------------------------------------------------

static inline struct spsa_policy_dbs_info *to_dbs_info(struct policy_dbs_info *policy_dbs)
{
	return container_of(policy_dbs, struct spsa_policy_dbs_info, policy_dbs);
}