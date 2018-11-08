/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include <string>

namespace ads {

#define STAGING_SERVER "https://ads-serve-staging.brave.com/"
#define PRODUCTION_SERVER "https://ads-serve.mercury.basicattentiontoken.org/"

#define CATALOG_PATH "v1/catalog"

static const uint64_t kMaximumEntriesInPageScoreHistory = 5;
static const uint64_t kMaximumEntriesInAdsShownHistory = 99;
static const uint64_t kMillisecondsInASecond = 1000;

static const uint64_t kOneHourInSeconds = 60 * 60;

static char kUnknownSSID[] = "UNKNOWN";
static char kUndisclosedPlace[] = "UNDISCLOSED";

static char kDefaultLanguage[] = "en";

}  // namespace ads
