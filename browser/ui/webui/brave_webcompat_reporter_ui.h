/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_UI_WEBUI_BRAVE_WEBCOMPAT_REPORTER_UI_H_
#define BRAVE_BROWSER_UI_WEBUI_BRAVE_WEBCOMPAT_REPORTER_UI_H_

#include <string>

#include "base/macros.h"
#include "chrome/browser/ui/webui/constrained_web_dialog_ui.h"

class BraveWebcompatReporterUI : public ConstrainedWebDialogUI {
 public:
  BraveWebcompatReporterUI(content::WebUI* web_ui, const std::string& host);
  ~BraveWebcompatReporterUI() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(BraveWebcompatReporterUI);
};

#endif  // BRAVE_BROWSER_UI_WEBUI_BRAVE_WEBCOMPAT_REPORTER_UI_H_
