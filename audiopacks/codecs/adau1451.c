// SPDX-License-Identifier: GPL-2.0-or-later
//
#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/gcd.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/tlv.h>
#include <sound/soc.h>

#include "adau1451.h"
#include "adau-utils.h"
#define ADAU1451_FORMATS (SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE | \
	SNDRV_PCM_FMTBIT_S32_LE)

#define ADAU1451_SOFT_RESET ()

static const struct reg_default adau1451_reg_defaults[] = {

};

struct adau1451_dai {
	unsigned int clk_src;
	unsigned int sysclk;
	bool enable_src;
	bool master;
};

struct adau1451{ 
	struct regmap *regmap;
	struct adau1451_dai dais[3];
};

static const struct snd_kcontrol_new adau1451_controls[] = {
};

static const struct snd_soc_dapm_widget adau1451_dapm_widgets[] = {
};

static const struct snd_soc_dapm_route adau1451_dapm_routes[] = {
};

static int adau1451_probe(struct snd_soc_component *component) {

	return 0;
}

static int adau1451_resume(struct snd_soc_component *component) {

	return 0;
}

static int adau1451_set_bias_level(struct snd_soc_component *component,
		enum snd_soc_bias_level level) {

	return 0;
}

static int adau1451_set_pll(struct snd_soc_component *component, int pll_id,
	int source, unsigned int freq_in, unsigned int freq_out) {

	return 0;
}

static const struct remap_config adau1451_remap_config = {
	.val_bits = 8,
	.reg_bits = 8,

	.volatile_reg = adau1451_register_volatile,
	.max_register = ADAU1451_SOFT_RESET,

	.cache_type = REGCACHE_RBTREE,
	.reg_defaults = adau1451_reg_defaults,
	.num_reg_defaults = ARRAY_SIZE(adau1451_reg_defaults),
};

static const struct snd_soc_component_driver adau1451_component_driver = {
	.probe			= adau1451_probe,
	.resume			= adau1451_resume,
	.set_bias_level		= adau1451_set_bias_level,
	.set_pll		= adau1451_set_pll,
	.controls		= adau1451_controls,
	.num_controls		= ARRAY_SIZE(adau1451_controls),
	.dapm_widgets		= adau1451_dapm_widgets,
	.num_dapm_widgets	= ARRAY_SIZE(adau1451_dapm_widgets),
	.dapm_routes		= adau1451_dapm_routes,
	.num_dapm_routes	= ARRAY_SIZE(adau1451_dapm_routes),
	.use_pmdown_time	= 1,
	.endianness		= 1,
	.non_legacy_dai_naming	= 1,
};

static struct snd_soc_dai_driver adau1451_dai_driver = {
	.name = "adau-hifi",
	.playback = {
		.stream_name = "Playback",
		.channels_min = 2,
		.channels_max = 8,
		.rates = SNDRV_PCM_RATE_8000_96000,
		.formats = ADAU1451_FORMATS,
	},
	.capture = {
		.stream_name = "Capture",
		.channels_min = 2,
		.channels_max = 8,
		.rates = SNDRV_PCM_RATE_8000_96000,
		.formats = ADAU1451_FORMATS,
	},
	.ops = &adau1451_dai_ops,
};

static int adau1451_i2c_probe(struct i2c_client *client,
                              const struct i2c_device_id *id) {
	struct adau1451 *adau1451;
	int ret;

	adau1451 = devm_kzalloc(&client->dev, sizeof(*adau1451), GFP_KERNEL);
	if (!adau1451) {
		return -ENOMEM;
	}

	adau1451->regmap = devm_regmap_init_i2c(client,
	&adau1451_remap_config);
	if (IS_ERR(adau1451->regmap))
		return PTR_ERR(adau1451->regmap);

	regmap_write(adau1451->regmap, ADAU1451_SOFT_RESET, 0x00);
	dev_set_drvdata(&client->dev, adau1451);
	return devm_snd_soc_register_component(&client->dev,
				&adau1451_component_driver,
				adau1451_dai_driver, ARRAY_SIZE(adau1451_dai_driver));
}

static const struct i2c_device_id adau1451_i2c_id[] = {
	{ "adau1451", 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, adau1451_i2c_id);


static struct i2c_driver adau1451_i2c_driver = {
	.driver = {
		.name = "adau1451",
	},
	.probe = adau1451_i2c_probe,
	.id_table = adau1451_i2c_id,
};

module_i2c_driver(adau1451_i2c_driver);

MODULE_DESCRIPTION("ASoC ADAU1451 driver");
MODULE_AUTHOR("Hiep Nguyen <hoahiepk10@gmail.com>");
MODULE_LICENSE("GPL");


