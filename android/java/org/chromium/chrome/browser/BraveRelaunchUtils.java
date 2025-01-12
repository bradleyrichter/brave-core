/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.chromium.chrome.browser;

import android.content.Context;
import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;

import org.chromium.chrome.R;
import org.chromium.base.annotations.JNINamespace;
import org.chromium.base.annotations.NativeMethods;

@JNINamespace("chrome::android")
public class BraveRelaunchUtils {
    static public void askForRelaunch(Context context) {
        AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(context);
        alertDialogBuilder
            .setMessage(R.string.settings_require_relaunch_notice)
            .setCancelable(true)
            .setPositiveButton(R.string.settings_require_relaunch_now, new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog,int id) {
                    BraveRelaunchUtilsJni.get().restart();
                    dialog.cancel();
                }
            })
            .setNegativeButton(R.string.settings_require_relaunch_later,new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog,int id) {
                    dialog.cancel();
                }
            });
            AlertDialog alertDialog = alertDialogBuilder.create();
            alertDialog.show();
    }

    @NativeMethods
    interface Natives {
        void restart();
    }
}
