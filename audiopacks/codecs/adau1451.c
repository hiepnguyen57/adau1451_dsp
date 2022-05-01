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

#define ADAU1451_FORMATS (SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE | \
	SNDRV_PCM_FMTBIT_S32_LE)


static const struct snd_kcontrol_new adau1451_controls[] = {
};

static const struct snd_soc_dapm_widget adau1451_dapm_widgets[] = {
};

static const struct snd_soc_dapm_route adau1451_dapm_routes[] = {
};

static int adau1451_probe(struct snd_soc_component *component) {

}

static int adau1451_resume(struct snd_soc_component *component) {

}

static int adau1451_set_bias_level(struct snd_soc_component *component,
		enum snd_soc_bias_level level) {

}

static int adau1451_set_pll(struct snd_soc_component *component, int pll_id,
	int source, unsigned int freq_in, unsigned int freq_out) {

}

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

MODULE_DESCRIPTION("ASoC ADAU1451 driver");
MODULE_AUTHOR("Hiep Nguyen <hoahiepk10@gmail.com>");
MODULE_LICENSE("GPL");


