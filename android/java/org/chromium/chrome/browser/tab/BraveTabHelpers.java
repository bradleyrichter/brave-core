/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.chromium.chrome.browser.tab;

import org.chromium.chrome.browser.tab.TabUma.TabCreationState;

/**
 * Helper class that initializes various tab UserData objects.
 */
public final class BraveTabHelpers {
    private BraveTabHelpers() {}

    static void initWebContentsHelpers(Tab tab) {
        DesktopModeTabHelper.from(tab);
    }
}
